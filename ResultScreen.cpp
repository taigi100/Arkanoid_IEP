#include "ResultScreen.h"

ResultScreen::ResultScreen(const char* screenText)
{
    font = new Font();
    if (!font->loadFromFile("arial.ttf")) {
        //return EXIT_FAILURE;
        cout << "Nada font";
    }
     text = new Text(screenText, *font, 100);
     replayText = new Text("Press 'p' to play again", *font, 60);
     exitText = new Text("Press ESC to exit", *font, 60);
     //text->setOrigin(text->findCharacterPos('N').x,text->findCharacterPos('N').y);
}

ResultScreen::~ResultScreen()
{
    //dtor
}

void ResultScreen::draw(RenderWindow& window) {
    text->setPosition(window.getPosition().x/4, window.getPosition().y/2);
    replayText->setPosition(window.getPosition().x/4, window.getPosition().y + 60);
    exitText->setPosition(window.getPosition().x/4, window.getPosition().y*2);
    window.draw(*text);
    window.draw(*replayText);
    window.draw(*exitText);
}
