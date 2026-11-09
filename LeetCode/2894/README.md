# 2894 — Divisible and Non-divisible Sums Difference

## 1. Understanding

या प्रश्नाचा गाभा म्हणजे विभाज्य आणि अविभाज्य संख्यांच्या बेरजांमधील फरक.

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> For positive integers `1...n`, add numbers not divisible by `m` to `num1` and subtract multiples of `m` into `num2`. Return `num1-num2`.

## 2. Worked examples and edge cases

उदाहरणे आणि सीमाप्रकरणांत विभाज्य आणि अविभाज्य संख्यांच्या बेरजांमधील फरक कशी लागू होते ते पाहा.

> **मराठी:** उदाहरणातील input पासून output पर्यंत प्रत्येक बदल समजून घ्या.
> For `n=10,m=3`, total sum is 55; divisible values are 3,6,9, sum 18. Difference is `(55-18)-18=19`. If `m>n`, no value is divisible by `m`, so result is `n(n+1)/2`. If `m=1`, every number is divisible and result is negative total sum.

## 3. Pattern identification + cheat sheet

येथे मुख्य pattern म्हणजे एकूण बेरजेतून प्रत्येक multiple दोनदा वजा करणे; वरील तुलना लक्षात घ्या.

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> This is **arithmetic-series aggregation**.
> | Quantity | Formula |
> |---|---|
> | Sum `1...n` | `n(n+1)/2` |
> | Number of multiples of `m` | `k=floor(n/m)` |
> | Sum of multiples | `m*k(k+1)/2` |
> | Difference | `total - 2*divisibleSum` |

## 4. Approaches

पद्धतींची तुलना करताना एकूण बेरजेतून प्रत्येक multiple दोनदा वजा करणे याचा वेळ आणि जागेवरील परिणाम पाहा.

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> The source includes a direct `O(n)` loop and a formula-based `O(1)` method. Both are correct for positive `m`; the formula avoids iterating through every integer. Avoid summing both categories separately if a single total and divisible sum suffice.

## 5. Flowchart

आकृतीमध्ये एकूण बेरजेतून प्रत्येक multiple दोनदा वजा करणे ही प्रक्रिया क्रमाने दाखवली आहे.

> **मराठी:** Flowchart मध्ये प्रत्येक decision, loop आणि loop कधी थांबतो ते पाहा.

```mermaid
flowchart TD
    A[Compute total n*(n+1)/2] --> B[k = floor(n/m)]
    B --> C[Compute divisible sum m*k*(k+1)/2]
    C --> D[Return total - 2*divisible sum]
```

Every divisible value is subtracted instead of added, so its contribution changes from `+x` to `-x`, a net adjustment of `-2x`.

## 6. Algorithm and intuition

मूळ कल्पना: एकूण बेरजेतून प्रत्येक multiple दोनदा वजा करणे.

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> Start with all values added once. For each multiple of `m`, the desired result needs `-x` instead of `+x`; subtracting twice the sum of those multiples performs this flip.

## 7. Code explanation

Code मधील state आणि updates हे एकूण बेरजेतून प्रत्येक multiple दोनदा वजा करणे या कल्पनेशी जोडून वाचा.

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `differenceOfSumsOriginal` loops `1...n`. `differenceOfSumsOptimized` computes the total and `k=n/m`, then the sum of `m,2m,...,km`. `main` compares outputs. Both return `int`, appropriate to the stated constraints.

## 8. Dry run

Dry run मध्ये एकूण बेरजेतून प्रत्येक multiple दोनदा वजा करणे कसे घडते ते प्रत्येक टप्प्यावर तपासा.

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> `n=10,m=3`:
> | Value | Calculation |
> |---|---:|
> | Total | `10*11/2 = 55` |
> | `k` | `10/3 = 3` |
> | Divisible sum | `3*3*4/2 = 18` |
> | Answer | `55-2*18 = 19` |

## 9. Complexity

एकूण बेरजेतून प्रत्येक multiple दोनदा वजा करणे यासाठी लागणारा वेळ आणि अतिरिक्त जागा वरील bounds मध्ये दिली आहेत.

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Loop version: `O(n)` time, `O(1)` space. Formula version: `O(1)` time and `O(1)` space.

## 10. Correctness

योग्यतेचा युक्तिवाद एकूण बेरजेतून प्रत्येक multiple दोनदा वजा करणे यावर आधारित आहे; वरील अटी तपासा.

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> The arithmetic-series formula sums every integer from 1 through `n`. The multiples of `m` are exactly `m*j` for `j=1...floor(n/m)`, whose sum is the second formula. Starting with total sum and subtracting twice that subset changes precisely those terms from positive to negative; all others remain positive.

## 11. Mistakes and interview traps

लक्षात ठेवा: multiple ची बेरीज उत्तरात वजा होत असल्याने तिचा दुहेरी परिणाम होतो.

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Divisible numbers need a negative sign; hence subtract the subset twice.
- `k=n/m` is integer floor division.
- Assume `m>0`; modulo/division by zero is invalid.
- For larger adapted limits, widen intermediate multiplication to `long long`.

## 12. Quick revision

थोडक्यात, एकूण बेरजेतून प्रत्येक multiple दोनदा वजा करणे. multiple ची बेरीज उत्तरात वजा होत असल्याने तिचा दुहेरी परिणाम होतो.

> **मराठी:** दोन मिनिटांच्या revision साठी pattern, मुख्य कल्पना आणि complexity आठवा.
> `total=n(n+1)/2`; `k=n/m`; `divisible=m*k(k+1)/2`; answer `total-2*divisible`.

## 13. Related problems and variations

संबंधित प्रश्नांत विभाज्य आणि अविभाज्य संख्यांच्या बेरजांमधील फरक यासारखी अट बदलल्यास योग्य पद्धतही तपासा.

> **मराठी:** Related problem मध्ये constraints बदलल्यास approach कसा बदलेल ते विचारा.
> LeetCode 2652 (Sum Multiples); arithmetic progression sums; variations: different coefficients for divisible/non-divisible classes.

## 14. Self-assessment

वरील प्रश्न स्वतः सोडवून विभाज्य आणि अविभाज्य संख्यांच्या बेरजांमधील फरक याची उजळणी करा.

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why is the divisible sum multiplied by two?
2. How many multiples of `m` are in `1...n`?
3. What is the result if `m>n`?
