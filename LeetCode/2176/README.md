# Count Equal and Divisible Pairs in an Array — LeetCode 2176

Source: `2176.cpp` includes `countPairsBruteForce` and `countPairsOptimized`; the latter groups indices by value but still checks pairs within each group.

## 1. Understanding — समजून घ्या

Count index pairs `(i,j)` with `i<j`, equal values `nums[i]==nums[j]`, and `(i*j)%k==0`.

## 2. Worked examples and edge cases

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> For `[3,1,2,2,2,1,3]`, `k=2`, the pair `(2,4)` has equal 2s and product 8, so it counts. Pair `(1,5)` has equal 1s but product 5, so it does not. Index zero makes the product zero, divisible by every positive `k`.

## 3. Pattern identification + cheat sheet

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Condition | Technique |
> |---|---|
> | Pair indices `i<j` | Nested pair enumeration |
> | Equality filters candidate pairs | Group indices by value |
> | Extra modular predicate | Check product modulo `k` |

## 4. Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> The direct nested loop is O(n²). The source's grouped method avoids comparing unequal values, but remains O(sum fᵥ²), which is O(n²) worst-case; it is not asymptotically better. A more advanced solution can group indices by value and residue/GCD classes when constraints justify it. Never test divisibility of a value instead of the index product.

## 5. Flowchart

> **मराठी:** Flowchart मधील decision, loop आणि termination condition क्रमाने समजून घ्या.

```mermaid
flowchart TD
    A([Group indices by value]) --> B[Choose a value group]
    B --> C[Enumerate pairs i<j in group]
    C --> D{(i*j) mod k equals 0?}
    D -- Yes --> E[Increment answer]
    D -- No --> F[Skip]
    E --> G{More pairs/groups?}
    F --> G
    G -- Yes --> C
    G -- No --> Z([Return answer])
```

## 6. Algorithm and intuition

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> Only indices with the same array value can form a valid pair. Group those indices, enumerate each unordered pair once using positions `a<b` within the group, and test the original indices' product modulo `k`.

## 7. Code explanation

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `countPairsBruteForce` visits every `i<j` and checks both predicates. `countPairsOptimized` fills `unordered_map<int,vector<int>> indexMap`, then runs a nested loop in each vector and checks `(indices[i]*indices[j])%k`.

## 8. Dry run

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> For equal-value indices `[2,3,4]` and `k=2`: pairs `(2,3)` product 6 ✓, `(2,4)` product 8 ✓, `(3,4)` product 12 ✓. Each contributes one.

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Brute force **O(n²)** time, **O(1)** extra space. Grouped version expected **O(n + Σ fᵥ²)** time, **O(n)** space; worst case **O(n²)** time.

## 10. Correctness

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> Grouping partitions indices by value, so every pair with equal values appears in exactly one group, and no unequal pair is considered. The inner loop enumerates every pair of distinct indices in that group once; the modulo test is exactly the remaining condition.

## 11. Mistakes and interview traps

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Require `i<j`; do not pair an index with itself.
- Use zero-based indices exactly as specified.
- The condition is `(i*j)%k`, not `(nums[i]*nums[j])%k`.
- `k` is positive by constraint.
- Grouping reduces irrelevant comparisons but does not improve worst-case asymptotics here.

## 12. Quick revision — झटपट उजळणी

> **मराठी सारांश:** समान मूल्यांच्या दोन निर्देशांकांची गुणाकार-अट तपासा.
> Group matching values → enumerate `i<j` → count when `i*j` is divisible by `k`.

## 13. Related problems and variations

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> Equal-value pairs; count pairs satisfying index residues; use modular arithmetic to avoid overflow for larger indices; count pairs where index sum/product meets a condition.

## 14. Self-assessment

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why is grouping correct for the equality condition?
2. What is the worst-case grouped complexity?
3. Why does any pair containing index 0 pass the divisibility test?
