#include "Punkty.h"


//Konstruktor
Punkty::Punkty(int t_X, int t_Y, float _ballRadius)
{
    ballRadius=_ballRadius;
    shape.setPosition(t_X,t_Y);
    shape.setRadius(this->ballRadius); //Ustawiamy radius
    shape.setFillColor(Color::Yellow); //Ustawiamy kolor
   

    shape.setOrigin(this->ballRadius,this->ballRadius);//Ustawiamy pozycje na podstawie wczesniejszej funkjci
}

//Metoda zwraca fakt że obiekt jest zniszczony
bool Punkty::isDestroyed()
{
    return this->destroyed;
}

//Metoda niszcząca obiekt
void Punkty::destroy()
{
    this->destroyed=true;
}

//Metoda rysuje obiekt na podawie referencji
void Punkty::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->shape,state); //Metoda rysowania 
}

