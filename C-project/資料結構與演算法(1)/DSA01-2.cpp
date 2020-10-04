#include <iostream>
#include <iomanip>
#include <string.h>
using   namespace std;

int main()
{
    //get data size
    int x;
    cin >> x;
    cin.get();
    //intput
    char **arr=new char*[x];
    for(int i=0;i<x;i++){
        arr[i]=new char[100];
    }

    for(int i=0;i<x;i++){
        cin.getline(arr[i],100);
    }
    //get weidth
    int max_length;
    int tmp=0;
    int length[x];
    for(int i=0;i<x;i++){
        tmp=0;
        for(int j=0;j<100;j++){
            if(arr[i][j]==' '){
                length[i]=tmp;
                if(tmp>max_length)
                    max_length=tmp;
                break;
            }
            tmp++;
        }
    }
    //copy array
    char **name=new char*[x];
    for(int i=0;i<x;i++){
        arr[i]=new char[max_length];
        memcpy(name[i],arr[i],max_length);
    }
    //output
    for(int i=0;i<x;i++){
        for(int j=0;j<max_length-length[i];j++){
            cout << " ";
        }
        cout << name[i] << endl;
    }
    //delete
    for(int i=0;i<x;i++)
        delete [] arr[i];
    delete [] arr;
}
