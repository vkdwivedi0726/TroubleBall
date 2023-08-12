//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Command Handler
// command_handler.h
//
#include "ICommandHandler.h"
#include "start_game_command.h"
#include "exit_game_command.h"

#include <memory>

class CommandHandler : public ICommandHandler {
    public:
    CommandHandler(std::unique_ptr<StartGameCommand>, std::unique_ptr<ExitGameCommand> );
    void HandleInput() override;
    bool CheckCollisionPointRec(const raylib::Rectangle& rect) override;
    const raylib::Rectangle& GetStartButtonRect() const override;
    const raylib::Rectangle& GetExitButtonRect() const override;
    void SetStartButtonRect(const raylib::Rectangle& rect);
    void SetExitButtonRect(const raylib::Rectangle& rect);

    private:
    raylib::Rectangle start_button_rect_;
    raylib::Rectangle exit_button_rect_;
    std::unique_ptr<StartGameCommand> start_game_command_;
    std::unique_ptr<ExitGameCommand> exit_game_command_;
};
