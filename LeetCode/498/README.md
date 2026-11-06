# Diagonal Traverse

**LeetCode ID:** 498

**Source file(s):** `498.cpp` (originally `findDiagonalOrder.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

vector<int> findDiagonalOrder(vector<vector<int>>& mat). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{diagonal index is even or odd?}
    E -- Yes --> F[walk up-right / down-left]
    E -- No --> G[advance to next diagonal]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{diagonal index is even or odd?}
    B -- Yes --> C[walk up-right / down-left]
    B -- No --> D[advance to next diagonal]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Enumerates diagonals by constant row+column sum, alternating upward-right and downward-left.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Every cell has one diagonal index and is appended once; no coordinate sorting is needed.

## Complexity

O(mn) time and O(1) auxiliary space beyond output.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\498\498.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
