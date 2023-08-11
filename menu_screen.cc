//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Menu Screen 
// menu_screen.cc
//

#include "menu_screen.h"

void InitStartScreen(StartScreen *start_screen, const char *title_font_path,
                    const char* button_font_path) {
    
    // start_screen->title_font_ = LoadFont(title_font_path);
    // start_screen->button_font_ = LoadFont(button_font_path);

    // Define start button
    start_screen->start_button_.rect_ = Rectangle { (float)GetScreenWidth() / 2 - 100, 350, 200, 50 };
    start_screen->start_button_.text_ = "Start";
    start_screen->start_button_.base_color_ = LIGHTGRAY;
    start_screen->start_button_.hover_color_ = DARKGRAY;

    // Define exit button
    start_screen->exit_button_.rect_ = Rectangle { (float)GetScreenWidth() / 2 - 100, 420, 200, 50 };
    start_screen->exit_button_.text_ = "Exit";
    start_screen->exit_button_.base_color_ = LIGHTGRAY;
    start_screen->exit_button_.hover_color_ = DARKGRAY;
}

// Draw the StartScreen
void DrawStartScreen(const StartScreen *start_screen) {
    ClearBackground(RAYWHITE);

    // Draw title
    DrawTextEx(start_screen->title_font_, "Trouble Ball", 
        Vector2 { (float)GetScreenWidth() / 2 - MeasureText("Start", start_screen->title_font_.baseSize) / 2, 150 }, 
            start_screen->title_font_.baseSize, 2, BLACK);

    // Draw buttons
    DrawRectangleRec(start_screen->start_button_.rect_,
        CheckCollisionPointRec(GetMousePosition(), start_screen->start_button_.rect_) ?
        start_screen->start_button_.hover_color_ : start_screen->start_button_.base_color_);
    DrawTextEx(start_screen->button_font_, 
            start_screen->start_button_.text_, 
            Vector2 { start_screen->start_button_.rect_.x + 50, 
            start_screen->start_button_.rect_.y + 10 }, start_screen->button_font_.baseSize, 2, BLACK);

    DrawRectangleRec(start_screen->exit_button_.rect_,
        CheckCollisionPointRec(GetMousePosition(), start_screen->exit_button_.rect_) ?
        start_screen->exit_button_.hover_color_ : start_screen->exit_button_.base_color_);

    DrawTextEx(start_screen->button_font_, 
            start_screen->exit_button_.text_, 
            Vector2 { start_screen->exit_button_.rect_.x + 60, 
            start_screen->exit_button_.rect_.y + 10 }, start_screen->button_font_.baseSize, 2, BLACK);
}

// Unload resources of the StartScreen
void UnloadStartScreen(StartScreen *start_screen) {
    // UnloadFont(start_screen->title_font_);
    // UnloadFont(start_screen->button_font_);
}