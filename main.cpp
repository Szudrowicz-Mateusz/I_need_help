#include "Ball.h"
#include "Bazowa.h"


int main()
{
    //Bazowa* tab[2];
    //tab[0]= new Ball(512,384);
    //tab[1]= new Ball(0,0);
    Ball ball(512,384,10.f,10.f);

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

            //window.draw(*tab[0]);
            //window.draw(*tab[1]);
            

        window.display(); //wywoływanie obiektów 
    }

    return 0; 
}