#include <iostream>
#include <iomanip>
using   namespace std;

class powerDate
{
private:
    int year;
    int month;
    int day;
public:
    powerDate(const int y,const int m,const int d);
    bool isLeap();
    int getWeek();
    bool set(const int y,const int m,const int d);
    friend ostream &operator<<(ostream &s,powerDate &x);
    friend istream &operator>>(istream &s,powerDate &x);
    powerDate operator[](const int n);
};
powerDate::powerDate(const int y,const int m,const int d)
{
    set(y,m,d);
}
bool powerDate::set(const int y,const int m,const int d)
{
    this->year=y;
    if(m>0&&m<13)
        this->month=m;
    else
        set(1900,1,1);
    if(this->month==1||this->month==3||this->month==5||this->month==7||this->month==8||this->month==10||this->month==12)
    {
        if(d>0&&d<32)
            this->day=d;
        else
            set(1900,1,1);
    }
    else if(this->month==2)
    {
        if(isLeap())
        {
            if(d>0&&d<30)
                this->day=d;
            else
                set(1900,1,1);
        }
        else
        {
            if(d>0&&d<29)
                this->day=d;
            else
                set(1900,1,1);
        }
    }
    else
    {
        if(d>0&&d<31)
            this->day=d;
        else
            set(1900,1,1);
    }
    return 0;
}
bool powerDate::isLeap()
{
    if(this->year%4==0&&this->year%100!=0)
        return 1;
    else if(this->year%400==0)
        return 1;
    else
        return 0;
}
int powerDate::getWeek()
{
    int Zmonth = this->month;
    int Zyear = this->year;
    if (Zmonth==1||Zmonth==2)
    {
        Zmonth = Zmonth + 12;
        Zyear -= 1;
    }
    int y = Zyear % 100, c = Zyear / 100;
    int DotW = ((y + y / 4 + c / 4 - 2 * c + 2 * Zmonth + (3 * (Zmonth + 1) / 5) + day + 1) % 7 + 7) % 7;
    switch(DotW)
    {
    case 0:
        cout<<"Sunday"<<endl;
        break;
    case 1:
        cout<<"Monday"<<endl;
        break;
    case 2:
        cout<<"Tuesday"<<endl;
        break;
    case 3:
        cout<<"Wednesday"<<endl;
        break;
    case 4:
        cout<<"Thursday"<<endl;
        break;
    case 5:
        cout<<"Friday"<<endl;
        break;
    case 6:
        cout<<"Saturday"<<endl;
        break;
    }
    return 0;
}
istream &operator>>(istream &s,powerDate &x)
{
    s >> x.year >> x.month >> x.day;
    x.set(x.year,x.month,x.day);
    return s;
}
ostream &operator<<(ostream &s,powerDate &x)
{
    s << "現在日期: " << x.year << "-" << setw(2) << setfill('0') << x.month << "-"<< setw(2) << setfill('0') << x.day;
    if(x.isLeap())
        s<< "L ";
    else
        s<< "l ";
    x.getWeek();
    return s;
}
powerDate powerDate::operator[](const int n)
{
    this->day+=n;
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
    }
    return powerDate(this->year,this->month,this->day);
}
int main()
{
    int a;

    powerDate d1(1900,1,1);
    while(cin>>a)
    {
        if(a==1)
        {
            cin >> d1;
            cout << d1 ;
        }
        else if(a==2)
        {
            int n;
            cin >> d1;
            cin >> n;
            d1[n];
            cout << d1 ;
        }
        else if(a==0)
            return 0;
    }
}
