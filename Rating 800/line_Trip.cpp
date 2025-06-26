// 🧠 Approach:
// 1. We calculate the maximum gap between any two consecutive gas stations (including 0 to first and last to x).
// 2. The return from last station to x is considered as 2*(x - last_station) because round trip needed.
// 3. The answer is the maximum of all these distances.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int maxDist = a[0];  // Distance from 0 to first gas station

        for (int i = 0; i < n - 1; ++i) {
            maxDist = max(maxDist, a[i + 1] - a[i]);  // Max gap between consecutive stations
        }

        maxDist = max(maxDist, 2 * (x - a[n - 1]));  // Round trip from last station to destination

        cout << maxDist << '\n';
    }

    return 0;
}
