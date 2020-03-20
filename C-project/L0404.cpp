#include <iostream>
#include <fstream>

using namespace std;

int countchar(char a);

int main()
{
    ifstream infile("1.in");
    ofstream outfile("1.out");

    int a;
    int cnt[62] = {0};
    int check[62] = {0};
    bool max = true;

    while (infile >> a)
    {
        countchar(a);
    }
    for (int i = 0; i < 60; i++)
    {
        max = true;
        for (int j = 0; j < 60; j++)
        {
            if (j == i)
                continue;
            if (cnt[i] < cnt[j])
                max = false;
        }
        if (max)
            check[i] = 1;
    }
}

int countchar(char a)
{
    if (a >= 'A' && a <= 'Z')
        cnt[a - 'A'] += 1;
    else if (a >= 'a' && a <= 'z')
        cnt[a - 'a' + 26] += 1;
    else
        cnt[a + 52] += 1;
}