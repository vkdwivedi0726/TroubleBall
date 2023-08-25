//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Button
// button.cc
//

#include "button.h"
#include "event.h"

class Button::ButtonEventDispatcher : public EventDispatcher<EventT> {
    public:
    SubscriberId Subscribe(const EventT& event_id, CallbackT cb);
    void UnSubscribe(const SubscriberId& subscriber_id);
    void Publish(std::shared_ptr<EventBase> event_obj);

    ButtonEventDispatcher() : EventDispatcher() {};
    ~ButtonEventDispatcher() = default;
};

IEventDispatcher::SubscriberId 
Button::ButtonEventDispatcher::Subscribe(const EventT& event_id, CallbackT cb) {
    return EventDispatcher<EventT>::Subscribe(event_id, cb);
}

void Button::ButtonEventDispatcher::UnSubscribe(const SubscriberId& subscriber_id) {
    EventDispatcher<EventT>::UnSubscribe(subscriber_id);
}

void Button::ButtonEventDispatcher::Publish(std::shared_ptr<EventBase> event_obj) {
    EventDispatcher<EventT>::Publish(event_obj);
}

Button::Button(const std::string &label, const Rectangle &rect)
    : label_(label), rect_(rect), is_active_(true) {
    button_event_dispatcher_ = std::make_shared<ButtonEventDispatcher>();
}

void Button::Initialize() {
    // Initialization code, if needed
}

void Button::Update(float deltaTime) {
    // Update logic, if needed
    bool is_mouse_hover = CheckCollisionPointRec(GetMousePosition(), rect_);
    is_mouse_hover ? rect_color_ = LIGHTGRAY : rect_color_ = GRAY;
}

void Button::Render() {
    //DrawRectangleRec(rect_, is_active_ ? GRAY : LIGHTGRAY);
    DrawRectangleRec(rect_, rect_color_);
    DrawText(label_.c_str(), rect_.x + rect_.width / 2 - (float)MeasureText(label_.c_str(), 20) / 2,
             rect_.y + rect_.height / 2 - (float)10, 20, is_active_ ? DARKGRAY : GRAY);
}

void Button::Shutdown() {
    // Cleanup code, if needed
}

void Button::SetPosition(float x, float y, float z) {
    rect_.x = x;
    rect_.y = y;
}

void Button::Translate(float offset_x, float offset_y, float offset_z) {
    rect_.x += offset_x;
    rect_.y += offset_y;
}

void Button::OnInteraction() {
    // Handle button click, if needed
    std::shared_ptr<ButtonPressEvent> event = std::make_shared<ButtonPressEvent>(label_);
    Publish(event);
}

bool Button::IsActive() const {
    return is_active_;
}

void Button::SetActive(bool active) {
    is_active_ = active;
}

IEventDispatcher::SubscriberId Button::Subscribe(const EventT& event_id, CallbackT cb) {
    return button_event_dispatcher_->Subscribe(event_id, cb);
}

void Button::UnSubscribe(const SubscriberId& subscriber_id) {
    button_event_dispatcher_->UnSubscribe(subscriber_id);
}

void Button::Publish(std::shared_ptr<EventBase> event_obj) {
    button_event_dispatcher_->Publish(event_obj);
}

Rectangle Button::GetRect() const {
    return rect_;
}