# The Two Sneaky Numbers of Digitville

**LeetCode ID:** 3289

**Source file(s):** `3289.cpp` (originally `getSneakyNumbers.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

vector<int> getSneakyNumbers(vector<int>& nums). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{neighboring sorted values are equal?}
    E -- Yes --> F[append duplicate and skip matched pair]
    E -- No --> G[advance]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{neighboring sorted values are equal?}
    B -- Yes --> C[append duplicate and skip matched pair]
    B -- No --> D[advance]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Sorts values and appends a value when adjacent entries match, skipping past the matched pair.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Under the problem constraint each of the two duplicated values appears exactly twice; sorting mutates the input.

## Complexity

O(n log n) time and O(1) auxiliary space beyond output/sort.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\3289\3289.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
