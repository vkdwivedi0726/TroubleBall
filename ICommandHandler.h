//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// CommandHandler Inteface
// ICommandHandler.h
//

#pragma once
#include <raylib-cpp.hpp>

class ICommandHandler {
    public:
    virtual ~ICommandHandler() {}
    virtual void HandleInput() = 0;
    virtual bool CheckCollisionPointRec(const raylib::Rectangle& rect) = 0;
    virtual const raylib::Rectangle& GetStartButtonRect() const = 0;
    virtual const raylib::Rectangle& GetExitButtonRect() const = 0;
};