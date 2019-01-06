#include <SFML/Graphics.hpp>
#include "globals.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

using namespace std;
using namespace sf;

void testCollision(Paddle& mPaddle, Ball& mBall)
{
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

    vector<Brick> bricks;

    for(int iX(0); iX < countBlocksX; ++ iX)
        for( int iY(0); iY < countBlocksY; ++ iY)
            bricks.emplace_back((iX + 1) * (blockWidth+3) + 20, (iY +2) *  (blockHeight+3));

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Arkanoid");
    window.setFramerateLimit(60);

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


        ball.update();
        paddle.update();
        testCollision(paddle, ball);

        for(auto& brick : bricks) testCollision(brick, ball);

        bricks.erase(remove_if(begin(bricks), end(bricks), [](const Brick& mBrick)
            {
                return mBrick.destroyed;

                }),end(bricks));


        window.draw(ball.shape);
        window.draw(paddle.shape);
        for(auto& brick : bricks) window.draw(brick.shape);

        window.display();
    }

    return 0;
}
