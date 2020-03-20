#include <iostream>
using namespace std;

void cbfSort(int a, int b, int c);


int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cbfSort(a, b, c);

}

void cbfSort(int i,int j,int k)
{
    int tmp =0;
    if (i < j){
        tmp = j;
        j = i;
        i = tmp;
    }
    if (j < k){
        tmp = k;
        k = j;
        j = tmp;
    }
    if (i < j){
        tmp = j;
        j = i;
        i = tmp;
    }

    cout << i << " " << j << " " << k << endl;
}