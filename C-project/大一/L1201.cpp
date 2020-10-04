#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;
class intList
{
    int *data;         //��Ʀs�񪺰ʺA�}�C
    int totalSize;     //�ثe�ʺA�}�C���j�p
    int sizeUsed;      //�ثe���X�ӥ����
    void expandSize(); //�X�W�ʺA�}�C�j�p���⭿
public:
    intList();
    void insert(int value);            //�s�W value ��ƦC
    bool remove(int pos);              //�R�� pos ��m�������
    int getValue(int pos);             //�^�� pos ��m����
    bool setValue(int pos, int value); //�]�w pos ��m���Ȭ� value
    int getSize();                     //sizeUsed �� accessor
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