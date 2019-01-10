#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include "globals.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "MainMenu.h"
#include "ResultScreen.h"

using namespace std;
using namespace sf;

int lives = 0;
vector<Brick> bricks;
GameState gameState = GameState::mainMenu;
Text *text;
string livesText;
void testCollision(Paddle& mPaddle, Ball& mBall)
{
    // testing for life
    if (mBall.bottom() > windowHeight) {
        lives--;
        if (lives <= 0)
            gameState = GameState::Lose;
        livesText.pop_back();
        livesText += to_string(lives);
        text->setString(livesText);
    }

    if(!mPaddle.isIntersecting(mBall))
        return;
    mBall.velocity.y = -ballVelocity;
    if(mBall.x() < mPaddle.x())
        mBall.velocity.x = -ballVelocity;
    else
        mBall.velocity.x = ballVelocity;
}

void testCollision(Brick& mBrick, Ball& mBall)
{
    if(!mBrick.isIntersecting(mBall))
        return;
    mBrick.destroyed = true;

     //how much the ball intersects the brick in every direction
    float overlapLeft(mBall.right() - mBrick.left());
    float overlapRight(mBrick.right() - mBall.left());
    float overlapTop(mBall.bottom() - mBrick.top());
    float overlapBottom(mBrick.bottom() - mBall.top());

    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

    float minOverlapX  = ballFromLeft ? overlapLeft : overlapRight;
    float minOverlapY = ballFromTop ? overlapTop : overlapBottom;

    if(abs(minOverlapX) < abs(minOverlapY))
        mBall.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
    else
        mBall.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;
}

int main()
{
    Ball ball(windowWidth / 2, windowHeight / 2);
    Paddle paddle(windowWidth / 2 ,windowHeight - 50);

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Arkanoid");
    window.setFramerateLimit(60);

    MainMenu* menu = new MainMenu();

    ResultScreen *winScreen = new ResultScreen("You won!");
    ResultScreen *loseScreen = new ResultScreen("You lost!");

    Font *font = new Font();
    if (!font->loadFromFile("arial.ttf")) {
        cout << "Nada font";
    }

    text = new Text("init", *font, 20);
    text->setPosition(10, 2);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }


        window.clear(Color::Black);
        if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;
        if(Keyboard::isKeyPressed(Keyboard::Key::P)) {
                gameState = GameState::initGame;
                continue;
        }

        switch(gameState) {
            case GameState::mainMenu: {
                menu->draw(window);
                break;
            }
            case GameState::Game: {
                ball.update();
                paddle.update();
                testCollision(paddle, ball);

                for(auto& brick : bricks) testCollision(brick, ball);

                bricks.erase(remove_if(begin(bricks), end(bricks), [](const Brick& mBrick)
                    {
                        return mBrick.destroyed;

                        }),end(bricks));

                if (bricks.size() == 0)
                    gameState = GameState::Win;
                window.draw(ball.shape);
                window.draw(paddle.shape);
                window.draw(*text);
                for(auto& brick : bricks) window.draw(brick.shape);
                break;
            }
            case GameState::Win: {
                winScreen->draw(window);
                break;
            }
            case GameState::Lose: {
                loseScreen->draw(window);
                break;
            }
            case GameState::initGame: {
                lives = 3;
                for(int iX(0); iX < countBlocksX; ++ iX)
                    for( int iY(0); iY < countBlocksY; ++ iY)
                        bricks.emplace_back((iX + 1) * (blockWidth+3) + 20, (iY +2) *  (blockHeight+3));
                livesText = "Lives: " + to_string(lives);
                text->setString(livesText);
                ball.setPosition(windowWidth / 2, windowHeight / 2);

                gameState = GameState::Game;
                break;
            }
        }

        window.display();
    }
    return 0;
}
