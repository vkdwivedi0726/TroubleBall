//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Main
// main.cc
//

#pragma once

#include "start_screen.h"
#include "game_screen.h"

#include <raylib-cpp.hpp>


int main() {
    InitWindow(800, 600, "Trouble Ball");
    SetTargetFPS(60);
    StartScreen start_screen;  // Create the StartScreen instance
    GameScreen game_screen;
    IScreen* current_screen = &start_screen;
    
    while (!WindowShouldClose()) {
        current_screen->Update(GetFrameTime());  // Update logic
        current_screen->Render();                // Render the scene
        // Check if the current screen is a StartScreen
        auto is_start_screen = dynamic_cast<StartScreen*>(current_screen);
        if (is_start_screen != nullptr && is_start_screen->StartGame()) {
            current_screen = &game_screen;  // Transition to the game screen
        }
    }

    CloseWindow();
    return 0;
}
