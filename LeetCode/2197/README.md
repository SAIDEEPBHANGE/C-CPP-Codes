# Replace Non-Coprime Numbers in Array — LeetCode 2197

Source: `2197.cpp` includes a restart-and-erase method and a stack method. The stack method is the efficient implementation.

## 1. Understanding — समजून घ्या

Repeatedly replace adjacent non-coprime numbers by their least common multiple until every adjacent pair is coprime. Return the resulting array.

## 2. Worked examples and edge cases

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> `[6,4,3]`: `6` and `4` merge to `12`; `12` and `3` merge to `12` → `[12]`. A gcd of 1 means no merge. Values equal to 1 never merge with another value.

## 3. Pattern identification + cheat sheet

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | Only adjacent items interact | Stack |
> | A merge can enable another merge | Repeatedly compare new value to stack top |
> | Need LCM | `a/gcd(a,b)*b` |

## 4. Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> The restart method checks neighbors, erases from the vector, and restarts at index 1; it is simple but incurs shifting and rescanning. The stack method processes each input once and merges backward as needed. A single left-to-right pass without rechecking the previous stack top is incorrect because one merge can create a new non-coprime adjacency.

## 5. Flowchart

> **मराठी:** Flowchart मधील decision, loop आणि termination condition क्रमाने समजून घ्या.

```mermaid
flowchart TD
    A([Read next value x]) --> B{Stack empty?}
    B -- Yes --> H[Push x]
    B -- No --> C[Compute gcd(top,x)]
    C --> D{gcd is 1?}
    D -- Yes --> H
    D -- No --> E[Replace x with lcm(top,x)]
    E --> F[Pop stack top]
    F --> B
    H --> G{More input?}
    G -- Yes --> A
    G -- No --> Z([Return stack])
```

## 6. Algorithm and intuition

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> For each value `x`, compare it with the current stack top. If coprime, push `x`. Otherwise replace both by their LCM, pop the old top, and continue checking the merged value against the new top. Push once no further merge is needed.

## 7. Code explanation

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `GCD` is iterative Euclid. `replaceNonCoprimesStack` stores merged values as `long long`, repeatedly computes `(top*curr)/gcd`, then converts final values to `int` per problem constraints. `replaceNonCoprimesBrute` mutates the input and restarts after each erase.

## 8. Dry run

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> Input `[6,4,3]`: push 6; `gcd(6,4)=2` → merge to 12, pop 6; `gcd(12,3)=3` → merge to 12, pop; push 12 → `[12]`.

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Stack method uses **O(n)** pushes/pops and **O(n)** space, plus GCD work per merge; a safe bound is **O(n log M)** GCD operations when intermediate magnitudes are bounded by `M`. The restart/erase variant can be quadratic or worse due to vector shifts and rescans.

## 10. Correctness

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> The stack represents a fully reduced prefix: all adjacent stack values are coprime. For each new value, merging while the top is non-coprime is necessary to restore that invariant; after merges stop, pushing restores it. Since only adjacent pairs can interact, any future merge can involve the current value and its new stack neighbor, exactly what the loop checks.

## 11. Mistakes and interview traps

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Recheck after each merge; LCM may share factors with an earlier value.
- Use LCM, not product: divide by gcd.
- Widen multiplication before computing LCM.
- Be explicit about input mutation: the brute version erases from `nums`; stack version does not.
- The final cast to `int` relies on problem bounds.

## 12. Quick revision — झटपट उजळणी

> **मराठी सारांश:** वरचा घटक non-coprime असेपर्यंत LCM करून मागे तपासा.
> Push; while `gcd(top,x)>1`, set `x=lcm(top,x)` and pop; push final `x`.

## 13. Related problems and variations

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> Monotonic/combining stacks; reduce adjacent fractions; simplify neighboring values; use a stack whenever processing a new item can repeatedly merge with a suffix.

## 14. Self-assessment

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why can a merge require checking an earlier stack element?
2. How is LCM computed without multiplying unnecessarily?
3. What invariant does the stack maintain?
