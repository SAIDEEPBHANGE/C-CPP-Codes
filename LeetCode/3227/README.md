# Vowels Game in a String

**LeetCode ID:** 3227

**Source file(s):** `3227.cpp` (originally `doesAliceWin.cpp`)

**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

doesAliceWinLoop/Lambda(const string& s). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{character is lowercase a/e/i/o/u?}
    E -- Yes --> F[return true]
    E -- No --> G[continue; return false if none]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{character is lowercase a/e/i/o/u?}
    B -- Yes --> C[return true]
    B -- No --> D[continue; return false if none]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Returns true iff at least one lowercase vowel occurs; one implementation loops and one uses any_of.

The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Under the problem's lowercase input constraint, game outcome is determined by vowel presence; direct scan avoids temporary string construction.

## Complexity

O(n) time and O(1) extra space.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\3227\3227.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
