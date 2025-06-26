// 🧠 Approach:
// 1. For each test case, check if the value 'k' is present in the array.
// 2. If found → print "YES", else → print "NO".

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        // Check if k is present in array
        bool isPresent = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == k)
            {
                isPresent = true;
                break;
            }
        }

        // Output result
        cout << (isPresent ? "YES" : "NO") << endl;
    }

    return 0;
}
