# Apply Operations to an Array

**LeetCode ID:** 2460
**Source file(s):** `2460.cpp` (originally `ApplyOperations.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

vector<int> applyOperations(vector<int>& nums). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{adjacent values match and are nonzero / current slot is zero?}
    E -- Yes --> F[merge the pair / move zero to the end]
    E -- No --> G[advance without changing values]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{adjacent values match and are nonzero / current slot is zero?}
    B -- Yes --> C[merge the pair / move zero to the end]
    B -- No --> D[advance without changing values]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Doubles equal adjacent nonzero values and zeroes the right slot, then erases each zero and appends it to the end. Class and free-function copies are present.
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Write-pointer compaction would be linear; the included erase-based version is simpler but shifts elements.

## Complexity

Merge pass O(n); repeated vector erases make compaction O(n^2) worst case; O(1) auxiliary space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\2460\2460.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
