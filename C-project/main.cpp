#include <iostream>
#include <curses.h>
#include <ctime>
#include <windows.h>

int d=0;  //¤W¤U¥ª¥k
int y=12;
int x=40;
void move()
{
    if((x==0||x==79)&&(y==0||y==23))
    {
        int n=rand()%2+1;
        if(x==0&&y==0)
        {
            if(n==1)
            {
                x+=1;
                d=4;
            }
            else
            {
                y+=1;
                d=1;
            }
        }
        else if(x==0&&y==23)
        {
            if(n==1)
            {
                x+=1;
                d=4;
            }
            else
            {
                y-=1;
                d=2;
            }
        }
        else if(x==79&&y==0)
        {
            if(n==1)
            {
                x-=1;
                d=3;
            }
            else
            {
                y+=1;
                d=1;
            }
        }
        else
        {
            if(n==1)
            {
                x-=1;
                d=3;
            }
            else
            {
                y-=1;
                d=2;
            }
        }
    }
    else if(x==0||x==79||y==0||y==23)
    {
        int n=rand()%3+1;
        if(x==0)
        {
            if(n==1)
            {
                y+=1;
                d=1;
            }
            else if(n==2)
            {
                y-=1;
                d=2;
            }
            else
            {
                x+=1;
                d=4;
            }
        }
        else if(x==79)
        {
            if(n==1)
            {
                y+=1;
                d=1;
            }
            else if(n==2)
            {
                y-=1;
                d=2;
            }
            else
            {
                x-=1;
                d=3;
            }
        }
        else if(y==0)
        {
            if(n==1)
            {
                x-=1;
                d=3;
            }
            else if(n==2)
            {
                x+=1;
                d=4;
            }
            else
            {
                y+=1;
                d=1;
            }
        }
        else
        {
            if(n==1)
            {
                x-=1;
                d=3;
            }
            else if(n==2)
            {
                x+=1;
                d=4;
            }
            else
            {
                y-=1;
                d=2;
            }
        }
    }
    else
    {
        int k=rand()%100;
        if(d==1)
        {
            if(k/85==1)
            {
                int n=rand()%3+1;
                if(n==1)
                {
                    x-=1;
                    d=3;
                }
                else if(n==2)
                {
                    x+=1;
                    d=4;
                }
                else
                {
                    y-=1;
                    d=2;
                }
            }
            else
            {
                y+=1;
                d=1;
            }
        }
        else if(d==2)
        {
            if(k/85==1)
            {
                int n=rand()%3+1;
                if(n==1)
                {
                    x-=1;
                    d=3;
                }
                else if(n==2)
                {
                    x+=1;
                    d=4;
                }
                else
                {
                    y+=1;
                    d=1;
                }
            }
            else
            {
                y-=1;
                d=2;
            }
        }
        else if(d==3)
        {
            if(k/85==1)
            {
                int n=rand()%3+1;
                if(n==1)
                {
                    y-=1;
                    d=2;
                }
                else if(n==2)
                {
                    y+=1;
                    d=1;
                }
                else
                {
                    x+=1;
                    d=4;
                }
            }
            else
            {
                x-=1;
                d=3;
            }
        }
        else
        {
            if(k/85==1)
            {
                int n=rand()%3+1;
                if(n==1)
                {
                    y-=1;
                    d=2;
                }
                else if(n==2)
                {
                    y+=1;
                    d=1;
                }
                else
                {
                    x-=1;
                    d=3;
                }
            }
            else
            {
                x+=1;
                d=4;
            }
        }
    }
}

using namespace std;
int main()
{
    int s;
    cin >> s;
    srand(s);
    d=rand()%4+1;
    initscr();
    cbreak();
    nonl();
    noecho();
    intrflush(stdscr,FALSE);
    keypad(stdscr,TRUE);
    refresh();
    //24*80
    mvaddch(y,x,'@');
    refresh();
    while(1)
    {
        Sleep(200);
        clear();
        move();
        mvaddch(y,x,'@');
        refresh();
    }
    endwin();
    return 0;
}
