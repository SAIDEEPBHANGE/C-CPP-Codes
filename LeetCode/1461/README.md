# Check If a String Contains All Binary Codes of Size K

**LeetCode ID:** 1461

**Source file(s):** `1461.cpp` (originally `hasAllCodes.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

hasAllCodes_Set/Rolling/Vector(string s,int k). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{completed window has not been seen?}
    E -- Yes --> F[mark code and increment unique count]
    E -- No --> G[leave count unchanged]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{completed window has not been seen?}
    B -- Yes --> C[mark code and increment unique count]
    B -- No --> D[leave count unchanged]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Encodes each length-k bit window and counts distinct values using a set, rolling bitmask hash set, or boolean vector.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Rolling mask retains exactly k bits; success requires all 2^k codes. Boolean vector avoids set overhead.

## Complexity

Rolling/vector O(n) time and O(2^k) space; set variant O(nk log(2^k)).

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\1461\1461.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
