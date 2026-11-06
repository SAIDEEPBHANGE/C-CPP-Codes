# Design a Food Rating System

**LeetCode ID:** 2353

**Source file(s):** `2353.cpp` (originally `FoodRatings.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

FoodRatings(foods,cuisines,ratings); changeRating; highestRated. Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{rating update requested?}
    E -- Yes --> F[erase old key and insert new one]
    E -- No --> G[highestRated reads first ordered entry]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{rating update requested?}
    B -- Yes --> C[erase old key and insert new one]
    B -- No --> D[highestRated reads first ordered entry]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Maps foods to ratings/cuisines and stores each cuisine's items in an ordered set keyed by negative rating then name.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Set order keeps the highest rating first and lexicographically smallest name first on ties.

## Complexity

Construction O(n log n), change O(log f), highestRated O(1) at set begin; O(n) storage.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\2353\2353.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
