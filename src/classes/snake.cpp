    #include "Point.h"
    #include "snake.h"
    #include "Board.h"
    #include <iostream>


    using namespace std ;

    snake::snake()
    {
        for(int x = 0; x < longeur; x++)
        {
            serpent[x].setPoint(0,x);
        }
    }


    snake::snake(int x,int y)
    {
        for(int d = 0; d < longeur; d++)
        {
            serpent[d].setPoint(x,d+y);
        }
    }


    void snake::affichSerpent()
    {
        /**Parcours du tableau*/
        for(int d = 0; d < longeur; d++)
        {
            serpent[d].drawPoint(); /** utilisation de la méthode drawPoint*/
        }
    }

    void snake::move(int direction)
    {
        for(int d = longeur; d > 0 ; d--)
        {
            serpent[d].erasePoint();
            serpent[d] = serpent[d-1];

        }

        if(direction == 1)
        {
            serpent[0].moveUp();
        }

        else if(direction == 2)
        {
            serpent[0].moveDown();
        }
        else if(direction == 3)
        {
            serpent[0].moveLeft();
        }
        else if(direction == 4)
        {
            serpent[0].moveRight();
        }

    }

