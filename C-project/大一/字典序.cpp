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
        cout << a << endl;
    } while (next_permutation(a, a + size));
}