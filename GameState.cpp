#include "GameState.hpp"

GameState::GameState()
{
  state_ = Waiting;
}

void GameState::doNext()
{
  state_ = static_cast<State>((state_ + 1) % 3);
}

GameState::State GameState::getState() const
{
  return state_;
}

void GameState::setState(GameState::State state)
{
  GameState::state_ = state;
}
