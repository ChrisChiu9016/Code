#include <iostream>
#include <string.h>

using namespace std;

void bubblesort(char **_arr, int arr_length, int arr_weidth);
int main()
{
    int x, y;
    cout << "��Jx,y:\n";
    cin >> x >> y;
    //55cin.get();      //����r��
    /*
    char **arr=new char*[x];    //new
    for(int i=0;i<x;i++)
    {
        arr[i]=new char[y+1]; //����r��
    }
*/

    char **arr = (char **)malloc(sizeof(char *) * x);
    for (int i = 0; i < x; i++)
    {
        arr[i] = (char *)malloc(sizeof(char) * y);
    }

    //cout<< "��J:\n";     //��J
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
    /*
    for(int i=0;i<x;i++)
        delete [] arr[i];
    delete [] arr;
*/
    free(arr);
    return 0;
}
void bubblesort(char **_arr, int arr_length, int arr_weidth)
{
    for (int i = 0; i < arr_length; i++)
    {
        int arr_size = strlen(_arr[i]);
        for (int n = 0; n < arr_size - 1; n++)
        {
            for (int j = 0; j < arr_size - 1; j++)
            {
                if (_arr[i][j] > _arr[i][j + 1])
                {
                    int tmp = _arr[i][j];
                    _arr[i][j] = _arr[i][j + 1];
                    _arr[i][j + 1] = tmp;
                }
            }
        }
    }
}
