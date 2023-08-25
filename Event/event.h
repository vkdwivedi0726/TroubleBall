//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Events
// event.h
//


#pragma once

#include "IEventDispatcher.h"

class StartGameEvent final : public IEventDispatcher::EventBase {
    public:
    static IEventDispatcher::EventT EventId() {
        return "start-game-event";
    }

    const IEventDispatcher::EventT EventType() const override {
        return EventId();
    }
};

class ButtonPressEvent : public IEventDispatcher::EventBase {
public:
    static IEventDispatcher::EventT EventId() {
        return "button-press-event";
    }

    explicit ButtonPressEvent(const std::string& button_name)
        : button_name_(button_name) {}

    const IEventDispatcher::EventT EventType() const override {
        return EventId();
    }

    const std::string& GetButtonName() const {
        return button_name_;
    }

private:
    std::string button_name_;
};
