#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

constexpr int windowWidth(800), windowHeight(600);
constexpr float ballRadius(10.f), ballVelocity(8.f);
constexpr float paddleWidth(60.f), paddleHeight(20.f), paddleVelocity(6.f);

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

struct Paddle
{

    RectangleShape shape;
    Vector2f velocity;

    Paddle(float mX, float mY){
        shape.setPosition(mX, mY);
        shape.setSize(Vector2f(paddleWidth, paddleHeight));
        shape.setFillColor(Color::Blue);
        shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);

    }

    void update()
    {
        shape.move(velocity);

        if(Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
            velocity.x = -paddleVelocity;
        else if(Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < windowWidth)
            velocity.x = paddleVelocity;
        else
            velocity.x = 0;

    }

    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getSize().x / 2.f; }
    float right() { return x() + shape.getSize().x / 2.f; }
    float top() { return y() - shape.getSize().y / 2.f; }
    float bottom() { return y() + shape.getSize().y / 2.f; }

};

int main()
{
    Ball ball(windowWidth / 2, windowHeight / 2);
    Paddle paddle(windowWidth / 2 ,windowHeight - 50);
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

        window.draw(ball.shape);
        window.draw(paddle.shape);
        window.display();
    }

    return 0;
}
