# 2401 — Longest Nice Subarray

## 1. Understanding

या प्रश्नाचा गाभा म्हणजे bitwise AND शून्य असलेल्या जोड्यांची सर्वात मोठी window.

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> A subarray is nice when every pair of elements has bitwise AND zero, meaning no bit is set in two elements. Return the longest such contiguous subarray.

## 2. Worked examples and edge cases

उदाहरणे आणि सीमाप्रकरणांत bitwise AND शून्य असलेल्या जोड्यांची सर्वात मोठी window कशी लागू होते ते पाहा.

> **मराठी:** उदाहरणातील input पासून output पर्यंत प्रत्येक बदल समजून घ्या.
> For `[1,3,8,48,10]`, `1` and `3` conflict because `1 & 3 != 0`; after shrinking, `[3,8,48]` has pairwise-disjoint set bits, length 3. One element is always nice; a zero value conflicts with no value.

## 3. Pattern identification + cheat sheet

येथे मुख्य pattern म्हणजे bit mask वापरून संघर्ष होईपर्यंत window वाढवणे; वरील तुलना लक्षात घ्या.

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> This is **sliding window + bitmask**: contiguous range, a validity condition that can be restored by moving the left pointer.
> | Signal | Technique |
> |---|---|
> | Longest contiguous valid range | Two pointers |
> | Pairwise bit conflicts | OR mask of active window |
> | Remove a departing element | XOR, because active bits do not overlap |

## 4. Approaches

पद्धतींची तुलना करताना bit mask वापरून संघर्ष होईपर्यंत window वाढवणे याचा वेळ आणि जागेवरील परिणाम पाहा.

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> Checking every subarray and every pair is correct but roughly `O(n^3)`. Recomputing all pairwise ANDs per window is still inefficient. The source's sliding window maintains one OR mask and runs in `O(n)`.

## 5. Flowchart

आकृतीमध्ये bit mask वापरून संघर्ष होईपर्यंत window वाढवणे ही प्रक्रिया क्रमाने दाखवली आहे.

> **मराठी:** Flowchart मध्ये प्रत्येक decision, loop आणि loop कधी थांबतो ते पाहा.

```mermaid
flowchart TD
    A[For each right index] --> B{mask AND nums[right] nonzero?}
    B -->|yes| C[Remove nums[left] bits with XOR; advance left]
    C --> B
    B -->|no| D[Add number bits to mask with OR]
    D --> E[Update maximum window length]
    E --> F{More elements?}
    F -->|yes| A
    F -->|no| G[Return maximum]
```

Conflict is resolved by shrinking until the incoming value shares no bit with the mask.

## 6. Algorithm and intuition

मूळ कल्पना: bit mask वापरून संघर्ष होईपर्यंत window वाढवणे.

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> `curr_or` is the union of set bits in the current valid window. If `(curr_or & x) != 0`, `x` conflicts with at least one current element. Remove left elements until no conflict remains; then add `x`. In a valid window, bits are pairwise disjoint, so XOR removes exactly the departing value's bits.

## 7. Code explanation

Code मधील state आणि updates हे bit mask वापरून संघर्ष होईपर्यंत window वाढवणे या कल्पनेशी जोडून वाचा.

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> The loop advances `right` once per element, shrinks `left` while needed, applies `curr_or |= nums[right]`, and tracks `right-left+1`. The code modifies no input.

## 8. Dry run

Dry run मध्ये bit mask वापरून संघर्ष होईपर्यंत window वाढवणे कसे घडते ते प्रत्येक टप्प्यावर तपासा.

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> | right / value | action | window | mask | best |
> |---|---|---|---:|---:|
> | 0 / 1 | add | `[1]` | 1 | 1 |
> | 1 / 3 | conflict with 1; remove 1, add 3 | `[3]` | 3 | 1 |
> | 2 / 8 | add | `[3,8]` | 11 | 2 |
> | 3 / 48 | add | `[3,8,48]` | 59 | 3 |

## 9. Complexity

bit mask वापरून संघर्ष होईपर्यंत window वाढवणे यासाठी लागणारा वेळ आणि अतिरिक्त जागा वरील bounds मध्ये दिली आहेत.

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> `O(n)` time: each pointer moves only forward. `O(1)` extra space (one integer bitmask).

## 10. Correctness

योग्यतेचा युक्तिवाद bit mask वापरून संघर्ष होईपर्यंत window वाढवणे यावर आधारित आहे; वरील अटी तपासा.

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> Before adding each `nums[right]`, the loop removes leftmost values until its AND with the current OR is zero. This means it shares no set bit with any window member. Adding it therefore preserves pairwise niceness. Every valid window ending at `right` is no longer than the maintained maximal suffix, so recording each length finds the global maximum.

## 11. Mistakes and interview traps

लक्षात ठेवा: bit संघर्ष असल्यास डावीकडून घटक काढायचे.

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Use bitwise `&`, not logical AND.
- Never shrink by removing an arbitrary element; the window must stay contiguous.
- XOR is safe only because the maintained window has no overlapping set bits.
- Update the answer after adding the current value.

## 12. Quick revision

थोडक्यात, bit mask वापरून संघर्ष होईपर्यंत window वाढवणे. bit संघर्ष असल्यास डावीकडून घटक काढायचे.

> **मराठी:** दोन मिनिटांच्या revision साठी pattern, मुख्य कल्पना आणि complexity आठवा.
> Maintain OR mask and `[left,right]`; while `mask & x`, XOR out left and increment; OR in `x`; update length.

## 13. Related problems and variations

संबंधित प्रश्नांत bitwise AND शून्य असलेल्या जोड्यांची सर्वात मोठी window यासारखी अट बदलल्यास योग्य पद्धतही तपासा.

> **मराठी:** Related problem मध्ये constraints बदलल्यास approach कसा बदलेल ते विचारा.
> LeetCode 3 (longest substring without repeats); 209 (minimum-size sum window); variations: maintain counts per bit if the invariant does not permit XOR removal.

## 14. Self-assessment

वरील प्रश्न स्वतः सोडवून bitwise AND शून्य असलेल्या जोड्यांची सर्वात मोठी window याची उजळणी करा.

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why does an AND with the window OR detect all pair conflicts?
2. Why is XOR a valid removal operation here?
3. What would change if the requirement allowed each bit to appear twice?
