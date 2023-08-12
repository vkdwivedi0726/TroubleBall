//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Exit Game Command
// exit_game_command.h
//

#include "ICommand.h"

class ExitGameCommand : public ICommand {
    public:
    void Execute() override;
};