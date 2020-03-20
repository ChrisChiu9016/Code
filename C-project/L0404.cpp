#include <iostream>
#include <fstream>

using namespace std;

int countchar(char a);
int cnt[62] = {0};

int main()
{
    ifstream infile("1.in");
    ofstream outfile("1.out");

    char x;
    int check[62] = {0};
    bool max = true;

    while (infile >> x){
        countchar(x);
    }
    for (int i = 0; i < 62; i++){
        max = true;
        for (int j = 0; j < 62; j++)
        {
            if (j == i)
                continue;
            if (cnt[i] < cnt[j]){
                max = false;
                break;
            }
        }
        if(max)
            check[i] = 1;
    }
    for(int i=0;i<62;i++){
        if(check[i]==1){
            if (i < 10){
                outfile << i;
                break;
            }
            else if (i < 36){
                outfile << char(i - 10 + 65);
                break;
            }
                else outfile << char(i - 36 + 97);
                break;
        }
    }
}

int countchar(char a){
    if (a >= 'A' && a <= 'Z')
        cnt[int(a - 'A' + 10)] += 1;
    else if (a >= 'a' && a <= 'z')
        cnt[int(a - 'a' + 36)] += 1;
    else
        cnt[int(a)] += 1;
    return 0;
}