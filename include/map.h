#ifndef _MAP_H_
#define _MAP_H_

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "camera.h"
#include "player.h"

class Map
{
public:
    Map(int width, int height, int tileWidth, int tileHeight);
    ~Map(void);

    static std::shared_ptr<Map> loadMap(const std::string &filePaht);

    enum Tile {
        TileGround1 = 1,
        TileBlock = 7
    };

    void render(sf::RenderWindow &window, const Camera &camera);

    bool collisionRight(const std::shared_ptr<Player> &player);
    bool collisionLeft(const std::shared_ptr<Player> &player);
    bool collisionDown(const std::shared_ptr<Player> &player);

    Vector2i worldToMap(const Vector2f &position) const;
    Vector2f mapToWorld(const Vector2i &position) const;

private:
    enum Side {
        SideRight = 0,
        SideLeft,
        SideDown
    };

    bool checkCollision(const std::shared_ptr<Player> &player, Side side);

    int m_width;
    int m_height;
    int m_tileWidth;
    int m_tileHeight;

    int *m_tiles;
};

#endif // _MAP_H_
