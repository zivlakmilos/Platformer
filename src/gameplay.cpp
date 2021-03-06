#include "gameplay.h"

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "resourcemanager.h"
#include "gamestatemanager.h"
#include "animation.h"

Gameplay::Gameplay(void)
{
    m_map = Map::loadMap("resources/maps/test.json");
    m_player = std::make_shared<Player>(128.0f, 128.0f);
    m_world = std::make_shared<b2World>(b2Vec2(0.0f, 0.0f));
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
                    case sf::Keyboard::Right:
                        m_player->moveRight(true);
                        break;
                    case sf::Keyboard::Left:
                        m_player->moveLeft(true);
                        break;
                }
                break;
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                    case sf::Keyboard::Right:
                        m_player->moveRight(false);
                        break;
                    case sf::Keyboard::Left:
                        m_player->moveLeft(false);
                        break;
                }
                break;
        }
    }
}

void Gameplay::update(float deltaTime)
{
    m_player->update(deltaTime);

    if(m_player->getVelocity().getX() < 0.0f)
        m_map->collisionLeft(m_player);
    else if(m_player->getVelocity().getX() > 0.0f)
        m_map->collisionRight(m_player);

    m_camera.follow(m_player);
}

void Gameplay::render(sf::RenderWindow &window)
{
    m_map->render(window, m_camera);
    m_player->render(window, m_camera);
}
