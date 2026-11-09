# Build Array from Permutation — LeetCode 1920

## Problem, constraints आणि examples

Given permutation `nums` of `[0,n-1]`, build `ans[i]=nums[nums[i]]`. Input permutation valid असल्याने nested lookup indicesमध्ये राहतो.
Example: `[0,2,1,5,3,4]`: `i=0` gives `nums[nums[0]]=0`; `i=1` gives `nums[2]=1`; full result `[0,1,2,4,5,3]`. For `[1,0]`, result `[0,1]`.

## Pattern clues

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | output position references input position twice | composition of mapping |
> | each result independent from original | direct indexed transform |
> | permutation bounds indices | no search needed |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Status | Cost |
> |---|---|---|
> | Build separate result vector | Selected, correct `O(n)` time / `O(n)` output |
> | In-place encoding | Possible with extra encoding constraints, not used here |
> | Search for value at every step | Correct but unnecessary `O(n²)` |
> | Use `nums[i]` only | Incorrect; misses second lookup |

## Flowchart

```mermaid
flowchart TD
    A[Create empty Result] --> B{More indices i?}
    B -- Yes --> C[Read j=nums[i]]
    C --> D[Append nums[j]]
    D --> B
    B -- No --> E[Return Result]
```

`nums` बदलत नाही, त्यामुळे पुढील input lookupला आधीच्या outputचा परिणाम होत नाही.

## Selected algorithm, source explanation, dry run

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> `buildArray` loops `i=0..n-1` and pushes `nums[nums[i]]` to `Result`. `main` copies test vector, calls method and prints output.
> Dry run (`[0,2,1,5,3,4]`):
> | i | `nums[i]` | `nums[nums[i]]` |
> |---:|---:|---:|
> | 0 | 0 | 0 |
> | 1 | 2 | 1 |
> | 2 | 1 | 2 |
> | 3 | 5 | 4 |
> | 4 | 3 | 5 |
> | 5 | 4 | 3 |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> A one-element permutation maps to itself; identity permutations remain unchanged.

## Complexity, correctness, traps

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> `O(n)` time, `O(n)` output space. Correctness: iteration `i` appends exactly the definition `nums[nums[i]]`; one pass visits every output index in order.
> Trap: indices are zero-based; do not overwrite input in place without preserving values still needed for later lookups. Output itself occupies `O(n)`.

## Quick revision, variations, self-check

पुनरावलोकन: प्रत्येक outputसाठी nested lookup करा.
Compose mapping twice and append. Related: array mapping composition, in-place permutation encoding.

1. What is output at index 1 for `[0,2,1]`?
2. Why is `nums[nums[i]]` safe?
3. What changes if input is modified during the loop?
4. Can a separate result avoid overwrite hazards?
