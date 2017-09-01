#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics/RenderWindow.hpp>

#include "vector2.h"
#include "animation.h"

class Camera;

class Player
{
public:
    Player(float x = 0.0f, float y = 0.0f);

    inline Vector2f getPosition(void) const { return m_position; }
    inline void setPosition(Vector2f position) { m_position = position; }

    inline Vector2f getVelocity(void) const { return m_velocity; }
    inline void setVelocity(Vector2f velocity) { m_velocity = velocity; }

    inline sf::FloatRect getBounds(void) const { return m_sprite.getLocalBounds(); }

    void update(float deltaTime);
    void render(sf::RenderWindow &window, const Camera &camera);

    void moveRight(bool move = true);
    void moveLeft(bool move = true);

private:
    enum PlayerState {
        PlayerStateStandingRight = 0x0001,
        PlayerStateStandingLeft = 0x0002,
        PlayerStateMovingRight = 0x0010,
        PlayerStateMovingLeft = 0x0020,

        PlayerStateStanding = 0x000F,
        PlayerStateMoving = 0x00F0
    };

    enum AnimationState {
        AnimationStateStanding = 0,
        AnimationStateMoving,
        AnimationStateDie,
        AnimationStateCount
    };

    Vector2f m_position;
    Vector2f m_velocity;

    Animation m_animation[AnimationStateCount];
    sf::Sprite m_sprite;

    int m_playerState;
    int m_animationState;

    float m_speed;
};

#endif // _PLAYER_H_
