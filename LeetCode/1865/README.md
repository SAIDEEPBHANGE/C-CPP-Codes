# Finding Pairs With a Certain Sum — LeetCode 1865

## Problem, constraints आणि examples

Maintain `nums1`, `nums2` with operations: `add(index,val)` updates `nums2[index]`; `count(tot)` counts index pairs `(i,j)` where `nums1[i]+nums2[j]=tot`. Equal values at different indices are separate pairs.
Example: `nums1=[1,2,3]`, `nums2=[3,4]`, `count(5)=2` (`1+4`, `2+3`). Then `add(0,1)` makes `nums2=[4,4]`; `count(5)=1`.

## Pattern clues

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | many repeated sum queries | frequency map |
> | only second array is mutable | update its count incrementally |
> | pair count asks multiplicity | add frequency, not just existence |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Status | Cost |
> |---|---|---|
> | Hash frequency of `nums2`; scan `nums1` complements | Selected; expected `count O(n1)`, `add O(1)` |
> | Rebuild all pairs for every count | Correct brute force `O(n1*n2)` per query |
> | Store only set of nums2 values | Incorrect; loses duplicate pair counts |
> | Update value without decrement old frequency | Incorrect; stale counts remain |

## Flowchart

```mermaid
flowchart TD
    A[Construct: count nums2 frequencies] --> B{Operation?}
    B -- add --> C[Decrement old value frequency]
    C --> D[Update nums2[index]; increment new frequency]
    B -- count --> E[For each x in nums1, add freq(total-x)]
    E --> F[Return accumulated pair count]
```

Old frequency कमी केल्याशिवाय map actual `nums2`शी consistent राहणार नाही.

## Selected algorithm, code-specific explanation, dry run

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> `FindSumPairs` constructor copies arrays and builds `freq2`. `add` gets old value, decrements and erases zero frequency, changes the stored element and increments new frequency. `count` sums `freq2[tot-num]` for every `nums1` element. Distinct indices in `nums1` naturally each contribute.
> Dry run (`nums1=[1,2,3]`, `nums2=[3,4]`, total 5):
> | `nums1` value | complement in nums2 | frequency | running count |
> |---:|---:|---:|---:|
> | 1 | 4 | 1 | 1 |
> | 2 | 3 | 1 | 2 |
> | 3 | 2 | 0 | 2 |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> Duplicate values represent multiple index pairs; an update can remove the last occurrence of an old key; empty frequency means no match.

## Complexity, correctness, traps

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Constructor `O(n2)` expected, map space `O(distinct nums2)` plus stored arrays. `add` expected `O(1)`; `count` expected `O(n1)`. Correctness: each `nums1` index has exactly `freq2[tot-x]` matching `nums2` indices, and summing covers all pairs once.
> Traps: decrement old value before replacing; erase zero count optionally; duplicates multiply pair count. Hash operation costs are expected.

## Quick revision, variations, self-check

पुनरावलोकन: `nums2` frequency update करून complement count करा.
Hash second array; update old/new; scan complements. Related: Two Sum, dynamic frequency maps, online pair counting.

1. Why does `count` add a frequency rather than 1?
2. What changes if `nums1` also has duplicate values?
3. When can an old key be erased?
4. Complexity of `add` in expected terms?
