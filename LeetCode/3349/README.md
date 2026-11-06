# Adjacent Increasing Subarrays Detection I

**LeetCode ID:** 3349

**Source file(s):** `3349.cpp` (originally `hasIncreasingSubarrays.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

hasIncreasingSubarrays(const vector<int>& nums,int k) (free function). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{both adjacent windows strictly increase?}
    E -- Yes --> F[return true]
    E -- No --> G[continue; return false if no start works]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{both adjacent windows strictly increase?}
    B -- Yes --> C[return true]
    B -- No --> D[continue; return false if no start works]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Tries each start where two adjacent length-k windows fit and checks both windows for strict increase.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Windows are adjacent, non-overlapping, equal length; precomputed increasing-run lengths could reduce repeated checks to O(n).

## Complexity

O(nk) time and O(1) auxiliary space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\3349\3349.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
