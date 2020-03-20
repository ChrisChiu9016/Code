#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int s;
    cin >> s;
    srand(s);
    int arr[100000] = {0};      //產生陣列存取亂數值
    int arrc[50] = {0};         //產生陣列紀錄出現次數
    //int arrc2[50] = {0};
    for (int i = 0; i < 100000;i++)//產生亂數值
    {
        arr[i] = rand() % 50 + 1;
        for (int num = 1; num <= 50; num++)//紀錄出現次數
        {
            if(arr[i]==num)
            {
                arrc[num - 1] += 1;
                arrc2[num - 1] += 1;
            }
        }
    }
    //int maxnumber, minnumber;
    //int maxcount, mincount;
    //maxnumber = minnumber = arr[0];
    //maxcount = mincount = arrc[0];
    int max, min;
    int arrc2_end = sizeof(arrc2) / sizeof(int);
    sort(arrc2, arrc2 + arrc2_end);
    for (int j = 0; j < 50; j++)
    {
        //if (arr[j]>maxcount)
        {
            // maxnumber = j + 1;
            // maxcount = arrc[j];
        }
        //else if (arr[j]<mincount)
        {
           // minnumber = j + 1;
           // mincount = arrc[j];
        }
        if (arrc[j]=arrc2[49])
        {}
    }
    cout << max << " " << arrc[max] << endl;
    cout << min << " " << arrc[min] << endl;
    cout << maxnumber << " " << maxcount << endl;
    cout << minnumber << " " << mincount << endl;
    return 0;
}