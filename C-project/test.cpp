#include<iostream>

#include<ctime>

using namespace std;

int main()

{
    cout<<"輸入一個延時時間（以秒為單位）：";
    float secs;
    cin>>secs;
    clock_t delay;
    delay=secs * CLOCKS_PER_SEC;
    cout<<"開始\n";
    clock_t start=clock();
    while(clock()-start < delay){}
    cout << "結束\n";
    return 0;
}
