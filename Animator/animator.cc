//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Animator
// animator.cc
//


#include "animator.h"

Animation::Animation(const std::vector<Texture2D>& frames, float frame_duration)
    : frames_(frames), frame_duration_(frame_duration), current_time_(0.0f), current_frame_(0) {}

void Animation::Update(float delta_time) {
    current_time_ += delta_time;
    if (current_time_ >= frame_duration_) {
        current_time_ -= frame_duration_;
        AdvanceFrame();
    }
}

const Texture2D& Animation::GetCurrentFrame() const {
    return frames_[current_frame_];
}

void Animation::AdvanceFrame() {
    current_frame_ = (current_frame_ + 1) % frames_.size();
}
