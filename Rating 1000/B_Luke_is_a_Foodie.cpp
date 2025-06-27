#include <bits/stdc++.h>
using namespace std;

/*
! 🤔 Problem Description:
- Luke walks from first to last pile of food.
- Before each pile, he can change his food affinity `v` (unlimited times).
- For pile `i`, he can eat only if |v - a[i]| <= x.
- Initially, he can choose any `v` (this does NOT count as a change).
- Find the **minimum number of times he needs to change `v`** during the walk.

? 🧠 Approach:
- Maintain a valid affinity range: [L, R].
- For each pile:
    - The food allowed at `i` → Allowed affinity window = [a[i] - x, a[i] + x].
    - Update running window → intersection of (current [L, R]) and this allowed window.
    - If intersection becomes empty → increment change count, reset L, R to new allowed window.
- Start with L = -INF, R = +INF (so first pile doesn't force a change).

*🔰 Sliding Window on Range of Valid v:
- Shrink range every step.
- Reset when invalid.

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int &val : a) cin >> val;

        int changes = 0;
        int L = -1e9, R = 1e9; // Current valid affinity range for v

        for (int i = 0; i < n; i++) {
            int low = a[i] - x;
            int high = a[i] + x;

            // Update current window
            L = max(L, low);
            R = min(R, high);

            // If invalid window, make a change
            if (L > R) {
                changes++;
                L = low;
                R = high;
            }
        }

        cout << changes << '\n';
    }

    return 0;
}

/*
⌚ Time Complexity:
- O(n) per test case

📦 Space Complexity:
- O(n) for input array
*/
