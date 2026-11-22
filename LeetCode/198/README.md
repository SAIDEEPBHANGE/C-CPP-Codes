# 198. House Robber

## 1. Problem Understanding

`nums[i]` हे `i`व्या घरात असलेले पैसे आहेत. शेजारील घरे एकाच रात्री rob करू शकत नाही, कारण alarm system trigger होईल. Rob केलेल्या घरांमधून मिळू शकणारी maximum रक्कम return करायची.
म्हणजेच कोणतीही दोन निवडलेली indices adjacent नसावीत. प्रत्येक घर skip करणे शक्य आहे; रिकाम्या input साठी उत्तर `0`.

## 2. Example Understanding

### Example 1

```text
nums = [1, 2, 3, 1]
Output: 4
```

`1`ला घर rob करा (`1`), दुसरे घर skip; `3`रे घर rob करा (`3`), चौथे skip. Total `1+3=4`. `2+1=3`; त्यामुळे maximum `4`.

### Example 2

```text
nums = [2, 7, 9, 3, 1]
Output: 12
```

`2 + 9 + 1 = 12`, आणि निवडलेली घरे एकमेकांना लागून नाहीत. सलग घरे `7` आणि `9` दोन्ही घेता येत नाहीत.

### Edge cases

- `[]` → `0`.
- `[5]` → `5`.
- `[10,5]` → `10`.
- सर्व values `0` असतील तर `0`.

## 3. Problem Identification

“Maximum total” सोबत **adjacent choices mutually exclusive** हा मुख्य clue. प्रत्येक घरासाठी दोन decisions आहेत: rob करा किंवा skip करा. हा linear dynamic programming / take-or-skip pattern आहे.
स्वतःला विचारा:

1. Current decision चा पुढच्या index वर काय परिणाम? Rob केल्यास पुढचे घर घेता येत नाही.
2. State कमी करता येईल का? `i` पासूनचा best answer.
3. Overlapping subproblems आहेत का? होय; recursion मध्ये पुढील indices पुन्हा पुन्हा येतात.
4. फक्त मागील दोन computed results पुरेसे आहेत का? होय, त्यामुळे O(1) space शक्य.

### Pattern Recognition Cheat Sheet

| Clue in Question                        | Possible Pattern   | Why?                                                       |
| --------------------------------------- | ------------------ | ---------------------------------------------------------- |
| Adjacent items एकत्र निवडता येत नाहीत   | Take/skip DP       | निवडल्यास पुढील state बदलतो                                |
| Linear row / sequence                   | 1D DP              | प्रत्येक index चा optimum आधीच्या छोट्या states वर अवलंबून |
| “Maximum sum” with constraint           | Optimization DP    | प्रत्येक स्थानावर best decision तुलना करावी लागते          |
| Same recursive states पुन्हा येतात      | Memoization        | प्रत्येक index चा result cache करता येतो                   |
| Recurrence फक्त मागील दोन states वापरते | Space optimization | पूर्ण DP array ऐवजी दोन variables पुरतात                   |

याच pattern चे cousins: non-adjacent maximum sum, minimum cost jumps, आणि काही scheduling/selection problems.

## 4. Different Approaches

### A. Recursion — brute force

Index `i` वर:

- Rob: `nums[i] + solve(i+2)`.
- Skip: `solve(i+1)`.
- दोघांपैकी maximum.
  Correct recurrence आहे, पण अनेक suffixes पुन्हा calculate होतात. Time `O(2^n)` worst case; recursion stack `O(n)`. Tiny input/recurrence derive करण्यासाठी, large input-க்கு இல்லை.

### B. Recursion + memoization (top-down DP)

`dp[i]` मध्ये index `i` पासून rob करता येणारी maximum रकम cache करा. `dp[i]` आधी computed असेल तर पुन्हा recursion करू नका.

- Time: `O(n)`, space: `O(n)` cache + recursion stack.
- Recurrence समजायला सोपी; large input साठी योग्य.

### C. Tabulation (bottom-up DP)

`dp[i]` = पहिल्या `i` घरांमधील best total. घर `i-1` घेतले तर `dp[i-2] + nums[i-1]`; skip केले तर `dp[i-1]`. त्यामुळे:
`dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])`

