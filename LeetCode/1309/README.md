# Decrypt String from Alphabet to Integer Mapping

**LeetCode ID:** 1309
**Source file(s):** `1309.cpp` (originally `freqAlphabets.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

string freqAlphabets(string s). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{third character from current position is #?}
    E -- Yes --> F[decode two digits and advance three]
    E -- No --> G[decode one digit and advance one]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{third character from current position is #?}
    B -- Yes --> C[decode two digits and advance three]
    B -- No --> D[decode one digit and advance one]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Scans left-to-right; a two-digit token followed by # maps 10..26 to j..z, otherwise one digit maps 1..9 to a..i.
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

The # marker makes tokenization unambiguous; greedy lookahead avoids a token list.

## Complexity

O(n) time and O(n) output space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\1309\1309.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
