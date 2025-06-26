#include <bits/stdc++.h>
using namespace std;

/*
!🤔 Problem Description:
- Given temperatures over `n` days.
- Find number of contiguous subarrays (vacation periods) of length at least `k`
  where all temperatures are ≤ `q`.

?🧠 Approach:
- Track length of each continuous segment where temperature ≤ q (call it `dayCount`).
- For each such segment where `dayCount >= k`, calculate number of valid subarrays.

TODO💊 Converting Original Loop to Formula:
-------------------------------------------------
Original Loop:
for (int j = k; j <= dayCount; j++) {
    poss += (dayCount - j + 1);
}

*🔰 Explanation:
- This loop was summing:
  (dayCount - k + 1) + (dayCount - k) + ... + 1
- Which equals:
  Sum of first (dayCount - k + 1) natural numbers.

?🤯 Final O(1) Formula:
if (dayCount >= k) {
    long long len = dayCount - k + 1;
    poss += (len * (len + 1)) / 2;
}
*/

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--){
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> a(n);
        
        long long poss = 0;
        long long dayCount = 0;

        for (int i = 0; i < n; i++){
            cin >> a[i];

            if (a[i] <= q)
                dayCount++;
            else{
                if (dayCount >= k){
                    long long len = dayCount - k + 1;
                    poss += (len * (len + 1)) / 2;
                }
                dayCount = 0;
            }
        }

        // Handle last segment if it ends at the end of array
        if (dayCount >= k){
            long long len = dayCount - k + 1;
            poss += (len * (len + 1)) / 2;
        }

        cout << poss << '\n';
    }

    return 0;
}

/*
*⌚ Time Complexity:
 O(n) per test case
*📦 Space Complexity:
 O(n)
*/

/*
!🤢 Worst Case Scenario:
Imagine entire array is valid, and dayCount = 2 × 10^5.

*Then:
Number of ways ≈ Sum of first ~2×10^5 natural numbers =

Total ≈ (2×10^5 × 2×10^5) / 2
?That’s roughly: ≈ 2×10^10
Which overflows int (max ~2×10^9)
*/
