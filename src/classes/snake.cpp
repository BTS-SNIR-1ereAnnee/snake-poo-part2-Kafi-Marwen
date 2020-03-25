#include "Point.h"
#include "snake.h"
#include "Board.h"
#include <iostream>


using namespace std ;

//CONSTRUCTEUR PAR DEFAUT.
snake::snake()
{
    for(int x = 0; x < longeur; x++)
    {
        serpent[x].setPoint(0,x);
    }
}

//CONSTRUCTEUR AVEC DES PARAMETRES
snake::snake(int x,int y)
{
    for(int d = 0; d < longeur; d++)
    {
        serpent[d].setPoint(x,d+y);
    }
}

//Sert a affciher le serpent
void snake::affichSerpent()
{
    /**Parcours du tableau*/
    for(int d = 0; d < longeur; d++)
    {
        serpent[d].drawPoint(); /** utilisation de la méthode drawPoint*/
    }
}

//Déplacement du snake
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

bool snake::checkColisionWithBoard()
{
    Board *b;
    b = Board::getInstance(); // on recup l'instance de board
    if (serpent[0].getX() == 0 || serpent[0].getX() == b->getXSize()-1) return TRUE;
    if (serpent[0].getY() == 0 || serpent[0].getY() == b->getYSize()-1) return TRUE;
    return FALSE;
}






