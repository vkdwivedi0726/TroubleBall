//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Game Screen 
// game_screen.cc
//

#pragma once

#include "boulder.h"
#include "event.h"
#include "game_screen.h"

GameScreen::GameScreen() {
    Load();
}

void GameScreen::Load() {

    // Initialize boulders
    for (int i = 0; i < 10; ++i) {
        auto boulder = std::make_shared<Boulder>();
        // Set initial position, adjust as needed
        boulder->SetPosition(GetRandomValue(0, GetScreenWidth()), GetRandomValue(-200, -100), 0);
        game_objects_.push_back(boulder);
    }

}

void GameScreen::Unload() {
    // start_button_.UnSubscribe(start_button_subid_);
    // exit_button_.UnSubscribe(exit_button_subid_);
    game_objects_.clear();
}

void GameScreen::Update(float delta_time)  {
    for(const auto& obj : game_objects_) {
        obj->Update(delta_time);
    }
}

void GameScreen::Render()  {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for(const auto& obj : game_objects_) {
        obj->Render();
    }

    EndDrawing();
}

void GameScreen::AddObject(std::shared_ptr<IObject> object) {
    game_objects_.emplace_back(std::move(object));
}

void GameScreen::RemoveObject(std::shared_ptr<IObject> object) {
    game_objects_.erase(
        std::remove_if(game_objects_.begin(), game_objects_.end(),
                       [&](std::shared_ptr<IObject> const &obj) -> bool {
                           return obj.get() == object.get();
                       }),
    game_objects_.end());

}

void GameScreen::OnSceneEnter() {};
void GameScreen::OnSceneExit() {};