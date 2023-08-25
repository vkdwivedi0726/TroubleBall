//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Object Inteface
// IOject.h
//

#pragma once

class IObject {
public:
    virtual ~IObject() {}

    // Lifecycle management
    virtual void Initialize() = 0;
    virtual void Update(float delta_time) = 0;
    virtual void Render() = 0;
    virtual void Shutdown() = 0;

    // Position and transformation
    virtual void SetPosition(float x, float y, float z) = 0;
    virtual void Translate(float offset_x, float offset_y, float offset_z) = 0;

    // Interactions
    virtual void OnInteraction() = 0;

    // Properties
    virtual bool IsActive() const = 0;
    virtual void SetActive(bool active) = 0;
};
