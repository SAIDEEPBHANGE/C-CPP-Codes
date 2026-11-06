# Check if Grid can be Cut into Sections

**LeetCode ID:** 3394

**Source file(s):** `3394.cpp` (originally `checkValidCuts.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

bool checkValidCuts(int n, vector<vector<int>>& rectangles). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{event opens/closes an interval; active count returns to zero?}
    E -- Yes --> F[update active count / count a separated component]
    E -- No --> G[continue sweeping]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{event opens/closes an interval; active count returns to zero?}
    B -- Yes --> C[update active count / count a separated component]
    B -- No --> D[continue sweeping]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Creates start/end events on both axes, sorts each list, and counts separated active intervals; succeeds if either axis forms at least three sections.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Two axis sweeps turn rectangle grouping into interval-component counting; ends sort before starts at equal coordinates.

## Complexity

O(r log r) time and O(r) space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\3394\3394.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
