#ifndef SFML_GAMESTATE_HPP
#define SFML_GAMESTATE_HPP


class GameState
{
public:
  enum State
  {
    Waiting,
    Running,
    Exiting
  };

  GameState();
  void doNext();
  State getState() const;
  void setState(State state);

private:
  State state_;

};


#endif
