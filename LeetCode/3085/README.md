# Minimum Deletions to Make String K-Special

**Problem ID:** 3085  
**Source:** `minimumDeletions.cpp`  
**Expected format:** C++ class-method solution with a local demonstration `main()`; see compile guidance below.

## Expected input and output / judge signature

Solution-facing declarations extracted from the source:

- `int minDel_V1(const string& word, int k)`
- `int minDel_V2(const string& word, int k)`
- `int minDel_V3(const string& word, int k)`
- `int minDel_V4(const string& word, int k)`
- `int minDel_V5(const string& word, int k)`
- `int minimumDeletions(string word, int k, int version = 5)`

The inputs and return value are described by these parameter and return types. The local `main()` runs test examples; it does not define a judge stdin/stdout protocol.

## Identification evidence

The filename, solution-facing signature, and implemented behavior support the mapping: Count letter frequencies and choose a baseline, deleting characters outside a k-wide retained-frequency range.

## Main flow

Count letter frequencies and choose a baseline, deleting characters outside a k-wide retained-frequency range.

```mermaid
flowchart TD
    S([Start]) --> I[Read the solution inputs]
    I --> P["Count letter frequencies and choose a baseline, deleting characters outside a k-wide retained-frequency range."]
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

Count letter frequencies and choose a baseline, deleting characters outside a k-wide retained-frequency range.

After each processed item or recursive state, the algorithm's maintained state represents the work accepted so far under the rule above; the final result is read from that accumulated state or returned by the terminal case.

## Complexity

- **Time:** O(26^2) fixed alphabet.
- **Auxiliary space:** O(26).

## Approach comparison

The source contains multiple implementations for comparison:

- `int minDel_V1(const string& word, int k)`
- `int minDel_V2(const string& word, int k)`
- `int minDel_V3(const string& word, int k)`
- `int minDel_V4(const string& word, int k)`
- `int minDel_V5(const string& word, int k)`

The approach described above is the primary strategy; where a direct/brute-force alternative is present, the optimized version reduces repeated work by reusing the state, ordering, or invariant described above. Complexity is qualified by variant where known.

```mermaid
flowchart LR
    A[Direct or brute-force alternative] --> B[Repeated candidate work]
    A --> C[Compare with optimized alternative]
    C --> D[Reuse the problem-specific state or invariant]
    D --> E[Obtain the same result with less repeated work]
```

## Compile and run

This source includes a demonstration `main()` and can be compiled with a C++17 compiler from the repository root:

```powershell
g++ -std=c++17 "LeetCode\3085\3085.cpp" -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, use the relevant method signature above and adapt the local harness: remove the demonstration `main()` and reconcile locally declared node/helper types with judge-provided definitions. Source bytes were preserved exactly during the move.