#include <iostream>
#include <iomanip>

using namespace std;

int year,month,day,hour,minute,second;
int hrs24,Zmonth,Zyear,DotW,scds;
bool Leap=0;
bool apm = 0;

class myDateTime
{
private:

    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

public:
    int setTime(const int hour,const int minute,const int second);
    int setDate(const int year,const int month,const int day);
    int whatDate();
    void output();
    void outputROC();
    int seconds();
    bool isLeap();
};

int myDateTime::setTime(const int hour,const int minute,const int second)
{
    this->hour=hour;
    this->minute=minute;
    this->second=second;
    return 0;
}
int myDateTime::setDate(const int year,const int month,const int day)
{
    this->year=year;
    this->month=month;
    this->day=day;
    return 0;

}
int myDateTime::whatDate()
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
int myDateTime::seconds()
{
    scds = hour * 60 * 60 + minute * 60 + second;
    return 0;

}
bool myDateTime::isLeap()
{
    Leap = 0;
    if(year%4==0&&year%100!=0)
        Leap=1;
    else if(year%400==0)
        Leap=1;
    return 0;
}
void myDateTime::output()
{
    apm=0;
    hrs24=hour;
    if (hrs24>12){
        hrs24 -= 12;
        apm=1;
    }
    else if (hrs24==12)
        apm=1;
    cout<<year<<"-"<<setw(2)<<setfill('0')<<month<<"-"<<setw(2)<<setfill('0')<<day<<" ";
    cout<<setw(2)<<setfill('0')<<hrs24<<":"<<setw(2)<<setfill('0')<<minute<<":"<<setw(2)<<setfill('0')<<second<<" ";
    if(apm==0)
        cout <<"am"<<endl;
    else cout << "pm"<<endl;
}
void myDateTime::outputROC()
{
    cout <<"中華民國"<<setw(3)<<setfill('0')<<year-1911<<"年"<<setw(2)<<setfill('0')<<month<<"月"<<setw(2)<<setfill('0')<<day<<"日";
    if(apm==0)
        cout<<"上午"<<setw(2)<<setfill('0')<<hrs24<<"時"<<setw(2)<<setfill('0')<<minute<<"分"<<setw(2)<<setfill('0')<<second<<"秒"<<endl;
    else cout <<"下午"<<setw(2)<<setfill('0')<<hrs24<<"時"<<setw(2)<<setfill('0')<<minute<<"分"<<setw(2)<<setfill('0')<<second<<"秒"<<endl;
}

int main()
{
    myDateTime oj;
    while(cin>>year>>month>>day>>hour>>minute>>second)
    {
        if(year==0&&month==0&&day==0&&hour==0&&minute==0&&second==0)
            break;

        oj.setDate(year,month,day);
        oj.setTime(hour,minute,second);

        oj.output();
        oj.outputROC();

        oj.isLeap();
        cout<<Leap;

        oj.whatDate();
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

        oj.seconds();
        cout<<scds<<endl;
    }
}
