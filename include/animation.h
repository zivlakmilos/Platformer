#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Animation
{
public:
    Animation(void);
    Animation(const std::shared_ptr<sf::Texture> &texture,
              const sf::IntRect &crop, int framesCount = 1, int fps = 1);

    inline std::shared_ptr<sf::Texture> getTexture(void) { return m_texture; }
    inline void setTexture(const std::shared_ptr<sf::Texture> texture) { m_texture = texture; }

    inline sf::IntRect getCrop(void) { return m_crop; }
    inline void setCrop(const sf::IntRect &crop) { m_crop = crop; }

    inline int getFramesCount(void) { return m_framesCount; }
    inline void setFramesCount(int framesCount) { m_framesCount = framesCount; }

    int getFps(void) { return 1 / m_frameTime; }
    void setFps(int fps) { m_frameTime = 1.0f / fps; }

    void update(float deltaTime);
    void apply(sf::Sprite &sprite) const;

private:
    std::shared_ptr<sf::Texture> m_texture;
    sf::IntRect m_crop;

    int m_framesCount;

    float m_frameTime;
    float m_currentTime;
};

#endif // _ANIMATION_H_
