#include <iostream>
using namespace std;
int main()
{
    int i = 1;
    int j = 1;
    //for (i = 1; i <= 9;i++)
    while (i<=9)
    {
        j = 1;
        while (j<=9)
        //for (j = 1; j <= 9;j++)
        {
            if (j==9&&i*j<10)
                cout << i << "x" << j << "=" << " " << i * j << " \n";
            else if (i*j<10)
                cout << i << "x" << j << "=" << " " << i * j << " ";
            else if(j==9)
                cout << i << "x" << j << "=" << i * j << " \n";
            else
                cout << i << "x" << j << "=" << i * j << " ";
            j++;
        }
        i++;
    }

}
