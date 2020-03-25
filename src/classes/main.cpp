/*
 Projet: snake
Marwen Kafi
*/
#include <iostream>
#include "Point.h"
#include "Board.h"
#include "snake.h"
#include <unistd.h>

int usleep(useconds_t usec);

using namespace std;

//https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c

#define  TOUCHE_KEY_UP 1 // sert a définir les touche de mouvement
#define  TOUCHE_KEY_DOWN 2
#define  TOUCHE_KEY_LEFT 3
#define  TOUCHE_KEY_RIGHT 4

/** Cette fonction retourne si une touche est appuyé par l'utilisateur
*   https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c
*/
int kbhit(void);

int main()
{
    int directionEnCours=TOUCHE_KEY_LEFT;

    // pointeurs sur l'unique instance de la classe fenetre
    Board *fenetre;
    // initialisation des pointeurs
    fenetre = Board::getInstance ();

    //On crée l'objet de la classe serpent
    snake serpent(10,4);
//Rend possible mouvements du snake
    keypad (stdscr,true);
    noecho();

    bool collision = FALSE;
    while (!collision)
    {
        if(kbhit())
        {
            switch (getch())
            {
            //Déplacement vers le haut.
            case 259:
                directionEnCours = TOUCHE_KEY_UP;
                break;
                //Déplacement vers la gauche.
            case 260:
                directionEnCours = TOUCHE_KEY_LEFT;
                break;
                 //Déplacement vers le bas.
            case 258:
                directionEnCours = TOUCHE_KEY_DOWN;
                break;
                 //Déplacement vers la droite
            case 261:
                directionEnCours = TOUCHE_KEY_RIGHT;

                break;
            }

        }
        //Déplacement du serpent
        serpent.move(directionEnCours);
        collision = serpent.checkColisionWithBoard() || serpent.checkColisionWithSnake();
        serpent.affichSerpent();
        usleep (150000);

    }
    //getchar();
    fenetre->kill();
    return 0;
};

int kbhit(void)    /* Cette fonction retourne si une touche est appuyé par l'utilisateur https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c */
{
    int ch, r;
    nodelay(stdscr, TRUE);
    ch = getch();
    if( ch == ERR)
        r = FALSE;
    else
    {
        r = TRUE;
        ungetch(ch);
    }
    echo();
    nodelay(stdscr, FALSE);
    return(r);
}
