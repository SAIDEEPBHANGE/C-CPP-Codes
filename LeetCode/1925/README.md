# Count Square Sum Triples

**LeetCode ID:** 1925
**Source file(s):** `1925.cpp` (originally `countTriples.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

int countTriples(int n). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{a^2+b^2  less than or equal to  n^2 and sum is marked square?}
    E -- Yes --> F[increment result]
    E -- No --> G[skip pair]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{a^2+b^2  less than or equal to  n^2 and sum is marked square?}
    B -- Yes --> C[increment result]
    B -- No --> D[skip pair]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Precomputes square values up to n^2, then tests ordered positive a,b pairs for a^2+b^2 being a square within the bound.
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Ordered pairs are intentionally counted separately; the lookup table makes each pair check constant time.

## Complexity

O(n^2) time and O(n^2) space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\1925\1925.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
