//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Main  
// main.cc
//

#include "menu_screen1.h"

#include "raylib-cpp.hpp"


#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
int screenWidth = 800;
int screenHeight = 450;

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void);     // Update and Draw one frame

//----------------------------------------------------------------------------------
// Main Enry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Trouble Ball");

    // Initialize StartScreen
    StartScreen start_screen;
    InitStartScreen(&start_screen/*, "resources/your_title_font.ttf", "resources/your_button_font.ttf"*/);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update
        if (CheckCollisionPointRec(GetMousePosition(), start_screen.exit_button_.rect_) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Handle button click for the exit button
            //CloseWindow(); // This will close the game window
            break;
        }

        // Input
        Vector2 mouse_pos = GetMousePosition();
        bool startButtonPressed = CheckCollisionPointRec(mouse_pos, start_screen.start_button_.rect_) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
        bool exitButtonPressed = CheckCollisionPointRec(mouse_pos, start_screen.exit_button_.rect_) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        // Draw
        BeginDrawing();

        DrawStartScreen(&start_screen);

        EndDrawing();
    }

    // Unload resources
    //UnloadStartScreen(&start_screen);

    // De-Initialization
    CloseWindow();

    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void)
{
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);

    EndDrawing();
    //----------------------------------------------------------------------------------
}
