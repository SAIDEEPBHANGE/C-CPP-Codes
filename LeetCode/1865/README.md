# Finding Pairs With a Certain Sum

**LeetCode ID:** 1865

**Source file(s):** `1865.cpp` (originally `FindSumPairs.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

FindSumPairs(nums1,nums2); add(index,val); count(tot). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{complement tot-nums1()i() exists?}
    E -- Yes --> F[add its multiplicity]
    E -- No --> G[continue scan]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{complement tot-nums1()i() exists?}
    B -- Yes --> C[add its multiplicity]
    B -- No --> D[continue scan]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Maintains a frequency table for nums2; add updates old/new frequency and count scans nums1 for matching complements.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

freq2 always reflects current nums2; multiplicity accounts for all index pairs.

## Complexity

Constructor O(n2), add expected O(1), count O(n1) expected; O(u2) frequencies.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\1865\1865.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
