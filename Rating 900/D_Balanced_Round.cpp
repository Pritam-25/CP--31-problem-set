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

        sort(a.begin(), a.end());

        int maxLen = 1;
        int left = 0;

        // Sliding window to find the longest valid subarray
        for (int right = 1; right < n; ++right)
        {
            if (a[right] - a[right - 1] <= k)
            {
                // valid pair, continue window
                // nothing to do, just move to next
            }
            else
            {
                // reset window start
                left = right;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        // Remove rest of the elements
        cout << (n - maxLen) << endl;
    }

    return 0;
}
