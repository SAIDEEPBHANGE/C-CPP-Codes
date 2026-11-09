# Minimize Maximum Pair Sum in Array — LeetCode 1877

## Problem, constraints आणि examples

Even-length arrayचे सर्व elements pairsमध्ये exactly एकदा वापरा; pair sumsमधील maximum शक्य तितका कमी करा. Minimize the largest sum, not the total sum.
Example: `[3,5,2,3]` sort → `[2,3,3,5]`; opposite ends `(2,5),(3,3)` give sums `7,6`, answer `7`.

## Pattern clues

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | minimize largest pair sum | bottleneck pairing |
> | sorted values, extremes dominate | pair smallest with largest |
> | each element used once | greedy matching |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Status | Cost |
> |---|---|---|
> | Sort, pair opposite ends | Selected `O(n log n)` time |
> | Counting sort then opposite extremes | Correct only for bounded nonnegative values; `O(n+MAXV)`, `O(MAXV)` space |
> | Enumerate all pairings | Correct brute force, factorial-scale |
> | Pair smallest with smallest | Incorrect greedy; not balancing large sums |
> Source methods take vector by value, so sorting works on a copy: additional `O(n)` memory even though sorting itself is in-place.

## Flowchart

```mermaid
flowchart TD
    A[Copy and sort values] --> B[Set left=0, right=n-1]
    B --> C{Unpaired elements remain?}
    C -- No --> F[Return maximum pair sum]
    C -- Yes --> D[Pair nums[left] with nums[right]]
    D --> E[Update maximum; move both pointers inward]
    E --> C
```

Extremes एकत्र pair केल्याने high endpointवरचा भार smallest उपलब्ध valueने balance होतो.

## Selected algorithm, code-specific explanation, dry run

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> `minPairSum_sort` sorts then updates `ans=max(ans, nums[i]+nums[n-1-i])`. `minPairSum_twoPointers` same pairings with two indices. Counting method uses frequencies across fixed domain `[0,100000]`, consuming smallest and largest. `main` compares methods.
> Dry run (`[3,5,2,3]`):
> | Pair | Sum | Maximum so far |
> |---|---:|---:|
> | `2+5` | 7 | 7 |
> | `3+3` | 6 | 7 |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> Two elements form one pair; equal values still form valid separate pairs; source counting assumes values in its fixed range.

## Complexity, correctness, traps

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Sorting method `O(n log n)`, `O(n)` copied input due pass-by-value; algorithmic extra after copy `O(1)`. Correctness by exchange argument: pairing extremes balances the largest values; swaps can transform an optimal matching to opposite-end pairings without increasing maximum.
> Trap: length is even; update maximum, not sum all pairs. Counting-sort method assumes its hardcoded value bound and nonnegative values.

## Quick revision, variations, self-check

पुनरावलोकन: sort करून smallest आणि largest pair करा.
Sort, pair `i` with `n-1-i`, take max. Related: bottleneck matching, minimizing maximum difference, greedy exchange arguments.

1. Why pair smallest with largest?
2. Does answer sum all pair sums?
3. What value range does source counting method assume?
4. Why does source use extra `O(n)` despite in-place sort?
