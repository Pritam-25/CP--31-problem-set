/*
!🤔 Problem Description:
Start at position 's' on the number line.
You can move left or right by 1 in each step.
Visit all positions in x[] at least once.
Calculate minimum total steps needed.

?🧠 Approach:
- Find leftmost and rightmost target positions (x[0], x[n-1] since x[] is sorted).
- Formula:
    steps = (right - left) + min(abs(s - left), abs(s - right))
- Meaning:
    - First reach nearest end.
    - Then walk the full span between left and right.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, s;
        cin >> n >> s;

        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }

        int left = x[0];       // Leftmost target position (since x is sorted)
        int right = x[n - 1];  // Rightmost target position

        int distanceToLeft = abs(s - left);
        int distanceToRight = abs(s - right);
        int rangeSpan = right - left;

        int ans = rangeSpan + min(distanceToLeft, distanceToRight);

        cout << ans << "\n";
    }

    return 0;
}

/*
*⌚ Time Complexity:
    O(n) per test case (input reading)
*📦 Space Complexity:
    O(n)
*/
