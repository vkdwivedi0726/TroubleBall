//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Boulder
// boulder.cc
//

#include "boulder.h"

Boulder::Boulder()
    
{
    // animation_(animation_frames_, GetFrameTime());
    Initialize();
}

void Boulder::Initialize()
{
    // Initialize animation, position, etc.
    std::vector<Texture2D> animation_frames;
    // Loop to load images from resources/boulder0, boulder1, ..., boulder4
    for (int i = 0; i < 5; ++i) {
        std::string image_path = "C:\\source\\TroubleBall\\build\\Debug\\resources\\boulder" + std::to_string(i) + ".png";
        Texture2D frame = LoadTexture(image_path.c_str());
        animation_frames.push_back(frame);
    }
    float rotation_speed = 1.0f;
    animation_frames_ = animation_frames;
    rotation_speed_ = rotation_speed;
    animation_ = std::make_shared<Animation>(animation_frames_, rotation_speed_);
    is_active_ = true; 
    current_frame_ = 0;
    rotation_ = 0.0f;
    position_ = { static_cast<float>(GetRandomValue(0, GetScreenWidth())), -50.0f };
    fall_speed_ = static_cast<float>(GetRandomValue(100, 300));
    x_speed_ = static_cast<float>(GetRandomValue(-50, 50));
    boulder_size_ = { static_cast<float>(animation_frames[0].width), static_cast<float>(animation_frames[0].height) };
    

}

void Boulder::Update(float delta_time)
{

    if (is_active_) {
        // Update logic for falling animation and collision
        // Update the animation
        animation_->Update(delta_time);
        rotation_ += rotation_speed_ * delta_time;

        // Update position for falling
        position_.y += fall_speed_ * delta_time;
        position_.x += x_speed_ * delta_time;

        // Check if the boulder is out of screen bounds
        if (position_.y > GetScreenHeight()) {
            ResetBoulder();
        }
    }



    // Update other properties
}

void Boulder::Render()
{
    if (is_active_) {
        // Define the desired size of the boulder
        float boulder_size = 50.0f; // Adjust as needed

        // Render the animation at the updated position and rotation with specified size
        //DrawTextureEx(animation_->GetCurrentFrame(), position_, rotation_, boulder_size_.x / animation_frames_[current_frame_].width, WHITE);
        DrawTextureEx(animation_->GetCurrentFrame(), position_, rotation_, boulder_size / animation_frames_[current_frame_].width, WHITE);
    }

    // Render other properties
}

void Boulder::Shutdown()
{
    // Cleanup resources
}

void Boulder::SetPosition(float x, float y, float z)
{
    position_ = {x, y};
}

void Boulder::Translate(float offset_x, float offset_y, float offset_z)
{
    position_.x += offset_x;
    position_.y += offset_y;
}

void Boulder::OnInteraction()
{
    // Handle interactions, such as collision
}

bool Boulder::IsActive() const
{
    return is_active_;
}

void Boulder::SetActive(bool active)
{
    is_active_ = active;
}