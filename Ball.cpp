#include "Ball.h"




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

void Ball::update(){
    shape.move(this->velocity);//Metoda wbudowana w SFML do poruszania obiektów
    Bazowa::update();
    
}

void Ball::kill(int i){
    if(i==1) score=score+50;
    else if(i==2) score=score+250;
}

void Ball::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->shape,state); //Metoda rysowania 
}


