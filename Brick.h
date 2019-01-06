#ifndef BRICK_H
#define BRICK_H

#include <SFML/Graphics.hpp>
#include "globals.h"
#include "BoxCollider.h"

using namespace sf;


class Brick : public BoxCollider
{
    public:
    RectangleShape shape;
    bool destroyed = false;

    Brick(float mX, float mY);

    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getSize().x / 2.f; }
    float right() { return x() + shape.getSize().x / 2.f; }
    float top() { return y() - shape.getSize().y / 2.f; }
    float bottom() { return y() + shape.getSize().y / 2.f; }

};

#endif // BRICK_H
