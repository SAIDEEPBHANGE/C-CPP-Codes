# 3634 — Minimum Removals to Balance Array

## 1. Problem understanding and constraints

Remove the fewest elements so the maximum remaining value is at most k times the minimum. Sort and keep the longest valid contiguous window in sorted order. **थोडक्यात:** काय मोजायचे/निवडायचे ते आधी स्पष्ट करा; मगच code निवडा.

## 2. Stepwise example and edge cases

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> `[2,1,5,4,2], k=2`: sorted `[1,2,2,4,5]`; window `[1,2,2]` is valid, so remove 2. **Edge cases:** check smallest valid input, ties/boundaries, and empty/no-match outcomes where constraints allow them.

## 3. Pattern identification — clue table

Sort + sliding window / longest valid range. हा मुख्य pattern आहे.
| Clue | What it suggests |
|---|---|
| Output depends on sort + sliding window / longest valid range. | Keep only the relevant state; avoid unrelated recomputation |
| Need to preserve the stated condition | State an invariant before coding |
| Input scan/order matters | Update once per item and test boundaries |

## 4. Multiple approaches

Checking every subset is exponential. Source brute force sorts and tests ranges (`O(n² log n)`); the sliding window is correct and `O(n log n)` including sorting. **योग्य निवड:** source मध्ये असलेली method आणि तिच्या मर्यादा वेगळ्या ओळखा.

## 5. Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[Read input and initialize state]
    B --> C[Process the next candidate]
    C --> D{does nums[right] exceed k×nums[left]?}
    D -->|Yes| E[advance left until window is balanced]
    D -->|No| F[Keep state unchanged]
    E --> G{More candidates?}
    F --> G
    G -->|Yes| C
    G -->|No| H[Return the result]
    H --> I([End])
```

Flow समजताना decision condition आणि update invariant शी जुळतात का ते तपासा.

## 6. Selected algorithm and intuition

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> For any chosen minimum and maximum, all sorted values between them can be kept; if endpoints violate balance, advance the left edge.

## 7. Code-specific explanation

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `LeetCode\3634\3634.cpp` — `minRemovalSlidingWindow` sorts its value copy, moves right once, advances left while `nums[right] > k*nums[left]`, and minimizes `n-windowLength`.

## 8. Dry run

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> | Step | State / action |
> |---:|---|
> | 1 | Sorted `[1,2,2,4,5]`, k=2: right=2 holds window `[1,2,2]` |
> | 2 | right=3 makes 4>2, shrink left |
> | 3 | final longest valid window length 3 → removals 2. |

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> `O(n log n)` time due to sorting, `O(n)` extra space for the by-value input copy; window scan is linear.

## 10. Correctness

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> Sorting means each candidate retained set is represented by a contiguous interval. The window advances its left boundary until its minimum and maximum satisfy the balance condition; every right endpoint is considered, so the longest valid retained interval is found and its complement is the minimum removals.

## 11. Mistakes and interview traps

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Compare max to k×min, not their difference.
- Use a wide type for multiplication if bounds warrant it.
- Duplicate values can remain together without special handling.

## 12. Quick revision

**झटपट:** For any chosen minimum and maximum, all sorted values between them can be kept; if endpoints violate balance, advance the left edge. Pattern ओळखा, condition तपासा, आणि answer एकदाच योग्य पद्धतीने update करा.

## 13. Related patterns and variations

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> Sort + two pointers; longest valid window; minimize removals by maximizing retained items.

## 14. Self-assessment

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why can the kept values be represented by a sorted interval?
2. What is the balance inequality?
3. How does longest valid window give minimum removals?
