#include <iostream>

using namespace std;

int binarySearch(int arr[],int l,int r,int x)
{
    while(l<=r){
        int mid = l + (r - l) / 2;
        if(arr[mid]==x)
            return mid;
        if(arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main()
{
    int *arr;
    int n,x;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    while(cin>>x){
        if(x<0)
            break;
        int result = binarySearch(arr, 0, n-1, x);
        if(result>=0)
            cout << "True" << endl;
        else if(result==-1)
            cout << "False" << endl;
    }
    return 0;
}