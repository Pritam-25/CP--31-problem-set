#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool continuous_three_empty_cell = false;
        int total_count_of_empty_cell = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
                total_count_of_empty_cell++;

            // check for 3 continuous empty cells
            if (i <= n - 3 && s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.')
            {
                continuous_three_empty_cell = true;
            }
        }

        if (continuous_three_empty_cell)
            cout << 2 << endl;
        else
            cout << total_count_of_empty_cell << endl;
    }

    return 0;
}
