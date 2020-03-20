#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int s, x;
    double sum = 0;
    cin >> s >> x;
    int *ptr = new int[1024];
    srand(s);
    for (int i = 0; i < x;i++){
        ptr[i] = rand() % 201 - 100;
        sum += ptr[i];
    }
    double average = sum / x;
    double SoSoD=0;
    for (int i = 0; i < x;i++){
        SoSoD += pow((ptr[i] - average),2);
    }
    double Var = SoSoD / x;
    double SD = sqrt(Var);
    cout << average << endl
         << SD << endl;
}