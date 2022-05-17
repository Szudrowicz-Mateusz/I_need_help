#include "Bazowa.h"

#include "Ball.h"
#include "Punkty.h"
#include "Przeciwnik.h"
#include "Ofiara.h"

#include <iostream>
#include <vector>

//Klasa szablonowa pobierająca zmienne różnych klas, która dzięki funkcją sprawdzania: right, left, top i bottom
//Sprawdza czy boiekty się nachodzą. Będzię wykorzystywana do collisionTest
template <class C1,class C2> bool isIntersecting(C1& A, C2& B)
{
    return A.right()>=B.left() && A.left()<=B.right()
     && A.bottom()>=B.top()&&A.top()<=B.bottom();
}

//Funkcje opierające się na klasie szablonowej. Sprawdzają one przecięcie i na tej podstawie pokazują się różne wyniki

bool collisionTestPoints(Ball& ball, Punkty& punkt)
{
    if(!isIntersecting(ball,punkt)) return false;

//tutaj dodać metode niszczącą obiekty typu Punkty

    punkt.destroy();
    ball.kill(1);
    
    return true;
}

bool collisionTestHunted(Ball& ball, Ofiara& ofiara)
{
    if(!isIntersecting(ball,ofiara)) return false;

//tutaj dodać metode niszczącą obiekty typu Ofiara

        ofiara.destroy();
        ball.kill(2);
        std::cout<<ball.score<<std::endl;
        
    return true;
    
}

bool collisionTestOponent(Ball& ball, Przeciwnik& przeciwnik)
{
    if(!isIntersecting(ball,przeciwnik)) return false;

//tutaj dodać metodę wyświetlającą game over
   
    return true;
    
}



int main()
{
    srand(time(NULL));

    int _x,_y;
    
    Ball ball(512,384,10.f,3.f);
    Przeciwnik przeciwnik(300,200,30.f,3.f);
    //Punkty punkt(300,200,30.f);
    //Ofiara ofiara(0,0,30.f,3.f);

    //,,Tablica" obiektów danego typu
    std::vector<Punkty> punkty;
    std::vector<Ofiara> ofiara;

    //Losujemy miejsce obiektów za pomocą rand() i umieszamy obiekt na ekranie dzięki emplace_back(konstruktor)
// Punkty
    for(int i=0; i<15;i++)
    {

        _x=rand()%1023+2;
       _y=rand()%767+2;
        punkty.emplace_back(_x,_y,3.f);
    }
// Ofiary
        for(int i=0; i<5;i++)
    {

        _x=rand()%1023+2;
       _y=rand()%767+2;
        ofiara.emplace_back(_x,_y,10.f,3.f);
    }

    
    //Tworzymy okno o wybranym rozmiarze i określonym limicie klatek
    RenderWindow window{VideoMode(1024,768),"Projekt Agar-io"};
    window.setFramerateLimit(60);

    // zmienna do wykonywania obiektów na oknie
    Event event;

    
    while(true) //Działanie okna
    {
        window.clear(Color::Black);

            window.pollEvent(event); // Pozwala nie frezzować kompa 

            if(event.type==Event::Closed) //Zamykanie za pomocą X okna
            {
                window.close();
                break;
            }


            ball.update();
            przeciwnik.update();
            //ofiara.update();

            window.draw(ball);
            window.draw(przeciwnik);
            //window.draw(punkt);
           // window.draw(ofiara);

// Rysujemy obiekty funkcja sf::draw() w pętli przechodzącej przez wszystkie obiekty naszego vectora
            for(auto& punkciki : punkty)
            {
                window.draw(punkciki);
            }

                for(auto& ofiary : ofiara)
            {
                window.draw(ofiary);
                ofiary.update();
            }

            //collisionTestPoints(ball,punkty);
            //collisionTestHunted(ball,ofiara);
            collisionTestOponent(ball,przeciwnik);
//Sprawdzamy czy jakikolwiek element w naszym vectorze został skolizowany
//Jeżeli tak usuwamy dany element z vectora 
            for(auto& punkciki : punkty) if(collisionTestPoints(ball,punkciki)) break;

            auto iteratorPoints=remove_if(begin(punkty), end(punkty), [](Punkty& punkty){return punkty.isDestroyed();});
            punkty.erase(iteratorPoints,end(punkty));


            for(auto& ofiary : ofiara) if(collisionTestHunted(ball,ofiary)) break;

            auto iteratorHunted=remove_if(begin(ofiara), end(ofiara), [](Ofiara& ofiara){return ofiara.isDestroyed();});
            ofiara.erase(iteratorHunted,end(ofiara));
            
            

        window.display(); //wywoływanie obiektów 
    }

    return 0; 
}