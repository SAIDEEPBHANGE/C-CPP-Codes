# Maximum Matrix Sum — LeetCode 1975

## Problem, constraints आणि examples

A move flips signs of two adjacent matrix cells. Maximize the sum after any number of moves; cells connect through the matrix's adjacency graph. Matrix has at least one cell.
Example: `[[1,-1],[-1,1]]`: two negatives (even), all magnitudes can be positive → sum `4`. `[-1,0,2]`: odd negative parity but min magnitude is zero, so sum of magnitudes `3` is attainable.

## Pattern clues

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | operation flips a pair of signs | parity invariant |
> | values change sign, not magnitude | sum absolute values |
> | odd negative count forces one residual negative | smallest magnitude penalty |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Status | Cost |
> |---|---|---|
> | Sum absolute values, track negative parity and min magnitude | Selected `O(RC)` / `O(1)` |
> | Explicitly apply flips/search states | Correct for tiny matrices, exponential and unnecessary |
> | Always make every value positive | Incorrect when negative count odd and no zero |
> | Track only negative count, ignore minimum magnitude | Incorrect; penalty depends on smallest absolute value |

## Flowchart

> **मराठी:** Flowchart मधील decision, loop आणि termination condition क्रमाने समजून घ्या.

```mermaid
flowchart TD
    A[sumAbs=0; odd=false; minAbs=large] --> B[Scan each cell x]
    B --> C[Add abs(x); update minAbs]
    C --> D{ x negative? }
    D -- Yes --> E[Toggle odd parity]
    D -- No --> F[Keep parity]
    E --> G{More cells?}
    F --> G
    G -- Yes --> B
    G -- No --> H{odd negatives?}
    H -- No --> I[Return sumAbs]
    H -- Yes --> J[Return sumAbs - 2*minAbs]
```

Pair flips preserve negative-count parity; if odd, one value must remain negative, and the smallest magnitude minimizes loss.

## Selected algorithm, code, dry run

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> `maxMatrixSumApproach2` accumulates `llabs(x)`, toggles `oddNegatives` for each negative, and tracks `minAbs`; final correction is `2*minAbs` only for odd parity. Approach1 counts negatives explicitly and uses `abs`; both are equivalent. `main` copies matrices for comparing methods.
> Dry run (`[-1,0,2]`): absolute sum `3`, negative parity odd, minimum absolute value `0`; answer `3-2*0=3`.

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> Even negative parity needs no penalty; odd parity with a zero also has no penalty; a one-cell matrix is valid.

## Complexity, correctness, traps

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> `O(RC)` time, `O(1)` auxiliary; input is passed by reference. Correctness: each pair operation toggles sign parity of two cells so parity of total negatives is invariant; all but possibly one sign can be positive. If one remains negative, placing it on minimum magnitude maximizes total.
> Trap: zero makes odd parity penalty zero; use `long long` for accumulated sum. Source has `abs(int)` in Approach1; constraints avoid `INT_MIN`.

## Quick revision, variations, self-check

पुनरावलोकन: absolute sum आणि negative parity लक्षात ठेवा.
Sum abs, parity of negatives, minimum abs; subtract twice min iff parity odd. Related: parity invariants, sign flips, greedy minimum penalty.

1. Why does pair flipping preserve negative parity?
2. What is the penalty for one negative of magnitude `m`?
3. What role does a zero play?
4. Why is `long long` used for sum?
