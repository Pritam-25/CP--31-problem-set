#include <bits/stdc++.h>
using namespace std;

/*
🤔 PROBLEM:
- We are given a string `s` of length `n`, and we need to determine if there exists a split:
    s = a + b + c
  such that:
    - a, b, c are non-empty
    - b is a substring of (a + c)
- Instead of checking every possible split (which is inefficient), we observe:
  ➤ If there is any character in the middle of the string (i.e., positions 1 to n-2)
    that appears again in the rest of the string (either before or after), 
    then we can form such a split.

🧠 APPROACH:
- Count frequency of each character using a hash map.
- Iterate from index 1 to n - 2 (valid middle positions for b).
- Temporarily decrease the count of current s[i] (removing it from b).
- If the character still exists in the map (i.e., in a or c), 
  then `b` can be a substring of (a + c), so the answer is "Yes".
- Restore the frequency in case the character wasn't found.
*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<char, long long> freq;

        // Step 1: Count frequency of each character
        for (int i = 0; i < n; ++i)
        {
            freq[s[i]]++;
        }

        bool isFound = false;

        // Step 2: Try splitting at different positions
        for (int i = 1; i < n - 1; i++)
        {
            freq[s[i]]--; // remove current char from "b"

            if (freq[s[i]]) // check if it still exists in "a + c"
            {
                isFound = true;
                break;
            }

            freq[s[i]]++; // restore frequency
        }

        cout << (isFound ? "Yes" : "No") << endl;
    }

    return 0;
}

/*
⌚ TIME COMPLEXITY: O(n) per test case
   - O(n) to count character frequency
   - O(n) to scan from index 1 to n-2
   - Total time across all test cases: O(∑n) ≤ 2 × 10⁵

📦 SPACE COMPLEXITY: O(1)
   - Only lowercase letters are used → max 26 entries in the frequency map
*/
