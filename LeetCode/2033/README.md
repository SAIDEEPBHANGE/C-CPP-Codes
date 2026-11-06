# Minimum Operations to Make a Uni-Value Grid

**LeetCode ID:** 2033

**Source file(s):** `2033.cpp` (originally `Flatten_minOperations.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

int minOperations(vector<vector<int>>& grid,int x). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{all remainders match / cell distance to median?}
    E -- Yes --> F[compute median operation count / add distance]
    E -- No --> G[return -1 if incompatible]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{all remainders match / cell distance to median?}
    B -- Yes --> C[compute median operation count / add distance]
    B -- No --> D[return -1 if incompatible]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Flattens the grid, checks all values share a remainder modulo x, sorts, then sums step distances to the median.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Equal residues are necessary and sufficient; median minimizes total absolute deviations.

## Complexity

O(N log N) time and O(N) space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\2033\2033.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
