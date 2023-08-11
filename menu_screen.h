//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Menu Screen 
// menu_screen.h
//

#pragma once

#include "raylib-cpp.hpp"

typedef struct {
    Rectangle rect_;
    const char *text_;
    Color base_color_;
    Color hover_color_;
} Button;

typedef struct {
    Font title_font_;
    Font button_font_;
    Button start_button_;
    Button exit_button_;
} StartScreen;

void InitStartScreen(StartScreen *start_screen, const char *title_font_path,
                    const char* button_font_path);

void DrawStartScreen(const StartScreen *start_screen);

void UnloadStartScreen(StartScreen *start_screen);