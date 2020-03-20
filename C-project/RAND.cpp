#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int bottom, up, n;
    cin >> n >> bottom >> up;
    for (int i = 1; i <= n;i++)
    {
        int result = int(rand() / (RAND_MAX + 1.0) * (up - bottom) + bottom);
        cout << result << endl;
    }
}