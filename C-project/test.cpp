#include<iostream>

#include<ctime>

using namespace std;

int main()

{
    cout<<"��J�@�ө��ɮɶ��]�H�����^�G";
    float secs;
    cin>>secs;
    clock_t delay;
    delay=secs * CLOCKS_PER_SEC;
    cout<<"�}�l\n";
    clock_t start=clock();
    while(clock()-start < delay){}
    cout << "����\n";
    return 0;
}
