#include "Punkty.h"



Punkty::Punkty(int t_X, int t_Y, float _ballRadius)
{
    ballRadius=_ballRadius;
    shape.setPosition(t_X,t_Y);
    shape.setRadius(this->ballRadius); //Ustawiamy radius
    shape.setFillColor(Color::Yellow); //Ustawiamy kolor
   

    shape.setOrigin(this->ballRadius,this->ballRadius);//Ustawiamy pozycje na podstawie wczesniejszej funkjci
}

bool Punkty::isDestroyed()
{
    return this->destroyed;
}

void Punkty::destroy()
{
    this->destroyed=true;
}

void Punkty::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->shape,state); //Metoda rysowania 
}

