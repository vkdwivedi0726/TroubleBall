//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Command Handler
// command_handler.cc
//

#include "command_handler.h"

CommandHandler::CommandHandler(std::unique_ptr<StartGameCommand> start_command, 
    std::unique_ptr<ExitGameCommand> exit_command) {
        start_game_command_ = std::move(start_command);
        exit_game_command_ = std::move(exit_command);
}

void CommandHandler::HandleInput() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        raylib::Vector2 mousePos = GetMousePosition();
        if (start_button_rect_.CheckCollision(mousePos)) {
            start_game_command_->Execute();
        }
        else if (exit_button_rect_.CheckCollision(mousePos)) {
            exit_game_command_->Execute();
        }
    }
}

bool CommandHandler::CheckCollisionPointRec(const raylib::Rectangle& rect) {
    return ::CheckCollisionPointRec(GetMousePosition(), rect);
}

const raylib::Rectangle& CommandHandler::GetStartButtonRect() const {
    return start_button_rect_;
}

const raylib::Rectangle& CommandHandler::GetExitButtonRect() const {
    return exit_button_rect_;
}

void CommandHandler::SetStartButtonRect(const raylib::Rectangle& rect) {
    start_button_rect_ = rect;
}

void CommandHandler::SetExitButtonRect(const raylib::Rectangle& rect) {
    exit_button_rect_ = rect;
}