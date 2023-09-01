//Copyright (C) 2023 TroubleBall LLC. All rights reserved.
//
// Boulder
// boulder.h
//

#include "animator.h"
#include "IObject.h"

#include <raylib-cpp.hpp>

#include <memory>
#include <vector>

class Boulder : public IObject {
public:
    Boulder();
    //const std::vector<Texture2D>& animationFrames, float rotationSpeed
    void Initialize() override;

    void Update(float delta_time) override;

    void Render() override;

    void Shutdown() override;

    void SetPosition(float x, float y, float z) override;

    void Translate(float offset_x, float offset_y, float offset_z) override;

    void OnInteraction() override;

    bool IsActive() const override;

    void SetActive(bool active) override;

    void Boulder::ResetBoulder()
    {
        fall_speed_ = static_cast<float>(GetRandomValue(100, 300)); // Adjust as needed
        x_speed_ = static_cast<float>(GetRandomValue(-50, 50));     // Adjust as needed

        position_.y = -boulder_size_.y;
        position_.x = static_cast<float>(GetRandomValue(0, GetScreenWidth() - boulder_size_.x));
    }

private:
    std::vector<Texture2D> animation_frames_;
    std::shared_ptr<Animation> animation_; // Assuming you have an Animation class
    float rotation_speed_;
    bool is_active_;
    Vector2 position_;
    float rotation_;
    size_t current_frame_;
    float fall_speed_; // Speed of falling in pixels per second
    float x_speed_;    // Speed in the x direction
    Vector2 boulder_size_;
};
