#include <iostream>
#include <string>

using namespace std;

int main()
{
    string out;
    int n, R;
    while(cin >> n >> R)
    {
        if(R>=1&&R<=n&&n<=10000)
        {
            out = "\0";
            int a[n];
            int b[R];
            for (int i = 0; i < n; i++)
            {
                a[i] = i + 1;
            }
            for(int i = 0; i < R; i++)
            {
                cin >> b[i];
            }
            for(int i = 0; i < n;i++)
            {
                bool bmissingNo = true;
                for(int j = 0; j < R;j++)
                {
                    if(a[i]==b[j])
                    {
                        bmissingNo = false;
                        break;
                    }
                }
                if(bmissingNo==true)
                {
                    out = out + to_string(a[i]) + " ";
                }
            }
            if(out=="\0")
                cout << "* " << endl;
            else
                cout << out << endl;
        }
    }
}