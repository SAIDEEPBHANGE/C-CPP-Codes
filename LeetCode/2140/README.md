# Solving Questions With Brainpower

**LeetCode ID:** 2140
**Source file(s):** `2140.cpp` (originally `FindMaxPointsmostPoints.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

long long mostPoints(vector<vector<int>>& questions). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{take question or skip it?}
    E -- Yes --> F[add points and recurse at i+brainpower+1]
    E -- No --> G[recurse at i+1]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{take question or skip it?}
    B -- Yes --> C[add points and recurse at i+brainpower+1]
    B -- No --> D[recurse at i+1]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Memoized recursion chooses skipping a question or taking its points then jumping past the brainpower cooldown.
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

memo[i] stores best score from suffix i onward; memoization computes each index once.

## Complexity

O(n) time and O(n) memo plus recursion-stack space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\2140\2140.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
