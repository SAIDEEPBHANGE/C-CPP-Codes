# Fraction to Recurring Decimal

**LeetCode ID:** 166
**Source file(s):** `166.cpp` (originally `fractionToDecimal.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

string fractionToDecimal(int numerator,int denominator) (free function). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{remainder is zero or was seen before?}
    E -- Yes --> F[finish / insert cycle parentheses]
    E -- No --> G[record remainder, emit digit, continue]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{remainder is zero or was seen before?}
    B -- Yes --> C[finish / insert cycle parentheses]
    B -- No --> D[record remainder, emit digit, continue]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Formats sign and integer part, then records each remainder before multiplying by ten; a repeated remainder marks a decimal cycle with parentheses.
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

A remainder determines all later digits; revisiting it identifies the exact repeating suffix. Denominator is assumed nonzero.

## Complexity

O(d) time and O(d) space for generated digits/remainders.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\166\166.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
