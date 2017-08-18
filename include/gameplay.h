#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_

#include "gamestate.h"
#include "animation.h"

class Gameplay : public GameState
{
public:
    Gameplay(void);
    virtual ~Gameplay(void);

    virtual void handleEvents(sf::RenderWindow &window);
    virtual void update(float deltaTime);
    virtual void render(sf::RenderWindow &window);

private:
};

#endif // _GAMEPLAY_H_
