# Number of Ways to Arrive at Destination

**LeetCode ID:** 1976

**Source file(s):** `1976.cpp` (originally `countPaths.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

int countPaths(int n,vector<vector<int>>& roads) (free function). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{candidate distance is shorter or equal to known shortest distance?}
    E -- Yes --> F[replace distance/ways, or add ways modulo MOD]
    E -- No --> G[ignore stale or longer candidate]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{candidate distance is shorter or equal to known shortest distance?}
    B -- Yes --> C[replace distance/ways, or add ways modulo MOD]
    B -- No --> D[ignore stale or longer candidate]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Builds a weighted undirected graph and runs Dijkstra while tracking shortest-path counts modulo 1e9+7.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

A shorter route resets ways; equal shortest routes accumulate, without enumerating paths.

## Complexity

O((n+m) log n) time and O(n+m) space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\1976\1976.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
