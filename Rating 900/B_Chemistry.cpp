#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> freq(26, 0); // 26 letters for a-z

        for (char c : s)
        {
            freq[c - 'a']++; // Count frequency of each character
        }

        int oddCount = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 != 0)
            {
                oddCount++;
            }
        }

        if (oddCount - 1 > k)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}
