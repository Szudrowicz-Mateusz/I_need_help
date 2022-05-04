#include "Ball.h"


int main()
{
    Ball ball(512,384);

    RenderWindow window{VideoMode(1024,768),"Arcanoid Tutorial"};
    window.setFramerateLimit(60);

        Event event;

    while(true) //Działanie okna
    {
        window.clear(Color::Black);

            window.pollEvent(event); // Pozwala nie frezzować kompa 

            if(event.type==Event::Closed)
            {
                window.close();
                break;
            }


            ball.update();
            window.draw(ball);
            

        window.display(); //wywoływanie obiektów 
    }

    return 0; 
}