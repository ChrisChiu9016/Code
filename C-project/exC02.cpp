#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string out;
    for (int i = 1; i <= n;i++)
    {
        int size;
        cin >> size;
        int *arr = new int[size];
        for (int j = 0; j < size; j++)
        {
            cin >> arr[j];
        }
        sort(arr, arr + size);
        int sum = 2 * (arr[size - 1] - arr[0]);
        const char *a = to_string(sum).c_str();
        out = out + a + "\n";
        delete [] arr;
    }
    cout << out << endl;
    return 0;
}