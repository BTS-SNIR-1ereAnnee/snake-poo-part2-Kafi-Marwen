/*
 Projet: snake
 Marwen Kafi
*/
#include <iostream>
#include "Point.h"
#include "Board.h"
#include "snake.h"
#include <unistd.h>

using namespace std;

//https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c
// sert a définir les touche de mouvement
#define  TOUCHE_KEY_UP 1 
#define  TOUCHE_KEY_DOWN 2
#define  TOUCHE_KEY_LEFT 3
#define  TOUCHE_KEY_RIGHT 4

/** Cette fonction retourne si une touche est appuyé par l'utilisateur
*   https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c
*/

//Vérifie si une touche est appuyé
int kbhit(void);

int main()
{
    int directionEnCours=TOUCHE_KEY_DOWN;

    // pointeurs sur l'unique instance de la classe fenetre
    Board *fenetre;
    // initialisation des pointeurs
    fenetre = Board::getInstance ();

    //On crée l'objet de la classe serpent
    snake serpent(10,10);

    //Rend possible mouvements du snake
    keypad (stdscr,true);
    noecho();
   
   while (!(serpent.checkColisionWithBoard())) 
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
        serpent.affichSerpent();
        usleep (150000);

    }
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

