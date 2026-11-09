# 2778 — Sum of Squares of Special Elements

## 1. Understanding

या प्रश्नाचा गाभा म्हणजे array लांबीचे विभाजक असलेल्या indices वरील वर्गांची बेरीज.

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> For an array of length `n`, index `i` (1-based) is special if `i` divides `n`. Return the sum of squares of values at special positions.

## 2. Worked examples and edge cases

उदाहरणे आणि सीमाप्रकरणांत array लांबीचे विभाजक असलेल्या indices वरील वर्गांची बेरीज कशी लागू होते ते पाहा.

> **मराठी:** उदाहरणातील input पासून output पर्यंत प्रत्येक बदल समजून घ्या.
> For `[1,2,3,4]`, `n=4`; special positions are 1, 2, 4, so answer is `1²+2²+4²=21`. An array of length 1 has one special position. If all values are 1, answer equals the number of divisors of `n`.

## 3. Pattern identification + cheat sheet

येथे मुख्य pattern म्हणजे प्रत्येक एक-आधारित index ची विभाज्यता तपासणे; वरील तुलना लक्षात घ्या.

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> This is **direct constraint scan / divisibility test**.
> | Array position | Test |
> |---|---|
> | C++ index `i` | Convert to 1-based position `i+1` |
> | Special condition | `n % (i+1) == 0` |
> | Contribution | `nums[i]*nums[i]` |

## 4. Approaches

पद्धतींची तुलना करताना प्रत्येक एक-आधारित index ची विभाज्यता तपासणे याचा वेळ आणि जागेवरील परिणाम पाहा.

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> Check every divisor and map positions, or simply scan the array once. Factoring `n` is unnecessary because the array values must still be accessed at those positions.

## 5. Flowchart

आकृतीमध्ये प्रत्येक एक-आधारित index ची विभाज्यता तपासणे ही प्रक्रिया क्रमाने दाखवली आहे.

> **मराठी:** Flowchart मध्ये प्रत्येक decision, loop आणि loop कधी थांबतो ते पाहा.

```mermaid
flowchart TD
    A[Set result=0] --> B[Scan index i from 0 to n-1]
    B --> C{n divisible by i+1?}
    C -->|yes| D[Add nums[i]^2]
    C -->|no| E[Skip]
    D --> F{More positions?}
    E --> F
    F -->|yes| B
    F -->|no| G[Return result]
```

The condition uses a 1-based position even though the loop is zero-based.

## 6. Algorithm and intuition

मूळ कल्पना: प्रत्येक एक-आधारित index ची विभाज्यता तपासणे.

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> The definition is already a per-index divisibility condition, so check each index, add its square if it divides the array length, and return the sum.

## 7. Code explanation

Code मधील state आणि updates हे प्रत्येक एक-आधारित index ची विभाज्यता तपासणे या कल्पनेशी जोडून वाचा.

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `sumOfSquares` stores `n`, scans `i=0...n-1`, tests `n%(i+1)==0`, and adds `nums[i]*nums[i]`. `main` exercises several arrays; the judge-facing method takes a vector reference.

## 8. Dry run

Dry run मध्ये प्रत्येक एक-आधारित index ची विभाज्यता तपासणे कसे घडते ते प्रत्येक टप्प्यावर तपासा.

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> For `[1,2,3,4]`:
> | `i` | Position `i+1` | `4 % position` | Contribution |
> |---:|---:|---:|---:|
> | 0 | 1 | 0 | 1 |
> | 1 | 2 | 0 | 4 |
> | 2 | 3 | 1 | 0 |
> | 3 | 4 | 0 | 16 |
> Total `21`.

## 9. Complexity

प्रत्येक एक-आधारित index ची विभाज्यता तपासणे यासाठी लागणारा वेळ आणि अतिरिक्त जागा वरील bounds मध्ये दिली आहेत.

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> `O(n)` time and `O(1)` extra space.

## 10. Correctness

योग्यतेचा युक्तिवाद प्रत्येक एक-आधारित index ची विभाज्यता तपासणे यावर आधारित आहे; वरील अटी तपासा.

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> The loop visits every array element exactly once. It adds the square exactly when its 1-based position divides `n`, which is the problem's definition of a special element. Thus every required contribution is included once and every other contribution is excluded.

## 11. Mistakes and interview traps

लक्षात ठेवा: array चा zero-based index आणि प्रश्नातील index वेगळे आहेत.

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Use `i+1`, not `i`; index zero cannot be a divisor.
- Square the value, not its index.
- Include all divisors, including 1 and `n`.
- Check integer bounds if adapting to larger values (the source returns `int` under given constraints).

## 12. Quick revision

थोडक्यात, प्रत्येक एक-आधारित index ची विभाज्यता तपासणे. array चा zero-based index आणि प्रश्नातील index वेगळे आहेत.

> **मराठी:** दोन मिनिटांच्या revision साठी pattern, मुख्य कल्पना आणि complexity आठवा.
> For each `i`, if `n%(i+1)==0`, add `nums[i]*nums[i]`.

## 13. Related problems and variations

संबंधित प्रश्नांत array लांबीचे विभाजक असलेल्या indices वरील वर्गांची बेरीज यासारखी अट बदलल्यास योग्य पद्धतही तपासा.

> **मराठी:** Related problem मध्ये constraints बदलल्यास approach कसा बदलेल ते विचारा.
> LeetCode 1952 (Three Divisors); divisor enumeration tasks; variations: count special positions or sum another function of their values.

## 14. Self-assessment

वरील प्रश्न स्वतः सोडवून array लांबीचे विभाजक असलेल्या indices वरील वर्गांची बेरीज याची उजळणी करा.

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why is the modulo divisor `i+1`?
2. Which positions are special for `n=6`?
3. What is the time and space complexity?
