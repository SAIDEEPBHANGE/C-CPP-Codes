# 2749 — Minimum Operations to Make the Integer Zero

## 1. Understanding

या प्रश्नाचा गाभा म्हणजे ठराविक वजाबाकीने संख्या शून्य करण्याची किमान पावले.

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> In one operation subtract `2^i + num2` from `num1`, where `i>=0`. Find the minimum positive operation count `k` that can make the value zero, or `-1`.

## 2. Worked examples and edge cases

उदाहरणे आणि सीमाप्रकरणांत ठराविक वजाबाकीने संख्या शून्य करण्याची किमान पावले कशी लागू होते ते पाहा.

> **मराठी:** उदाहरणातील input पासून output पर्यंत प्रत्येक बदल समजून घ्या.
> After `k` operations, the powers of two must sum to `x=num1-k*num2`. A sum of `k` powers of two is possible exactly when `x>=k` and `popcount(x)<=k`: split set bits as needed until there are `k` positive terms. If `x<0` or `x<k`, that `k` is impossible.

## 3. Pattern identification + cheat sheet

येथे मुख्य pattern म्हणजे प्रत्येक operation count साठी उरलेल्या संख्येचे popcount तपासणे; वरील तुलना लक्षात घ्या.

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> This is **algebraic reduction + bit counting**.
> | Transform | Check |
> |---|---|
> | Remove `k*num2` from `num1` | `x = num1-k*num2` |
> | Minimum number of powers-of-two terms | `popcount(x)` |
> | Exactly `k` terms required | `popcount(x) <= k <= x` |

## 4. Approaches

पद्धतींची तुलना करताना प्रत्येक operation count साठी उरलेल्या संख्येचे popcount तपासणे याचा वेळ आणि जागेवरील परिणाम पाहा.

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> Searching operation sequences is exponential. The algebra reduces each candidate `k` to a constant-time bit condition. Important: the source checks `x>=0` and `popcount(x)<=k`, but **omits `x>=k`**; this can accept an impossible candidate. Keep this source-specific issue in mind; do not silently assume its implementation is fully correct.

## 5. Flowchart

आकृतीमध्ये प्रत्येक operation count साठी उरलेल्या संख्येचे popcount तपासणे ही प्रक्रिया क्रमाने दाखवली आहे.

> **मराठी:** Flowchart मध्ये प्रत्येक decision, loop आणि loop कधी थांबतो ते पाहा.

```mermaid
flowchart TD
    A[Try k from 1 to 60] --> B[x = num1 - k*num2 using 64-bit]
    B --> C{x >= k and popcount(x) <= k?}
    C -->|yes| D[Return k]
    C -->|no| E{More k values?}
    E -->|yes| A
    E -->|no| F[Return -1]
```

The mathematical flowchart includes both necessary conditions. The checked-in C++ currently tests only nonnegative `x` and popcount, so it can return a false positive; no source changes are included here.

## 6. Algorithm and intuition

मूळ कल्पना: प्रत्येक operation count साठी उरलेल्या संख्येचे popcount तपासणे.

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> For a fixed `k`, rearrange the operations to `num1-k*num2 = 2^i1+...+2^ik`. The binary representation gives the fewest powers (its set bits). Splitting `2^p` into two `2^(p-1)` terms increases term count by one while preserving sum, up to `x` terms of value one. Therefore a representation in exactly `k` terms exists iff `popcount(x)<=k<=x`.

## 7. Code explanation

Code मधील state आणि updates हे प्रत्येक operation count साठी उरलेल्या संख्येचे popcount तपासणे या कल्पनेशी जोडून वाचा.

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `makeTheIntegerZero` tries `k=1..60`, computes the residual in `long long`, skips negative residuals, and checks `__builtin_popcountll`. Its actual condition is only `bits<=k`, so it misses the lower bound. For example, `num1=5,num2=2`: at `k=2`, residual is 1 and the code accepts, although two positive powers cannot sum to 1; the true answer is `-1`.

## 8. Dry run

Dry run मध्ये प्रत्येक operation count साठी उरलेल्या संख्येचे popcount तपासणे कसे घडते ते प्रत्येक टप्प्यावर तपासा.

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> For `num1=5,num2=2`:
> | `k` | `x=5-2k` | popcount | Mathematical check |
> |---:|---:|---:|---|
> | 1 | 3 | 2 | fails `popcount<=k` |
> | 2 | 1 | 1 | fails `x>=k`; source would incorrectly accept |

## 9. Complexity

प्रत्येक operation count साठी उरलेल्या संख्येचे popcount तपासणे यासाठी लागणारा वेळ आणि अतिरिक्त जागा वरील bounds मध्ये दिली आहेत.

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> At most 60 iterations: `O(1)` time and `O(1)` space under the problem's bounded integer constraints.

## 10. Correctness

योग्यतेचा युक्तिवाद प्रत्येक operation count साठी उरलेल्या संख्येचे popcount तपासणे यावर आधारित आहे; वरील अटी तपासा.

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> The derived criterion `popcount(x)<=k<=x` is necessary because at least one term is needed for each set bit and each of the `k` positive powers contributes at least one. It is sufficient because repeatedly split powers of two to add terms until there are exactly `k`; this can reach any count through `x`. The source's implemented weaker test is not fully correct because it omits `x>=k`.

## 11. Mistakes and interview traps

लक्षात ठेवा: उरलेली बेरीज positive आणि पुरेशी मोठी असणे आवश्यक आहे.

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Use 64-bit arithmetic for `num1-k*num2`.
- Negative residual cannot work.
- `popcount<=k` alone is not sufficient; also require `k<=x`.
- `k=0` is excluded by the problem's operation requirement.
- The source issue is documented, not patched, per request.

## 12. Quick revision

थोडक्यात, प्रत्येक operation count साठी उरलेल्या संख्येचे popcount तपासणे. उरलेली बेरीज positive आणि पुरेशी मोठी असणे आवश्यक आहे.

> **मराठी:** दोन मिनिटांच्या revision साठी pattern, मुख्य कल्पना आणि complexity आठवा.
> For each positive `k`, let `x=num1-k*num2`; valid iff `x>=k` and `popcount(x)<=k`. Return first valid `k`.

## 13. Related problems and variations

संबंधित प्रश्नांत ठराविक वजाबाकीने संख्या शून्य करण्याची किमान पावले यासारखी अट बदलल्यास योग्य पद्धतही तपासा.

> **मराठी:** Related problem मध्ये constraints बदलल्यास approach कसा बदलेल ते विचारा.
> LeetCode 338 (Counting Bits); 191 (Number of 1 Bits); variations: represent a number as exactly `k` powers or minimize the number of powers.

## 14. Self-assessment

वरील प्रश्न स्वतः सोडवून ठराविक वजाबाकीने संख्या शून्य करण्याची किमान पावले याची उजळणी करा.

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why must residual `x` be at least `k`?
2. What does `popcount(x)` tell us about the minimum term count?
3. Find an input where `popcount(x)<=k` but `x<k`.
