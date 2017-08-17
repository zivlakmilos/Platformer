#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include <SFML/Graphics/RenderWindow.hpp>

class GameState
{
public:
    virtual ~GameState(void) {};

    virtual void handleEvents(sf::RenderWindow &window) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow &window) = 0;

private:
};

#endif // _GAME_STATE_H_
