
#include <curses.h>
#include <cmath>
#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

//***�q��class***//
class elevator
{
private:
    int ID;
    int NumOfPeople;
    bool UpOrDown; //0=down 1=up
    int NowFloor;
    int NextFloor;
    int PeopleInElevator[10];
    int StayTime;
    int InOutNum; //The number of people who get into or get out the elevator
    int Milage;
    int state;
public:
    elevator()
    {
        NumOfPeople = 0;
        NowFloor = 1;
        for (int i = 0; i < 10; i++)
        {
            PeopleInElevator[i] = 0;
        }
        StayTime = 2;
        InOutNum = 0;
        Milage = 0;
    }
    void setarrPIE(const int i, const int &floor)
    {
        PeopleInElevator[i] = floor;
    }
    int getarrPIE(const int i)
    {
        return PeopleInElevator[i];
    }
    void setUpOrDown(bool updown)
    {
        UpOrDown = updown;
    }
    void setNumOfPeople(int peoplenum)
    {
        NumOfPeople = peoplenum;
    }
    void setNowFloor(int floor)
    {
        NowFloor = floor;
    }
    void setNextFloor(int floor)
    {
        NextFloor = floor;
    }
    int getID()
    {
        return ID;
    }
    int getNumOfPeople()
    {
        return NumOfPeople;
    }
    int getNowFloor()
    {
        return NowFloor;
    }
    int getNextFloor()
    {
        return NextFloor;
    }
    bool getUpOrDown()
    {
        return UpOrDown;
    }
    void setION(const int n)
    {
        InOutNum = n;
    }
    int getION()
    {
        return InOutNum;
    }
    void setStayTime(const int n)
    {
        if (n<2)
            StayTime=2;
        else
            StayTime = n;
    }
    int getStayTime()
    {
        return StayTime;
    }
    void resetStayTime()
    {
        StayTime = 2;
        InOutNum = 0;
    }
    void countMilage()
    {
        Milage += (NumOfPeople + 3);
    }
    void setMilage(int mile)
    {
        Milage = mile;
    }
    int getMilage()
    {
        return Milage;
    }
    void setID(const int n)
    {
        ID=n;
    }
};

//***�Hclass***//

const int randomFloor[11] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
const int StayOrLeave[5] = {0, 0, 0, 0, 1};

class people
{
    int **arr;
    int numberofpeople;

public:
    people();
    void generate(const int n);      //�ͦ� n �ӤH
    void deleteID(const int ID);     //�R���s�� "ID" ���H
    void Displacement(const int ID); //���s�� "ID" ���H����
    int getNumberofpeople();         //��o�ثe�`�H��
    void setID();
    void setCurrentfloor(const int &ID, const int floor);
    void setDestination(const int &ID, const int floor);
    void setStaytime(const int &ID, const int t);
    void setState(const int &ID, const bool state); //�]�w�U�Ӫ��A:0���}1���d��
    void setPosition(const int &ID, const int p);   //�]�w�ثe��m:1�Ӽh2���q��3�q�褺
    void setElevator(const int &ID, const int eleID);
    int getID(const int i);
    int getCurrentfloor(const int ID);
    int getDestination(const int ID);
    int getStaytime(const int ID);
    int getState(const int ID);
    int getPosition(const int ID);
    int getElevator(const int ID);
};

people::people()
{
    int **arr = new int *[150];
    for (int i = 0; i < 150; i++)
    {
        arr[i] = new int[7](); //�x�s"ID"�B"��e�Ӽh"�B"�ؼмӼh"�B"�ݦh�["�B"�ثe��m"�B"�U�Ӫ��A(�~�򰱯d�ηǳ����})"�B"�ϥέ��x�q��"
    }
    numberofpeople = 0;
}
void people::generate(const int n)
{
    for (int i = 0; i < n; i++)
    {
        int f = rand() % 11;
        setID();
        setCurrentfloor(getID(numberofpeople), 1);
        setDestination(getID(numberofpeople), randomFloor[f]);
        setStaytime(getID(numberofpeople), rand() % 61 + 20);
        setPosition(getID(numberofpeople), 2);
        setState(getID(numberofpeople), 1);
        numberofpeople++;
    }
}
void people::deleteID(const int ID)
{
    for (int i = ID - 1; i < 149; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            arr[i][j] = arr[i + 1][j];
        }
    }
    for (int i = 0; i < 7; i++)
    {
        arr[150][i] = 0;
    }
    numberofpeople--;
}
int people::getNumberofpeople()
{
    return numberofpeople;
}
void people::setID()
{
    arr[numberofpeople][0] = numberofpeople + 1;
}
void people::setCurrentfloor(const int &ID, const int floor)
{
    arr[ID - 1][1] = floor;
}
void people::setDestination(const int &ID, const int floor)
{
    arr[ID - 1][2] = floor;
}
void people::setStaytime(const int &ID, const int t)
{
    arr[ID - 1][3] = t;
}
void people::setPosition(const int &ID, const int p)
{
    arr[ID - 1][4] = p;
}
void people::setState(const int &ID, const bool state)
{
    arr[ID - 1][5] = state;
}
void people::setElevator(const int &ID, const int eleID)
{
    arr[ID - 1][6] = eleID;
}
int people::getID(const int i)
{
    return arr[i][0];
}
int people::getCurrentfloor(const int ID)
{
    return arr[ID - 1][1];
}
int people::getDestination(const int ID)
{
    return arr[ID - 1][2];
}
int people::getStaytime(const int ID)
{
    return arr[ID - 1][3];
}
int people::getPosition(const int ID)
{
    return arr[ID - 1][4];
}
int people::getState(const int ID)
{
    return arr[ID - 1][5];
}
int people::getElevator(const int ID)
{
    return arr[ID - 1][6];
}
void people::Displacement(const int ID)
{
    setPosition(ID, 2); //�N��m�]��2:���q��
    int n = rand() % 5;
    setState(ID, StayOrLeave[n]); //�M�w�U�Ӫ��A (80%)0:���} (20%)1:���L�Ӽh
    if (getState(ID) == 0)
    {
        setDestination(ID, 1);
    }
    else if (getState(ID) == 1)
    {
        int n = rand() % 10;
        int t = rand() % 61 + 20;
        int floor[10];
        for (int i = 2; i < 13; i++)
        {
            int cnt = 0;
            if (i == getCurrentfloor(ID))
                continue;
            else
                floor[cnt] = i;
            cnt++;
        }
        setDestination(ID, floor[n]);
        setStaytime(ID, t);
    }
}

