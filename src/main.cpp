#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "metadata.h"

int main()
{
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  // instantiate class metadata to display platform info
  MetaData meta;
  meta.displayPlatform();

  Game game(kGridWidth, kGridHeight);
  game.SetStartSpeed();
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;

  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  int player_score = game.GetScore();
  int high_score = meta.getHighScore();

  if (player_score <= high_score)
  {
    std::cout << "current high score: " << high_score << "\n";
  }
  else
  {
    std::cout << "New High Score!! Congratulations!!" << "\n";
    meta.setHighScore(player_score);
  }
  std::cout << "Your Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  return 0;
}