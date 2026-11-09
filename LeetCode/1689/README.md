# Partitioning Into Minimum Number Of Deci-Binary Numbers — LeetCode 1689

## Problem, constraints आणि examples

Decimal string `n` ला फक्त decimal digit `0` किंवा `1` असलेल्या positive integersच्या बेरजेत लिहा; किमान किती numbers लागतात? `n` मोठी असू शकते, म्हणून stringवरच काम करा.
Example: `32 = 10+11+11`, answer `3`; `82734` answer `8`. कारण digit `8` ला 8 unit contributions लागतात; digit `2`-ला त्याच आठ numbersपैकी दोनमध्ये `1` पुरते.

## Pattern clues

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | each position digit independently needs unit contributions | greedy lower bound |
> | deci-binary digit max is 1 | maximum digit determines count |
> | input may exceed integer range | scan string, no parsing |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Status | Complexity |
> |---|---|---|
> | Scan and take maximum digit | Selected, correct `O(L)` / `O(1)` |
> | Early exit when digit `9` appears | Correct same asymptotic; small constant optimization |
> | `max_element` over chars | Correct `O(L)` / `O(1)` |
> | Convert whole string to integer then process | Unsafe for long input and unnecessary |
> | Return sum of digits | Incorrect; one deci-binary number contributes multiple positions simultaneously |

## Flowchart

```mermaid
flowchart TD
    A[best=0] --> B{More digits?}
    B -- No --> E[Return best]
    B -- Yes --> C[Convert current char to digit]
    C --> D[best = max(best,digit)]
    D --> F{best is 9?}
    F -- Yes --> G[Return 9]
    F -- No --> B
```

Maximum possible digit `9` मिळाल्यावर पुढील scan उत्तर बदलू शकत नाही.

## Selected algorithm, intuition आणि code

`minPartitions_Linear` प्रत्येक digitसाठी `result=max(result,c-'0')`. Lower bound: digit `d` असलेल्या positionवर `d` वेगळे `1`s लागतात; upper bound: प्रत्येक digitच्या rankपर्यंत एक deci-binary number तयार करता येतो. `minPartitions_EarlyExit` 9 वर थांबतो; STL version `max_element`. `main` तिन्ही compare करतो.
Dry run (`82734`):
| Digit | Current maximum |
|---:|---:|
| 8 | 8 |
| 2 | 8 |
| 7 | 8 |
| 3 | 8 |
| 4 | 8 |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> All zeros require 0 numbers; a digit 9 fixes the answer at 9; long inputs must stay strings.

## Complexity, correctness, traps

Each method `O(L)` time, `O(1)` auxiliary; string by value असल्यामुळे source-level parameter copy `O(L)` असू शकतो. Correctness lower-bound + construction argumentवर आधारित: maximum digit इतके layers पुरे आणि त्याहून कमी शक्य नाही.
Trap: मोठा string integerमध्ये convert करू नका; answer maximum digit आहे, digit sum नाही. Leading zeros असल्यास maximumवर परिणाम नाही.

## Quick revision, variations, self-check

पुनरावलोकन: उत्तर म्हणजे stringमधील maximum digit.
Answer `max digit`; 9 आढळल्यावर exit. Related: digit-wise greedy lower bounds, layer decomposition.

1. `273` साठी answer?
2. digit `0` ला किती `1`s हवेत?
3. digit sum किमान संख्या का देत नाही?
4. `9` मिळाल्यावर early return का सुरक्षित?
