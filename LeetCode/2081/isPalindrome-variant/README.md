# K-Mirror Numbers

**Problem ID:** 2081  
**Source:** `isPalindrome.cpp`  
**Expected format:** C++ class-method solution with a local demonstration `main()`; see compile guidance below.

> **Collision handling:** kMirror.cpp is a second verified implementation of problem 2081. This source is kept in a named variant subfolder so the required 2081.cpp is not overwritten.

## Expected input and output / judge signature

Solution-facing declarations extracted from the source:

- `bool isPalindrome(string baseK)`
- `string convertToBaseK(long long num, int k)`
- `long long kMirror(int k, int n)`

The inputs and return value are described by these parameter and return types. The local `main()` runs test examples; it does not define a judge stdin/stdout protocol.

## Identification evidence

The filename, solution-facing signature, and implemented behavior support the mapping: Generate decimal palindromes by length and accumulate those whose base-k digits are also palindromic.

## Main flow

Generate decimal palindromes by length and accumulate those whose base-k digits are also palindromic.

```mermaid
flowchart TD
    S([Start]) --> I[Read the solution inputs]
    I --> P["Generate decimal palindromes by length and accumulate those whose base-k digits are also palindromic."]
    P --> L{More input positions, candidates, or states?}
    L -- Yes --> T{Does the current item satisfy the algorithm rule?}
    T -- Yes --> U[Update the answer or maintained state]
    T -- No --> N[Keep the invariant and continue]
    U --> L
    N --> L
    L -- No --> R[Return or print the computed result]
    R --> E([End])
```

## Important branch and loop flow

The repeated step processes the next input item, candidate, or state. The branch either applies the algorithm's update or leaves the state unchanged, then continues until no work remains.

```mermaid
flowchart TD
    A[Select the next input item or candidate] --> B{Does it satisfy the solution's condition?}
    B -- Yes --> C[Apply the corresponding state or answer update]
    B -- No --> D[Leave the answer unchanged]
    C --> E[Advance to the next item or state]
    D --> E
    E --> F{Work remains?}
    F -- Yes --> A
    F -- No --> G[Finalize using the stated algorithm]
```

## Core logic and invariant

Generate decimal palindromes by length and accumulate those whose base-k digits are also palindromic.

After each processed item or recursive state, the algorithm's maintained state represents the work accepted so far under the rule above; the final result is read from that accumulated state or returned by the terminal case.

## Complexity

- **Time:** O(C * d), where C is the number of decimal-palindrome candidates tested and d is the candidate digit length.
- **Auxiliary space:** O(d) for the current candidate and its base-k representation.


## Compile and run

This source includes a demonstration `main()` and can be compiled with a C++17 compiler from the repository root:

```powershell
g++ -std=c++17 "LeetCode\2081\isPalindrome-variant\isPalindrome-variant.cpp" -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, use the relevant method signature above and adapt the local harness: remove the demonstration `main()` and reconcile locally declared node/helper types with judge-provided definitions. Source bytes were preserved exactly during the move.