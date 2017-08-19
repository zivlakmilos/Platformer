#include "gameplay.h"

#include <SFML/Graphics.hpp>

#include "resourcemanager.h"
#include "gamestatemanager.h"
#include "animation.h"

Gameplay::Gameplay(void)
{
    m_map = Map::loadMap("resources/maps/test.json");
}

Gameplay::~Gameplay(void)
{
}

void Gameplay::handleEvents(sf::RenderWindow &window)
{
    GameStateManager *manager = GameStateManager::getGameStateManager();

    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                manager->setCurrentGameState("mainMenu");
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        manager->setCurrentGameState("mainMenu");
                        break;
                }
                break;
        }
    }
}

void Gameplay::update(float deltaTime)
{
}

void Gameplay::render(sf::RenderWindow &window)
{
    m_map->render(window);
}
