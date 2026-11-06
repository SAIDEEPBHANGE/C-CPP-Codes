# Maximum Distance Between a Pair of Values

**Problem ID:** 1855  
**Source:** `maxDistance1855.cpp`  
**Expected format:** C++ class-method solution with a local demonstration `main()`; see compile guidance below.

## Expected input and output / judge signature

Solution-facing declarations extracted from the source:

- `int maxDistanceTwoPointer(vector<int>& nums1, vector<int>& nums2)`
- `int maxDistanceBinarySearch(vector<int>& nums1, vector<int>& nums2)`
- `int maxDistanceBrute(vector<int>& nums1, vector<int>& nums2)`
  The inputs and return value are described by these parameter and return types. The local `main()` runs test examples; it does not define a judge stdin/stdout protocol.

## Identification evidence

The filename, solution-facing signature, and implemented behavior support the mapping: Compare a monotone two-pointer scan with binary search for the farthest valid second-array index.

## Main flow

Compare a monotone two-pointer scan with binary search for the farthest valid second-array index.

```mermaid
flowchart TD
    S([Start]) --> I[Read the solution inputs]
    I --> P["Compare a monotone two-pointer scan with binary search for the farthest valid second-array index."]
    P --> L{More input positions, candidates, or states?}
    L -- Yes --> T{Does the current item satisfy the algorithm rule?}
    T -- Yes --> U[Update the answer or maintained state]
    T -- No --> N[Keep the invariant and continue]
    U --> L
    N --> L
    L -- No --> R[Return or print the computed result]
    R --> E([End])
```

## Important branch and loop flow

The repeated step processes the next input item, candidate, or state. The branch either applies the algorithm's update or leaves the state unchanged, then continues until no work remains.

```mermaid
flowchart TD
    A[Select the next input item or candidate] --> B{Does it satisfy the solution's condition?}
    B -- Yes --> C[Apply the corresponding state or answer update]
    B -- No --> D[Leave the answer unchanged]
    C --> E[Advance to the next item or state]
    D --> E
    E --> F{Work remains?}
    F -- Yes --> A
    F -- No --> G[Finalize using the stated algorithm]
```

## Core logic and invariant

Compare a monotone two-pointer scan with binary search for the farthest valid second-array index.
After each processed item or recursive state, the algorithm's maintained state represents the work accepted so far under the rule above; the final result is read from that accumulated state or returned by the terminal case.

## Complexity

- **Time:** O(n + m) two pointers.
- **Auxiliary space:** O(1) two pointers.

## Approach comparison

The source contains multiple implementations for comparison:

- `int maxDistanceTwoPointer(vector<int>& nums1, vector<int>& nums2)`
- `int maxDistanceBinarySearch(vector<int>& nums1, vector<int>& nums2)`
- `int maxDistanceBrute(vector<int>& nums1, vector<int>& nums2)`
  The approach described above is the primary strategy; where a direct/brute-force alternative is present, the optimized version reduces repeated work by reusing the state, ordering, or invariant described above. Complexity is qualified by variant where known.

```mermaid
flowchart LR
    A[Direct or brute-force alternative] --> B[Repeated candidate work]
    A --> C[Compare with optimized alternative]
    C --> D[Reuse the problem-specific state or invariant]
    D --> E[Obtain the same result with less repeated work]
```

## Compile and run

This source includes a demonstration `main()` and can be compiled with a C++17 compiler from the repository root:

```powershell
g++ -std=c++17 "LeetCode\1855\1855.cpp" -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, use the relevant method signature above and adapt the local harness: remove the demonstration `main()` and reconcile locally declared node/helper types with judge-provided definitions. Source bytes were preserved exactly during the move.
