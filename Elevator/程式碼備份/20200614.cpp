//***�̫�@����s:�ץ�20%�Ӽh���ʪ����D�ADisplacement���^people���Aelevator constructor�u��***//

#include <curses.h>
#include <time.h>
#include <iostream>
#include <windows.h>

using namespace std;

const int randomFloor[11]= {2,3,4,5,6,7,8,9,10,11,12};
const int StayOrLeave[5]= {0,0,0,0,1};

//*****���ɶ�(�ȩw):1��*****//

//***�q��class***//
class  elevator
{
private:
    int ID;
    int NumOfPeople;
    bool UpOrDown;//0=down 1=up
    int NowFloor;
    int NextFloor;
    int PeopleInElevator[10];
    int StayTime;
    int InOutNum;//The number of people who get into or get out the elevator
    int Milage;
public:
    elevator()
    {
        NumOfPeople=0;
        NowFloor=1;
        for(int i=0; i<10; i++)
        {
            PeopleInElevator[i]=0;
        }
        StayTime=2;
        InOutNum=0;
        Milage=0;
    }
    void setUpOrDown(bool updown)
    {
        UpOrDown=updown;
    }
    void setNumOfPeople(int peoplenum)
    {
        NumOfPeople=peoplenum;
    }
    void setNowFloor(int floor)
    {
        NowFloor=floor;
    }
    void setNextFloor(int floor)
    {
        NextFloor=floor;
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
    void setStayTime()
    {
        int time=InOutNum*0.7;
        if(time>2)
        {
            StayTime=time;
        }
    }
    int getStayTime()
    {
        return StayTime;
    }
    void resetStayTime()
    {
        StayTime=2;
        InOutNum=0;
    }
    void countMilage()
    {
        Milage+=(NumOfPeople+3);
    }
    void setMilage(int mile)
    {
        Milage=mile;
    }
    int getMilage()
    {
        return Milage;
    }
};

//***�Hclass***//
class people
{
    int **arr;
    int numberofpeople;
public:
    people();
    void generate(const int n);         //�ͦ� n �ӤH
    void deleteID(const int ID);          //�R���s�� "ID" ���H
    void Displacement(const int ID);    //���s�� "ID" ���H����
    int getNumberofpeople();        //��o�ثe�`�H��
    void setID();
    void setCurrentfloor(const int &ID,const int floor);
    void setDestination(const int &ID,const int floor);
    void setStaytime(const int &ID,const int t);
    void setState(const int &ID,const bool state);                           //�]�w�U�Ӫ��A:0���}1���d��
    void setPosition(const int &ID,const int p);                     //�]�w�ثe��m:1�Ӽh2���q��3�q�褺
    void setElevator(const int &ID,const int eleID);
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
    int **arr=new int *[150];
    for(int i=0; i<150; i++)
    {
        arr[i]=new int [7]();                 //�x�s"ID"�B"��e�Ӽh"�B"�ؼмӼh"�B"�ݦh�["�B"�ثe��m"�B"�U�Ӫ��A(�~�򰱯d�ηǳ����})"�B"�ϥέ��x�q��"
    }
    numberofpeople=0;
}
void people::generate(const int n)
{
    for(int i=0; i<n; i++)
    {
        int n=rand()%11;
        setID();
        setCurrentfloor(getID(numberofpeople),1);
        setDestination(getID(numberofpeople),randomFloor[n]);
        setStaytime(getID(numberofpeople),rand()%61+20);
        setPosition(getID(numberofpeople),2);
        setState(getID(numberofpeople),1);
        numberofpeople++;
    }
}
void people::deleteID(const int ID)
{
    for(int i=ID; i<149; i++)
    {
        for(int j=1; j<7; j++)
        {
            arr[i][j]=arr[i+1][j];
        }
    }
    for(int i=0; i<7; i++)
    {
        arr[150][i]=0;
    }
    numberofpeople--;
}
int people::getNumberofpeople()
{
    return numberofpeople;
}
void people::setID()
{
    arr[numberofpeople][0]=numberofpeople+1;
}
void people::setCurrentfloor(const int &ID,const int floor)
{
    arr[ID-1][1]=floor;
}
void people::setDestination(const int &ID,const int floor)
{
    arr[ID-1][2]=floor;
}
void people::setStaytime(const int &ID,const int t)
{
    arr[ID-1][3]=t;
}
void people::setPosition(const int &ID,const int p)
{
    arr[ID-1][4]=p;
}
void people::setState(const int &ID,const bool state)
{
    arr[ID-1][5]=state;
}
void people::setElevator(const int &ID,const int eleID)
{
    arr[ID-1][6]=eleID;
}
int people::getID(const int i)
{
    return arr[i][0];
}
int people::getCurrentfloor(const int ID)
{
    return arr[ID-1][1];
}
int people::getDestination(const int ID)
{
    return arr[ID-1][2];
}
int people::getStaytime(const int ID)
{
    return arr[ID-1][3];
}
int people::getPosition(const int ID)
{
    return arr[ID-1][4];
}
int people::getState(const int ID)
{
    return arr[ID-1][5];
}
void people::Displacement(const int ID)
{
    setPosition(ID,2);  //�N��m�]��2:���q��
    int n=rand()%5;
    setState(ID,StayOrLeave[n]);    //�M�w�U�Ӫ��A (80%)0:���} (20%)1:���L�Ӽh
    if(getState(ID)==0)
    {
        setDestination(ID,1);
    }
    else if(getState(ID)==1)
    {
        int n=rand()%10;
        int t=rand()%61+20;
        int floor[10];
        for(int i=2; i<13; i++)
        {
            int cnt=0;
            if(i==getCurrentfloor(ID))
                continue;
            else
                floor[cnt]=i;
            cnt++;
            setDestination(ID,floor[n]);
        }
        setStaytime(ID,t);
    }
}

//***�D��+�ù����***//

void Countdown(class people &c);
int availableElevator(class elevator &c);
int IfAvailable(class elevator &c);

int main()
{
    people people();
    elevator elevator1(),elevator2(),elevator3();

    initscr();

}
void Countdown(class people &c)
{
    for(int i=0; i<150; i++)
    {
        if(c.getState(i+1)==1)    //�p�G���d��
        {
            if(c.getStaytime(i+1)==0)
            {
                c.Displacement(i+1);      //����
            }
            else
                c.setStaytime(i+1,c.getStaytime(i+1)-1);        //-1���ɶ�
        }
        else if(c.getState(i+1)==2)       //�p�G�b���q��
        {

            if(c.getDestination(i+1)-c.getCurrentfloor(i+1)>0)
            {

            }
            else if(c.getDestination(i+1)-c.getCurrentfloor(i+1)<0)
            {

            }
        }
        else if(c.getState(i+1)==3)       //�p�G�b�q�褺
        {

        }
    }
}
int IfAvailable(class elevator &c)
{
    if(c.PeopleInElevator()<=10&&)
}
void setPeopleInElevator(class elevator &c,const int floor)
{
    for(int i=0; i<10; i++)
    {
        if(PeopleInElevator[i]==0)
        {
            PeopleInElevator[i]=floor;
            NumOfPeople++;
            InOutNum++;
            break;
        }
    }
}
void releasePeopleInElevator(class elevator &c)
{
    int floor=NowFloor;
    for(int i=0; i<10; i++)
    {
        if(PeopleInElevator[i]==floor)
        {
            PeopleInElevator[i]=0;
            NumOfPeople--;
            InOutNum++;
        }
    }
}
