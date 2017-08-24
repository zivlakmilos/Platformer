#include "animation.h"

Animation::Animation(void)
    : m_framesCount(0),
      m_frameTime(0)
{
}

Animation::Animation(const std::shared_ptr<sf::Texture> &texture,
                     const sf::IntRect &crop, int framesCount, int fps)
    : m_texture(texture),
      m_crop(crop),
      m_framesCount(framesCount),
      m_frameTime(1.0f / fps)
{
}

void Animation::update(float deltaTime)
{
    m_currentTime += deltaTime;
    if(m_currentTime >= m_frameTime)
    {
        m_currentTime = 0.0f;
        m_crop.left += m_crop.height;
        if(m_crop.left >= m_framesCount * m_crop.height)
            m_crop.left = 0;
    }
}

void Animation::apply(sf::Sprite &sprite) const
{
    sprite.setTexture(*m_texture);
    sprite.setTextureRect(m_crop);
}
