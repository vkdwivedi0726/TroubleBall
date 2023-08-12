//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Menu Screen 
// menu_screen.cc
//

#include "menu_screen.h"

MenuScreen::MenuScreen(const raylib::Rectangle &start_button_rect, const raylib::Rectangle &exit_button_rect)
    : command_handler_(std::make_unique<StartGameCommand>(), std::make_unique<ExitGameCommand>()) {
    command_handler_.SetStartButtonRect(start_button_rect);
    command_handler_.SetExitButtonRect(exit_button_rect);
}

void MenuScreen::Update() {
    command_handler_.HandleInput();
}

void MenuScreen::Draw() {
    ClearBackground(raylib::RAYWHITE);

    // Draw start button
    DrawRectangleRec(command_handler_.GetStartButtonRect(),
                     command_handler_.CheckCollisionPointRec(command_handler_.GetStartButtonRect()) ? raylib::DARKGRAY : raylib::LIGHTGRAY);
    DrawText("Start", command_handler_.GetStartButtonRect().x + 50, command_handler_.GetStartButtonRect().y + 10, 24, raylib::BLACK);

    // Draw exit button
    DrawRectangleRec(command_handler_.GetExitButtonRect(),
                     command_handler_.CheckCollisionPointRec(command_handler_.GetExitButtonRect()) ? raylib::DARKGRAY : raylib::LIGHTGRAY);
    DrawText("Exit", command_handler_.GetExitButtonRect().x + 60, command_handler_.GetExitButtonRect().y + 10, 24, raylib::BLACK);
}
