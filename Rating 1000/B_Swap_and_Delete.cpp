#include <bits/stdc++.h>
using namespace std;

/*
?🧠 APPROACH:
- You are allowed to swap characters freely, but t[i] must differ from s[i].
- This means position-wise pairing is required.
- As we go through the string:
  → If current char is '1', and there's an unused '0', we can place a '0' here (t[i] ≠ s[i])
  → If it's '0', and we have unused '1', we can place a '1' here.
- Once we run out of opposite characters, we break.
- All remaining characters must be deleted.

✅ This guarantees that t[i] ≠ s[i] at each used position.
*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int n = s.size();
        int one = 0, zero = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1') one++;
            else zero++;
        }

        int lenOf_t = 0;

        // Try to build t such that t[i] ≠ s[i]
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && zero > 0)
            {
                zero--;
                lenOf_t++;
            }
            else if (s[i] == '0' && one > 0)
            {
                one--;
                lenOf_t++;
            }
            else break; // can't match this position safely
        }

        // Remaining unmatched positions must be deleted
        cout << n - lenOf_t << endl;
    }

    return 0;
}

/*
*⌚ TIME COMPLEXITY: 
O(n) per test case
*📦 SPACE COMPLEXITY:
 O(1)
*/
