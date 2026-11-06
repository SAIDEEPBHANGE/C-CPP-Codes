# Count the Number of Complete Components

**LeetCode ID:** 2685
**Source file(s):** `2685.cpp` (originally `countCompleteComponents.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

int countCompleteComponents(int n, vector<vector<int>>& edges). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{component adjacency-entry total equals nodes*(nodes-1)?}
    E -- Yes --> F[increment complete-component count]
    E -- No --> G[leave count unchanged]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{component adjacency-entry total equals nodes*(nodes-1)?}
    B -- Yes --> C[increment complete-component count]
    B -- No --> D[leave count unchanged]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Builds an undirected adjacency list, DFSes each component, counts vertices and directed adjacency entries, then checks entries == v\*(v-1).
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Each undirected edge contributes two adjacency entries, so a complete component has v(v-1) entries.

## Complexity

O(n+m) time and O(n+m) space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\2685\2685.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