- Time: `O(n)`, space: `O(n)`.
- Recursion stack नाही; state table पाहता येतो.

### D. Space-optimized DP

Tabulation ला फक्त मागील दोन values लागतात. Code मधील `prev2` म्हणजे दोन steps मागचा best; `prev1` म्हणजे मागील घरांपर्यंतचा best. Current = `max(prev1, prev2 + nums[i])`.

- Time: `O(n)`, extra space: `O(1)`.
- **Final recommended method:** `robOptimized`.
  | Approach | Time | Space | Pros | Cons |
  |---|---:|---:|---|---|
  | Plain recursion | `O(2^n)` | `O(n)` stack | Recurrence सहज derive होते | Repeated work, large input ला slow |
  | Memoization | `O(n)` | `O(n)` | Natural top-down DP | Cache व stack लागतात |
  | Tabulation | `O(n)` | `O(n)` | Iterative, states स्पष्ट | पूर्ण array लागतो |
  | Space optimized | `O(n)` | `O(1)` | Fast आणि memory efficient | State meaning नीट track करावा |
  Plain recursion चुकीची नाही; फक्त inefficient आहे. Greedy पद्धतीने प्रत्येक वेळी मोठे घर निवडणे योग्य नाही—मोठ्या घरामुळे पुढची चांगली जोड गमावली जाऊ शकते.

## 5. Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[Set prev2 = 0 and prev1 = 0]
    B --> C{More houses?}
    C -- No --> G[Return prev1]
    C -- Yes --> D[Read current house amount]
    D --> E[ current = max(prev1, prev2 plus amount)]
    E --> F[Shift prev2 = prev1 and prev1 = current]
    F --> C
