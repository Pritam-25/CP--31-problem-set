#include <bits/stdc++.h>
using namespace std;

/*
! 🤔 Problem Description:
- Given a traffic light cycle string of length `n` containing 'r', 'y', and 'g'.
- You stand at the traffic light showing color `targetColor`.
- The cycle repeats infinitely.
- From any possible position where the light shows `targetColor`,  
  find the **maximum time (in seconds)** you may have to wait until the light turns green ('g').

? 🧠 Approach:
- Duplicate the string (concatenate s + s) to easily handle circular wraparound.
- Iterate from right-to-left, track nearest `'g'` using a variable `nextGreenPosition`.
- For each position in the original string where `s[i] == targetColor`,  
  calculate time to reach next `'g'`.
- Track the **maximum wait time** across all such positions.

*🔰 Why right-to-left:
  - So that for every position we instantly know the next `'g'` ahead.

*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        char targetColor;
        cin >> n >> targetColor;

        string trafficCycle;
        cin >> trafficCycle;

        // Handle circular wraparound by duplicating the string
        trafficCycle += trafficCycle;

        int nextGreenPosition = -1;   // Tracks nearest 'g' position
        int maxWaitTime = 0;          //  Final answer: worst case wait time

        for (int i = trafficCycle.size() - 1; i >= 0; i--) {
            if (trafficCycle[i] == 'g') nextGreenPosition = i;

            // Only consider original n-length portion of the string
            if (i < n && trafficCycle[i] == targetColor && nextGreenPosition != -1) {
                int waitTime = nextGreenPosition - i;
                maxWaitTime = max(maxWaitTime, waitTime);
            }
        }

        cout << maxWaitTime << endl;
    }

    return 0;
}

/*
*⌚ Time Complexity:
    O(n) per test case  
*📦 Space Complexity: 
    O(n) for storing the string
*/
