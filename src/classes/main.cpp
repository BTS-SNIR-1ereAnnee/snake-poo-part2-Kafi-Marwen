	/*
	 Projet: snake
	 Auteur: Marwen Kafi
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

	int kbhit(void)    /* Cette fonction retourne si une touche est appuyé par l'utilisateur https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c */
	{
	    int ch, r;


	    nodelay(stdscr, TRUE);



	    ch = getch();  //Getch est une fonction équivalente a la fonction non curses getchar, elle permet la saisie de caractère.
	    if( ch == ERR)
	            r = FALSE;
	    else
	    {
	            r = TRUE;
	            ungetch(ch);
	    }


	    echo();   // Pour supprimer l'écho automatique des caractères tapés.
	    nodelay(stdscr, FALSE);
	    return(r);
	}

	int main()
	{
	    int direction=TOUCHE_KEY_DOWN;

	    // pointeurs sur l'unique instance de la classe UniqueObject
	    Board *fenetre;
	    // initialisation des pointeurs
	    fenetre = Board::getInstance ();

	    snake serpent(10,4);



       //Permet de gérer la direction
		keypad (stdscr,true);
		noecho();
		while (true)
		{
           
			if(kbhit()) {
				switch (getch()){
					case 259:
						direction = TOUCHE_KEY_UP;
						serpent.move(TOUCHE_KEY_UP);
						break;
					case 260:
						direction = TOUCHE_KEY_LEFT;
						serpent.move(TOUCHE_KEY_LEFT);
						break;
					case 258:
					    direction = TOUCHE_KEY_DOWN;
						serpent.move(TOUCHE_KEY_DOWN);
						break;
					case 261:
					    direction = TOUCHE_KEY_RIGHT;
						serpent.move(TOUCHE_KEY_RIGHT);
						break;
				}



			}else{ //move left
			    serpent.move (direction);

			}
			serpent.affichSerpent(); //Utilise la méthode afficheserpent avec la classe serpent.
	        usleep (150000);   //vitesse du serpent

		}
	    //getchar();
	    fenetre->kill();
	    return 0;
	};
