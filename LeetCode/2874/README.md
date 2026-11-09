# 2874 — Maximum Value of an Ordered Triplet II

## 1. Understanding

या प्रश्नाचा गाभा म्हणजे क्रमबद्ध तीन indices साठी कमाल triplet मूल्य.

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> Choose `i<j<k` to maximize `(nums[i]-nums[j])*nums[k]`. The answer is at least zero, so if all products are negative the result remains 0. The source has a cubic reference method and a linear optimized method.

## 2. Worked examples and edge cases

उदाहरणे आणि सीमाप्रकरणांत क्रमबद्ध तीन indices साठी कमाल triplet मूल्य कशी लागू होते ते पाहा.

> **मराठी:** उदाहरणातील input पासून output पर्यंत प्रत्येक बदल समजून घ्या.
> For `[12,6,1,2,7]`, choose `(12,1,7)`: `(12-1)*7=77`. If values are nondecreasing, every difference is nonpositive and answer is 0. Fewer than three elements also yields 0 in the provided implementations.

## 3. Pattern identification + cheat sheet

येथे मुख्य pattern म्हणजे आधीचा सर्वोत्तम फरक आणि कमाल मूल्य राखणे; वरील तुलना लक्षात घ्या.

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> This is **ordered triplet optimization / prefix maximum + best difference**.
> | At current `k` | Maintain |
> |---|---|
> | Best `nums[i]-nums[j]` with `i<j<k` | `MaxDiff` |
> | Best earlier value for a future `j` | `MaxLeft` |
> | Best product so far | `MaxResult` |

## 4. Approaches

पद्धतींची तुलना करताना आधीचा सर्वोत्तम फरक आणि कमाल मूल्य राखणे याचा वेळ आणि जागेवरील परिणाम पाहा.

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.

- Three loops enumerate all triples: `O(n³)` reference.
- Precompute prefix maxima and suffix products/candidates: `O(n)` alternatives.
- One pass updates `MaxResult` before incorporating current index into `MaxDiff`; source's optimized method is `O(n)`.

## 5. Flowchart

आकृतीमध्ये आधीचा सर्वोत्तम फरक आणि कमाल मूल्य राखणे ही प्रक्रिया क्रमाने दाखवली आहे.

> **मराठी:** Flowchart मध्ये प्रत्येक decision, loop आणि loop कधी थांबतो ते पाहा.

```mermaid
flowchart TD
    A[Initialize best result, difference, left max to 0] --> B[Read nums[i] as possible k]
    B --> C[Update result with best difference times nums[i]]
    C --> D[Update best difference with left max minus nums[i]]
    D --> E[Update left max with nums[i]]
    E --> F{More indices?}
    F -->|yes| B
    F -->|no| G[Return result]
```

Update order ensures current index cannot be used for both `j` and `k`.

## 6. Algorithm and intuition

मूळ कल्पना: आधीचा सर्वोत्तम फरक आणि कमाल मूल्य राखणे.

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> At each index `i`, treat it as `k` and multiply by the best difference formed before it. Then treat it as a possible `j` and update `MaxDiff` using the greatest value seen earlier. Finally update the prefix maximum. This maintains index ordering without storing triples.

## 7. Code explanation

Code मधील state आणि updates हे आधीचा सर्वोत्तम फरक आणि कमाल मूल्य राखणे या कल्पनेशी जोडून वाचा.

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `maximumTripletValueOptimized` uses `long long` for all aggregate calculations and keeps three state values. `maximumTripletValueBruteForce` checks all triples, but casts **after** `(nums[i]-nums[j])*nums[k]`; that multiplication is performed as `int` first and can overflow under large values. The optimized method casts early and avoids this issue. The file's `main` compares both.

## 8. Dry run

Dry run मध्ये आधीचा सर्वोत्तम फरक आणि कमाल मूल्य राखणे कसे घडते ते प्रत्येक टप्प्यावर तपासा.

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> For `[12,6,1,2,7]`:
> | Current index/value | Best result before | `MaxDiff` update | `MaxLeft` after |
> |---|---:|---:|---:|
> | 0 / 12 | 0 | 0 | 12 |
> | 1 / 6 | 0 | 6 | 12 |
> | 2 / 1 | 0 | 11 | 12 |
> | 3 / 2 | 22 | 11 | 12 |
> | 4 / 7 | 77 | 11 | 12 |

## 9. Complexity

आधीचा सर्वोत्तम फरक आणि कमाल मूल्य राखणे यासाठी लागणारा वेळ आणि अतिरिक्त जागा वरील bounds मध्ये दिली आहेत.

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Brute force `O(n³)` time, `O(1)` space (with the source overflow caveat). Optimized `O(n)` time and `O(1)` space.

## 10. Correctness

योग्यतेचा युक्तिवाद आधीचा सर्वोत्तम फरक आणि कमाल मूल्य राखणे यावर आधारित आहे; वरील अटी तपासा.

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> Before processing index `k`, `MaxDiff` is the maximum `nums[i]-nums[j]` over valid earlier `i<j<k`; multiplying by `nums[k]` evaluates the best triplet ending there (and the zero baseline handles nonpositive products). Updating `MaxDiff` with the previous `MaxLeft` makes `j` current and guarantees `i<j`; updating `MaxLeft` last preserves strict ordering. Every valid triplet is therefore considered in the pass.

## 11. Mistakes and interview traps

लक्षात ठेवा: i < j < k हा क्रम updates करताना जपायचा.

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Preserve strict index order: result update must happen before updating current difference.
- Initialize answer/difference at zero per problem's nonnegative result convention.
- Use 64-bit multiplication before the product; post-product cast is too late.
- Do not mistake `MaxDiff` for a simple prefix difference; it represents a valid ordered pair.

## 12. Quick revision

थोडक्यात, आधीचा सर्वोत्तम फरक आणि कमाल मूल्य राखणे. i < j < k हा क्रम updates करताना जपायचा.

> **मराठी:** दोन मिनिटांच्या revision साठी pattern, मुख्य कल्पना आणि complexity आठवा.
> One pass: result `maxDiff*x`; diff `max(diff,leftMax-x)`; left max `max(leftMax,x)`.

## 13. Related problems and variations

संबंधित प्रश्नांत क्रमबद्ध तीन indices साठी कमाल triplet मूल्य यासारखी अट बदलल्यास योग्य पद्धतही तपासा.

> **मराठी:** Related problem मध्ये constraints बदलल्यास approach कसा बदलेल ते विचारा.
> LeetCode 121 (Best Time to Buy and Sell Stock); 1937 (Maximum Number of Points with Cost); variations: maximize `(a-b)*c` with different index ordering or return negative maxima.

## 14. Self-assessment

वरील प्रश्न स्वतः सोडवून क्रमबद्ध तीन indices साठी कमाल triplet मूल्य याची उजळणी करा.

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why update the result before updating `MaxDiff`?
2. What does `MaxDiff` represent at index `k`?
3. Why is the brute-force cast potentially too late?
