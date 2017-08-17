#include "gamestatemanager.h"

GameStateManager *GameStateManager::getGameStateManager(void)
{
    static GameStateManager gameStateManager;
    return &gameStateManager;
}

void GameStateManager::addGameState(const std::string &id, const std::shared_ptr<GameState> &gameState)
{
    m_states[id] = gameState;
}

void GameStateManager::setCurrentGameState(const std::string &id)
{
    auto it = m_states.find(id);
    if(it != m_states.end())
        m_currentState = it->second;
}

std::shared_ptr<GameState> GameStateManager::getCurrentGameState(void)
{
    return m_currentState;
}
