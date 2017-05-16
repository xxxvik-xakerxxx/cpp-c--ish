#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char items[3][40] = {
    "Open gurnal",
    "Redakt gurnal",
    "Exit&save",
};

int main()
{


    if (!initscr())
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }

    initscr();
    curs_set(0);
    refresh();



    WINDOW *win = newwin(20, 20, 0, 0);


    box(win, 0, 0);


    wrefresh(win);
    getch();

    delwin(win);
    endwin();
}
