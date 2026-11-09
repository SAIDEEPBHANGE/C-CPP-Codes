# 2966 — Divide Array Into Arrays With Max Difference

## 1. Problem understanding and constraints

Partition all numbers into groups of three so each group's maximum minus minimum is at most `k`; return empty if any group fails. The input length is divisible by three under the problem constraints. **थोडक्यात:** काय मोजायचे/निवडायचे ते आधी स्पष्ट करा; मगच code निवडा.

## 2. Stepwise example and edge cases

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> `nums=[1,3,4,8,9,10], k=2`: sorted groups `[1,3,4]` and `[8,9,10]` both have range ≤2. **Edge cases:** check smallest valid input, ties/boundaries, and empty/no-match outcomes where constraints allow them.

## 3. Pattern identification — clue table

Sort then greedily form consecutive fixed-size groups. हा मुख्य pattern आहे.
| Clue | What it suggests |
|---|---|
| Output depends on sort then greedily form consecutive fixed-size groups. | Keep only the relevant state; avoid unrelated recomputation |
| Need to preserve the stated condition | State an invariant before coding |
| Input scan/order matters | Update once per item and test boundaries |

## 4. Multiple approaches

Trying arbitrary triples is exponential in the worst case and offers no benefit. The source includes two sorting-based implementations; both are correct when every sorted triple passes. Sorted consecutive triples minimize each group's spread. **योग्य निवड:** source मध्ये असलेली method आणि तिच्या मर्यादा वेगळ्या ओळखा.

## 5. Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[Read input and initialize state]
    B --> C[Process the next candidate]
    C --> D{is nums[i+2] - nums[i] ≤ k?}
    D -->|Yes| E[append the next three sorted values]
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
> Sort once, then inspect indices `i,i+1,i+2`. If their endpoint difference exceeds `k`, no alternative grouping can rescue the remaining smallest values.

## 7. Code-specific explanation

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `LeetCode\2966\2966.cpp` — `divideArrayApproach1` and `divideArrayApproach2` build groups from sorted data and return `{}` on the first invalid triple. Both sort `nums` in place; returned groups are ascending.

## 8. Dry run

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> | Step | State / action |
> |---:|---|
> | 1 | Sorted `[1,3,4,8,9,10]`: group `[1,3,4]`, range 3 |
> | 2 | if `k=3` keep it. Next `[8,9,10]`, range 2. Output has two triples. |

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> `O(n log n)` time, `O(n)` result space; sorting may use `O(log n)` stack space. If the vector is copied by the method, that copy is also `O(n)`.

## 10. Correctness

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> Sorting makes each selected triple's minimum and maximum its first and last values. If the first three remaining values already exceed the allowed range, any group containing the smallest remaining value must include a value at least as large as the third-smallest, so no valid partition exists. Otherwise greedily taking them is safe.

## 11. Mistakes and interview traps

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Check the range, not adjacent pair differences alone.
- Return an empty vector immediately on failure.
- Preserve groups of exactly three and do not forget the divisibility constraint.

## 12. Quick revision

**झटपट:** Sort once, then inspect indices `i,i+1,i+2`. If their endpoint difference exceeds `k`, no alternative grouping can rescue the remaining smallest values. Pattern ओळखा, condition तपासा, आणि answer एकदाच योग्य पद्धतीने update करा.

## 13. Related patterns and variations

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> Greedy grouping after sorting; interval partitioning; minimax grouping.

## 14. Self-assessment

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why are consecutive sorted triples the natural greedy choice?
2. What exact check validates a group?
3. When must the function return an empty result?
