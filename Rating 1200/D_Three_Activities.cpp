#include <bits/stdc++.h>
using namespace std;

/*
!🤔 PROBLEM:
- You are given 3 arrays of size n: a[], b[], and c[]
- a[i]: friends for skiing on day i
- b[i]: friends for movie on day i
- c[i]: friends for board games on day i
- Choose 3 distinct days x, y, z such that:
    - x ≠ y ≠ z
    - Total friends = a[x] + b[y] + c[z] is maximized

?🧠 APPROACH:
- For each array, store the value and its index as a pair.
- Sort each array in descending order to get the top 3 values and their indices.
- Try all 3 × 3 × 3 = 27 combinations of indices from the top 3 of each array.
- For each combination, if all indices are different, compute the total and update the max sum.

*⌚ TIME COMPLEXITY:
- O(n log n) for sorting 3 arrays of size n
- O(27) = O(1) for checking all combinations
- Total per test case: O(n log n)

*📦 SPACE COMPLEXITY:
- O(n) for storing each array and its indexed version
*/

vector<int> findTop3Indices(const vector<int> &arr)
{
    int n = arr.size();
    vector<pair<int, int>> temp(n);

    // Store value and index
    for (int i = 0; i < n; ++i)
        temp[i] = {arr[i], i};


    // Sort in descending order of value
    sort(temp.rbegin(), temp.rend());

    // Extract only the indices of top 3
    vector<int> top3;

    for (int i = 0; i < min(3, n); ++i)
        top3.push_back(temp[i].second);
    

    return top3;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);

        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        for (int &x : c) cin >> x;

        // Get indices of top 3 elements from each array
        vector<int> maxA = findTop3Indices(a);
        vector<int> maxB = findTop3Indices(b);
        vector<int> maxC = findTop3Indices(c);

        int ans = 0;

        // Try all 27 combinations
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){

                    int x = maxA[i], y = maxB[j], z = maxC[k];

                    // Ensure all indices are distinct
                    if (x == y || y == z || z == x)continue;

                    ans = max(ans, (a[x] + b[y] + c[z]));
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}