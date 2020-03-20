#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int angle[4]={0,0,0,0};
    string out;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> angle[j-1];
        }
        int angle_end = sizeof(angle) / sizeof(int);
        sort(angle, angle + angle_end);
        if (angle[0]==angle[3])
            out = out + "square\n";
        else if (angle[0] == angle[1]&&angle[2]==angle[3])
            out = out + "rectangle\n";
        else if (angle[0]+angle[1]+angle[2]>angle[3])
            out = out + "quadrangle\n";
        else
            out = out + "none\n";
    }
    cout << out << endl;
    return 0;
}