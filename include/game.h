#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics/RenderWindow.hpp>

class GameStateManager;

class Game
{
public:
    Game(void);

    inline void start(void) { gameLoop(); };
    void gameLoop(void);

private:
    GameStateManager *m_gameStateManager;
    sf::RenderWindow m_window;
};

#endif // _GAME_H_
