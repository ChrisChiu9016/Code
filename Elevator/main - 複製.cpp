
#include <curses.h>
#include <cmath>
#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

//***電梯class***//
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

//***人class***//

const int randomFloor[11] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
const int StayOrLeave[5] = {0, 0, 0, 0, 1};

class people
{
    int **arr;
    int numberofpeople;

public:
    people();
    void generate(const int n);      //生成 n 個人
    void deleteID(const int ID);     //刪除編號 "ID" 的人
    void Displacement(const int ID); //讓編號 "ID" 的人移動
    int getNumberofpeople();         //獲得目前總人數
    void setID();
    void setCurrentfloor(const int &ID, const int floor);
    void setDestination(const int &ID, const int floor);
    void setStaytime(const int &ID, const int t);
    void setState(const int &ID, const bool state); //設定下個狀態:0離開1停留˙
    void setPosition(const int &ID, const int p);   //設定目前位置:1樓層2等電梯3電梯內
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
        arr[i] = new int[7](); //儲存"ID"、"當前樓層"、"目標樓層"、"待多久"、"目前位置"、"下個狀態(繼續停留或準備離開)"、"使用哪台電梯"
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
    setPosition(ID, 2); //將位置設為2:等電梯
    int n = rand() % 5;
    setState(ID, StayOrLeave[n]); //決定下個狀態 (80%)0:離開 (20%)1:到其他樓層
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

//***主控+螢幕顯示***//

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



int main()
{
    people people;
    elevator elevator1, elevator2, elevator3;

    for(int i=0; i<12; i++)
    {
        ElevatorStop[i]=0;
    }
    elevator1.setID(1);
    elevator2.setID(2);
    elevator3.setID(3);

    initscr();
    cbreak();
    noecho();
    printback();
    printelevator(elevator1);
    printelevator(elevator2);
    printelevator(elevator3);
    refresh();
    //peopleinfloor(people);
    //peoplewaiting(people);
    refresh();
    while (1)
    {
        Sleep(1000);
        int n = rand() % 3;
        elevator1.setNowFloor(elevator1.getNowFloor()+1);
        //people.generate(n);有問題
        ///主控部分
        for(int i=1; i<12; i++)
        {

            if(ElevatorStop[i]!=0)
            {
                int n1=100,n2=100,n3=100;
                if((i+1-elevator1.getNowFloor()>0&&elevator1.getUpOrDown()==1)||(i+1-elevator1.getNowFloor()<0&&elevator1.getUpOrDown()==0))
                    n1=abs(i+1-elevator1.getNowFloor());
                if((i+1-elevator2.getNowFloor()>0&&elevator2.getUpOrDown()==1)||(i+1-elevator2.getNowFloor()<0&&elevator2.getUpOrDown()==0))
                    n2=abs(i+1-elevator2.getNowFloor());
                if((i+1-elevator3.getNowFloor()>0&&elevator3.getUpOrDown()==1)||(i+1-elevator3.getNowFloor()<0&&elevator3.getUpOrDown()==0))
                    n3=abs(i+1-elevator3.getNowFloor());
                if(n1<=n2&&n1<=n3&&elevator1.getNumOfPeople()<10)
                {
                    for(int j=0; j<10; j++)
                    {
                        if(elevator1.getarrPIE(j)==0)
                        {
                            elevator1.setarrPIE(j,i+1);
                            ElevatorStop[i]=0;
                            break;
                        }
                    }
                }
                else if(n2<=n3&&elevator2.getNumOfPeople()<10)
                {
                    for(int j=0; j<10; j++)
                    {
                        if(elevator2.getarrPIE(j)==0)
                        {
                            elevator2.setarrPIE(j,i+1);
                            ElevatorStop[i]=0;
                            break;
                        }
                    }
                }
                else if(elevator3.getNumOfPeople()<10)
                {
                    for(int j=0; j<10; j++)
                    {
                        if(elevator3.getarrPIE(j)==0)
                        {
                            elevator3.setarrPIE(j,i+1);
                            ElevatorStop[i]=0;
                            break;
                        }
                    }
                }
            }
        }
        //電梯移動
        if (elevator1.getStayTime() != 0)
            elevator1.setStayTime(elevator1.getStayTime() - 1);
        else
        {
            for (int i = 0; i < 12; i++)
            {
                if (elevator1.getarrPIE(i) > elevator1.getNowFloor() && elevator1.getUpOrDown() == 1)
                {
                    elevator1.setNowFloor(elevator1.getNowFloor() + 1);
                    elevator1.countMilage();
                    break;
                }
                else if (elevator1.getarrPIE(i) < elevator1.getNowFloor() && elevator1.getUpOrDown() == 0)
                {
                    elevator1.setNowFloor(elevator1.getNowFloor() - 1);
                    elevator1.countMilage();
                    break;
                }
            }
        }
        if (elevator2.getStayTime() != 0)
            elevator2.setStayTime(elevator2.getStayTime() - 1);
        else
        {
            for (int i = 0; i < 12; i++)
            {
                if (elevator2.getarrPIE(i)>elevator2.getNowFloor()&&elevator2.getUpOrDown()==1)
                {
                    elevator2.setNowFloor(elevator2.getNowFloor() + 1);
                    elevator2.countMilage();
                    break;
                }
                else if (elevator2.getarrPIE(i)<elevator2.getNowFloor()&&elevator2.getUpOrDown()==0)
                {
                    elevator2.setNowFloor(elevator2.getNowFloor() - 1);
                    elevator2.countMilage();
                    break;
                }
            }
        }
        if (elevator3.getStayTime() != 0)
            elevator3.setStayTime(elevator3.getStayTime() - 1);
        else
        {
            for (int i = 0; i < 12; i++)
            {
                if (elevator3.getarrPIE(i)>elevator3.getNowFloor()&&elevator3.getUpOrDown()==1)
                {
                    elevator3.setNowFloor(elevator3.getNowFloor() + 1);
                    elevator3.countMilage();
                    break;
                }
                else if (elevator3.getarrPIE(i)<elevator3.getNowFloor()&&elevator3.getUpOrDown()==0)
                {
                    elevator3.setNowFloor(elevator3.getNowFloor() - 1);
                    elevator3.countMilage();
                    break;
                }
            }
        }
        //檢查停靠
        int cnt=0;
        for(int i=0; i<10; i++)
        {
            if(elevator1.getarrPIE(i)==elevator1.getNowFloor())
                cnt =cnt+1;
        }
        elevator1.setION(cnt);
        elevator1.setStayTime(2);

        /*for (int i = 0; i < 150; i++) //開始檢查人   迴圈斷掉i=7;
        {
            if (people.getState(i + 1) == 1) //如果停留中
            {
                if (people.getStaytime(i + 1) == 0)
                {
                    people.Displacement(i + 1);    //移動
                    callElevator(people, i + 1, people.getCurrentfloor(i + 1)); //按電梯
                }
                else
                    people.setStaytime(i + 1, people.getStaytime(i + 1) - 1); //-1單位時間
            }
            else if (people.getState(i + 1) == 2) //如果在等電梯
            {
                int d;
                if (people.getDestination(i + 1) - people.getCurrentfloor(i + 1) > 0)
                    d = 1;
                else if (people.getDestination(i + 1) - people.getCurrentfloor(i + 1) < 0)
                    d = 0;
                if (IfAvailable(elevator1, d))
                {
                    setPeopleInElevator(elevator1, people.getDestination(i + 1));
                    people.setPosition(i + 1, 3);
                    people.setElevator(i + 1, 1);
                }
                else if (IfAvailable(elevator2, d))
                {
                    setPeopleInElevator(elevator2, people.getDestination(i + 1));
                    people.setPosition(i + 1, 3);
                    people.setElevator(i + 1, 2);
                }
                else if (IfAvailable(elevator3, d))
                {
                    setPeopleInElevator(elevator3, people.getDestination(i + 1));
                    people.setPosition(i + 1, 3);
                    people.setElevator(i + 1, 3);
                }
            }
            else if (people.getState(i + 1) == 3) //如果在電梯內
            {
                if (people.getElevator(i + 1) == 1)
                {
                    if (people.getDestination(i + 1) == elevator1.getNowFloor())
                    {
                        releasePeopleInElevator(elevator1);
                        people.setCurrentfloor(i + 1, elevator1.getNowFloor());
                        people.setDestination(i + 1, 0); //0:目前沒有要前往的樓層
                        people.setElevator(i + 1, 0);    //重設
                        people.setPosition(i + 1, 1);
                    }
                    if (elevator1.getNumOfPeople() < 10 && elevator1.getUpOrDown() == 1)
                        for (int j = 0; j < 10; j++)
                        {
                            elevator1.setarrPIE(j, i + 1);
                        }
                    else if (elevator2.getNumOfPeople() < 10 && elevator2.getUpOrDown() == 1)
                        for (int j = 0; j < 10; j++)
                        {
                            elevator2.setarrPIE(j, i + 1);
                        }
                    else if (elevator3.getNumOfPeople() < 10 && elevator3.getUpOrDown() == 1)
                        for (int j = 0; j < 10; j++)
                        {
                            elevator3.setarrPIE(j, i + 1);
                        }
                }
                if (people.getElevator(i + 1) == 2)
                {
                    if (people.getDestination(i + 1) == elevator2.getNowFloor())
                    {
                        releasePeopleInElevator(elevator2);
                        people.setCurrentfloor(i + 1, elevator2.getNowFloor());
                        people.setDestination(i + 1, 0); //0:目前沒有要前往的樓層
                        people.setElevator(i + 1, 0);    //重設
                        people.setPosition(i + 1, 1);
                    }
                }
                if (people.getElevator(i + 1) == 3)
                {
                    if (people.getDestination(i + 1) == elevator3.getNowFloor())
                    {
                        releasePeopleInElevator(elevator3);
                        people.setCurrentfloor(i + 1, elevator3.getNowFloor());
                        people.setDestination(i + 1, 0); //0:目前沒有要前往的樓層
                        people.setElevator(i + 1, 0);    //重設
                        people.setPosition(i + 1, 1);
                    }
                }
            }
            if (people.getState(i + 1) == 0 && people.getCurrentfloor(i + 1) == 1)
                people.deleteID(i + 1);
        }*/


        ///顯示部分
        clear();
        printback();
        //peopleinfloor(people);
        //peoplewaiting(people);
        printelevator(elevator1);
        printelevator(elevator2);
        printelevator(elevator3);
        refresh();
    }
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
        for(i=1;i<=150;i++){
            if(p.getState(i)==1&&y==floortoline(p.getCurrentfloor(i))){
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
