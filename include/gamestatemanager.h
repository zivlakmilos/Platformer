#ifndef _GAME_STATE_MANAGER_H_
#define _GAME_STATE_MANAGER_H_

#include <unordered_map>
#include <memory>

#include "gamestate.h"

class GameStateManager
{
public:
    GameStateManager(const GameStateManager &gameStateManager) = delete;
    GameStateManager &operator=(const GameStateManager &gameStateManager) = delete;

    static GameStateManager *getGameStateManager(void);

    void addGameState(const std::string &id, const std::shared_ptr<GameState> &gameState);

    void setCurrentGameState(const std::string &id);
    std::shared_ptr<GameState> getCurrentGameState(void) const;

private:
    GameStateManager(void) {};

    std::unordered_map<std::string, std::shared_ptr<GameState>> m_states;
    std::shared_ptr<GameState> m_currentState;
};

#endif // _GAME_STATE_MANAGER_H_
