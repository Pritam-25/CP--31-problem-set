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

        map<int, int> freq;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }

        if (freq.size() > 2)
        {
            cout << "No" << endl;
        }
        // } else if (freq.size() == 2) {
        //     auto it = freq.begin();
        //     int count1 = it->second;
        //     ++it;
        //     int count2 = it->second;

        //     if (abs(count1 - count2) <= 1)
        //         cout << "Yes" << endl;
        //     else
        //         cout << "No" << endl;
        // } else {
        //     cout << "Yes" << endl;
        // }
        else
        {
            int count1 = freq.begin()->second;
            int count2 = freq.rbegin()->second;
            if (abs(count1 - count2) > 1)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}
