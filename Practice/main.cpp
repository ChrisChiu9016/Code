#include <curses.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int hour=0;
int minute=0;
int second=0;
void check();

int main()
{

    cin>>hour>>minute>>second;
    initscr();
    while(1)
    {
        clear();
        check();
        string c=to_string(second);
        const char *pchar=c.c_str();
        mvaddstr(hour,minute,pchar);
        second++;
        refresh();
        Sleep(1000);
    }
    endwin();
    return 0;
}
void check()
{
    if(second>=60)
    {
        second-=60;
        minute+=1;
    }
    if(minute>=60)
    {
        minute-=60;
        hour+=1;
    }
}
