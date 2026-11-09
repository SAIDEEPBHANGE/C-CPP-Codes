# Maximum Distance Between a Pair of Values — LeetCode 1855

## Problem, constraints आणि examples

Non-increasing sorted arrays `nums1`, `nums2` मध्ये `i≤j`, `nums1[i]≤nums2[j]` असलेली pair निवडा; maximum `j-i` द्या. `nums1` no longer than `nums2`.
Example: `[55,30,5,4,2]`, `[100,20,10,10,5]`: `(i,j)=(2,4)` gives `2`; no valid pair farther → `2`. If every comparison fails, answer `0`.

## Pattern clues

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | sorted arrays and `≤` feasibility | two pointers / binary search |
> | want farthest valid `j` for each `i` | monotone boundary |
> | indices must obey `i≤j` | pointer ordering invariant |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Status | Cost |
> |---|---|---|
> | Two pointers | Selected `O(n+m)` / `O(1)` |
> | Binary search farthest valid `j` per `i` | Correct `O(n log m)` / `O(1)` |
> | Check all valid `(i,j)` pairs | Correct brute force `O(nm)` / `O(1)` |
> | Sort again | Unneeded; can lose index relation |

## Flowchart

```mermaid
flowchart TD
    A[Set i=0, j=0, best=0] --> B{Both indices in range?}
    B -- No --> E[Return best]
    B -- Yes --> C{nums1[i] <= nums2[j]?}
    C -- Yes --> D[Update best with j-i; increment j]
    C -- No --> F[Increment i]
    D --> B
    F --> B
```

`j` पुढे गेल्यावर मागे येत नाही; valid comparisonमध्ये तो पुढील मोठे distance देऊ शकतो.

## Selected algorithm, source explanation, dry run

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> `maxDistanceTwoPointer`: if `nums1[i]≤nums2[j]`, update and advance `j`; otherwise current `i` too large for this `j`, advance `i`. Source has binary and brute alternatives. Binary method searches rightmost valid index, initialized `i-1` to represent no valid index; it checks `best≥i` before use.
> Dry run (`nums1=[2,2,2]`, `nums2=[10,10,1]`):
> | `(i,j)` | Test | Action / best |
> |---|---|---|
> | (0,0) | 2≤10 | best 0; j=1 |
> | (0,1) | 2≤10 | best 1; j=2 |
> | (0,2) | 2≤1 false | i=1 |
> | (1,2), (2,2) | false | advance i; answer 1 |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> No valid pair returns 0; i=j is allowed; nums1 may have one element and nums2 may be longer.

## Complexity, correctness, traps

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Two pointer `O(n+m)` time, `O(1)` extra. Correctness: when comparison fails, this `j` cannot pair with current or any later `nums1[i]` (nums1 non-increasing); when it passes, advancing `j` explores farther candidates. Source vectors are references; no input copy.
> Trap: arrays are non-increasing; keep `i≤j`; binary search wants last true boundary.

## Quick revision, variations, self-check

पुनरावलोकन: valid असेल तर `j`, अन्यथा `i` पुढे न्या.
Move `j` on valid, `i` on invalid. Related: monotone two pointers, upper-bound searches, merge-like scans.

1. Why does failed pair justify incrementing `i`?
2. If no pair valid, what is returned?
3. Binary search seeks first true or last true?
4. Why not reset `j` for every `i`?
