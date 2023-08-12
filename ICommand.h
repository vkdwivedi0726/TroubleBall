//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Command Inteface
// ICommand.h
//

#pragma once

#include <raylib-cpp.hpp>

class ICommand {
    public:
    virtual ~ICommand() {}
    virtual void Execute() = 0;
};