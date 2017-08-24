#include "player.h"

#include "resourcemanager.h"

Player::Player(float x, float y)
      : m_position(x, y),
        m_playerState(PlayerStateStandingRight),
        m_animationState(AnimationStateStanding),
        m_speed(100.0f)
{
    auto texture = ResourceManager::getResourceManager()->getTexture("player");
    sf::IntRect crop(0, 0, 64, 64);

    crop.top = 8 * crop.height;
    m_animation[AnimationStateStanding] = Animation(texture, crop, 1, 1);
    crop.top = 4 * crop.height;
    m_animation[AnimationStateMoving] = Animation(texture, crop, 8, 8);
    crop.top = 2 * crop.height;
    m_animation[AnimationStateDie] = Animation(texture, crop, 8, 8);
}

void Player::update(float deltaTime)
{
    m_position += m_velocity * deltaTime;

    if(m_velocity.getX() > 0.0f)
    {
        m_playerState = PlayerStateMovingRight;
        m_animationState = AnimationStateMoving;
    } else if(m_velocity.getX() < 0.0f)
    {
        m_playerState = PlayerStateMovingLeft;
        m_animationState = AnimationStateMoving;
    } else
    {
        if(m_playerState & PlayerStateMoving)
            m_playerState = m_playerState >> 4;
        m_animationState = AnimationStateStanding;
    }

    m_animation[m_animationState].update(deltaTime);
}

void Player::render(sf::RenderWindow &window)
{
    m_animation[m_animationState].apply(m_sprite);

    if(m_playerState & (PlayerStateStandingLeft | PlayerStateMovingLeft))
    {
        m_sprite.setScale(-1.0f, 1.0f);
        m_sprite.setPosition(m_position.getX() + m_sprite.getLocalBounds().width,
                             m_position.getY());
    } else
    {
        m_sprite.setScale(1.0f, 1.0f);
        m_sprite.setPosition(m_position.getX(), m_position.getY());
    }

    window.draw(m_sprite);
}

void Player::moveRight(bool move)
{
    Vector2f acceleration;
    acceleration.setX(move ? m_speed : -m_speed);
    m_velocity += acceleration;
}

void Player::moveLeft(bool move)
{
    Vector2f acceleration;
    acceleration.setX(move ? -m_speed : m_speed);
    m_velocity += acceleration;
}
