#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <memory>
#include "vector2.h"
#include "player.h"

class Camera
{
public:
    Camera(float x = 0.0f, float y = 0.0f,
           float width = 1000.0f, float height = 500.0f,
           int state = CameraStateFree);

    inline Vector2f getPosition(void) const { return m_position; };
    inline void setPosition(const Vector2f &position) { m_position = position; };

    void follow(const std::shared_ptr<Player> &player);

    Vector2f worldToView(const Vector2f &position) const;

private:
    enum CameraState {
        CameraStateFree = 0,
        CameraStateLockDown
    };

    Vector2f m_position;
    float m_width;
    float m_height;

    int m_state;
};

#endif // _CAMERA_H_
