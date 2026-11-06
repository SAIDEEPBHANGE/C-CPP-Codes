# Smallest Missing Non-negative Integer After Operations

**LeetCode ID:** 2598
**Source file(s):** `2598.cpp` (originally `findSmallestInteger.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

int findSmallestInteger(vector<int>& nums,int value). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{count()k mod value() is zero?}
    E -- Yes --> F[return k]
    E -- No --> G[decrement residue count and advance]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{count()k mod value() is zero?}
    B -- Yes --> C[return k]
    B -- No --> D[decrement residue count and advance]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Counts normalized modulo-value residues (including negatives), then consumes residue counts in ascending candidate order until one is exhausted.
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Each input number supplies one candidate with its residue; no number is consumed twice.

## Complexity

O(n+MEX) expected time and O(value) possible residue storage.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\2598\2598.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
