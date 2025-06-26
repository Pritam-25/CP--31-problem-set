// 🧠 Approach:
// 1. If k == 1, we can only perform the operation on one element → sorting is only possible if the array is already sorted.
// 2. If k > 1, we can swap more freely → it's always possible to sort the array.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;  // number of test cases
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), sorted_a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sorted_a[i] = a[i];  // Copy of original array
        }

        sort(sorted_a.begin(), sorted_a.end());  // Sorted version for comparison

        if (k == 1 && a != sorted_a) {
            // If only 1 operation allowed and not already sorted → impossible
            cout << "NO\n";
        } else {
            // If k > 1 or already sorted → always possible
            cout << "YES\n";
        }
    }

    return 0;
}
