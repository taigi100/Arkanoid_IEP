#include "Paddle.h"



Paddle::Paddle(float mX, float mY)
{
    shape.setPosition(mX, mY);
    shape.setSize(Vector2f(paddleWidth, paddleHeight));
    shape.setFillColor(Color::Blue);
    shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);

}

void Paddle::update()
{
    shape.move(velocity);

    if(Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
        velocity.x = -paddleVelocity;
    else if(Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < windowWidth)
        velocity.x = paddleVelocity;
    else
        velocity.x = 0;

}
