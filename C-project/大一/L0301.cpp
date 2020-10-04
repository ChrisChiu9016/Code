#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("1.in");
    outfile.open("1.out");

    char a;
    int final;

    while(infile>>a){
        final = a ^ 'a';
        outfile << char(final);
    }
    outfile << endl;
}