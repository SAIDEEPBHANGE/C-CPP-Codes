# Binary Gap

**LeetCode ID:** 868

**Source file(s):** `868.cpp` (originally `binaryGap.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

binaryGap_bitset(int), binaryGap_bitwise(int), binaryGap_string(int). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{current bit is 1 and a previous 1 exists?}
    E -- Yes --> F[update maximum gap and last-one index]
    E -- No --> G[advance bit position]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{current bit is 1 and a previous 1 exists?}
    B -- Yes --> C[update maximum gap and last-one index]
    B -- No --> D[advance bit position]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Tracks consecutive set-bit positions and maximizes their distance; compares fixed bitset, right-shift, and binary-string versions.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Bitwise scanning avoids allocating and reversing the binary string; bitset cost is fixed for 32-bit input.

## Complexity

Bitwise O(log n) time/O(1) space; bitset O(32); string version O(log n) space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\868\868.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
