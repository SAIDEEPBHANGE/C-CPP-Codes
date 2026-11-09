# 2918 — Minimum Equal Sum of Two Arrays After Replacing Zeros

## 1. Understanding

या प्रश्नाचा गाभा म्हणजे दोन्ही arrays मधील शून्ये बदलून मिळणारी किमान समान बेरीज.

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> Replace each zero in either positive-integer array with any positive integer. Find the minimum common sum achievable by both arrays, or return `-1` if no equal sum is possible.

## 2. Worked examples and edge cases

उदाहरणे आणि सीमाप्रकरणांत दोन्ही arrays मधील शून्ये बदलून मिळणारी किमान समान बेरीज कशी लागू होते ते पाहा.

> **मराठी:** उदाहरणातील input पासून output पर्यंत प्रत्येक बदल समजून घ्या.
> Each zero must contribute at least 1, so a minimum possible sum is `sum(nonzero)+zeroCount`. If one array has no zeros, its sum is fixed; the other can reach any larger sum because it can increase a replacement. If both have no zeros and unequal sums, equality is impossible.

## 3. Pattern identification + cheat sheet

येथे मुख्य pattern म्हणजे प्रत्येक शून्याला आधी एक धरून किमान बेरीज तपासणे; वरील तुलना लक्षात घ्या.

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> This is **minimum feasible value + monotonic adjustability**.
> | Array property | Minimum achievable sum |
> |---|---|
> | Sum of nonzeros `S`, zeros `z` | `S+z` |
> | Has a zero | Can increase minimum by any nonnegative amount |
> | No zeros | Sum is fixed |

## 4. Approaches

पद्धतींची तुलना करताना प्रत्येक शून्याला आधी एक धरून किमान बेरीज तपासणे याचा वेळ आणि जागेवरील परिणाम पाहा.

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> Brute-force replacement values is unbounded and unnecessary. Compute each minimum sum and zero count. If the smaller minimum belongs to a zero-free array, it cannot be raised; otherwise both can reach the larger minimum.

## 5. Flowchart

आकृतीमध्ये प्रत्येक शून्याला आधी एक धरून किमान बेरीज तपासणे ही प्रक्रिया क्रमाने दाखवली आहे.

> **मराठी:** Flowchart मध्ये प्रत्येक decision, loop आणि loop कधी थांबतो ते पाहा.

```mermaid
flowchart TD
    A[For each array sum nonzeros and replace each zero by 1] --> B[Get minimum sums S1 and S2]
    B --> C{S1 < S2 and array1 has no zero?}
    C -->|yes| D[Return -1]
    C -->|no| E{S2 < S1 and array2 has no zero?}
    E -->|yes| D
    E -->|no| F[Return max(S1,S2)]
```

The larger minimum is the smallest common target if the lower-sum array can be increased.

## 6. Algorithm and intuition

मूळ कल्पना: प्रत्येक शून्याला आधी एक धरून किमान बेरीज तपासणे.

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> For each array, replace each zero by 1 to calculate its minimum possible sum. A zero-containing array can raise its total arbitrarily by increasing one replacement. A zero-free array is fixed. If the fixed sum is below the other array's minimum, equality is impossible; otherwise return the larger minimum.

## 7. Code explanation

Code मधील state आणि updates हे प्रत्येक शून्याला आधी एक धरून किमान बेरीज तपासणे या कल्पनेशी जोडून वाचा.

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `CalculateVector` counts zeros and adds 1 per zero while summing nonzeros into `long long`. `minSum` returns `-1` for the two impossible cases and otherwise `max(nums1Sum,nums2Sum)`. The demo `main` uses copies of the same sample vector for both inputs; it is illustrative, not a varied judge test.

## 8. Dry run

Dry run मध्ये प्रत्येक शून्याला आधी एक धरून किमान बेरीज तपासणे कसे घडते ते प्रत्येक टप्प्यावर तपासा.

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> Array 1 `[1,2,3,0]`: minimum sum 7, one zero. Array 2 `[5,4]`: fixed sum 9.
> | Array | Minimum | Can increase? |
> |---|---:|---|
> | 1 | 7 | yes |
> | 2 | 9 | no |
> The first array can raise 7 to 9, so answer is 9.

## 9. Complexity

प्रत्येक शून्याला आधी एक धरून किमान बेरीज तपासणे यासाठी लागणारा वेळ आणि अतिरिक्त जागा वरील bounds मध्ये दिली आहेत.

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> For lengths `n` and `m`, `O(n+m)` time and `O(1)` extra space.

## 10. Correctness

योग्यतेचा युक्तिवाद प्रत्येक शून्याला आधी एक धरून किमान बेरीज तपासणे यावर आधारित आहे; वरील अटी तपासा.

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> Replacing a zero by 1 yields the minimum because replacements must be positive. If an array has at least one zero, increasing that replacement realizes every integer sum at or above its minimum. A zero-free array has only its fixed sum. The code rejects exactly when a fixed sum lies below the other minimum; otherwise the maximum of the two minima is reachable by both and is the smallest common sum.

## 11. Mistakes and interview traps

लक्षात ठेवा: शून्य नसलेल्या array ची बेरीज पुढे वाढवता येत नाही.

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Zero replacement is at least 1, not 0.
- A zero means the sum is adjustable upward, not downward.
- Handle both impossible directions symmetrically.
- Use `long long` for sums.
- Problem values are positive except zero; don't interpret negative demo values as valid constraints.

## 12. Quick revision

थोडक्यात, प्रत्येक शून्याला आधी एक धरून किमान बेरीज तपासणे. शून्य नसलेल्या array ची बेरीज पुढे वाढवता येत नाही.

> **मराठी:** दोन मिनिटांच्या revision साठी pattern, मुख्य कल्पना आणि complexity आठवा.
> Minimum sum = nonzero sum + zero count. If lower side has no zero and is below other minimum, `-1`; else return max minima.

## 13. Related problems and variations

संबंधित प्रश्नांत दोन्ही arrays मधील शून्ये बदलून मिळणारी किमान समान बेरीज यासारखी अट बदलल्यास योग्य पद्धतही तपासा.

> **मराठी:** Related problem मध्ये constraints बदलल्यास approach कसा बदलेल ते विचारा.
> LeetCode 1838 (Frequency of the Most Frequent Element); 1482 (Minimum Number of Days); variations: bounded replacement values or minimizing a shared target with costs.

## 14. Self-assessment

वरील प्रश्न स्वतः सोडवून दोन्ही arrays मधील शून्ये बदलून मिळणारी किमान समान बेरीज याची उजळणी करा.

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why does every zero add 1 to the minimum sum?
2. When is a sum fixed?
3. Why is `max(min1,min2)` the minimum common sum when feasible?
