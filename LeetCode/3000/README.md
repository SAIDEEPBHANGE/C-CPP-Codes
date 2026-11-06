# Maximum Area of Longest Diagonal Rectangle

**LeetCode ID:** 3000
**Source file(s):** `3000.cpp` (originally `areaOfMaxDiagonal.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

int areaOfMaxDiagonal(vector<vector<int>>& dimensions). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{diagonal exceeds best, or ties it within 1e-9?}
    E -- Yes --> F[replace best diagonal/area, or maximize area on a tie]
    E -- No --> G[leave best unchanged]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{diagonal exceeds best, or ties it within 1e-9?}
    B -- Yes --> C[replace best diagonal/area, or maximize area on a tie]
    B -- No --> D[leave best unchanged]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Scans rectangles, computes each diagonal with sqrt, and retains the area for the longest diagonal, breaking ties by larger area.
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Comparing squared diagonal lengths would avoid sqrt and floating-point tolerance; this implementation uses an epsilon tie check.

## Complexity

O(n) time and O(1) auxiliary space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\3000\3000.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
