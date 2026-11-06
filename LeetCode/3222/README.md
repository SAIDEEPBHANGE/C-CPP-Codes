# Find the Winning Player in Coin Game — LeetCode 3222

## Problem and judge interface

string winningPlayer(int x, int y); return Alice or Bob for x 75-value coins and y 10-value coins.

## Identification evidence

The code counts min(x,y/4) moves, each consuming one x and four y coins, then uses parity as in problem 3222.

## Main flow

```mermaid
flowchart TD
 A([Start]) --> B[Compute min(x, floor(y/4))]
 B --> C[Determine the parity of the move count]
 C --> D{Is move count odd?}
 D -- Yes --> E[Return Alice]
 D -- No --> F[Return Bob]
 E --> G{More work remains?}
 F --> G
 G -- Yes --> C
 G -- No --> H([Return result])
```

## Important branch / loop

```mermaid
flowchart TD
 A[Compare available x coins and y bundles] --> B{Which resource limits moves?}
 B -- Yes --> C[Use x as maximum]
 B -- No --> D[Use floor(y/4) as maximum]
 C --> E([Continue or return as indicated])
 D --> E
```

## Core logic and invariants

Maximum legal moves are min(x,floor(y/4)). Alternating turns mean Alice wins exactly when this count is odd.

## Complexity

O(1) time and O(1) space.

## Comparison and optimization

Count-and-parity replaces explicit turn simulation because each move consumes the same bundle.

## Compile and run

The `.cpp` is the original standalone source, including its local `main()` demonstration where present. Compile and run from the repository root with a C++17 compiler:

```text
g++ -std=c++17 LeetCode\3222\3222.cpp -o solution.exe
.\solution.exe
```

For LeetCode, adapt the implementation to the required class/method signature and omit the local `main()` and demonstration helpers; use the judge-provided node types. Notes above identify method-name or behavior differences. The moved source bytes have not been edited.
