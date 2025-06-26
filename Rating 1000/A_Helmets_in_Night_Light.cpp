#include <bits/stdc++.h>
using namespace std;

/*
! 🤔 Problem Description:
- Notify all `n` residents with minimum total cost.
- Two ways:
    1. Direct inform (cost = `p` per person).
    2. Spread via residents using helmet (spread limit = a[i], cost per spread = b[i]).

? 🧠 Approach:
- Pak Chanek will directly inform at least 1 person → Initial cost = `p`.
- For remaining (n-1) residents:
    - Pick cheapest spreaders (where `b[i] < p`) first.
    - Sort residents by `b[i]`.
    - For each, spread as much as their `a[i]` allows (up to remaining people).
- Any leftover residents after that → Direct inform at cost `p`.

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<pair<int, int>> spreaders;  // {b[i], a[i]}

        for (int i = 0; i < n; i++) {
            if (b[i] < p) {
                spreaders.push_back({b[i], a[i]});
            }
        }

        // Sort spreaders by spread cost (ascending)
        sort(spreaders.begin(), spreaders.end());

        // ✅ Use long long: n*p or n*b[i] can reach ~1e10, avoid int overflow
        long long totalCost = p;  // Initial direct inform
        int remaining = n - 1;    // Remaining residents to inform

        for (int i = 0; i < spreaders.size() && remaining > 0; i++) {
            int costPerSpread = spreaders[i].first;
            int maxSpread = spreaders[i].second;

            int canSpread = min(maxSpread, remaining);

            totalCost += 1LL * canSpread * costPerSpread;
            remaining -= canSpread;
        }

        // If still people remain, use direct inform
        if (remaining > 0) {
            totalCost += 1LL * remaining * p;
        }

        cout << totalCost << '\n';
    }

    return 0;
}

/*
*⌚ Time Complexity:
- O(n log n) (because of sorting)

*📦 Space Complexity:
- O(n)
*/
