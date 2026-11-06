# Find Closest Person

**LeetCode ID:** 3516

**Source file(s):** `3516.cpp` (originally `findClosest.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

findClosest/findClosestOptimal/findClosestOneLine(int x,int y,int z). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{distance to x is less, greater, or equal to distance to y?}
    E -- Yes --> F[return corresponding person ID]
    E -- No --> G[none; all cases return immediately]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{distance to x is less, greater, or equal to distance to y?}
    B -- Yes --> C[return corresponding person ID]
    B -- No --> D[none; all cases return immediately]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Compares absolute distances from x and y to z and returns 1, 2, or 0 for person 1, person 2, or tie.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Only the absolute distance to the destination affects the result; the three methods express the same comparison.

## Complexity

O(1) time and space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\3516\3516.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
