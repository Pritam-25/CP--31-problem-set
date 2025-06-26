#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string x, s;
        cin >> x >> s;

        // Write your code here

        int minOpr = 0;
        bool isFind = false;

        for (int i = 0; i <= 5 ; i++)
        {
            if (x.find(s) != string::npos)
            {
                isFind = true;
                break;
            }
            x += x;
            minOpr++;
        }

        if (isFind)
            cout << minOpr << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}