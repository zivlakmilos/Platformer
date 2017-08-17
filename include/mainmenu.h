#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

#include "gamestate.h"

class GameStateManager;

class MainMenu : public GameState
{
public:
    MainMenu(void);
    virtual ~MainMenu(void);

    virtual void handleEvents(sf::RenderWindow &window) override;
    virtual void update(float deltaTime) override;
    virtual void render(sf::RenderWindow &window) override;

private:
    GameStateManager *m_gameStateManager;
};

#endif // _MAIN_MENU_H_
