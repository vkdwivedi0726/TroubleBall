//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Start Command
// start_game_command.h
//

#include "ICommand.h"

class StartGameCommand : public ICommand {
    public:
    void Execute() override;
};