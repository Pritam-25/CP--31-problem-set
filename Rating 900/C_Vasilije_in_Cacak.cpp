#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;

        // Write your code here

        // minSum = 1+2+3+⋯+k
        long long minSum = (k * (k + 1)) / 2;

        // maxSum = n+(n−1)+⋯+(n−k+1)
        long long maxSum = (k * ((2 * n) - k + 1)) / 2;

        if (minSum <= x && x <= maxSum)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}