#include "Bazowa.h"

        Bazowa::~Bazowa(){
            //nic
        }

void Bazowa::update()
{

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

        float Bazowa::left()
        {
            return this->shape.getPosition().x-shape.getRadius();
        }
        float Bazowa::right()
        {
            return this->shape.getPosition().x+shape.getRadius();
        }
        float Bazowa::top()
        {
            return this->shape.getPosition().y-shape.getRadius();
        }
        float Bazowa::bottom()
        {
            return this->shape.getPosition().y+shape.getRadius();
        }