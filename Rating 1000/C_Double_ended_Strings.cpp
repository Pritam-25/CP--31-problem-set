#include <bits/stdc++.h>
using namespace std;

/*
! 🤔 Problem Description:
- Given two strings `a` and `b`.
- You can delete characters from either j of both strings.
- Goal: Make both strings equal (including possibly empty strings) with **minimum operations**.

? 🧠 Approach:
- Find the length of the **Longest Common Substring (LCSUB)** that appears somewhere in both strings.
- Minimum operations = Total length - 2 × LCSUB length.
- Brute force all substrings of `a` and check if it exists in `b` using `find()`.

*🔰 Reason for Brute Force:
- Since max |a| and |b| ≤ 20, total substring checks ≈ 400 per test case.  
  Acceptable within time limit.

*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        int maxCmnSubstrLen = 0;

        // Brute force: Generate all substrings of a
        for (int i = 0; i < a.size(); i++) {
            string currSubstr = "";
            for (int j = i; j < a.size(); j++) {
                currSubstr += a[j];
                if (b.find(currSubstr) != string::npos) {
                    maxCmnSubstrLen = max(maxCmnSubstrLen, (j - i + 1));
                }
            }
        }

        int operations = a.size() + b.size() - 2 * maxCmnSubstrLen;

        cout << operations << endl;
    }

    return 0;
}

/*
*⌚ Time Complexity:
    O(n^2 × m) → Where n = |a| (≤20), m = |b| (≤20)

*📦 Space Complexity:
    O(1) (ignoring input string storage)
*/
