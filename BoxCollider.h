#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include <iostream>

class BoxCollider {
public:
    virtual ~BoxCollider() {}

    virtual float left()=0;
    virtual float right()=0;
    virtual float top()=0;
    virtual float bottom()=0;

    bool isIntersecting(BoxCollider& other)
    {
         return this->right() >= other.left() &&
                this->left() <= other.right() &&
                this->bottom() >= other.top() &&
                this->top() <= other.bottom();
    }
};

#endif // BOXCOLLIDER_H
