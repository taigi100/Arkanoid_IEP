#ifndef RESULTSCREEN1_H
#define RESULTSCREEN1_H

#include <SFML/graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class ResultScreen
{
    public:
        Font *font;
        Text *text;
        Text *replayText;
        Text *exitText;

        ResultScreen(const char* screenText);
        virtual ~ResultScreen();

        void draw(RenderWindow& window);
    protected:

    private:
};

#endif // RESULTSCREEN1_H
