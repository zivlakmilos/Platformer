#include "camera.h"

Camera::Camera(float x, float y, float width, float height, int state)
    : m_position(x, y),
      m_width(width),
      m_height(height),
      m_state(state)
{
}

void Camera::follow(const std::shared_ptr<Player> &player)
{
    Vector2f playerPosition = player->getPosition();

    Vector2f diff(playerPosition.getX() - m_position.getX(),
                  playerPosition.getY() - m_position.getY());

    if(diff.getX() > 64.0f)
        m_position += diff - Vector2f(64.0f, 0.0f);
    else if(diff.getX() < -64.0f)
        m_position += diff + Vector2f(64.0f, 0.0f);
}

Vector2f Camera::worldToView(const Vector2f &position) const
{
    return Vector2f(position.getX() - m_position.getX() + m_width / 2.0f,
                    position.getY() - m_position.getY() + m_height / 2.0f);
}
