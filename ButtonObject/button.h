//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Button
// button.h
//

#pragma once


#include "IEventDispatcher.h"
#include "IObject.h"

#include <raylib-cpp.hpp>

#include <string>


class Button : public IObject, public IEventDispatcher {
public:
    Button(const std::string &label, const Rectangle &rect);

    void Initialize() override;
    void Update(float delta_time) override;
    void Render() override;
    void Shutdown() override;
    
    void SetPosition(float x, float y, float z) override;
    void Translate(float offset_x, float offset_y, float offset_z) override;
    
    void OnInteraction() override;
    bool IsActive() const;
    void SetActive(bool active) override;

    IEventDispatcher::SubscriberId Subscribe(const EventT& event_id, CallbackT cb) override;
    void UnSubscribe(const SubscriberId& subscriber_id) override;
    void Publish(std::shared_ptr<EventBase> event_obj) override;

    Rectangle GetRect() const;

private:
    std::string label_;
    Rectangle rect_;
    Color rect_color_;
    bool is_active_;
    class ButtonEventDispatcher;
    std::shared_ptr<EventDispatcher<EventT>> button_event_dispatcher_;
};