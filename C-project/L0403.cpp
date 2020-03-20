#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("1.in");
    ofstream outfile("1.out");
    
    char a;
    int count = 0;
    int pwd;
    while(infile.get(a)){
        if (count == 0){
            pwd = a;
            outfile << a;
            count = 1;
        }
        else
            outfile << char(a ^ pwd);
    }
    infile.close();
    outfile.close();
}
