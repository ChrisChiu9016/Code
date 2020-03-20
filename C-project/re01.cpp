#include <iostream>
using namespace std;

int gcd(int i, int j);

int main()
{
    int num1,num2;
    cin >> num1 >> num2;
    if(num1<0||num2<0){
        cout << "0 0\n";
        return 0;
    }
    int GCD = gcd(num1, num2);
    int LCM = num1 * num2 / GCD;
    cout << GCD << " " << LCM << endl;

}

int gcd(int i,int j)
{
    if(i%j==0) return j;
    else return gcd(j,i%j);
}