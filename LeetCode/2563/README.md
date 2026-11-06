# Count the Number of Fair Pairs

**LeetCode ID:** 2563
**Source file(s):** `2563.cpp` (originally `countFairPairs.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

long long countFairPairs(vector<int>& nums,int lower,int upper). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{partner sum lies in ()lower,upper()?}
    E -- Yes --> F[add upper-bound index minus lower-bound index]
    E -- No --> G[advance i]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{partner sum lies in ()lower,upper()?}
    B -- Yes --> C[add upper-bound index minus lower-bound index]
    B -- No --> D[advance i]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Sorts values; for each i, binary-searches the allowable partner range [lower-nums[i], upper-nums[i]] among later indices.
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Searching only j>i counts each unordered pair once; sorting plus binary search replaces quadratic enumeration.

## Complexity

O(n log n) time and O(1) extra space apart from sorting.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\2563\2563.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
