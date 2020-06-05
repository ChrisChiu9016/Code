#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int Zmonth, Zyear, DotW = 0;

class myDate
{
    int year;
    int month;
    int day;

public:
    myDate(const int y, const int m, const int d);
    const myDate operator + (const int day); //d+day天
    const myDate operator - (const int day); //d-day天
	int getYear();
	int getMonth();
	int getDay();
	int getWeek(); //0~6 蔡勒公式
	int setDate(const int y, const int m, const int d );
	void output(); //輸出 year-month-day (week)
    bool isLeap();
    void adjust();
};
myDate::myDate(const int y, const int m, const int d)
{
    setDate(y, m, d);
}
const myDate myDate::operator+(const int day)
{
    this->day += day;
    adjust();
    return myDate(this->year,this->month,this->day);
}
const myDate myDate::operator-(const int day)
{
    this->day -= day;
    adjust();
    return myDate(this->year,this->month,this->day);
}
void myDate::adjust()
{
    while(1){
        if(this->month==4||this->month==6||this->month==9||this->month==11)
    {
        if(this->day>30)
        {
            this->day-=30;
            this->month+=1;
        }
        else if(this->day<1)
        {
            this->day+=31;
            this->month-=1;
        }
        else
            break;
    }
    else if(this->month==5||this->month==10)
    {
        if(this->day>31)
        {
            this->day-=31;
            this->month+=1;
        }
        else if(this->day<1)
        {
            this->day+=30;
            this->month-=1;
        }
        else
            break;
    }
    else if(this->month==3)
    {
        if(this->day>31)
        {
            this->day-=31;
            this->month+=1;
        }
        else if(this->day<1)
        {
            this->day+=28+isLeap();
            this->month-=1;
        }
        else
            break;
    }
    else if(this->month==7)
    {
        if(this->day>31)
        {
            this->day-=31;
            this->month+=1;
        }
        else if(this->day<1)
        {
            this->day+=30;
            this->month-=1;
        }
        else
            break;
    }
    else if(this->month==12)
    {
        if(this->day>31)
        {
            this->day-=31;
            this->month=1;
            this->year+=1;
        }
        else if(this->day<1)
        {
            this->day+=30;
            this->month-=1;
        }
        else
            break;
    }
    else if(this->month==8)
    {
        if(this->day>31)
        {
            this->day-=31;
            this->month+=1;
        }
        else if(this->day<1)
        {
            this->day+=31;
            this->month-=1;
        }
        else
            break;
    }
    else if(this->month==1)
    {
        if(this->day>31)
        {
            this->day-=31;
            this->month+=1;
        }
        else if(this->day<1)
        {
            this->day+=31;
            this->month=12;
            this->year-=1;
        }
        else
            break;
    }
    else if(this->month==2)
    {
        if(this->day>28+isLeap())
        {
            this->day-=28+isLeap();
            this->month+=1;
        }
        else if(this->day<1)
        {
            this->day+=31;
            this->month-=1;
        }
        else
            break;
    }
    }
}
bool myDate::isLeap()
{
    if(this->year%4==0&&this->year%100!=0)
        return 1;
    else if(this->year%400==0)
        return 1;
    else
        return 0;
}
int myDate::setDate(const int year,const int month,const int day)
{
    this->year=year;
    this->month=month;
    this->day=day;
    return 0;
}
int myDate::getWeek() //蔡勒公式
{
    Zmonth = month;
    Zyear = year;
    if (Zmonth==1||Zmonth==2){
        Zmonth = Zmonth + 12;
        Zyear -= 1;
    }
    int y = Zyear % 100, c = Zyear / 100;
    DotW = ((y + y / 4 + c / 4 - 2 * c + 2 * Zmonth + (3 * (Zmonth + 1) / 5) + day + 1) % 7 + 7) % 7;
    return 0;
}
int myDate::getDay()
{
    return day;
}
int myDate::getMonth()
{
    return month;
}
int myDate::getYear()
{
    return year;
}
void myDate::output()
{
    cout << getYear() << "-" << getMonth() << "-" << getDay() << " (" << DotW << ")" << endl;
}

int main()
{
    int x;
    int y = 0, m = 0, d = 0;
    cin >> y >> m >> d;
    myDate oj(y,m,d);
    while(cin>>x)
    {
        if(x==0)
            break;
        else if(x>0)
            oj + x;
        else
            oj - abs(x);

        oj.getWeek();
        oj.output();
    }
    return 0;
}
