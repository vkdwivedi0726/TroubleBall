//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Event Dispatcher Interface
// IEventDispatcher.h
//


#pragma once

#include "event_dispatcher.h"

#include <memory>
#include <string>

class IEventDispatcher {
public:
    virtual ~IEventDispatcher() {}

    using EventT = std::string;
    using SubscriberId = EventDispatcher<EventT>::SubscriberId;
    using CallbackT = EventDispatcher<EventT>::CallbackT;
    using EventBase = EventDispatcher<EventT>::EventBase;

    virtual SubscriberId Subscribe(const EventT& event_id, CallbackT cb) = 0;
    virtual void UnSubscribe(const SubscriberId& subscriber_id) = 0;
    virtual void Publish(std::shared_ptr<EventBase> event_obj) = 0;

};