#include <cmath>
#include <iostream>
#include <string.h>
#include <algorithm>

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
    void Sizeplus();
    void sortArray();
    bool ExpandNeeded();

protected:
    bool swapValue(int pos1, int pos2);
};
class sortList : public intList{
public:
    int insert(int value);
};
int sortList::insert(int value){
    ExpandNeeded();                     //檢查是否需要 expandSize
    setValue(getSize()+1, value);       
    Sizeplus();                         //siezUsed +1
    sortArray();
    return 0;
}
intList::intList()
{
    totalSize = 100;                    //初始大小設為100
    sizeUsed = 0;                       //目前使用大小設為0
    data = new int[totalSize]();        //配置記憶體空間，且元素初始值設為零
}
bool intList::ExpandNeeded()
{
    if(sizeUsed==totalSize){
        expandSize();
        return true;
    }
    return false;
}
void intList::sortArray()
{
    sort(data, data + sizeUsed);
}
void intList::Sizeplus()
{
    sizeUsed++;
}
void intList::insert(int value)
{
    if(sizeUsed==totalSize)             //大小不足時 expendSize
        expandSize();
    data[sizeUsed] = value;
    sizeUsed++;
}
bool intList::remove(int pos)
{
    if(pos>=0&&pos<=getSize()){
        for (int i = pos-1;i<getSize();i++){
            data[i] = data[i + 1];              //data[i] 後的資料往前平移
        }
        cout << "ok" << endl;
        return 0;
    }
    //若 pos 傳入值不合法
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
    int *copydata = new int[2 * totalSize]();   //產生一新陣列，大小為兩倍 totalSize，用來暫時存取 data[] 內的資料
    memcpy(copydata, data, totalSize);          //將 data[] 的前 totalSize 項複製給 copydata[]
    totalSize *= 2;
    data = new int[totalSize];                  //重新配置 data[] 大小
    memcpy(data, copydata, totalSize);          //將 copydata[] 的前 totalSize(新的) 項複製給 data[]
    delete [] copydata;                         //歸還記憶體空間
}
bool intList::swapValue(int pos1,int pos2)
{
    swap(data[pos1 - 1], data[pos2 - 1]);
    return 0;
}
int main()
{
    int x;
    sortList List1;
    while (cin >> x){
        if(x>0)
            List1.insert(x);
        if(x==0){
            for (int i = 1; i <= List1.getSize();i++)
                cout << List1.getValue(i) << endl;
            return 0;
        }
    }
}
    