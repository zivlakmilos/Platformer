#include "resourcemanager.h"

ResourceManager::ResourceManager(void)
{
}

ResourceManager *ResourceManager::getResourceManager(void)
{
    static ResourceManager resourceManager;
    return &resourceManager;
}

void ResourceManager::loadTexture(const std::string &id, const std::string &texturePath)
{
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    texture->loadFromFile(texturePath);
    m_textures[id] = texture;
}

std::shared_ptr<sf::Texture> ResourceManager::getTexture(const std::string &id) const
{
    auto texture = m_textures.find(id);
    if(texture != m_textures.end())
        return texture->second;
    return nullptr;
}

void ResourceManager::loadFont(const std::string &id, const std::string &fontPath)
{
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    font->loadFromFile(fontPath);
    m_fonts[id] = font;
}

std::shared_ptr<sf::Font> ResourceManager::getFont(const std::string &id) const
{
    auto font = m_fonts.find(id);
    if(font != m_fonts.end())
        return font->second;
    return nullptr;
}
