#include "Ball.h"

//Funkcja zmieniająca liczby w ciąg znaków.
//Wykorzystywana do wyświetlania bierzącego wyniku
String toString(int integer)
{
    char numstr[4];
    sprintf(numstr, "%i", integer);
    return numstr;
}



//Konstruktor
Ball::Ball(float t_X, float t_Y, float _ballRadius, float _ballVelocity)
{
    ballRadius=_ballRadius;
    ballVelocity=_ballVelocity;
    shape.setPosition(t_X,t_Y);
    shape.setRadius(this->ballRadius); //Ustawiamy radius
    shape.setFillColor(Color::White); //Ustawiamy kolor
 

        velocity.x=ballVelocity;//Pozwalamy classie pochodnej zdobyć jej wektor
        velocity.y=ballVelocity;//Bez tego piłka nie ruszy się

    shape.setOrigin(this->ballRadius,this->ballRadius);//Ustawiamy pozycje na podstawie wczesniejszej funkjci

}

//Metoda ustawiająca teskty po wygranej i przegranej oraz licznik puntków
void Ball::setMyText()
{
    font.loadFromFile("Terserah.ttf");

    gameLose.setFont(font);
    gameLose.setString("Game Over");
    gameLose.setCharacterSize(60);
    gameLose.setFillColor(Color::Red);
    gameLose.setOrigin(0,0);
    gameLose.setPosition(250,330);

    gameWin.setFont(font);
    gameWin.setString("Winner Winner Chicken Dinner");
    gameWin.setCharacterSize(60);
    gameWin.setFillColor(Color::Green);
    gameWin.setOrigin(0,0);
    gameWin.setPosition(75,330);

    scoreTxt.setFont(font);
    scoreTxt.setString(toString(score));
    scoreTxt.setCharacterSize(35);
    scoreTxt.setFillColor(Color::Blue);
    scoreTxt.setOrigin(0,0);
    scoreTxt.setPosition(0,0);
    
}

//Metoda, wywoływana co klatkę gry aby zmieniać prędkość oraz odbijać obiekt od ścian
void Ball::update(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) shape.move(-3.f, 0.f);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) shape.move(3.f, 0.f);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) shape.move(0.f,-3.f);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) shape.move(0.f,3.f);
    
    Bazowa::update();
    scoreTxt.setString(toString(score));
    
}

//Metoda która dodaje punkty do zmiennej ,,score" na podstawie której wygrywamy lub nie 
void Ball::kill(int i){
    if(i==1) score=score+50;
    else if(i==2) score=score+250;
    else score=0;
}

//Metoda przekazująca realny obiekt aby rysować go na ekranie
void Ball::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->shape,state); //Metoda rysowania 
}


