/*
!🤔 Problem Description:
- Given 3 rectangles with dimensions:
  - l1 × b1
  - l2 × b2
  - l3 × b3
- You need to check whether you can arrange all 3 rectangles (without rotation and no overlap) to form a perfect square.
- Rectangles must align along the edges (no diagonal placements).

?🧠 Approach:
- Since rectangles can't rotate and are sorted (`l3 ≤ l2 ≤ l1`, `b3 ≤ b2 ≤ b1`), there are only 4 meaningful layout patterns possible.
- For each test case, check all 4 layout conditions:

    1. Three rectangles placed horizontally (one above another).
    2. Two small rectangles placed side by side below one big rectangle.
    3. Three rectangles stacked vertically (one beside another).
    4. Two small rectangles stacked vertically beside one big rectangle.

- For each case:
  - Check relevant dimension conditions (lengths and breadths) to confirm if the total shape becomes a square.

*⌚ Time Complexity:
- O(1) per test case.

*📦 Space Complexity:
- O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

        bool possible = false;

        // Case 1: Three rectangles placed horizontally (one above another)
        if (l1 + l2 + l3 == b1 && b1 == b2 && b2 == b3)
            possible = true;

        //  Case 2: Two small rectangles beside one big (Big on top, two small below)
        else if (l2 + l3 == l1 && b2 == b3 && b1 + b2 == l1)
            possible = true;

        //  Case 3: Three rectangles stacked vertically (one beside another)
        else if (b1 + b2 + b3 == l1 && l1 == l2 && l2 == l3)
            possible = true;

        //  Case 4: Two small rectangles stacked below one big (Big on left, two small on right)
        else if (b2 + b3 == b1 && l2 == l3 && l1 + l2 == b1)
            possible = true;

        cout << (possible ? "YES" : "NO") << "\n";
    }

    return 0;
}

/*
?============ 🔎 All 4 Case Diagrams Summary ============

*Case 1: Three rectangles placed horizontally (one above another)

+----------------+
|     Rect 1     |  ← (l1 × b1)
+----------------+
|     Rect 2     |  ← (l2 × b2)
+----------------+
|     Rect 3     |  ← (l3 × b3)
+----------------+

--------------------------------------------------------

*Case 2: Two small rectangles beside one big (Big on top, two small below)

+---------------+
| Big Rectangle |
|               |  ← (l1 × b1)
+-------+-------+
| Small | Small |
| Rect 2| Rect3 |  ← (l2 × b2), (l3 × b3)
+-------+-------+

--------------------------------------------------------

*Case 3: Three rectangles stacked vertically (side by side)

+---------------+
|     Rect 1    |  ← (l1 × b1)
+---------------+
|     Rect 2    |  ← (l2 × b2)
+---------------+
|     Rect 3    |  ← (l3 × b3)
+---------------+

--------------------------------------------------------

*Case 4: Two small rectangles stacked vertically beside one big (Big on left, two small on right)

+---------------+
|   Big Rect    |
|               |     ← (l1 × b1)
+-------+-------+
|Rect 2 | Rect 3|
|               |    ← (l2 × b2), (l3 × b3)
+-------+-------+

*/
