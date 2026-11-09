# Minimum Difference Between Highest and Lowest of K Scores — LeetCode 1984

## Problem, constraints आणि examples

Choose any `k` scores; minimize highest minus lowest among chosen scores. `1≤k≤n`.
Example: `[9,4,1,7]`, `k=2`: sort `[1,4,7,9]`; adjacent windows differences `3,3,2`, answer `2` from `[7,9]`. `k=1` always gives `0`.

## Pattern clues

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | minimize range of chosen values | sort then sliding window |
> | selected group has k elements | contiguous sorted window |
> | only max-min matters | compare window endpoints |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Status | Cost |
> |---|---|---|
> | Sort and scan length-k windows | Selected, `O(n log n)` time |
> | Enumerate all k-subsets | Correct brute force, `O(C(n,k)*k)` time, exponential in general |
> | Sort and two pointers | Same correct approach, `O(n log n)` |
> | Choose k arbitrary adjacent original elements | Incorrect; best set need not be adjacent before sorting |
> Source sorting methods take vector by value, so input-copy storage is `O(n)`; brute uses a recursive subset selection.

## Flowchart

```mermaid
flowchart TD
    A{ k <= 1?} -->|Yes| Z[Return 0]
    A -->|No| B[Sort scores]
    B --> C[Set best=large; scan left endpoints]
    C --> D[range = nums[left+k-1]-nums[left]]
    D --> E[Update best]
    E --> F{More windows?}
    F -- Yes --> C
    F -- No --> G[Return best]
```

Sorted निवडलेल्या कोणत्याही `k` valuesची min/max एका contiguous windowमध्ये मिळतात; त्यामुळे फक्त `n-k+1` windows तपासा.

## Selected algorithm, source-specific explanation, dry run

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> `minimumDifference_sorting` early-returns for `k≤1`, sorts its copy, then minimizes `nums[i+k-1]-nums[i]`. `minimumDifference_twoPointers` compares `right-left` while both advance. `minimumDifference_bruteforce` picks/skips values and evaluates every size-k subset. `main` skips brute for large arrays.
> Dry run (`[9,4,1,7]`, `k=2`):
> | Sorted window | Difference |
> |---|---:|
> | `[1,4]` | 3 |
> | `[4,7]` | 3 |
> | `[7,9]` | 2 |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> k=1 returns 0; k=n uses the full sorted range; duplicate scores can make the minimum 0.

## Complexity, correctness, traps

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Selected `O(n log n)` time; `O(n)` copied input, `O(1)` scan extra. Correctness: for a chosen minimum and maximum, any selected values between them can be represented by sorted contiguous window; scanning every k-window includes a range no worse than any selected set.
> Trap: sort first; endpoint difference, not sum; `k=1` answer zero. Brute recursion depth is `O(n)` and evaluates combinations.

## Quick revision, variations, self-check

पुनरावलोकन: sorted arrayमधील प्रत्येक k-window तपासा.
Sort, check `nums[i+k-1]-nums[i]`. Related: smallest range, sliding windows after sorting, k closest values.

1. Why are selected items contiguous after sorting?
2. What is answer for `k=1`?
3. How many windows are tested?
4. Why does source sorting method use `O(n)` memory?
