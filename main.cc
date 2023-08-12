
#pragma once


#include "menu_screen.h"

#include <raylib-cpp.hpp>

int main() {
    // Initialization code
    raylib::Window window(800, 600, "Menu Screen Example");

    raylib::Rectangle start_button_rect { (float)GetScreenWidth() / 2 - 100, 350, 200, 50 };
    raylib::Rectangle exit_button_rect { (float)GetScreenWidth() / 2 - 100, 420, 200, 50 };

    MenuScreen menu_screen(start_button_rect, exit_button_rect);

    // Create instances of StartGameCommand and ExitGameCommand
    std::unique_ptr<StartGameCommand> start_game_command = std::make_unique<StartGameCommand>(/* Pass parameters */);
    std::unique_ptr<ExitGameCommand> exit_game_command = std::make_unique<ExitGameCommand>();

    CommandHandler command_handler(std::move(start_game_command), std::move(exit_game_command));
    command_handler.SetStartButtonRect(start_button_rect);
    command_handler.SetExitButtonRect(exit_button_rect);

    while (!window.ShouldClose()) {
        // Update code

        // Update menu screen
        menu_screen.Update();

        // Draw code
        window.BeginDrawing();
        window.ClearBackground(raylib::RAYWHITE);

        // Draw menu screen
        menu_screen.Draw();

        window.EndDrawing();
    }

    // Clean-up code
    CloseWindow();

    return 0;
}