#include "Brick.h"

Brick::Brick(float mX, float mY)
    {
        shape.setPosition(mX, mY);
        shape.setSize(Vector2f(blockWidth, blockHeight));
        shape.setFillColor(Color(148,0,211));
        shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
    }
