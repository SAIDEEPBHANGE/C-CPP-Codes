# Longest Unequal Adjacent Groups Subsequence I

**LeetCode ID:** 2900

**Source file(s):** `2900.cpp` (originally `getLongestSubsequence.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

vector<string> getLongestSubsequence(words,groups). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{current group differs from last selected group?}
    E -- Yes --> F[append word and update last group]
    E -- No --> G[skip word]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{current group differs from last selected group?}
    B -- Yes --> C[append word and update last group]
    B -- No --> D[skip word]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Keeps the first word and each later word whose group differs from the last selected group.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Selected adjacent groups alternate; taking every change maximizes the subsequence length.

## Complexity

O(n) time and O(n) output space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\2900\2900.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
