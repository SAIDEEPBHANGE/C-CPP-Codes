# 3195 — Find the Minimum Area to Cover All Ones I

## 1. Problem understanding and constraints

Find the smallest axis-aligned rectangle containing every 1 in a binary grid. A bounding rectangle's area is inclusive in both row and column coordinates. **थोडक्यात:** काय मोजायचे/निवडायचे ते आधी स्पष्ट करा; मगच code निवडा.

## 2. Stepwise example and edge cases

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> `[[0,1,0],[1,1,0],[0,0,0]]`: min/max rows 0..1, columns 0..1; area 2×2=4. **Edge cases:** check smallest valid input, ties/boundaries, and empty/no-match outcomes where constraints allow them.

## 3. Pattern identification — clue table

Single grid scan maintaining coordinate extrema. हा मुख्य pattern आहे.
| Clue | What it suggests |
|---|---|
| Output depends on single grid scan maintaining coordinate extrema. | Keep only the relevant state; avoid unrelated recomputation |
| Need to preserve the stated condition | State an invariant before coding |
| Input scan/order matters | Update once per item and test boundaries |

## 4. Multiple approaches

Trying all rectangles is wasteful. The source scans every cell and updates four bounds; it is correct and optimal asymptotically. **योग्य निवड:** source मध्ये असलेली method आणि तिच्या मर्यादा वेगळ्या ओळखा.

## 5. Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[Read input and initialize state]
    B --> C[Process the next candidate]
    C --> D{is grid[r][c] equal to one?}
    D -->|Yes| E[expand min/max row and column]
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
> The tightest enclosing rectangle is determined entirely by the first/last row and column containing a one.

## 7. Code-specific explanation

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `LeetCode\3195\3195.cpp` — `minimumArea` tracks min/max row/column for cells equal to 1, then multiplies inclusive height and width. Constraints ensure at least one 1.

## 8. Dry run

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> | Step | State / action |
> |---:|---|
> | 1 | On the sample, ones occur at rows {0,1}, columns {0,1} |
> | 2 | height=1-0+1=2, width=2 |
> | 3 | area=4. |

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> `O(RC)` time and `O(1)` auxiliary space.

## 10. Correctness

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> Every enclosing rectangle must include the minimum and maximum row and column containing a one. Those extrema define a valid rectangle and are no larger than any alternative, so its area is minimum.

## 11. Mistakes and interview traps

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Add 1 to coordinate differences for inclusive dimensions.
- Ignore zeros.
- If adapting beyond the problem constraints, handle the no-ones case explicitly.

## 12. Quick revision

**झटपट:** The tightest enclosing rectangle is determined entirely by the first/last row and column containing a one. Pattern ओळखा, condition तपासा, आणि answer एकदाच योग्य पद्धतीने update करा.

## 13. Related patterns and variations

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> Bounding boxes; matrix scans; coordinate extrema.

## 14. Self-assessment

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Which four extrema define the answer?
2. Why add one to each difference?
3. What assumption avoids an empty-boundary case?
