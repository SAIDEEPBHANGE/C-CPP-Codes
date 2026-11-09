# Count Good Triplets — LeetCode 1534

## Problem, constraints आणि examples

Distinct indices `i < j < k` निवडा. तिन्ही conditions true असतील तर triplet count करा: `|arr[i]-arr[j]|≤a`, `|arr[j]-arr[k]|≤b`, `|arr[i]-arr[k]|≤c`. Array values non-negative; अनेक indicesचे values समान असू शकतात.
Example: `[3,0,1,1,9,7]`, `(a,b,c)=(7,2,3)`: `(0,1,2)` values `(3,0,1)` satisfy `3≤7, 1≤2, 2≤3`, so countमध्ये `1`. `a=b=c=0` असल्यास फक्त तिन्ही values equal असलेले index-triplets qualify.

## Pattern clues

| Clue                             | Pattern                           |
| -------------------------------- | --------------------------------- |
| तीन ordered indices              | nested loops / combinations       |
| pairwise threshold checks        | early pruning                     |
| प्रत्येक valid combination मोजणे | enumeration, not greedy selection |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Correct? | Cost |
> |---|---|---|
> | Three nested loops + prune | Yes; selected, `O(n³)` worst, `O(1)` extra |
> | Backtracking all 3-index combinations | Yes; source recursive method, `O(n³)` combinations, `O(1)` depth/selection |
> | Check all pairs only / sort and greedily choose | No | all three pair constraints and original indices matter |
> | Enumerate all subsets then inspect | Correct but more work | `O(2ⁿ)` vs only triples |
> Source's “iterative greedy” is enumeration, not a greedy optimization.

## Flowchart

```mermaid
flowchart TD
    A[Choose i from 0 to n-3] --> B[Choose j greater than i]
    B --> C{abs(arr[i]-arr[j]) <= a?}
    C -- No --> B
    C -- Yes --> D[Choose k greater than j]
    D --> E{Other two bounds pass?}
    E -- Yes --> F[Increment answer]
    E -- No --> D
    F --> D
    D --> G{More j or i?}
    G -- Yes --> B
    G -- No --> H[Return answer]
```

First bound fail झाला तर त्या `i,j` साठी कोणताही `k` उपयोगी नसल्यामुळे inner loop skip करता येतो.

## Selected algorithm, code आणि dry run

`countGoodTripletsIterative` वापरा. `i<j<k` uniqueness राखते; `abs(i-j)` fail झाल्यास `continue`; उरलेल्या दोन checks pass झाल्यावर count वाढतो. Recursive alternative `selected` मध्ये indices push/pop करून हाच triplet set बनवतो; `ak,bk,ck` parameters save करतो. `main` paired hard-coded cases चालवतो.
Dry run (`[3,0,1]`, limits `7,2,3`):
| `(i,j,k)` | Checks | Result |
|---|---|---|
| `(0,1,2)` | `3≤7`, `1≤2`, `2≤3` | count = 1 |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> Fewer than three elements gives 0; zero thresholds allow only equal-valued triples.

## Complexity, correctness, traps

Iterative worst-case `O(n³)` time, `O(1)` extra; recursive enumerator also `O(n³)` time and constant-sized chosen list (depth 3). Correctness: every legal index triple appears once in increasing order; count only when all required inequalities pass.
Mistakes: value-distinct triplets मोजू नका; conditionमध्ये `≤` आहे, `<` नाही; तीन pair checksपैकी एक विसरू नका. Absolute differenceचा क्रम signsवर अवलंबून नसतो.

## Quick revision, variations, self-check

पुनरावलोकन: ordered indices निवडा आणि तिन्ही bounds तपासा.
Loop `i<j<k`; filter `ij`, then validate `jk,ik`. Related: 3Sum enumeration, k-combinations, threshold pair counting.

1. Equal values but different indices count होऊ शकतात का?
2. `i<j<k` का आवश्यक?
3. `ij` bound fail झाल्यावर `k` loop का skip?
4. Recursive methodचे `selected` किती indices ठेवते?
