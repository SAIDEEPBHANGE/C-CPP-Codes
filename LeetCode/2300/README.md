# Successful Pairs of Spells and Potions — LeetCode 2300

Source: `2300.cpp`; it sorts potions and binary-searches the first potion that reaches the success threshold for each spell.

## 1. Understanding — समजून घ्या

For each spell, count potions for which `spell * potion >= success`. Return counts in the original spell order.

## 2. Worked examples and edge cases

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> For spell `10`, success `100`, the minimum potion is `ceil(100/10)=10`; if sorted potions are `[1,2,10,20]`, count is 2. A potion exactly meeting the threshold is successful. Potions are positive by constraints.

## 3. Pattern identification + cheat sheet

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | One operand fixed per query | Derive threshold |
> | Sorted values with monotonic predicate | Lower-bound binary search |
> | Need count of all values above boundary | `n - firstValidIndex` |

## 4. Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> Brute force checks every spell-potion pair in O(S·P). Sorting potions and binary searching each threshold gives O(P log P + S log P). Sorting spells too or using a two-pointer sweep can help when queries are processed in sorted order, but requires restoring original spell positions.

## 5. Flowchart

> **मराठी:** Flowchart मधील decision, loop आणि termination condition क्रमाने समजून घ्या.

```mermaid
flowchart TD
    A([Sort potions]) --> B[Read next spell]
    B --> C[Compute ceil(success/spell)]
    C --> D[Binary search first potion >= threshold]
    D --> E[Count n - position]
    E --> F{More spells?}
    F -- Yes --> B
    F -- No --> Z([Return counts])
```

## 6. Algorithm and intuition

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> For positive `spell`, the product condition is equivalent to `potion >= ceil(success/spell)`. The sorted potion array is partitioned into failures followed by successes. Lower-bound search finds that boundary; all entries from it to the end count.

## 7. Code explanation

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `successfulPairs` sorts `potions` in place. It computes the ceiling with `(success + spell - 1) / spell` using `long long`, binary searches the half-open range `[0,n)`, and appends `n-low` for each input spell.

## 8. Dry run

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> `potions=[1,2,3,4,5]`, `spell=3`, `success=7`: threshold `ceil(7/3)=3`; lower bound points to 3, so `5-2=3` successful potions.

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> For `S` spells and `P` potions: **O(P log P + S log P)** time, **O(S)** output space, and **O(1)** extra search space (sorting stack excluded).

## 10. Correctness

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> With positive spell, multiplication inequality is equivalent to the derived potion threshold. Sorting makes all successful potions a suffix. Binary search returns the first suffix position; subtracting it from array length counts exactly the successful potions.

## 11. Mistakes and interview traps

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Use ceiling division, not floor division.
- Use 64-bit arithmetic for `success + spell - 1` and products/thresholds.
- Lower bound must include potions equal to threshold.
- Keep answer order aligned with original spells; only potions are sorted here.
- This derivation assumes positive spell values.

## 12. Quick revision — झटपट उजळणी

> **मराठी सारांश:** किमान potion threshold काढा आणि lower bound शोधा.
> Sort potions → threshold `ceil(success/spell)` → lower_bound → `P-index`.

## 13. Related problems and variations

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> Successful pairs; count values meeting a monotone threshold; binary search on answer; process sorted queries with a sweep line.

## 14. Self-assessment

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why is the boundary a lower bound?
2. How is integer ceiling division computed?
3. Why does sorting potions not change spell output order?
