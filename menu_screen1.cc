//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Menu Screen 
// menu_screen.cc
//

#include "menu_screen1.h"

void InitStartScreen(StartScreen *start_screen) {
    // Define start button
    start_screen->start_button_.rect_ = Rectangle{ (float)GetScreenWidth() / 2 - 100, 350, 200, 50 };
    start_screen->start_button_.text_ = "Start";
    start_screen->start_button_.base_color_ = LIGHTGRAY;
    start_screen->start_button_.hover_color_ = DARKGRAY;

    // Define exit button
    start_screen->exit_button_.rect_ = Rectangle{ (float)GetScreenWidth() / 2 - 100, 420, 200, 50 };
    start_screen->exit_button_.text_ = "Exit";
    start_screen->exit_button_.base_color_ = LIGHTGRAY;
    start_screen->exit_button_.hover_color_ = DARKGRAY;
}

// Draw the StartScreen
void DrawStartScreen(const StartScreen *start_screen) {
    ClearBackground(RAYWHITE);

    // Draw title using default font
    DrawText("Trouble Ball", GetScreenWidth() / 2 - MeasureText("Trouble Ball", 40) / 2, 150, 40, BLACK);

    // Draw buttons
    DrawRectangleRec(start_screen->start_button_.rect_,
        CheckCollisionPointRec(GetMousePosition(), start_screen->start_button_.rect_) ?
        start_screen->start_button_.hover_color_ : start_screen->start_button_.base_color_);
    DrawText(start_screen->start_button_.text_,
             start_screen->start_button_.rect_.x + 50,
             start_screen->start_button_.rect_.y + 10,
             24, BLACK);

    DrawRectangleRec(start_screen->exit_button_.rect_,
        CheckCollisionPointRec(GetMousePosition(), start_screen->exit_button_.rect_) ?
        start_screen->exit_button_.hover_color_ : start_screen->exit_button_.base_color_);
    DrawText(start_screen->exit_button_.text_,
             start_screen->exit_button_.rect_.x + 60,
             start_screen->exit_button_.rect_.y + 10,
             24, BLACK);
}

// No changes needed for UnloadStartScreen
