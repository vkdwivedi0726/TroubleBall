//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Screen Inteface
// IScreen.h
//

#include "IObject.h"

#include <memory>

class IScreen {
public:
    virtual ~IScreen() {}

    // Lifecycle management
    virtual void Load() = 0;
    virtual void Unload() = 0;

    // Scene management
    virtual void AddObject(std::shared_ptr<IObject> object) = 0;
    virtual void RemoveObject(std::shared_ptr<IObject> object) = 0;

    // Update and rendering
    virtual void Update(float delta_time) = 0;
    virtual void Render() = 0;

    // Scene-specific functionality
    virtual void OnSceneEnter() = 0;
    virtual void OnSceneExit() = 0;
};
