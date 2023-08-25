//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Event Dispatcher 
// event_dispatcher.h
//


#pragma once

#include "IEventDispatcher.h"

#include <functional>
#include <list>
#include <map>
#include <mutex>


template <typename EventT>
class EventDispatcher {
public:
    class EventBase {
    public:
        virtual const EventT EventType() const = 0;
        virtual ~EventBase() = default;
    };

    using CallbackT = std::function<void(std::shared_ptr<EventBase> event_obj)>;

    EventDispatcher() = default;
    EventDispatcher(EventDispatcher &) = delete;
    EventDispatcher(EventDispatcher &&) = delete;
    EventDispatcher operator=(EventDispatcher &) = delete;
    EventDispatcher operator=(EventDispatcher &&) = delete;

    class SubscriberList;
    class Subscriber;
    class SubscriberId;

    auto Subscribe(const EventT &event, CallbackT cb);
    void UnSubscribe(const SubscriberId subscriber_id);
    void Publish(std::shared_ptr<EventBase> event_obj);

private:
    std::map<EventT, std::shared_ptr<SubscriberList>> event_map_;
    std::mutex mutex_;
};

template <typename EventT>
class EventDispatcher<EventT>::Subscriber {
public:
    Subscriber(const Subscriber &) = delete;
    CallbackT cb_;
    std::shared_ptr<char> validity_;
    Subscriber(CallbackT cb) : cb_(cb), validity_(std::make_shared<char>()) {}
};

template <typename EventT>
class EventDispatcher<EventT>::SubscriberId {
    public:
    SubscriberId() : valid_(false) {}
    SubscriberId(typename std::list<Subscriber>::iterator i, EventT event_type) : iter_(i), event_type_(event_type), valid_(true) {}

private:
    typename std::list<Subscriber>::iterator iter_;
    EventT event_type_;
    bool valid_;
    friend EventDispatcher;
    friend EventDispatcher<EventT>::SubscriberList;
};

template <typename EventT>
class EventDispatcher<EventT>::SubscriberList {
    using SubscriberType = Subscriber;
    using listType = std::list<SubscriberType>;

private:
    std::mutex mutex_;
    listType subscriber_;

public:
    SubscriberList() = default;
    auto AddSubscriber(CallbackT);
    bool Empty() { return subscriber_.empty(); }
    void NotifyAll(std::shared_ptr<EventBase> event_obj);
    void RemoveSubscriber(const SubscriberId &subscriber_id) {
        std::unique_lock<std::mutex> lock(mutex_);
        subscriber_.erase(subscriber_id.iter_);
    }
};

template <typename EventT>
auto EventDispatcher<EventT>::SubscriberList::AddSubscriber(
    typename EventDispatcher<EventT>::CallbackT cb) {
    std::unique_lock<std::mutex> lock(mutex_);
    subscriber_.emplace_back(cb);

    return --subscriber_.end();
}

template <typename EventT>
void EventDispatcher<EventT>::SubscriberList::NotifyAll(
    std::shared_ptr<typename EventDispatcher<EventT>::EventBase> event_obj) {
    std::unique_lock<std::mutex> lock(mutex_);
    for (const auto &subscriber : subscriber_) {
        std::weak_ptr<char> validity = subscriber.validity_;
        if (!validity.expired()) {
            subscriber.cb_(event_obj);
        }
    }
}

//template <typename EventT>
//EventDispatcher<EventT>::EventDispatcher() {}

template <typename EventT>
auto EventDispatcher<EventT>::Subscribe(
    const EventT &event_type, typename EventDispatcher<EventT>::CallbackT cb) {
    std::unique_lock<std::mutex> lock(mutex_);
    auto subscriber_list_iter = event_map_.find(event_type);
    if (subscriber_list_iter == event_map_.end()) {
        event_map_[event_type] = std::make_shared<SubscriberList>();
        subscriber_list_iter = event_map_.find(event_type);
    }

    auto subscribers_list = subscriber_list_iter->second;
    auto iter = subscribers_list->AddSubscriber(cb);
    return SubscriberId(iter, event_type);
}

template <typename EventT>
void EventDispatcher<EventT>::Publish(std::shared_ptr<EventBase> event_obj) {
    std::unique_lock<std::mutex> lock(mutex_);
    auto subscriber_list_iter = event_map_.find(event_obj->EventType());

    if (subscriber_list_iter != event_map_.end()) {
        auto subscriber_list = subscriber_list_iter->second;
        subscriber_list->NotifyAll(event_obj);
    }
}

template <typename EventT>
void EventDispatcher<EventT>::UnSubscribe(const SubscriberId subscriber_id) {
    std::unique_lock<std::mutex> lock(mutex_);
    auto map_entry = event_map_.find(subscriber_id.event_type_);
    if (map_entry != event_map_.end()) {
        auto subscriber_list = map_entry->second;
        subscriber_list->RemoveSubscriber(subscriber_id);
        if (subscriber_list->Empty()) {
            event_map_.erase(subscriber_id.event_type_);
        }
    }
}
