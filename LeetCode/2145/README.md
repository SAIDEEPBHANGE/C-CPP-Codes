# Count the Hidden Sequences — LeetCode 2145

Source: `2145.cpp`; it tracks minimum and maximum prefix sums of `differences`.

## 1. Understanding — समजून घ्या

The hidden sequence has adjacent differences given by `differences`, and every value must lie in `[lower, upper]`. Count possible choices for the first value that keep the entire sequence in range.

## 2. Worked examples and edge cases

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> For differences `[1,-3,4]`, prefix offsets are `0,1,-2,2`; their range is `[-2,2]`, width 4. With `lower=1, upper=6`, there are `6-1-4+1=2` valid starts. Empty differences produce one-element sequences, so answer is `upper-lower+1`.

## 3. Pattern identification + cheat sheet

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | Adjacent differences fix all relative values | Prefix sums |
> | Unknown starting offset | Shift the whole prefix profile |
> | Every shifted value must fit one interval | Range-width counting |

## 4. Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> Brute force each possible first value and simulate all differences: O(width·n). The source is optimal O(n), tracking only minimum and maximum relative prefix values. Track both extrema; checking only the final prefix misses intermediate out-of-range values.

## 5. Flowchart

> **मराठी:** Flowchart मधील decision, loop आणि termination condition क्रमाने समजून घ्या.

```mermaid
flowchart TD
    A([Initialize prefix,min,max to 0]) --> B[Add next difference]
    B --> C[Update min and max prefix]
    C --> D{More differences?}
    D -- Yes --> B
    D -- No --> E[Compute upper-lower-(max-min)+1]
    E --> F{Count positive?}
    F -- Yes --> G[Return count]
    F -- No --> H[Return 0]
```

## 6. Algorithm and intuition

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> Let relative prefix values start at zero. The sequence is a translated copy of these prefixes, shifted by unknown `hidden[0]`. For the full translated range to fit inside `[lower,upper]`, the number of valid shifts is the interval width minus the prefix spread plus one.

## 7. Code explanation

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `PrefixSum` accumulates in `long long`; `LowerBound`/`HigherBound` track minimum and maximum prefixes, including the initial zero. It calculates `upper-lower-(max-min)+1` and clamps a nonpositive result to zero.

## 8. Dry run

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> For differences `[1,-3,4]`: prefixes `1,-2,2`; including zero gives min `-2`, max `2`, spread `4`. With bounds `[1,6]`, count=`6-1-4+1=2`.

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> **O(n)** time and **O(1)** extra space. The source uses 64-bit prefix and extrema values.

## 10. Correctness

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> Every hidden sequence is uniquely determined by its first value. The smallest relative prefix is `min` and largest is `max`, so after shifting by `x`, all values fit exactly when `x+min >= lower` and `x+max <= upper`. The count of integer `x` satisfying both inequalities is `max(0, upper-lower-(max-min)+1)`.

## 11. Mistakes and interview traps

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Include prefix offset zero, not only values after differences.
- Use the full prefix spread, not just final sum or maximum absolute prefix.
- Add one when counting inclusive integer starts.
- Use 64-bit for prefix sums and spread.

## 12. Quick revision — झटपट उजळणी

> **मराठी सारांश:** Prefix ची कमाल-किमान तफावत काढून शक्य सुरुवाती मोजा.
> Scan prefix sums; retain min/max including 0; answer `max(0, upper-lower-(max-min)+1)`.

## 13. Related problems and variations

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> Prefix-sum range constraints; count starting offsets for a walk; calculate feasible translations of an interval; find the number of starts for which a cumulative path remains bounded.

## 14. Self-assessment

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why must zero be included among prefix sums?
2. Why does only `maxPrefix-minPrefix` matter?
3. Where does the `+1` come from?
