# Three Consecutive Odds — LeetCode 1550

## Problem, constraints आणि examples

Integer arrayमध्ये सलग तीन odd numbers आहेत का ते boolean स्वरूपात return करा. Arrayमध्ये तीनपेक्षा कमी elements असतील तर उत्तर false.
Example: `[2,4,1,3,5]` मध्ये window `[1,3,5]` odd → true. `[1,2,3,5,7]` मध्ये शेवटचे दोनच odd → false. Negative odd values देखील `%2 != 0` (codeचा nonzero remainder check) satisfy करतात.

## Pattern clues

| Clue                          | Pattern             |
| ----------------------------- | ------------------- |
| सलग fixed-length 3 window     | sliding-window scan |
| फक्त existence विचारले        | early return        |
| parityने property तपासता येते | `% 2` / bit parity  |

## Approaches

| Method                            | Status                               | Cost |
| --------------------------------- | ------------------------------------ | ---- |
| Scan each length-3 window         | Selected, correct `O(n)` / `O(1)`    |
| Track current consecutive-odd run | Correct `O(n)` / `O(1)`              |
| Count total odds in entire array  | Incorrect; odds adjacent असणे गरजेचे |
| Sort then inspect                 | Incorrect; original adjacency बदलते  |

Brute forceची गरज नाही; प्रत्येक possible start तपासणेच linear आहे.

## Flowchart

```mermaid
flowchart TD
    A[Set i=2] --> B{i < n?}
    B -- No --> Z[Return false]
    B -- Yes --> C{arr[i], arr[i-1], arr[i-2] all odd?}
    C -- Yes --> D[Return true]
    C -- No --> E[Increment i]
    E --> B
```

एका windowमध्ये तिन्ही parity tests pass झाल्यावर पुढे scan करण्याची गरज नसते.

## Selected algorithm, code-specific explanation, dry run

`threeConsecutiveOdds` index `2` पासून scan करतो आणि current तसेच मागील दोन valuesचे `%2` truthiness तपासतो. `main` test arrays print करतो; solutionचा output फक्त bool आहे.
Dry run (`[2,4,1,3,5]`):
| `i` | Triple | All odd? |
|---:|---|---|
| 2 | `2,4,1` | No |
| 3 | `4,1,3` | No |
| 4 | `1,3,5` | Yes → true |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> Length below 3, all-even input, or no consecutive odd triple returns false; the first matching window returns early.

## Complexity, correctness, traps

`O(n)` time, `O(1)` extra space. Correctness: प्रत्येक contiguous tripleचा शेवटचा index `2..n-1` पैकी नेमका एक; scan सर्व triples तपासतो आणि odd तिन्ही असतील तेव्हाच true देतो.
Mistakes: three odd values वेगळ्या ठिकाणी असणे पुरेसे नाही; `i=2` पासून सुरुवात; length < 3 मध्ये loop skip. Negative oddची remainder `1` नसू शकते; nonzero test म्हणून code ठीक.

## Quick revision, variations, self-check

पुनरावलोकन: प्रत्येक length-3 windowची parity तपासा.
Check `i,i-1,i-2`, return on first hit. Related: consecutive-run counting, fixed-size window checks.

1. `[1,3,2,5,7]` चे उत्तर?
2. length 2 arrayमध्ये loop का चालत नाही?
3. Total odd count condition पुरेशी का नाही?
4. Window सुरू करणारा पहिला index कोणता?
