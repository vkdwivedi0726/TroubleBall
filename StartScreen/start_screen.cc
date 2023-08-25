//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Start Screen 
// start_screen.cc
//

#pragma once

#include "event.h"
#include "start_screen.h"

StartScreen::StartScreen() {
    Load();
}

void StartScreen::Load() {

    auto start_button = std::make_shared<Button>("start-button", raylib::Rectangle{100, 100, 150, 50});
    auto exit_button = std::make_shared<Button>("exit-button", raylib::Rectangle{100, 200, 150, 50});
    start_button_subid_ = start_button->Subscribe(ButtonPressEvent::EventId(), 
        [this](std::shared_ptr<IEventDispatcher::EventBase> event) {
        //Handle button press event
        
    });
    
    exit_button_subid_ = exit_button->Subscribe(ButtonPressEvent::EventId(), 
        [this](std::shared_ptr<IEventDispatcher::EventBase> event) {
        //Handle button press event
        auto button_event = std::dynamic_pointer_cast<ButtonPressEvent>(event);
        if(button_event->GetButtonName() == "exit-button") {
            Unload();
            CloseWindow();
        }
    });

    start_screen_objects_.push_back(start_button);
    start_screen_objects_.push_back(exit_button);
}

void StartScreen::Unload() {
    // start_button_.UnSubscribe(start_button_subid_);
    // exit_button_.UnSubscribe(exit_button_subid_);
    start_screen_objects_.clear();
}

void StartScreen::Update(float delta_time)  {
    for(const auto& obj : start_screen_objects_) {
        obj->Update(delta_time);

        // Check if the button is clicked
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            auto button = std::dynamic_pointer_cast<Button>(obj);
            if (button) {
                if (CheckCollisionPointRec(GetMousePosition(), button->GetRect())) {
                    button->OnInteraction();
                }
            }
        }
    }
}

void StartScreen::Render()  {
    BeginDrawing();
    //ClearBackground(RAYWHITE);

    for(const auto& obj : start_screen_objects_) {
        obj->Render();
    }

    EndDrawing();
}

void StartScreen::AddObject(std::shared_ptr<IObject> object) {
    start_screen_objects_.emplace_back(std::move(object));
}

void StartScreen::RemoveObject(std::shared_ptr<IObject> object) {
    start_screen_objects_.erase(
        std::remove_if(start_screen_objects_.begin(), start_screen_objects_.end(),
                       [&](std::shared_ptr<IObject> const &obj) -> bool {
                           return obj.get() == object.get();
                       }),
    start_screen_objects_.end());

}

void StartScreen::OnSceneEnter() {};
void StartScreen::OnSceneExit() {};