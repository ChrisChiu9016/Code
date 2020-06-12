#include <iostream>
#include <curses.h>
#include <ctime>
#include <windows.h>
using namespace std;
int main()
{
    initscr();
    cbreak();
    nonl();
    noecho();
    intrflush(stdscr,FALSE);
    keypad(stdscr,TRUE);
    refresh();
    move(0,0);
    addch('S');
    refresh();
    Sleep(1000);
    move(23,79);
    addch('E');
    refresh();
    getch();
    endwin();
}
