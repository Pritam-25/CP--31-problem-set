#include <bits/stdc++.h>
using namespace std;

/*
!🤔 Problem Description:
- Given n monsters with initial health.
- Monocarp deals k damage repeatedly to the monster with the current highest health.
- If multiple monsters have same health, attack the one with smaller index.
- Output the order in which monsters will die.

TODO⚠️ Contest-specific observation (used here):
- Sort based on (a[i] % k) descending.
- Treat 0 remainder as k (so that divisible monsters come last in priority).

?🧠 Approach:
1. For each monster, calculate (health % k).
2. If remainder == 0, set it as k (to prioritize correctly).
3. Store (adjusted remainder, original index) in a vector.
4. Sort the vector:
    - Primary key → Descending remainder.
    - Secondary key → Ascending index.
5. Output the sorted indices.
*/

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> ans;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            int val = x % k;

            // Treat 0 remainder as k to push it last in descending order
            if (val == 0)
                val = k;

            ans.push_back({val, i + 1}); // Store (adjusted remainder, 1-based index)
        }

        // Sort by descending remainder, then ascending index
        sort(ans.begin(), ans.end(), [&](pair<int, int> x, pair<int, int> y)
             {
            if (x.first != y.first)
                return x.first > y.first;
            else
                return x.second < y.second; });

        // Output result
        for (auto &it : ans)
            cout << it.second << " ";
        cout << '\n';
    }

    return 0;
}

/*
*⌚ Time Complexity:
- O(n log n) per test case (because of sorting)

*📦 Space Complexity:
- O(n) per test case
*/
