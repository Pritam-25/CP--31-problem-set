/*
!🤔 Problem Description:
- Given an array of n integers.
- You can perform at most k operations. In each operation, you can increase any array element by 1.
- Each number's beauty = number of 1s in its binary representation.
- Goal: Maximize total beauty (sum of 1s across the whole array) after at most k operations.

?🧠 Approach:
1. Calculate the initial beauty (count of 1s in the array using __builtin_popcountll).
2. For each bit from 0 to 60:
    - For each element:
        - If this bit is currently OFF and we have enough k left to turn it ON:
            - Spend the required k (cost = 2^bit).
            - Increase beauty by 1.
    - Break early if k becomes 0 to save time.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> array(n);
        long long totalBeauty = 0;

        // Step 1: Calculate initial beauty (number of 1s)
        for (int i = 0; i < n; i++) {
            cin >> array[i];
            totalBeauty += __builtin_popcountll(array[i]);
        }

        // Step 2: Try setting bits starting from least significant bit
        for (int bit = 0; bit <= 60; bit++) {
            long long costToSetBit = (1LL << bit);  // Cost to set this bit (2^bit)

            for (int i = 0; i < n; i++) {
                // If this bit is currently OFF and we can afford the cost
                if ((array[i] & costToSetBit) == 0 && k >= costToSetBit) {
                    totalBeauty += 1;   // Gain 1 more beauty
                    k -= costToSetBit;  // Reduce available operations

                    if (k == 0) break;  // No more operations left, break inner loop
                }
            }
            if (k == 0) break;  // Fully used up k, break outer loop too
        }

        // Output the final beauty for this test case
        cout << totalBeauty << "\n";
    }

    return 0;
}

/*
*⌚ Time Complexity:
- O(n * 61)
- Because we check at most 61 bits (bit positions 0 to 60) for each of n elements.

*📦 Space Complexity:
- O(n)
- Only need to store the array of size n.
*/

/*
?🔰 Example of Bit Checking:
Suppose:
    array[i] = 5;   // Binary: 101
    bit = 1;        // Checking 2nd bit (zero-indexed)

!Check if bit 1 is ON or OFF:
    * Step 1: 
    Calculate mask → (1LL << bit) = (1LL << 1) = 2 → Binary: 010
    * Step 2: Check → (array[i] & mask)
    (5 & 2) → (101 & 010) → 0 → Means bit 1 is OFF (0).
    * Step 3: So condition:
        if ((array[i] & (1LL << bit)) == 0)
        → TRUE → Means this bit is currently OFF and can be turned ON if k allows.
*/