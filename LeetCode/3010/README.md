# 3010 — Divide an Array Into Subarrays With Minimum Cost I

## 1. Problem understanding and constraints

Split the array into three non-empty contiguous subarrays. The first subarray contributes its first element; minimize the total by choosing the two smallest remaining starting values. Inputs satisfy the required length. **थोडक्यात:** काय मोजायचे/निवडायचे ते आधी स्पष्ट करा; मगच code निवडा.

## 2. Stepwise example and edge cases

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> `nums=[1,2,3,4]`: choose first value 1 and the two smallest later values 2 and 3; minimum cost=6. **Edge cases:** check smallest valid input, ties/boundaries, and empty/no-match outcomes where constraints allow them.

## 3. Pattern identification — clue table

Fixed anchor plus two minima; selection can replace exhaustive split enumeration. हा मुख्य pattern आहे.
| Clue | What it suggests |
|---|---|
| Output depends on fixed anchor plus two minima | Keep only the relevant state; avoid unrelated recomputation |
| Need to preserve the stated condition | State an invariant before coding |
| Input scan/order matters | Update once per item and test boundaries |

## 4. Multiple approaches

Enumerating every pair of cut positions is correct but `O(n²)`. Source has sort, linear scan, and heap methods; the linear scan is best and correct. Heap offers no advantage for selecting only two minima. **योग्य निवड:** source मध्ये असलेली method आणि तिच्या मर्यादा वेगळ्या ओळखा.

## 5. Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[Read input and initialize state]
    B --> C[Process the next candidate]
    C --> D{is nums[i] among the two smallest suffix values?}
    D -->|Yes| E[insert it into the two-minimum state]
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
> The first subarray must start at index 0; its cost is fixed as `nums[0]`. The other two starts must be distinct indices after 0, so pick their two smallest values.

## 7. Code-specific explanation

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `LeetCode\3010\3010.cpp` — `minimumCost_linear` tracks the two smallest values from index 1 onward. Sorting and heap variants are included for comparison; their costs differ from the linear scan.

## 8. Dry run

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> | Step | State / action |
> |---:|---|
> | 1 | `[1,2,3,4]`: scan suffix: first min=2, second=∞ |
> | 2 | see 3→second=3 |
> | 3 | 4 changes neither. Sum 1+2+3=6. |

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Linear: `O(n)` time, `O(1)` extra. Sorting: `O(n log n)` time; heap construction/pushes can cost `O(n log n)` time and `O(n)` space.

## 10. Correctness

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> Every valid partition has first cost `nums[0]`, and its other two subarray starts are two distinct indices in the suffix. Conversely, any two selected suffix indices can be realized as the starts of the second and third subarrays. Choosing the two least values therefore minimizes the total.

## 11. Mistakes and interview traps

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Include `nums[0]` exactly once.
- Choose two distinct suffix indices, not one value twice.
- The first subarray's endpoint does not change its cost.

## 12. Quick revision

**झटपट:** The first subarray must start at index 0; its cost is fixed as `nums[0]`. The other two starts must be distinct indices after 0, so pick their two smallest values. Pattern ओळखा, condition तपासा, आणि answer एकदाच योग्य पद्धतीने update करा.

## 13. Related patterns and variations

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> Two smallest values; greedy selection; partition cost reductions.

## 14. Self-assessment

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why is the first cost fixed?
2. Which elements are eligible for the other two costs?
3. What is the time-optimal source method?
