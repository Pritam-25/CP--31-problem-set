// 🧠 Approach:
// Use the button when the first closed door (`1`) appears.
// From that moment, Yourself can move x steps forward (1 door/sec), even through closed doors.
// If any closed door appears after (firstOne + x), it's invalid → print "No", else "Yes".

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int firstOne = -1;

        // 🔍 Find the first occurrence of 1
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                firstOne = i;
                break;
            }
        }

        // 🧪 From (firstOne + x) onward, check for any more 1s
        int start = firstOne + x;
        bool isPossible = true;

        for (int i = start; i < n; i++)
        {
            if (a[i] == 1)
            {
                isPossible = false;
                break;
            }
        }

        cout << (isPossible ? "Yes" : "No") << endl;
    }

    return 0;
}

// Time Complexity: O(n) 
// Space Complexity: O(1)