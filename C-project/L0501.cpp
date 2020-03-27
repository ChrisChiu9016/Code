#include <iostream>
#include <algorithm>
using namespace std;

int n;
int bonus = 0, cnt = 0, netprofit = 0;
int crtbonus = 0;
int winnumber[5] = {0};
int **ltry;

int check(void)
{
    for (int i = 0; i < n;i++){
        cnt = 0;
        crtbonus = 0;
        for (int j = 0; j < 5;j++){
            for (int k = 0; k < 5; k++){
                if (ltry[i][j]==winnumber[k]){
                    cnt += 1;
                    break;
                }
            }
        }
        switch(cnt){
            case 2:
                crtbonus = 50;
                bonus += crtbonus;
                break;
            case 3:
                crtbonus = 300;
                bonus += crtbonus;
                break;
            case 4:
                crtbonus = 20000;
                bonus += crtbonus;
                break;
            case 5:
                crtbonus = 8000000;
                bonus += crtbonus;
                break;
        }
        if(crtbonus!=0){
            cout << crtbonus << " ";
            for (int l = 0; l < 5;l++){
                if(l!=4)
                    cout << ltry[i][l] << " ";
                else
                    cout << ltry[i][l] << endl;
            }
        }
    }
    netprofit = bonus - n * 50;
    return netprofit;
}

int main()
{
    cin >> n;
    ltry = new int*[n];
    for (int i = 0; i < n;i++){
        ltry[i] = new int[5];
        for (int j = 0; j < 5;j++){
            cin >> ltry[i][j];
        }
        sort(ltry[i], ltry[i] + 5);
    }

    for (int i = 0; i < 5;i++){
        cin >> winnumber[i];
    }
    check();
    cout << netprofit << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] ltry[i];
    }
    delete[] ltry;
}