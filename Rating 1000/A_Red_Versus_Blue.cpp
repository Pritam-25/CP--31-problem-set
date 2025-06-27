/*
! 🤔 Problem Description:
- Two teams (Red and Blue) played 'n' matches.
- Red won 'r' times, Blue won 'b' times (where b < r and r + b = n).
- You need to construct a string of length 'n' consisting of characters 'R' and 'B'.
- The goal is to minimize the maximum number of consecutive 'R's in the string.
- Multiple answers are allowed.

? 🧠 Approach:
- Total gaps where Red wins ('R') can be placed = (b + 1).
- Distribute the 'r' Red wins as evenly as possible across these gaps.
- Base number of Reds per gap = (r / (b + 1)).
- Extra Reds = (r % (b + 1)) → First 'extraReds' gaps will get one extra Red.
- For each gap:
    - Add required number of 'R's.
    - Add a 'B' (except after the last gap).

*🔰 Example for better understanding:
    For n = 7, r = 4, b = 3
    Gaps = 4
    Base Reds per gap = 1
    Extra Reds = 0
    Result: R B R B R B R → RBRBRBR
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;

        int gaps = b + 1;
        int reds_per_gap = r / gaps;
        int extra_reds = r % gaps;

        string matches = "";

        for (int i = 0; i < gaps; i++) {
            int cur_red_count = reds_per_gap;
            if (extra_reds > 0) {
                cur_red_count++;  // First extra_reds gaps get 1 extra R
                extra_reds--;
            }

            // Add reds for this gap
            for(int i=0; i<cur_red_count; i++){
                matches += "R";
            }

            // Add a blue between gaps (but not after the last gap)
            if (b > 0) {
                matches += "B";
                b--;
            }
        }

        cout << matches << "\n";
    }

    return 0;
}

/*
*⌚ Time Complexity:
- O(n) per test case (because we construct a string of length n).

*📦 Space Complexity:
- O(n) for the result string.
*/



//* my initial logic which was also accepted (but bit complex and confusing)
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;

        // Write your code here
        int gaps = b + 1;
        int reds_per_gap = r / gaps;
        int extra_reds = r % gaps;

        string matches = "";

        while (b) {
            int cur_red_gaps = reds_per_gap;
            // if extra reds present
            if (extra_reds) {
                cur_red_gaps++;
                for (int i = 0; i < cur_red_gaps; i++) {
                    matches += "R";
                    r--;
                }
                extra_reds--;
            } else {
                // if extra red not present
                for (int i = 0; i < reds_per_gap; i++) {
                    matches += "R";
                    r--;
                }
            }
            // add b between reds
            matches += "B";
            b--;
        }

        // if reds are remaining
        for (int i = 0; i < r; i++) {
            matches += "R";
        }

        cout << matches << endl;
    }

    return 0;
}
*/
