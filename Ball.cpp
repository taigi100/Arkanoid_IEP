#include "Ball.h"

Ball::Ball(float mX, float mY)
{
    shape.setPosition(mX, mY);
    shape.setRadius(ballRadius);
    shape.setFillColor(Color::Red);
    shape.setOrigin(ballRadius, ballRadius);
}

void Ball::update()
{
    shape.move(velocity);

    // We need to keep the ball "inside the screen".

    if(left() < 0) velocity.x = ballVelocity;
    else if(right() > windowWidth)
        velocity.x = -ballVelocity;

    if(top() < 0)
        velocity.y = ballVelocity;
    else if(bottom() > windowHeight)
        velocity.y = -ballVelocity;
}
