# Find Triangular Sum of an Array — LeetCode 2221

Source: `2221.cpp`; `triangularSum` overwrites the input with each row of pairwise sums modulo 10.

## 1. Understanding — समजून घ्या

Repeatedly replace each adjacent pair by their sum modulo 10 until one number remains. Return that number.

## 2. Worked examples and edge cases

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> `[1,2,3,4,5]` → `[3,5,7,9]` → `[8,2,6]` → `[0,8]` → `[8]`. A one-element input returns itself. The judge guarantees a nonempty array.

## 3. Pattern identification + cheat sheet

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | Repeated adjacent reductions | In-place simulation |
> | Modulo at each combine step | Local recurrence |
> | Row shrinks by one | Triangular O(n²) process |

## 4. Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> Direct simulation mirrors the definition and uses O(1) extra space. A binomial-coefficient formula can reduce operation count only with careful modulo-10 arithmetic; ordinary modular division is unsafe because 10 is composite. Recomputing a separate array every round is correct but uses O(n) extra space.

## 5. Flowchart

> **मराठी:** Flowchart मधील decision, loop आणि termination condition क्रमाने समजून घ्या.

```mermaid
flowchart TD
    A([Set active length n]) --> B{n greater than 1?}
    B -- No --> Z[Return nums[0]]
    B -- Yes --> C[For i=1..n-1 set nums[i-1]=(nums[i-1]+nums[i]) mod 10]
    C --> D[Decrease n by 1]
    D --> B
```

Only the active prefix is needed for the next row.

## 6. Algorithm and intuition

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> For each row, update left-to-right: write the pair result into the left slot. The next pair still reads the untouched right slot. Then reduce the active length by one and repeat.

## 7. Code explanation

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `triangularSum` sets `n=nums.size()`, loops while `n>0`, computes each adjacent sum modulo 10 into `nums[i-1]`, then decrements `n`. It mutates its argument; only `nums[0]` is returned.

## 8. Dry run

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> `[1,2,3]`: first row writes `3,5` → active `[3,5]`; next writes `8` → answer `8`.

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> **O(n²)** time from `n-1 + n-2 + ... + 1` updates and **O(1)** extra space. The input array is modified.

## 10. Correctness

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> Each update stores exactly the required next-row value `(nums[i-1]+nums[i])%10`. Left-to-right order does not overwrite `nums[i]` before it is read. Repeating for the shrinking active prefix performs every reduction row, leaving the specified final value.

## 11. Mistakes and interview traps

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Apply `%10` at every pair combination.
- Iterate left-to-right so the right operand remains from the old row.
- Track the shrinking prefix; stale suffix values are irrelevant.
- Empty input would access `nums[0]`; judge constraints guarantee nonempty input.

## 12. Quick revision — झटपट उजळणी

> **मराठी सारांश:** शेजारच्या संख्यांची बेरीज mod 10 करून active भाग कमी करा.
> Update left neighbor with pair sum mod 10; shrink the active length until one remains.

## 13. Related problems and variations

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> Pascal-triangle reduction; repeated adjacent transforms; compute the final value with binomial coefficients; in-place rolling-array simulation.

## 14. Self-assessment

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why is left-to-right update safe in place?
2. How many pair updates occur overall?
3. Why is simple modular division by binomial coefficients risky modulo 10?
