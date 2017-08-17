#include "game.h"

#include "resourcemanager.h"
#include "gamestatemanager.h"
#include "mainmenu.h"

Game::Game(void)
    : m_resourceManager(ResourceManager::getResourceManager()),
      m_gameStateManager(GameStateManager::getGameStateManager()),
      m_window(sf::VideoMode(1000, 500), "Platformer \xA9 Milos Zivlak - ZI 2017")
{
    m_resourceManager->loadFont("kaushan", "resources/fonts/kaushan.otf");

    m_gameStateManager->addGameState("mainMenu", std::make_shared<MainMenu>());
    m_gameStateManager->setCurrentGameState("mainMenu");
}

void Game::gameLoop(void)
{
    sf::Clock clock;
    while(m_window.isOpen())
    {
        auto gameState = m_gameStateManager->getCurrentGameState();

        gameState->handleEvents(m_window);

        sf::Time deltaTime = clock.getElapsedTime();
        gameState->update(deltaTime.asSeconds());

        m_window.clear();
        gameState->render(m_window);
        m_window.display();
    }
}
