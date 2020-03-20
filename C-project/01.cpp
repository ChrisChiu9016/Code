#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int seed;
    int i, j;
    int a[13]={0};
    int res;
    int count=0;
    int find;
    cin >> seed;
    srand(seed);
    while(count<13){
        res = rand() % 52 + 1;
        //cout << res << endl;
        find = 0;
        for (i = 0; i < count;++i){
            if (a[i]==res){
                find = 1;
                break;
            }
        }
        if (find==0){
            a[count] = res;
            count++;
        }
    }
    for (j = 0; j < 13;j++){
        int suit = a[j] % 4 + 1;
        int point = a[j] % 13 + 1;
        switch(suit){
            case 1:
                cout << "S";
                break;
            case 2:
                cout << "H";
                break;
            case 3:
                cout << "D";
                break;
            case 4:
                cout << "C";
                break;
        }
        switch(point){
            case 1:
                cout << "A\n";
                break;
            case 2:
                cout << "2\n";
                break;
            case 3:
                cout << "3\n";
                break;
            case 4:
                cout << "4\n";
                break;
            case 5:
                cout << "5\n";
                break;
            case 6:
                cout << "6\n";
                break;
            case 7:
                cout << "7\n";
                break;
            case 8:
                cout << "8\n";
                break;
            case 9:
                cout << "9\n";
                break;
            case 10:
                cout << "10\n";
                break;
            case 11:
                cout << "J\n";
                break;
            case 12:
                cout << "Q\n";
                break;
            case 13:
                cout << "K\n";
                break;
        }
    }
}