#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int x;
    cin >> x;

    int max_Weidth = 0;
    string *name = new string[x];
    int cnt = 0;
    while (cin.peek() != '\0' && cnt < x)
    {
        getline(cin, name[cnt]);
        if (sizeof(name[cnt]) > max_Weidth)
            max_Weidth = sizeof(name[cnt]);
        cnt++;
    }

    char **arr = new char *[x];
    for (int i = 0; i < x; i++)
    {
        arr[i] = new char[max_Weidth];
    }
}