```

प्रत्येक घरासाठी rob करणे (`prev2 + amount`) आणि skip करणे (`prev1`) यापैकी जास्त रक्कम घेतो. नंतर दोन मागील best values पुढच्या iteration साठी shift होतात.

## 6. Algorithm / Intuition

**Key observation:** घर `i` rob केल्यास `i-1` घेता येत नाही; पण `i-2` पर्यंतचा optimum जोडता येतो. Skip केल्यास मागील optimum तसाच राहतो.

1. `prev2 = 0`, `prev1 = 0` पासून सुरू करा.
2. प्रत्येक घरासाठी `current = max(prev1, prev2 + nums[i])`.
3. `prev2 = prev1`; `prev1 = current`.
4. शेवटी `prev1` return करा.
   हे initial zero values empty input सुद्धा naturally handle करतात.

## 7. Code Explanation

फाइलमध्ये brute recursion, memoization, tabulation आणि optimized DP आहेत. `robRecursiveHelper(nums, i)` index `i` पासूनचा best answer काढतो. Memoization मध्ये `-1` म्हणजे state अजून compute झालेला नाही. Tabulation मध्ये `dp[i]` पहिल्या `i` घरांचा answer आहे.
`robOptimized` मध्ये:

- `prev2`: current index च्या दोन आधीच्या स्थितीपर्यंतचा optimum.
- `prev1`: मागील index पर्यंतचा optimum.
- `current`: current घर rob/skip करून मिळणारा best.
  दिलेली implementation empty vector साठीही `0` देते.
  **Submission note:** LeetCode method चे नाव `rob` असते; फाइलमधील methods वेगवेगळे नाव वापरतात आणि `main` local comparison harness आहे. Judge साठी `robOptimized` logic ला अपेक्षित signature मध्ये expose/rename करावे.

## 8. Dry Run

Input: `[2, 7, 9, 3, 1]`
| Step | Variables | Condition | Action | Result |
|---:|---|---|---|---:|
| 0 | `prev2=0, prev1=0` | Initial | अजून घर घेतलेले नाही | `0` |
| 1 | amount `2` | Rob vs skip | `current=max(0,0+2)=2`; shift | `prev2=0, prev1=2` |
| 2 | amount `7` | Rob vs skip | `current=max(2,0+7)=7`; shift | `prev2=2, prev1=7` |
| 3 | amount `9` | Rob vs skip | `current=max(7,2+9)=11`; shift | `prev2=7, prev1=11` |
| 4 | amount `3` | Rob vs skip | `current=max(11,7+3)=11`; shift | `prev2=11, prev1=11` |
| 5 | amount `1` | Rob vs skip | `current=max(11,11+1)=12`; shift | `prev2=11, prev1=12` |
Return `12`.

## 9. Complexity Analysis

Optimized method प्रत्येक घरावर constant-time comparison/update करतो: **`O(n)` time**. `prev2`, `prev1`, `current` या ठराविक variables व्यतिरिक्त memory नाही: **`O(1)` extra space**. Memoization/tabulation `O(n)` memory वापरतात. Plain recursion मध्ये branching मुळे worst-case `O(2^n)` calls होतात.
Linear time आणि constant extra space असल्याने दिलेल्या constraints साठी space-optimized DP योग्य आहे.

## 10. Why This Solution Works

`prev1` हा process केलेल्या prefix मधील maximum loot आणि `prev2` हा त्याच्या दोन घरांपूर्वीच्या prefix चा maximum loot दर्शवतो. Current घर skip केल्यास `prev1` मिळतो; rob केल्यास शेजारील घर टाळून `prev2 + nums[i]` मिळतो. वैध optimal solution या दोनपैकी एका पर्यायात येतोच. Maximum निवडल्याने induction ने प्रत्येक prefix साठी optimum मिळतो. प्रत्येक iteration एक घर पुढे जाते, म्हणून algorithm terminate होतो.

## 11. Common Mistakes & Interview Traps

- शेजारील दोन घरे एकत्र घेणे.
- प्रत्येक वेळी स्थानिकदृष्ट्या जास्त असलेले घर निवडणे (greedy); global optimum हमखास मिळत नाही.
- Rob case मध्ये `prev1 + nums[i]` वापरणे; हे शेजारील घराची loot घेतल्यासारखे होईल.
- Empty आणि one-house cases विसरणे.
- `dp` चा अर्थ स्पष्ट न ठेवणे: “index पासून” आणि “पहिल्या i घरांपर्यंत” या दोन definitions वेगळ्या आहेत.
- Interview follow-up: circular street असेल तर पहिलं व शेवटचं घरही neighbors; दोन linear ranges solve करून maximum घ्या.
- Negative house values दिले तर problem च्या “rob none” semantics/constraints पुन्हा तपासा; मूळ समस्या non-negative amounts देते.

## 12. Revision Notes (Quick Recall)

- **Pattern:** 1D take/skip DP; non-adjacent maximum sum.
- **Clues:** adjacent choices prohibited, maximum total.
- **Intuition:** current house घ्या तर दोन मागच्या best ला जोडा; नाहीतर previous best ठेवा.
- **Transition:** `current = max(prev1, prev2 + nums[i])`.
- **Complexity:** `O(n)` time, `O(1)` extra space.
- **Mistakes:** greedy local choice, wrong previous state, adjacent houses दोन्ही घेणे.
- **Takeaway:** प्रत्येक item साठी “take” आणि “skip” यांचे best compare करा.

## 13. Similar Problem Recognition

House Robber II मध्ये houses circle मध्ये असतात: पहिलं आणि शेवटचं दोन्ही घेता येत नाहीत; `[0..n-2]` आणि `[1..n-1]` यांचे linear answers compare करा. House Robber III मध्ये houses tree वर असल्याने प्रत्येक node साठी rob/skip states वापरा. General weighted interval/scheduling problems मध्येही incompatible choices साठी take/skip DP येते; पण compatible previous state शोधण्यासाठी binary search किंवा predecessor index लागू शकतो.

## 14. Final Self-Assessment

1. Rob-current transition मध्ये `prev2` का वापरतो?
2. `prev1` आणि `prev2` यांचा अर्थ dry run दरम्यान कसा बदलतो?
3. Plain recursion exponential का होऊ शकते?
4. `[2, 1, 1, 2]` साठी greedy largest-first का पुरेसा नाही?
5. Circle version मध्ये linear recurrence ला कोणता अतिरिक्त boundary issue येतो?
