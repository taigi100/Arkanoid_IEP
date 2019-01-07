#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class MainMenu
{
    public:
        Font *font;
        Text *gameTitle;
        Text *playText;
        Text *exitText;

        MainMenu();
        virtual ~MainMenu();

        void draw(RenderWindow& window);
    protected:

    private:
};

#endif // MAINMENU_H
