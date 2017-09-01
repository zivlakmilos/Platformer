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

void Map::render(sf::RenderWindow &window, const Camera &camera)
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

        Vector2f position = mapToWorld(Vector2i(i % m_width, i / m_width));
        position = camera.worldToView(position);
        sprite.setPosition(position.getX(), position.getY());

        window.draw(sprite);
    }
}

bool Map::collisionRight(const std::shared_ptr<Player> &player)
{
    return checkCollision(player, Side::SideRight);
}

bool Map::collisionLeft(const std::shared_ptr<Player> &player)
{
    return checkCollision(player, Side::SideLeft);
}

bool Map::collisionDown(const std::shared_ptr<Player> &player)
{
    return checkCollision(player, Side::SideDown);
}

Vector2i Map::worldToMap(const Vector2f &position) const
{
    return Vector2i(position.getX() / m_tileWidth,
                    position.getY() / m_tileHeight);
}

Vector2f Map::mapToWorld(const Vector2i &position) const
{
    return Vector2f(position.getX() * m_tileWidth,
                    position.getY() * m_tileHeight);
}

bool Map::checkCollision(const std::shared_ptr<Player> &player, Map::Side side)
{
    Vector2f playerPosition = player->getPosition();
    sf::FloatRect playerBounds = player->getBounds();
    Vector2f halfSize(playerBounds.width / 2.0f, playerBounds.height / 2.0f);
    playerPosition += halfSize;
    Vector2i playerMapPosition = worldToMap(playerPosition);

    switch(side)
    {
        case Side::SideRight:
            halfSize.setY(0.0f);
            if(worldToMap(playerPosition + halfSize).getX() > playerMapPosition.getX() &&
                m_tiles[playerMapPosition.getY() * m_width + (playerMapPosition.getX() + 1) % m_width] > 0)
            {
                Vector2f position = player->getPosition();
                position.setX(mapToWorld(playerMapPosition).getX());
                player->setPosition(position);
                return true;
            }
            break;
        case Side::SideLeft:
            halfSize.setY(0.0f);
            if(worldToMap(playerPosition - halfSize).getX() < playerMapPosition.getX() &&
                m_tiles[playerMapPosition.getY() * m_width + (playerMapPosition.getX() - 1) % m_width] > 0)
            {
                Vector2f position = player->getPosition();
                position.setX(mapToWorld(playerMapPosition).getX());
                player->setPosition(position);
                return true;
            }
            break;
        case Side::SideDown:
            halfSize.setX(0.0f);
            if(worldToMap(playerPosition + halfSize).getY() > playerMapPosition.getY() &&
                m_tiles[(playerMapPosition.getY() + 1) * m_width + playerMapPosition.getX() % m_width] > 0)
            {
                Vector2f position = player->getPosition();
                position.setY(mapToWorld(playerMapPosition).getY());
                player->setPosition(position);
                return true;
            }
            break;
    }

    return false;
}
