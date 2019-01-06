#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "globals.h"

using namespace sf;

class Ball
{
    public:
    CircleShape shape;
    Vector2f velocity{-ballVelocity, -ballVelocity};

    Ball(float mX, float mY);

    void update();

    // We can also create "property" methods to easily
    // get commonly used values.
    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getRadius(); }
    float right() { return x() + shape.getRadius(); }
    float top() { return y() - shape.getRadius(); }
    float bottom() { return y() + shape.getRadius(); }
};

#endif // BALL_H
