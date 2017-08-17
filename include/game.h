#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics/RenderWindow.hpp>

class ResourceManager;
class GameStateManager;

class Game
{
public:
    Game(void);

    inline void start(void) { gameLoop(); };
    void gameLoop(void);

private:
    ResourceManager *m_resourceManager;
    GameStateManager *m_gameStateManager;
    sf::RenderWindow m_window;
};

#endif // _GAME_H_
