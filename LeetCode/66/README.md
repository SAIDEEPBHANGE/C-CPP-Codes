# Plus One

**Problem ID:** 66  
**Source:** `plusOne.cpp`  
**Expected format:** C++ class-method solution with a local demonstration `main()`; see compile guidance below.

## Expected input and output / judge signature

Solution-facing declarations extracted from the source:

- `long long getNum(const vector<int>& digits, long long sum, int i)`
- `vector<int> numToVec(long long num)`
- `vector<int> plusOne_Approach1(vector<int> digits)`
- `vector<int> plusOne_Approach2(vector<int> digits)`
- `vector<int> plusOne_Approach3(vector<int> digits)`
- `void printVector(const vector<int>& v)`
  The inputs and return value are described by these parameter and return types. The local `main()` runs test examples; it does not define a judge stdin/stdout protocol.

## Identification evidence

The filename, solution-facing signature, and implemented behavior support the mapping: Propagate a carry from the least-significant digit, with alternative numeric conversion approaches.

## Main flow

Propagate a carry from the least-significant digit, with alternative numeric conversion approaches.

```mermaid
flowchart TD
    S([Start]) --> I[Read the solution inputs]
    I --> P["Propagate a carry from the least-significant digit, with alternative numeric conversion approaches."]
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

Propagate a carry from the least-significant digit, with alternative numeric conversion approaches.
After each processed item or recursive state, the algorithm's maintained state represents the work accepted so far under the rule above; the final result is read from that accumulated state or returned by the terminal case.

## Complexity

- **Time:** O(n).
- **Auxiliary space:** O(n).

## Approach comparison

The source contains multiple implementations for comparison:

- `vector<int> plusOne_Approach1(vector<int> digits)`
- `vector<int> plusOne_Approach2(vector<int> digits)`
- `vector<int> plusOne_Approach3(vector<int> digits)`
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
g++ -std=c++17 "LeetCode\66\66.cpp" -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, use the relevant method signature above and adapt the local harness: remove the demonstration `main()` and reconcile locally declared node/helper types with judge-provided definitions. Source bytes were preserved exactly during the move.
