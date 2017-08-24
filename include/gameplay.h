#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_

#include "gamestate.h"
#include "map.h"
#include "player.h"

class Gameplay : public GameState
{
public:
    Gameplay(void);
    virtual ~Gameplay(void);

    virtual void handleEvents(sf::RenderWindow &window);
    virtual void update(float deltaTime);
    virtual void render(sf::RenderWindow &window);

private:
    std::shared_ptr<Map> m_map;
    std::shared_ptr<Player> m_player;
};

#endif // _GAMEPLAY_H_
