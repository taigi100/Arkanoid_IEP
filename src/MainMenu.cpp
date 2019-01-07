#include "MainMenu.h"

MainMenu::MainMenu()
{
    font = new Font();
    if (!font->loadFromFile("arial.ttf")) {
        //return EXIT_FAILURE;
        cout << "Nada font";
    }
     gameTitle = new Text("ARKANOID", *font, 100);
     playText = new Text("Press 'p' to play", *font, 60);
     exitText = new Text("Press ESC to exit", *font, 60);
     //text->setOrigin(text->findCharacterPos('N').x,text->findCharacterPos('N').y);
}

MainMenu::~MainMenu()
{
    //dtor
}

void MainMenu::draw(RenderWindow& window) {
    gameTitle->setPosition(window.getPosition().x/4, window.getPosition().y/2);
    playText->setPosition(window.getPosition().x/4, window.getPosition().y + 60);
    exitText->setPosition(window.getPosition().x/4, window.getPosition().y*2);
    window.draw(*gameTitle);
    window.draw(*playText);
    window.draw(*exitText);
}
