#include <bits/stdc++.h>
using namespace std;

/*
🧠 APPROACH:
1. Read array and build a prefix sum array to allow O(1) range sum queries.
2. For each query, calculate:
   - The sum of original values in the range [l, r] using prefix sum.
   - The sum after replacing that range with value `k`.
3. If the new total sum is odd, print "YES"; otherwise, print "NO".
*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> a(n + 1, 0);
        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];  // Prefix sum computation
        }

        int sum = prefix[n];  // Total sum of the array

        while (q--)
        {
            int l, r, k;
            cin >> l >> r >> k;

            // Sum of the original subarray [l, r]
            int eliminate = prefix[r] - prefix[l - 1];

            // New total sum after replacing [l, r] with k
            int newSum = sum - eliminate + (r - l + 1) * k;

            cout << (newSum % 2 ? "YES" : "NO") << endl;  // Check if sum is odd
        }
    }

    return 0;
}

/*
⏱️ TIME COMPLEXITY:
- O(n) to compute prefix sum
- O(1) per query
- Total: O(n + q) per test case

📦 SPACE COMPLEXITY:
- O(n) for prefix sum array
*/
