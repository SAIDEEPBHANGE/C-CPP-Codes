# 2563 — Count the Number of Fair Pairs

## 1. Understanding

या प्रश्नाचा गाभा म्हणजे दिलेल्या समावेशक मर्यादेत बेरीज असलेल्या index जोड्यांची मोजणी.

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> Count index pairs `i<j` whose sum lies in the inclusive interval `[lower, upper]`. Equal values at different indices are valid separate choices.

## 2. Worked examples and edge cases

उदाहरणे आणि सीमाप्रकरणांत दिलेल्या समावेशक मर्यादेत बेरीज असलेल्या index जोड्यांची मोजणी कशी लागू होते ते पाहा.

> **मराठी:** उदाहरणातील input पासून output पर्यंत प्रत्येक बदल समजून घ्या.
> For `[5,5,5,5]`, range `[10,10]`, all `4 choose 2 = 6` pairs qualify. For sorted `[1,3,5]` and range `[4,6]`, pairs `(1,3)` and `(1,5)` qualify; endpoints are included.

## 3. Pattern identification + cheat sheet

येथे मुख्य pattern म्हणजे sorted array मध्ये योग्य partner ची सीमा शोधणे; वरील तुलना लक्षात घ्या.

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> This is **sort + binary search over valid partner ranges**.
> | Need for each `i` | Search |
> |---|---|
> | First partner sum `>= lower` | `lower_bound(lower-nums[i])` |
> | First partner sum `> upper` | `upper_bound(upper-nums[i])` |
> | Keep `i<j` | Search only suffix beginning at `i+1` |

## 4. Approaches

पद्धतींची तुलना करताना sorted array मध्ये योग्य partner ची सीमा शोधणे याचा वेळ आणि जागेवरील परिणाम पाहा.

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.

- Check every pair: brute force `O(n²)`.
- Sort and use two pointers to count sums `<=X`, then subtract counts for `<lower`.
- The source sorts and performs two binary searches per `i`, `O(n log n)`.

## 5. Flowchart

आकृतीमध्ये sorted array मध्ये योग्य partner ची सीमा शोधणे ही प्रक्रिया क्रमाने दाखवली आहे.

> **मराठी:** Flowchart मध्ये प्रत्येक decision, loop आणि loop कधी थांबतो ते पाहा.

```mermaid
flowchart TD
    A[Sort nums] --> B[Choose i]
    B --> C[Search suffix i+1..end for lower-nums[i]]
    C --> D[Search suffix for first value > upper-nums[i]]
    D --> E[Add iterator distance to count]
    E --> F{More i?}
    F -->|yes| B
    F -->|no| G[Return long long count]
```

The interval of acceptable partners is `[left,right)`, so its length gives the number of partners.

## 6. Algorithm and intuition

मूळ कल्पना: sorted array मध्ये योग्य partner ची सीमा शोधणे.

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> Sorting makes partner values monotonic. For each `nums[i]`, valid partners satisfy `lower-nums[i] <= nums[j] <= upper-nums[i]`. `lower_bound` finds the first inclusive lower endpoint; `upper_bound` finds the first value past the inclusive upper endpoint. Restricting searches to `i+1...` prevents using an index twice or counting a pair twice.

## 7. Code explanation

Code मधील state आणि updates हे sorted array मध्ये योग्य partner ची सीमा शोधणे या कल्पनेशी जोडून वाचा.

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `countFairPairs` sorts the input in place, initializes a `long long` count, then adds `right-left` iterator distance per `i`. The bounds are computed from the current value; the answer can be quadratic, hence `long long`.

## 8. Dry run

Dry run मध्ये sorted array मध्ये योग्य partner ची सीमा शोधणे कसे घडते ते प्रत्येक टप्प्यावर तपासा.

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> For `[1,3,5]`, bounds `[4,6]`:
> | `i`, value | acceptable partner values | Added |
> |---|---|---:|
> | 0, 1 | `[3,5]` | 2 |
> | 1, 3 | `[1,3]` in suffix `[5]`: none | 0 |
> | 2, 5 | no suffix | 0 |
> Total `2`.

## 9. Complexity

sorted array मध्ये योग्य partner ची सीमा शोधणे यासाठी लागणारा वेळ आणि अतिरिक्त जागा वरील bounds मध्ये दिली आहेत.

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Sorting `O(n log n)` plus `n` pairs of binary searches: `O(n log n)` time. `O(1)` extra space apart from sorting implementation stack.

## 10. Correctness

योग्यतेचा युक्तिवाद sorted array मध्ये योग्य partner ची सीमा शोधणे यावर आधारित आहे; वरील अटी तपासा.

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> For fixed `i`, the suffix contains exactly candidates with `j>i`. Since it is sorted, all values satisfying the inclusive sum bounds form one contiguous interval. The two binary searches return precisely its start and end, so `right-left` counts exactly the valid partners. Every pair is counted once at its smaller index.

## 11. Mistakes and interview traps

लक्षात ठेवा: lower आणि upper दोन्ही सीमा समाविष्ट आहेत.

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Use `upper_bound` for inclusive upper bound.
- Search from `i+1`, not from the full array.
- Preserve duplicates; equal values at distinct indices count.
- Sorting mutates `nums`; use a copy if input preservation is required.
- Return/count in 64-bit type.

## 12. Quick revision

थोडक्यात, sorted array मध्ये योग्य partner ची सीमा शोधणे. lower आणि upper दोन्ही सीमा समाविष्ट आहेत.

> **मराठी:** दोन मिनिटांच्या revision साठी pattern, मुख्य कल्पना आणि complexity आठवा.
> Sort; for each `i`, count suffix values in `[lower-a[i],upper-a[i]]` using `lower_bound` and `upper_bound`.

## 13. Related problems and variations

संबंधित प्रश्नांत दिलेल्या समावेशक मर्यादेत बेरीज असलेल्या index जोड्यांची मोजणी यासारखी अट बदलल्यास योग्य पद्धतही तपासा.

> **मराठी:** Related problem मध्ये constraints बदलल्यास approach कसा बदलेल ते विचारा.
> LeetCode 1 (Two Sum); 167 (Two Sum II); 327 (Count of Range Sum); variations: count pairs `<=X` with two pointers.

## 14. Self-assessment

वरील प्रश्न स्वतः सोडवून दिलेल्या समावेशक मर्यादेत बेरीज असलेल्या index जोड्यांची मोजणी याची उजळणी करा.

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why is the search range restricted to indices after `i`?
2. Why do `lower_bound` and `upper_bound` differ here?
3. Why can the answer require 64-bit storage?
