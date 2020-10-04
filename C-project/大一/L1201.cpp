#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;
class intList
{
    int *data;         //資料存放的動態陣列
    int totalSize;     //目前動態陣列的大小
    int sizeUsed;      //目前有幾個正整數
    void expandSize(); //擴增動態陣列大小為兩倍
public:
    intList();
    void insert(int value);            //新增 value 到數列
    bool remove(int pos);              //刪除 pos 位置的正整數
    int getValue(int pos);             //回傳 pos 位置的值
    bool setValue(int pos, int value); //設定 pos 位置的值為 value
    int getSize();                     //sizeUsed 的 accessor
protected:
    bool swapValue(int pos1, int pos2);
};
class searchList:public intList{
    public:
        int search(int value);
};
intList::intList()
{
    totalSize = 100;
    sizeUsed = 0;
    data = new int[totalSize]();
}
void intList::insert(int value)
{
    if(sizeUsed==totalSize)
        expandSize();
    data[sizeUsed] = value;
    sizeUsed++;
}
bool intList::remove(int pos)
{
    if(pos>=0&&pos<=getSize()){
        cout << data[pos - 1] << endl;
        data[pos - 1] = data[sizeUsed - 1];
        return 0;
    }
    cout << "no" << endl;
    return 1;
}
int intList::getValue(int pos)
{
    return data[pos - 1];
} 
bool intList::setValue(int pos,int value)
{
    data[pos - 1] = value;
    return 0;
}
int intList::getSize()
{
    return sizeUsed;
}
void intList::expandSize()
{
    int *copydata = new int[2 * totalSize]();
    memcpy(copydata, data, totalSize);
    totalSize *= 2;
    data = new int[totalSize];
    memcpy(data, copydata, totalSize);
    delete [] copydata;
}
bool intList::swapValue(int pos1,int pos2)
{
    swap(data[pos1 - 1], data[pos2 - 1]);
    return 0;
}
int searchList::search(int value)
{
    for (int i = 1; i < getSize() + 1; i++)
    {
        if(getValue(i)==value)
            return i;
    }
    return -1;
}
int main()
{
    int x;
    searchList List1;
    while (cin >> x){
        if(x==0)
            break;
        if(x>0)
            List1.insert(x);
        else
            List1.remove(abs(x));
    }
}