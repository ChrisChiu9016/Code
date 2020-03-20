#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    int sum = 0;
    string out;
    cin >> n;
    for(int i = 1; i <= n;i++)
    {
        int a = 0, b = 0;
        int tmp = 0;
        sum = 0;
        cin >> a >> b;
        if(a>b)
            {
                tmp = a;
                a = b;
                b = tmp;
            }
        for (int j = a; j <= b; j++)
            {
                if(j%2==1)
                    sum = sum + j;
            }
			out = out + "Case " + to_string(i) + ": " + to_string(sum) + "\n";
	}
    cout << out << endl;
    return 0;
}