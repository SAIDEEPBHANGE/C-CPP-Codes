# Divisible and Non-divisible Sums Difference

**LeetCode ID:** 2894
**Source file(s):** `2894.cpp` (originally `differenceOfSums.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

differenceOfSumsOriginal/Optimized(int n,int m). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{integer is divisible by m?}
    E -- Yes --> F[subtract it / compute divisible sum m*k*(k+1)/2]
    E -- No --> G[add nonmultiples / finish formula]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{integer is divisible by m?}
    B -- Yes --> C[subtract it / compute divisible sum m*k*(k+1)/2]
    B -- No --> D[add nonmultiples / finish formula]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Computes sum(nonmultiples of m)-sum(multiples), with a loop and a closed-form arithmetic-series formula.
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Every integer from 1..n belongs to one side; formula subtracts twice the divisible sum from total.

## Complexity

Loop O(n); formula O(1) time and space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\2894\2894.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
