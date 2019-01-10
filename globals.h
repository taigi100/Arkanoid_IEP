#ifndef GLOBALS_H
#define GLOBALS_H

constexpr int windowWidth(800), windowHeight(600);
constexpr float ballRadius(10.f), ballVelocity(5.f);
constexpr float paddleWidth(100.f), paddleHeight(20.f), paddleVelocity(6.f);
constexpr float blockWidth(60.f), blockHeight(20.f);
constexpr int countBlocksX(11), countBlocksY(4);

enum GameState { mainMenu, Game, Win, Lose, initGame};
#endif
