# Minimum Deletions to Make String Balanced — LeetCode 1653

## Problem, constraints आणि examples

Stringमध्ये फक्त `a,b`. Balanced म्हणजे कोणताही `b` हा कोणत्याही `a`च्या आधी येत नाही; रूप `aaa...bbb...` असते. Minimum characters delete करा.
Example: `aababbab`: split नंतर left-side `b`s आणि right-side `a`s मोजल्यास best deletion `2`. `aaaa`, `bbbb`, empty string यांना `0` deletions.

## Pattern clues

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | final string is `a* b*` | choose split point |
> | delete misplaced chars on either side | prefix/suffix counts |
> | scan can retain best prefix state | one-pass DP/greedy |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Status | Cost |
> |---|---|---|
> | Prefix `b` count + suffix `a` count for every split | Correct `O(n)` / `O(n)` |
> | One-pass DP/greedy (`b_count`, `deletions`) | Selected `O(n)` / `O(1)` |
> | Full DP array | Correct `O(n)` / `O(n)` |
> | Delete first encountered `ba` pair repeatedly | Can be correct with iteration, but inefficient; arbitrary single deletion is not necessarily optimal |

## Flowchart

```mermaid
flowchart TD
    A[deletions=0, b_count=0] --> B{More characters?}
    B -- No --> E[Return deletions]
    B -- Yes --> C{Current char is b?}
    C -- Yes --> D[Increment b_count]
    C -- No, current is a --> F[deletions = min(deletions+1, b_count)]
    D --> B
    F --> B
```

`a` आल्यावर दोन पर्याय: हे `a` delete करा, किंवा आधीचे सर्व `b` delete करा.

## Selected algorithm, code आणि dry run

`minimumDeletionsGreedy` हे recurrence लागू करतो. `minimumDeletionsPrefixSuffix` प्रत्येक splitचा `prefixB+suffixA`; `minimumDeletionsDP` हाच recurrence arrayमध्ये ठेवतो. `main` तीन पद्धती compare करतो.
Dry run (`s="ba"`):
| char | `b_count` before | decision | deletions after |
|---|---:|---|---:|
| `b` | 0 | keep, increment b count | 0 |
| `a` | 1 | min(delete `a`:1, delete prior `b`:1) | 1 |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> All-a, all-b, and empty strings need 0 deletions; alternating patterns exercise both choices.

## Complexity, correctness, traps

Greedy `O(n)` time, `O(1)` space. Correctness: प्रत्येक prefixचा optimal cost राखतो; `b` जोडल्याने cost बदलत नाही, `a` जोडल्यावर optimal उपाय फक्त `a` delete करणे किंवा preceding `b`s delete करणे यांपैकी एक.
Trap: balanced म्हणजे all `a` before all `b`; counts equal असणे नव्हे. Prefix/suffix split endpoints `0` आणि `n` समाविष्ट करा.

## Quick revision, variations, self-check

पुनरावलोकन: `a` आल्यावर delete it किंवा आधीचे `b`s delete करा.
On `b`: count; on `a`: `min(cost+1,b_count)`. Related: partitioning strings, prefix/suffix minima, sequence editing DP.

1. `ba` चा minimum किती?
2. `a` आल्यावर दोन पर्याय कोणते?
3. `b` आल्यावर deletions का बदलत नाहीत?
4. Prefix-suffix पद्धतीत split `n` काय दर्शवतो?
