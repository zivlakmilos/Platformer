#ifndef _MAP_H_
#define _MAP_H_

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

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

    void render(sf::RenderWindow &window);

private:
    int m_width;
    int m_height;
    int m_tileWidth;
    int m_tileHeight;

    int *m_tiles;
};

#endif // _MAP_H_
