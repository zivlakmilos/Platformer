#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include <unordered_map>
#include <memory>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

class ResourceManager
{
public:
    ResourceManager(const ResourceManager &resourceManager) = delete;
    ResourceManager &operator=(const ResourceManager &resourceManager) = delete;

    static ResourceManager *getResourceManager(void);

    void loadTexture(const std::string &id, const std::string &texturePath);
    std::shared_ptr<sf::Texture> getTexture(const std::string &id) const;

    void loadFont(const std::string &id, const std::string &fontPath);
    std::shared_ptr<sf::Font> getFont(const std::string &id) const;

private:
    ResourceManager(void);

    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_textures;
    std::unordered_map<std::string, std::shared_ptr<sf::Font>> m_fonts;
};

#endif // _RESOURCE_MANAGER_H_
