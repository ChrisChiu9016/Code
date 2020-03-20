#include <iostream>
using namespace std;
int main()
{
    int n,i;
    int pr[5] = {0};
    int count = 0;
    cin >> n;
    bool isPrime = true;
    while(count<5){
        isPrime = true;
        for (i = 2; i < n; i++)
        {
            if(n%i==0){
                isPrime = false;
                break;
            }
        }
        if(isPrime==true){
            pr[count] = n;
            count ++;
        }
        n ++;
    }
    cout << pr[0] << " " << pr[1] << " " << pr[2] << " " << pr[3] << " " << pr[4] << endl;
}