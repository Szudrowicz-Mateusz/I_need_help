#include "Ball.h"


Ball::Ball(float t_X,float t_Y)
{
    shape.setPosition(t_X,t_Y);
    shape.setRadius(this->ballRadius); //Ustawiamy radius
    shape.setFillColor(Color::White); 

    shape.setOrigin(this->ballRadius,this->ballRadius);//Ustawiamy pozycje na podstawie wczesniejszej funkjci
}

void Ball::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->shape,state); //Metoda rysowania 
}

void Ball::update()
{
    shape.move(this->velocity);

    if(this->left()<0)
    {
        velocity.x=ballVelocity;
    }

    else if(this->right()>1024)
    {
        velocity.x=-ballVelocity;
    }

    else if(this->top()<0)
    {
        velocity.y=ballVelocity;
    }

    if(this->bottom()>768)
    {
        velocity.y=-ballVelocity;
    }
}

        float Ball::left()
        {
            return this->shape.getPosition().x-shape.getRadius();
        }
        float Ball::right()
        {
            return this->shape.getPosition().x+shape.getRadius();
        }
                float Ball::top()
        {
            return this->shape.getPosition().y-shape.getRadius();
        }
                float Ball::bottom()
        {
            return this->shape.getPosition().y+shape.getRadius();
        }