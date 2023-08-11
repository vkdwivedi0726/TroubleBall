//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Menu Screen 
// menu_screen.h
//
#pragma once

#include "raylib-cpp.hpp"

struct Button {
    raylib::Rectangle rect_;
    const char *text_;
    raylib::Color base_color_;
    raylib::Color hover_color_;
};

struct StartScreen {
    raylib::Font title_font_;
    raylib::Font button_font_;
    Button start_button_;
    Button exit_button_;
};

void InitStartScreen(StartScreen *start_screen);

void DrawStartScreen(const StartScreen *start_screen);

void UnloadStartScreen(StartScreen *start_screen);
