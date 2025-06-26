// 🧠 Approach:
// Find the length of the longest group of consecutive '<' or '>'.
// The minimum cost = longest group length + 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int maxGroup = 1, curLen = 1;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
                curLen++;
            else
                curLen = 1;

            maxGroup = max(maxGroup, curLen);
        }

        cout << maxGroup + 1 << endl; // answer is longest group + 1
    }

    return 0;
}

// 🕒 Time Complexity: O(n) per test case
// 🧠 Space Complexity: O(1) extra