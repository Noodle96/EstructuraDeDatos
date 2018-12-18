#ifndef MENU_H
#define MENU_H

#include <ncurses.h>

////////////////////////////////////////////////////////////////////////////////
                            //MENU PRINCIPAL//

#define WIDTH 90
#define HEIGHT 9
int startx = (225 - WIDTH) / 2; // parte al eje x;
int starty = (24 - HEIGHT) / 2; //parte al eje y;


const char *choices[] = {
			"Agregar Personal",
			"Eliminar Personal",
			"Buscar Persona",
			"Salir",
};
int n_choices = sizeof(choices) / sizeof(char *);

const char *choices_agregar[] = {
    "choices_agregar1",
    "choices_agregar2",
    "choices_agregar3",
    "Retroceder",
};
int n_choices_agregar = sizeof(choices_agregar) / sizeof(char *);

void print_menu(WINDOW *menu_win, int highlight){
	int x=10, y=2, i;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win,A_STANDOUT ); // A_BLINK, A_REVERSE, A_BOLD, A_DIM, A_UNDERLINE, A_STANDOUT
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win,A_STANDOUT );
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////


void print_menu_agregar(WINDOW *menu_win2, int highlight){
    int x = 10, y=2, i;
    box(menu_win2, 0, 0);
    for(i = 0; i < n_choices_agregar; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win2,A_STANDOUT ); // A_BLINK, A_REVERSE, A_BOLD, A_DIM, A_UNDERLINE, A_STANDOUT
			mvwprintw(menu_win2, y, x, "%s", choices_agregar[i]);
			wattroff(menu_win2,A_STANDOUT );
		}
		else
			mvwprintw(menu_win2, y, x, "%s", choices_agregar[i]);
		++y;
	}
	wrefresh(menu_win2);
}
WINDOW *create_newwin(int height, int width, int starty, int startx){
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);          /* 0, 0 gives default characters
                                 * for the vertical and horizontal
                                 * lines                        */
	wrefresh(local_win);            /* Show that box                */
	return local_win;
}

void destroy_win(WINDOW *local_win){
/* box(local_win, ' ', ' '); : This won't produce the desired
 * result of erasing the window. It will leave it's four corners
 * and so an ugly remnant of window.
 wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
/* The parameters taken are
 * 1. win: the window on which to operate
 * 2. ls: character to be used for the left side of the window
 * 3. rs: character to be used for the right side of the window
 * 4. ts: character to be used for the top side of the window
 * 5. bs: character to be used for the bottom side of the window
 * 6. tl: character to be used for the top left corner of the window
 * 7. tr: character to be used for the top right corner of the window
 * 8. bl: character to be used for the bottom left corner of the window
 * 9. br: character to be used for the bottom right corner of the window
 */
	wrefresh(local_win);
	delwin(local_win);
}










#endif // MENU_H
