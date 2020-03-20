#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int s,a=0;
    cin >> s >> a;
    srand(s);
    for (int i = 0; i < a;i++){
        int *x = new int(a);
        *x = rand() % 100 + 1;
        if(*x%2==0)
            cout << *x << endl;
        delete x;
    }
}