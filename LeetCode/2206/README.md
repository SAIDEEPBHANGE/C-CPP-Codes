# Divide Array Into Equal Pairs

**LeetCode ID:** 2206
**Source file(s):** `2206.cpp` (originally `DivideArrPairs.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

divideArraySorting/Frequency(vector<int>& nums). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{a value has odd frequency / sorted pair differs?}
    E -- Yes --> F[return false]
    E -- No --> G[continue; return true if all groups pass]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{a value has odd frequency / sorted pair differs?}
    B -- Yes --> C[return false]
    B -- No --> D[continue; return true if all groups pass]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Checks whether every value occurs an even number of times using sorted adjacent pairs or a frequency map.
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Every value must occur evenly; frequency counting avoids sorting, while sorting directly exhibits pairs.

## Complexity

Sorting O(n log n); frequency expected O(n) time and O(u) space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\2206\2206.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
