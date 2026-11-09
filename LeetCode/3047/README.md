# 3047 — Find the Largest Area of Square Inside Two Rectangles

## 1. Problem understanding and constraints

For each pair of axis-aligned rectangles, find their intersection. The largest square fitting in that intersection has side equal to the smaller intersection dimension; return the greatest area. Coordinates may be negative; use 64-bit area. **थोडक्यात:** काय मोजायचे/निवडायचे ते आधी स्पष्ट करा; मगच code निवडा.

## 2. Stepwise example and edge cases

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> Rectangles `[1,1]-[4,5]` and `[2,2]-[5,6]` intersect in width 2, height 3; square area is 2²=4. **Edge cases:** check smallest valid input, ties/boundaries, and empty/no-match outcomes where constraints allow them.

## 3. Pattern identification — clue table

Pairwise interval intersection followed by min-dimension geometry. हा मुख्य pattern आहे.
| Clue | What it suggests |
|---|---|
| Output depends on pairwise interval intersection followed by min-dimension geometry. | Keep only the relevant state; avoid unrelated recomputation |
| Need to preserve the stated condition | State an invariant before coding |
| Input scan/order matters | Update once per item and test boundaries |

## 4. Multiple approaches

Brute force over all pairs is the natural correct method (`O(n²)`). Source's optimized version prunes pairs that cannot beat the current best, but worst-case remains quadratic. Pruning must be a safe upper bound. **योग्य निवड:** source मध्ये असलेली method आणि तिच्या मर्यादा वेगळ्या ओळखा.

## 5. Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[Read input and initialize state]
    B --> C[Process the next candidate]
    C --> D{is the pair's intersection positive and potentially best?}
    D -->|Yes| E[maximize best with min(width,height) squared]
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
> Intersection lower corner is coordinate-wise max of lower bounds; upper corner is coordinate-wise min of upper bounds. Non-positive width/height means no overlap.

## 7. Code-specific explanation

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `LeetCode\3047\3047.cpp` — Both `largestSquareAreaBruteForce` and `largestSquareAreaOptimized` evaluate pairs. The optimized branch skips impossible/non-improving pairs; results use `long long`.

## 8. Dry run

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> | Step | State / action |
> |---:|---|
> | 1 | Intersection widths: `min(4,5)-max(1,2)=2` |
> | 2 | heights: `min(5,6)-max(1,2)=3` |
> | 3 | side=min(2,3)=2 |
> | 4 | area=4. |

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Both methods are `O(n²)` worst-case time; optimized pruning improves typical work only. Extra space `O(1)` beyond the input/result.

## 10. Correctness

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> The coordinate-wise intersection bounds describe exactly the shared region. A square fits iff its side is at most both dimensions, so the best side is their minimum. Checking every pair (or safely pruning pairs unable to improve) finds the global maximum.

## 11. Mistakes and interview traps

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Treat touching edges as zero area.
- Use intersection dimensions, not rectangle dimensions.
- Promote to `long long` before multiplying.

## 12. Quick revision

**झटपट:** Intersection lower corner is coordinate-wise max of lower bounds; upper corner is coordinate-wise min of upper bounds. Non-positive width/height means no overlap. Pattern ओळखा, condition तपासा, आणि answer एकदाच योग्य पद्धतीने update करा.

## 13. Related patterns and variations

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> Interval intersection; bounding boxes; pairwise geometry.

## 14. Self-assessment

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. How are intersection bounds computed?
2. Why is the square side the smaller dimension?
3. Can safe pruning improve worst-case complexity?
