#include <iostream>
#include <string.h>

using namespace std;

void bubblesort(char **_arr, int arr_length, int arr_weidth);
int main()
{
    int x, y;
    cout << "��Jx,y:\n";
    cin >> x >> y;
    cin.get();      //����r��

    char **arr=new char*[x];    //new
    for(int i=0;i<x;i++)
    {
        arr[i]=new char[y];
    }

/*
    char **arr = (char **)malloc(sizeof(char *) * x);
    for (int i = 0; i < x; i++)
    {
        arr[i] = (char *)malloc(sizeof(char) * y);
    }
*/
    cout<< "��J:\n";     //��J
    for (int i = 0; i < x; i++)
    {
        cout << i + 1 << ": ";
        cin.getline(arr[i], y + 1); //����r��
    }

    bubblesort(arr, x, y); //�Ƨ�

    //cout << "��X:\n";
    for (int i = 0; i < x; i++)
    {
        cout << i + 1 << ". ";
        for (int j = 0; j < y; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }

    for(int i=0;i<x;i++)
        delete [] arr[i];
    delete [] arr;

/*
    free(arr);
*/
    return 0;
}
void bubblesort(char **_arr, int arr_length, int arr_weidth)
{
    for(int i=0;i<arr_length;i++){
        for(int j=i+1;j<arr_length;j++){
            if(_arr[j][0]>_arr[i][0]){
                int tmp=0;
                for(int k=0;k<arr_weidth;k++){
                    tmp=_arr[i][k];
                    _arr[i][k]=_arr[j][k];
                    _arr[j][k]=tmp;
                }
            }
        }
    }
}
