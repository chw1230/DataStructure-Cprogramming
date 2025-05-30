#include <ncurses.h>

int main(void)
{
    initscr();
    printw("Normal Text.");

    move(2, 10);
    attron(A_BOLD| A_BLINK);
    printw("Bold Text.");
    attroff(A_BOLD);
    printw("Not Bold Text.");

    refresh();
    getch();
    endwin();

    return 0;
}
