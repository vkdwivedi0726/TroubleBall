//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Main
// main.cc
//

#include "start_screen.h"

#include <raylib-cpp.hpp>


int main() {
    InitWindow(800, 600, "Trouble Ball");
    SetTargetFPS(60);
    StartScreen start_screen;  // Create the StartScreen instance
    while (!WindowShouldClose()) {
        start_screen.Update(GetFrameTime());  // Update logic
        start_screen.Render();                // Render the scene
    }

    CloseWindow();
    return 0;
}
