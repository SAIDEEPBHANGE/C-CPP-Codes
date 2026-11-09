# Sort Colors — LeetCode 75

## 1. Understanding

फक्त 0, 1, 2 असलेला vector in-place `0,1,2` क्रमात लावा. Source मध्ये pairwise exchange, counting आणि दोन Dutch National Flag (DNF) versions आहेत.

## 2. Worked examples and edges

- `[2,0,2,1,1,0]` → `[0,0,1,1,2,2]`.
- `[2,0,1]` → `[0,1,2]`; empty/single-color inputsही source test करतो.
- Value set `{0,1,2}` असणे आवश्यक; counting methodचा `else` बाकी सर्व valuesना 2 मानतो.

## 3. Pattern identification + cheat sheet

| Clue                          | Pattern             | कारण                  |
| ----------------------------- | ------------------- | --------------------- |
| तीन categories, in-place      | Three-way partition | Low/mid/high regions  |
| Fixed small value domain      | Counting sort       | Counts नंतर overwrite |
| One-pass constant extra space | Dutch National Flag | Unknown range shrink  |

## 4. Approaches

- `sortColorsBubble`: nested pairwise swaps, O(n²), O(1); inefficient baseline (strictly speaking comparison exchange, not stable bubble sort).
- `sortColorsCounting`: count then rewrite, O(n), O(1), two passes.
- `sortColorsDutchFlag1/2`: O(n), O(1), one pass; optimal for in-place single-pass target.
- DNF `2` swap nंतर `mid` increment करू नका; swapped-in value unclassified.

## 5. Flowchart

```mermaid
flowchart TD
 A([Start]) --> B[Set low=mid=0 and high=n-1]
 B --> C{mid <= high?}
 C -- No --> G[Done]
 C -- Yes --> D{nums[mid]}
 D -- 0 --> E[Swap low and mid; increment both]
 D -- 1 --> F[Increment mid]
 D -- 2 --> H[Swap mid and high; decrement high only]
 E --> C
 F --> C
 H --> C
```

`mid` म्हणजे current unclassified value; 2 swap नंतर ती नव्याने तपासली जाते.

## 6. Algorithm / intuition

`[0,low)` मध्ये zeros, `[low,mid)` मध्ये ones, `(high,n)` मध्ये twos; `[mid,high]` unknown. Current 0 low कडे, 1 जागी, 2 high कडे.

## 7. Code explanation

`sortColorsDutchFlag2` clean version: 0 वर swap/increment low आणि mid; 1 वर mid++; अन्यथा 2 म्हणून high शी swap आणि high--. `DutchFlag1` 2 नंतर mid-- करून loop increment compensate करतो. `Counting` input पुन्हा लिहितो.

## 8. Dry run

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> `[2,0,1]`, `(low,mid,high)=(0,0,2)`:
> | current | operation | array | pointers |
> |---:|---|---|---|
> | 2 | swap mid/high | `[1,0,2]` | `(0,0,1)` |
> | 1 | advance mid | `[1,0,2]` | `(0,1,1)` |
> | 0 | swap low/mid | `[0,1,2]` | `(1,2,1)` done |

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Pairwise method O(n²); counting and both DNF methods O(n). Extra space O(1) for all.

## 10. Correctness

प्रत्येक iterationमध्ये classified regionsचा invariant टिकतो आणि unknown range एका elementने कमी होते. `mid>high` झाल्यावर unknown elements उरत नाहीत; सर्व zeros, ones, twos योग्य क्रमात असतात.

## 11. Mistakes and interview traps

- 2 swap केल्यावर current mid value तपासा.
- 0 swap आल्यावर mid आणि low दोन्ही advance होतात.
- `nums[mid]` फक्त 0/1/2 असल्याचे constraints गृहीत.
- Source चा `int high = nums.size()-1` empty-vector case मध्ये unsigned subtraction/conversion करतो; व्यवहार सामान्य platformsवर `-1`, पण robust code मध्ये empty check किंवा signed size वापरा.

## 12. Quick revision

Low/mid/high; 0 → left, 1 → mid पुढे, 2 → right. Unknown range संपेपर्यंत.

## 13. Related problems / variations

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> Partition Array by Pivot, sort 0s and 1s, QuickSort partition, three-way partition with duplicate keys.

## 14. Self-assessment

1. 2 ला high शी swap केल्यावर mid का तसाच?
2. DNF loop condition काय?
3. Counting आणि DNF मधील trade-off?
4. Empty array साठी signed boundary का उपयुक्त?
