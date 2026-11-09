# Maximum Absolute Sum of Any Subarray — LeetCode 1749

## Problem, constraints आणि examples

Non-empty contiguous subarray निवडून `|sum|` maximum करा. Empty selectionचा प्रभाव `0` baselineने समाविष्ट होतो; array non-empty असते.
Example: `[1,-3,2,3,-4]`: subarray `[2,3]` sum `5`; `[-3,2,3,-4]` sum `-2`; maximum absolute sum `5`. All negative array `[-2,-1]` → `3` from full array.

## Pattern clues

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | maximum positive subarray sum | Kadane |
> | maximum magnitude includes negative sums | maximum and minimum subarray sums |
> | contiguous range, linear scan desired | rolling prefix state |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Status | Cost |
> |---|---|---|
> | Track max-ending and min-ending sums | Selected `O(n)` / `O(1)` |
> | Enumerate all subarrays with running sum | Correct brute force `O(n²)` / `O(1)` |
> | Source recursion for every start | Correct but `O(n²)` time, `O(n)` stack |
> | Maximum sum alone then abs | Incorrect; large-magnitude negative range may win |

## Flowchart

```mermaid
flowchart TD
    A[Initialize maxEnd=minEnd=0; extrema=0] --> B{More values?}
    B -- No --> E[Return max(maxSub,-minSub)]
    B -- Yes --> C[Add x to maxEnd and minEnd]
    C --> D[Update maxSub and minSub]
    D --> F[Reset maxEnd if negative; minEnd if positive]
    F --> B
```

Positive Kadane negative-ending state discard करतो; minimum version positive-ending state discard करतो.

## Selected algorithm, source-specific explanation, dry run

`maxAbsoluteSumKadane`: `currMax/currMin` हे current indexला end होणारे best max/min sums; `maxSum/minSum` global values. Final `max(maxSum,abs(minSum))`. Brute method nested subarray scan; recursion `AllPossible` suffix sums explore करतो; `compareMethods` तिन्ही answers दाखवतो.
Dry run (`[1,-3,2,3,-4]`):
| x | max-ending after reset | min-ending after reset | Best max / min |
|---:|---:|---:|---:|
| 1 | 1 | 0 | 1 / 0 |
| -3 | 0 | -3 | 1 / -3 |
| 2 | 2 | 0 | 2 / -3 |
| 3 | 5 | 0 | 5 / -3 |
| -4 | 1 | -4 | 5 / -4 |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> All-positive, all-negative, mixed-sign, and one-element arrays verify both extrema; result is never negative.

## Complexity, correctness, traps

Kadane variant `O(n)` time, `O(1)` space. Correctness: any best subarray ending at current index extends prior best-ending sum or starts at current value; same recurrence works for minimum; absolute maximum is max(maximum sum, negative minimum sum).
Trap: min sum negative असतो; त्याचा absolute घ्या. Empty subarray makes baseline 0 but doesn't change positive answer. Recursion source explores every suffix and is not exponential here.

## Quick revision, variations, self-check

पुनरावलोकन: max आणि min subarray sums दोन्ही track करा.
Run Kadane for max and min; answer `max(maxSum,-minSum)`. Related: max subarray, prefix sums, maximum circular subarray.

1. All-positive arrayमध्ये answer काय बनेल?
2. Minimum subarray sum का track करतो?
3. `currMin>0` झाल्यावर reset का?
4. Recursion methodचा worst time किती?
