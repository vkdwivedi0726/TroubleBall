//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Menu Screen 
// menu_screen.h
//

#pragma once

#include "ICommand.h"
#include "command_handler.h"

#include <raylib-cpp.hpp>

class MenuScreen {
public:
    MenuScreen(const raylib::Rectangle& startButtonRect, const raylib::Rectangle& exitButtonRect);

    void Update();

    void Draw();

private:
    CommandHandler command_handler_;
};