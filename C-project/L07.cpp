#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

string name;
int phy, ics, cal;
double average;

class student
{
public:
    student(string name);
    student(string name, int cal, int phy, int ics);
    bool setName(string name);
    bool setCAL(const int cal);
    bool setPHY(const int phy);
    bool setICS(const int ics);
    int getName();
    int getCAL();
    int getPHY();
    int getICS();
    int getaverage();

private:
    string stName;
    int cal;
    int phy;
    int ics;
};

student::student(string stName)
{
    setName(name);
    setCAL(rand()%101);
    setPHY(rand()%101);
    setICS(rand()%101);
}
student::student(string stName, int cal, int phy, int ics)
{
    setName(name);
    setCAL(cal);
    setPHY(phy);
    setICS(ics);
}
bool student::setName(string stName)
{
    this->stName = name;
}
bool student::setCAL(const int cal)
{
    this->cal = cal;
}
bool student::setPHY(const int phy)
{
    this->phy = phy;
}
bool student::setICS(const int ics)
{
    this->ics = ics;
}
int student::getName()
{
    cout << stName << endl;
}
int student::getCAL()
{
    cout << this->cal << endl;
}
int student::getPHY()
{
    cout << this->phy << endl;
}
int student::getICS()
{
    cout << this->ics << endl;
}
int student::getaverage()
{
    average = (double(this->cal) + double(this->phy) + double(this->ics)) / 3;
    cout << average << endl;
}

int main()
{
    int trigger = 0, s;
    while(cin>>trigger)
    {
        if(trigger==0)
            break;
        if(trigger==1)
        {
            cin >> s;
            srand(s);
            cin >> name;
            student oj(name);
            oj.setName(name);
            oj.getName();
            oj.getCAL();
            oj.getPHY();
            oj.getICS();
            oj.getaverage();
        }
        if(trigger==2)
        {
            cin >> name;
            cin >> cal >> phy >> ics;
            student oj(name, cal, phy, ics);
            oj.getName();
            oj.getCAL();
            oj.getPHY();
            oj.getICS();
            oj.getaverage();
        }
    }
    return 0;
}
