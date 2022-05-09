#include "Ball.h"

#include <iostream>


Ball::Ball(float t_X, float t_Y, float _ballRadius, float _ballVelocity)
{
    ballRadius=_ballRadius;
    ballVelocity=_ballVelocity;
    shape.setPosition(t_X,t_Y);
    shape.setRadius(this->ballRadius); //Ustawiamy radius
    shape.setFillColor(Color::White); //Ustawiamy kolor
    std::cout<<"BallRadius"<<ballRadius<<std::endl<<"BallVelocity"<<ballVelocity;

        velocity.x=ballVelocity;//Pozwalamy classie pochodnej zdobyć jej wektor
        velocity.y=ballVelocity;//Bez tego piłka nie ruszy się

    shape.setOrigin(this->ballRadius,this->ballRadius);//Ustawiamy pozycje na podstawie wczesniejszej funkjci
}

void Ball::update(){
    shape.move(this->velocity);//Metoda wbudowana w SFML do poruszania obiektów
    Bazowa::update();
    
}

void Ball::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->shape,state); //Metoda rysowania 
}


