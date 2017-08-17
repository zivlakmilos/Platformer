#include "mainmenu.h"

#include <SFML/Graphics.hpp>

#include "gamestatemanager.h"

MainMenu::MainMenu(void)
    : GameState(),
      m_gameStateManager(GameStateManager::getGameStateManager())
{
}

MainMenu::~MainMenu(void)
{
}

void MainMenu::handleEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyReleased:
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
        }
    }
}

void MainMenu::update(float deltaTime)
{
}

void MainMenu::render(sf::RenderWindow &window)
{
}
