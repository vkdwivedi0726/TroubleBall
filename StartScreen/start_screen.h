//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Start Screen 
// start_screen.h
//

#pragma once

#include "button.h"
#include "IEventDispatcher.h"
#include "IScreen.h"

#include <raylib-cpp.hpp>

#include <memory>
#include <vector>

class StartScreen : public IScreen/*, public IEventDispatcher*/ {
public:
    
    StartScreen();
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

    void StartGameCb(std::function<void()> cb);
    bool StartGame() const;

private:
    std::vector<std::shared_ptr<IObject>> start_screen_objects_;
    IEventDispatcher::SubscriberId start_button_subid_, exit_button_subid_;
    std::function<void()> start_game_cb_;
    bool start_game_;
};