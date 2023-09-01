//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Game Screen 
// game_screen.h
//

#pragma once

#include "IEventDispatcher.h"
#include "IScreen.h"

#include <raylib-cpp.hpp>

#include <memory>
#include <vector>

class GameScreen : public IScreen/*, public IEventDispatcher*/ {
public:
    
    GameScreen();
    // Lifecycle management
    void Load() override;
    void Unload() override;

    // Scene management
    void AddObject(std::shared_ptr<IObject> object) override;
    void RemoveObject(std::shared_ptr<IObject> object) override;

    // Update and rendering
    void Update(float delta_time) override;
    void Render() override;

    // Scene-specific functionality
    void OnSceneEnter() override;
    void OnSceneExit() override;

private:
    std::vector<std::shared_ptr<IObject>> game_objects_;
    IEventDispatcher::SubscriberId start_button_subid_, exit_button_subid_;
};