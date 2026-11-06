# Lexicographically Smallest Equivalent String — LeetCode 1061

## Problem and judge interface

string smallestEquivalentString(string s1, string s2, string baseStr); paired letters define equivalence and each base character maps to its smallest equivalent.

## Identification evidence

The function unions lowercase-letter equivalence classes and rewrites baseStr using the minimum representative, uniquely identifying problem 1061.

## Main flow

```mermaid
flowchart TD
 A([Start]) --> B[Initialize 26 DSU roots]
 B --> C[Union roots for each aligned letter pair]
 C --> D{Do the pair roots differ?}
 D -- Yes --> E[Attach larger root beneath smaller root]
 D -- No --> F[Leave the component unchanged]
 E --> G{More work remains?}
 F --> G
 G -- Yes --> C
 G -- No --> H([Return result])
```

## Important branch / loop

```mermaid
flowchart TD
 A[For a paired character] --> B{Are the two roots equal?}
 B -- Yes --> C[No union needed]
 B -- No --> D[Link the larger root to the smaller]
 C --> E([Continue or return as indicated])
 D --> E
```

## Core logic and invariants

The DSU has 26 roots. Union attaches the larger root to the smaller, preserving the smallest letter as canonical representative. The optimized find uses path compression; the original copies the parent vector and does not compress paths.

## Complexity

Optimized: O((length(s1)+length(baseStr)) alpha(26)) time in practice and O(26) space. Original find can traverse longer chains and copies parent storage.

## Comparison and optimization

Path compression and reference-based find avoid repeated copying and shorten paths.

## Compile and run

The `.cpp` is the original standalone source, including its local `main()` demonstration where present. Compile and run from the repository root with a C++17 compiler:

```text
g++ -std=c++17 LeetCode\1061\1061.cpp -o solution.exe
.\solution.exe
```

For LeetCode, adapt the implementation to the required class/method signature and omit the local `main()` and demonstration helpers; use the judge-provided node types. Notes above identify method-name or behavior differences. The moved source bytes have not been edited.
