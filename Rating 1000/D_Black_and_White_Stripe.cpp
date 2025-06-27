#include <bits/stdc++.h>
using namespace std;

/*
! 🤔 Problem Description:
- Given a stripe of length `n` containing 'B' and 'W'.
- Goal: Find the **minimum number of white ('W') cells to repaint black ('B')**
  to get at least one continuous segment of exactly `k` consecutive black cells.

? 🧠 Approach (Sliding Window on Fixed Size k):
- Use a **fixed-size sliding window** of length `k`.
- For each window, count how many 'W' are present (since they need repainting).
- Track the **minimum repaint count** across all possible windows.

*🔰 Why Sliding Window works:
- Total windows = (n - k + 1)
- For each window:
    - Slide 1 position at a time → O(n) time
    - Keep updating count efficiently → No nested loop needed.

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int repaint = 0;

        // Count 'W' in the first window of size k
        for (int i = 0; i < k; i++) {
            if (s[i] == 'W') repaint++;
        }

        int minRepaint = repaint;

        // Slide the window
        for (int i = k; i < n; i++) {
            if (s[i - k] == 'W') repaint--; // Remove outgoing char
            if (s[i] == 'W') repaint++;     // Add incoming char
            minRepaint = min(minRepaint, repaint);
        }

        cout << minRepaint << '\n';
    }

    return 0;
}

/*
*⌚ Time Complexity:
  O(n) per test case.

*📦 Space Complexity:
  O(1) extra space (ignoring input storage).
*/
