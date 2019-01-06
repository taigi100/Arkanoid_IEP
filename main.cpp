#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

constexpr int windowWidth(800), windowHeight(600);
constexpr float ballRadius(10.f), ballVelocity(8.f);

struct Ball
{
     CircleShape shape;
     Vector2f velocity{-ballVelocity, -ballVelocity};

     Ball(float mX, float mY)
    {
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(Color::Red);
        shape.setOrigin(ballRadius, ballRadius);
    }

    void update()
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

    // We can also create "property" methods to easily
    // get commonly used values.
    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getRadius(); }
    float right() { return x() + shape.getRadius(); }
    float top() { return y() - shape.getRadius(); }
    float bottom() { return y() + shape.getRadius(); }
};


int main()
{
    Ball ball(windowWidth / 2, windowHeight / 2);
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

        window.draw(ball.shape);
        window.display();
    }

    return 0;
}
