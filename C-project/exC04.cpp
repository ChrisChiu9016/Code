#include <iostream>
#include <string>

using namespace std;

int gcd(int i,int j);

int main()
{
    int n;
    string out;
    int count = 1;
    int sum = 0;
    if (count > 100)
        cout << sum << endl;
    while (cin>>n)
    {
        sum = 0;
        if (n==0)
            break;
        for (int i = 1; i < n;i++)
        {
            for (int j = i + 1; j <= n;j++)
            {
                sum = sum + gcd(i, j);
            }
        }
        out = out + to_string(sum) + "\n";
    }
    cout << out << endl;
}

int gcd(int i,int j)
{
    if(i%j==0) return j;
    else return gcd(j, i % j);
}

