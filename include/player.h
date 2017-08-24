#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics/RenderWindow.hpp>

#include "vector2.h"
#include "animation.h"

class Player
{
public:
    Player(float x = 0.0f, float y = 0.0f);

    void update(float deltaTime);
    void render(sf::RenderWindow &window);

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