//***�D��+�ù����***//

void Countdown(class people &c);
int IfAvailable(class elevator &c, const int d);
void setPeopleInElevator(class elevator &c, const int floor);
void releasePeopleInElevator(class elevator &c);
void callElevator(class people &c, const int ID, const int floor);
int ElevatorStop[12];
bool freeElevator[3]= {0};
int floortoline(int floor);
void printback();
void printelevator(class elevator &d);
void peopleinfloor(class people &p);
void peoplewaiting(class people &p);


people people;
elevator elevator1, elevator2, elevator3;

int main()
{

    for(int i=0; i<12; i++)
    {
        ElevatorStop[i]=0;
    }
    initscr();
    int p=10;
    mvprintw(12,40,"%d",p);
    while (1)
    {
        Sleep(1000);
        mvaddch(12,40,'1');

        refresh();
    }
    endwin();
    return 0;
}
int IfAvailable(class elevator &c, const int d)
{
    if (c.getNumOfPeople() <= 10 && c.getUpOrDown() == d)
        return 1;
    else
        return 0;
}
void setPeopleInElevator(class elevator &c, const int floor)
{
    for (int i = 0; i < 10; i++)
    {
        if (c.getarrPIE(i) == 0)
        {
            c.setarrPIE(i, floor);
            int n1 = c.getNumOfPeople() + 1;
            int n2 = c.getION() + 1;
            c.setNumOfPeople(n1);
            c.setION(n2);
            break;
        }
    }
}
void releasePeopleInElevator(class elevator &c)
{
    int floor = c.getNowFloor();
    for (int i = 0; i < 10; i++)
    {
        if (c.getarrPIE(i) == floor)
        {
            c.setarrPIE(i, 0);
            int n1 = c.getNumOfPeople() - 1;
            int n2 = c.getION() + 1;
            c.setNumOfPeople(n1);
            c.setION(n2);
        }
    }
}
void callElevator(class people &c, const int ID, const int floor)
{
    if (c.getDestination(ID) - c.getCurrentfloor(ID) > 0)
        ElevatorStop[floor-1]=1;
    else if (c.getDestination(ID) - c.getCurrentfloor(ID) < 0)
        ElevatorStop[floor-1]=1;
}

int floortoline(int floor)
{
   return  25-2*floor;
}
void printback()
{
    mvaddstr(1,1,"CF\n\n BF\n\n AF\n\n 9F\n\n 8F\n\n 7F\n\n 6F\n\n 5F\n\n 4F\n\n 3F\n\n 2F\n\n 1F");
    refresh();
}
void printelevator(class elevator &d)
{
    int y=floortoline(d.getNowFloor());
    int x=60+5*d.getID();
    int n=d.getNumOfPeople();
    int m=d.getMilage();
    mvaddstr(y,x,"|   |");
    if(d.getUpOrDown()==1)
    {
        mvaddstr(y-1,x,"+   +");
    }
    else
    {
        mvaddstr(y-1,x,"-   -");
    }
    mvprintw(y-1,x+2,"%d",n);
    mvprintw(y,x+2,"%d",m);
}
void peopleinfloor(class people &p){
    int i,y;
    int j=0;
    for(y=1;y<=23;y+=2){
        for(i=0;i<=150;i++){
            if(p.getState(i)!=3&&((-0.5)*y+12.5)==p.getCurrentfloor(i)){
                j++;
            }
        }
        mvprintw(y,3,"%d",j);
        j=0;
    }
}
void peoplewaiting(class people &p){
    int n,i,y,x;
    int t=0;
    int f=0;
    for(y=1;y<=23;y+=2){
        for(x=64;x>3;x-=3){
            for(i=t+1;i<=150;i++){
                if(p.getState(i)==2&&((-0.5)*y+12.5)==p.getCurrentfloor(i)){
                    n=p.getDestination(i);
                    t=i;
                    break;
                }
                else if(i==150){
                    f=1;
                }
            }
            if(f==1){
                f=0;
                break;
            }
            mvprintw(y,x,"%d",n);
        }
    }
}
