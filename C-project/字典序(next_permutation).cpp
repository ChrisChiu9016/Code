#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    char a[50];
    cin >> a;
    int size = strlen(a);
    sort(a, a + size);
    do{
        for (int i = 0; i < size;i++)
            cout << a[i];
        cout << endl;
    } while (next_permutation(a, a + size));
}