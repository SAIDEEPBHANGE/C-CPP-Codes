# Minimum Operations to Make a Uni-Value Grid — LeetCode 2033

## Problem, constraints आणि examples

One operation adds/subtracts `x` from one grid cell. Make all values equal with minimum operations, or return `-1` if impossible. Grid is non-empty and `x>0`.
Example: `[1,2,3]`, `x=1` → median `2`; changes are `1+0+1=2`. With `x=2`, values `1` and `2` have different residues mod 2, so impossible → `-1`.

## Pattern clues

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | each operation changes value by fixed step `x` | residue invariant |
> | all targets require sum of absolute distances | median minimizes L1 distance |
> | 2D cells independent after flattening | flatten + sort |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Status | Cost |
> |---|---|---|
> | Check common residue, choose median, sum step counts | Selected `O(N log N)` time, `O(N)` space |
> | Try every possible target | Correct but slow; target range can be large |
> | Choose arithmetic mean | Incorrect in general; absolute-distance sum is minimized by median |
> | Skip residue check and divide differences | Incorrect when difference is not divisible by `x` |

## Flowchart

```mermaid
flowchart TD
    A[Flatten grid] --> B[Take first value residue mod x]
    B --> C{Every value same residue?}
    C -- No --> Z[Return -1]
    C -- Yes --> D[Sort flattened values]
    D --> E[Choose middle value as median]
    E --> F[Sum abs(value-median)/x]
    F --> G[Return operations]
```

Same residue असल्यास सर्व pairwise differences `x` ने divisible; median minimizes total absolute adjustment.

## Selected algorithm, source-specific explanation, dry run

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> `Flatten` copies grid values into `fg`. `minOperations` stores `fg[0]%x`, rejects any different residue, sorts, selects `fg[size/2]`, and sums `abs(fg[i]-median)/x`. Source requires non-empty grid; main demonstrates `x=1`.
> Dry run (`[1,2,3]`, `x=1`):
> | Sorted value | Distance from 2 | Operations |
> |---:|---:|---:|
> | 1 | 1 | 1 |
> | 2 | 0 | 0 |
> | 3 | 1 | 1 |
> | Total | — | 2 |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> A one-cell grid needs 0 operations; x=1 always passes residue compatibility; mismatched residues return -1.

## Complexity, correctness, traps

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> For `N=m*n`: flatten/residue check `O(N)`, sort `O(N log N)`, sum `O(N)`; total `O(N log N)` time, `O(N)` space. Correctness: modular residue is invariant under ±x; if compatible, each unit step costs equal per `x`, and median minimizes sum absolute differences.
> Trap: check feasibility before choosing target; use middle after sorting; for even N either middle is optimal. Source uses `int` operation sum, within given constraints.

## Quick revision, variations, self-check

पुनरावलोकन: residue जुळल्यावर medianकडे values हलवा.
Flatten; equal residue; median; sum distance divided by `x`. Related: L1 median, modular invariants, equalization by fixed increments.

1. Why must residues match?
2. Why is median preferred over mean?
3. What is cost for value equal to median?
4. If `x=2` and values are 1,3,5, possible?
