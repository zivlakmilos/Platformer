#include "map.h"

#include <fstream>
#include <SFML/Graphics.hpp>

#include "json.hpp"
#include "resourcemanager.h"

Map::Map(int width, int height, int tileWidth, int tileHeight)
    : m_width(width),
      m_height(height),
      m_tileWidth(tileWidth),
      m_tileHeight(tileHeight),
      m_tiles(nullptr)
{
    m_tiles = new int[m_width * m_height];
}

Map::~Map(void)
{
    if(m_tiles)
        delete[] m_tiles;
}

std::shared_ptr<Map> Map::loadMap(const std::string &filePaht)
{
    nlohmann::json json;
    std::ifstream file(filePaht);

    if(!file.is_open())
        return nullptr;

    file >> json;

    int width = json["width"].get<int>();
    int height = json["height"].get<int>();
    int tileWidth = json["tilewidth"].get<int>();
    int tileHeight = json["tileheight"].get<int>();
    auto tiles = json["layers"][0]["data"];

    std::shared_ptr<Map> map = std::make_shared<Map>(width, height, tileWidth, tileHeight);

    int i = 0;
    auto it = tiles.begin();
    for(; it != tiles.end(); it++, i++)
        map->m_tiles[i] = *it;

    return map;
}

void Map::render(sf::RenderWindow &window)
{
    sf::Sprite sprite;
    auto texture = ResourceManager::getResourceManager()->getTexture("tiles");
    sprite.setTexture(*texture);

    for(int i = 0; i < m_width * m_height; i++)
    {
        if(m_tiles[i] == 0)
            continue;
        int tile = m_tiles[i] - 1;
        sf::IntRect crop = { (tile * m_tileWidth) % texture->getSize().x,
                             (tile * m_tileWidth) / texture->getSize().x,
                             m_tileWidth, m_tileHeight };
        sprite.setTextureRect(crop);
        sprite.setPosition((i % m_width) * m_tileWidth, (i / m_width) * m_tileHeight);
        window.draw(sprite);
    }
}
