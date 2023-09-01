//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Animator
// animator.h
//

#pragma once

#include <raylib-cpp.hpp>

#include <vector>


class Animation {
public:
    Animation(const std::vector<Texture2D>& frames, float frame_duration);

    void Update(float delta_time);
    const Texture2D& GetCurrentFrame() const;

private:
    void AdvanceFrame();

    std::vector<Texture2D> frames_;
    float frame_duration_;
    float current_time_;
    size_t current_frame_;
};
