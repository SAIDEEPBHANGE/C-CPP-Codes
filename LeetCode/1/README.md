# Two Sum — LeetCode 1

## 1. Understanding

`nums` मधील दोन वेगळ्या indices ची values मिळून `target` होतात; त्या indices परत करायच्या. Source मध्ये `twoSumOriginal` आणि `twoSumOptimized` आहेत.

## 2. Worked examples and edges

- `[2,7,11,15], target=9` → `[0,1]`.
- `[3,3], target=6` → दोन्ही equal values असूनही वेगळे indices `[0,1]`.
- `[0,4,3,0], target=0` → duplicate zero indices valid.
- Problem मध्ये exactly one answer असल्याची हमी आहे; source तरीही न मिळाल्यास empty vector परतवतो.

## 3. Pattern identification + cheat sheet

| Clue                                 | Pattern           | कारण                                                  |
| ------------------------------------ | ----------------- | ----------------------------------------------------- |
| Pair sum आणि indices विचारले आहेत    | Complement lookup | `target - nums[i]` शोधायचा                            |
| एका pass मध्ये पूर्वीची value उपयोगी | Hash map          | Seen values पटकन मिळतात                               |
| Sorted data / pair existence         | Two pointers      | पण येथे indices/order जपण्यासाठी sort करणे योग्य नाही |

## 4. Approaches

- Brute force: प्रत्येक pair तपासा — O(n²), O(1); समजायला सोपे.
- `twoSumOriginal`: प्रत्येक `i` साठी पुढील suffix मध्ये `find` — O(n²), O(1), accepted brute-force implementation.
- `twoSumOptimized`: complement-to-index hash map — expected O(n), O(n), optimal practical choice.
- चुकीचा trap: current value map मध्ये आधी घातली तर target 2x असताना तोच index दोनदा लागू शकतो.

## 5. Flowchart

```mermaid
flowchart TD
 A([Start]) --> B[Create empty value-to-index map]
 B --> C[Read nums[i]]
 C --> D[Find target - nums[i]]
 D --> E{Complement already seen?}
 E -- Yes --> F[Return seen index and i]
 E -- No --> G[Store nums[i] with index i]
 G --> H{More values?}
 H -- Yes --> C
 H -- No --> I[Return empty result]
```

Map आधी तपासतो, नंतर current item store करतो; त्यामुळे एकच item पुन्हा वापरला जात नाही.

## 6. Algorithm / intuition

प्रत्येक value `x` साठी `target-x` आधी पाहिला आहे का ते विचारा. असल्यास pair सापडतो; नसेल तर `x` चा index भविष्यातील values साठी ठेवा.

## 7. Code explanation

`twoSumOriginal` पुढील elements मध्ये `find` करतो आणि iterator चे index मध्ये रूपांतर `distance` ने करतो. `twoSumOptimized` unordered map मध्ये value→index ठेवतो व match मिळताच `{seen[complement], i}` परत करतो.

## 8. Dry run

`nums=[2,7,11], target=9`
| i | value | complement | map आधी | action |
|---:|---:|---:|---|---|
| 0 | 2 | 7 | `{}` | 2→0 store |
| 1 | 7 | 2 | `{2:0}` | match; return `[0,1]` |

## 9. Complexity

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Original: O(n²) time, O(1) auxiliary space. Hash map: expected O(n) time and O(n) space; worst-case hash operations can degrade.

## 10. Correctness

प्रत्येक index `i` आधी map मध्ये फक्त indices `< i` असतात. Complement सापडल्यास त्याची value आणि `nums[i]` यांची बेरीज target असते आणि indices distinct असतात. Pair नसल्यास scan नंतर map मध्ये नसलेला valid earlier complement नव्हता.

## 11. Mistakes and interview traps

- Values नव्हे, indices परत करा.
- Duplicate values असू शकतात; map मध्ये फक्त value आहे म्हणून pair नाकारू नका.
- Sort करून two pointers लावल्यास original indices हरवतात (index tracking शिवाय).
- Expected O(n) म्हणताना hash-table worst case लक्षात ठेवा.

## 12. Quick revision

`complement = target - nums[i]`; आधी lookup, मग insert. दोन distinct indices, one pass, hash map.

## 13. Related problems / variations

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> 3Sum, 4Sum, Two Sum II (sorted input), count pairs with given sum.

## 14. Self-assessment

1. Lookup insertion च्या आधी का?
2. `[3,3]`, target 6 कसे हाताळले जाते?
3. Hash-map आणि nested-loop complexities काय?
4. Input sorted असता कोणता पर्याय उपयोगी?
