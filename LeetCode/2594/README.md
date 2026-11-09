# 2594 — Minimum Time to Repair Cars

## 1. Understanding

या प्रश्नाचा गाभा म्हणजे सर्व cars दुरुस्त करण्यासाठी लागणारा किमान वेळ.

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> Mechanic with rank `r` repairs `x` cars in `r*x²` minutes. Given ranks and required car count, find the minimum time when mechanics work in parallel.

## 2. Worked examples and edge cases

उदाहरणे आणि सीमाप्रकरणांत सर्व cars दुरुस्त करण्यासाठी लागणारा किमान वेळ कशी लागू होते ते पाहा.

> **मराठी:** उदाहरणातील input पासून output पर्यंत प्रत्येक बदल समजून घ्या.
> For rank 4 and time 36, one mechanic can repair `floor(sqrt(36/4))=3` cars. At time 35, capacity is only 2. Time is feasible when summed mechanic capacities reach at least `cars`. One mechanic with rank `r` needs `r*cars²` time.

## 3. Pattern identification + cheat sheet

येथे मुख्य pattern म्हणजे वेळेवर binary search करून प्रत्येक mechanic ची क्षमता मोजणे; वरील तुलना लक्षात घ्या.

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> This is **binary search on the answer** with a monotonic feasibility predicate.
> | Candidate time `T` | Capacity per mechanic `r` |
> |---|---|
> | Feasible cars | `floor(sqrt(T/r))` |
> | Predicate | total capacity `>= cars` |
> | Search direction | Feasible -> try smaller; infeasible -> larger |

## 4. Approaches

पद्धतींची तुलना करताना वेळेवर binary search करून प्रत्येक mechanic ची क्षमता मोजणे याचा वेळ आणि जागेवरील परिणाम पाहा.

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> Enumerating every time is too slow. Assigning work greedily by ranks is harder because mechanics work in parallel. Binary search the smallest feasible time, using the rank formula for the check.

## 5. Flowchart

आकृतीमध्ये वेळेवर binary search करून प्रत्येक mechanic ची क्षमता मोजणे ही प्रक्रिया क्रमाने दाखवली आहे.

> **मराठी:** Flowchart मध्ये प्रत्येक decision, loop आणि loop कधी थांबतो ते पाहा.

```mermaid
flowchart TD
    A[low=1; high=minRank*cars^2] --> B[Compute mid]
    B --> C[Sum floor sqrt(mid/rank) for each mechanic]
    C --> D{Capacity >= required cars?}
    D -->|yes| E[Save mid; search left by reducing high]
    D -->|no| F[Increase low]
    E --> G{Search remains?}
    F --> G
    G -->|yes| B
    G -->|no| H[Return low]
```

Feasibility is monotonic: if time `T` works, every larger time also works.

## 6. Algorithm and intuition

मूळ कल्पना: वेळेवर binary search करून प्रत्येक mechanic ची क्षमता मोजणे.

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> Search integer time in `[1, minRank*cars²]`. For each midpoint, mechanic `i` repairs `floor(sqrt(mid/rank[i]))` cars; sum capacities and stop early if enough. Find the first feasible time via lower-bound binary search.

## 7. Code explanation

Code मधील state आणि updates हे वेळेवर binary search करून प्रत्येक mechanic ची क्षमता मोजणे या कल्पनेशी जोडून वाचा.

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `repairCars` uses `long long` for bounds and midpoint. The upper bound lets the fastest mechanic repair every car. It accumulates `sqrt(mid/i)` for each rank; feasible candidates move `high` left, otherwise `low` right. `sqrt` returns floating point; the problem's integer ranges are used by this implementation.

## 8. Dry run

Dry run मध्ये वेळेवर binary search करून प्रत्येक mechanic ची क्षमता मोजणे कसे घडते ते प्रत्येक टप्प्यावर तपासा.

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> Ranks `[4,2,3]`, `cars=10`; upper bound is `2*10²=200`.
> | Time candidate | Capacities `(r=4,2,3)` | Total | Decision |
> |---:|---|---:|---|
> | 100 | 5, 7, 5 | 17 | feasible; search lower |
> | 50 | 3, 5, 4 | 12 | feasible; search lower |
> | 25 | 2, 3, 2 | 7 | infeasible; search higher |

## 9. Complexity

वेळेवर binary search करून प्रत्येक mechanic ची क्षमता मोजणे यासाठी लागणारा वेळ आणि अतिरिक्त जागा वरील bounds मध्ये दिली आहेत.

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Let `R` be mechanic count and `H=minRank*cars²`. Time `O(R log H)`; extra space `O(1)`.

## 10. Correctness

योग्यतेचा युक्तिवाद वेळेवर binary search करून प्रत्येक mechanic ची क्षमता मोजणे यावर आधारित आहे; वरील अटी तपासा.

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> At a fixed time, the square-root expression gives the maximum whole cars each mechanic can finish because `r*x²<=T` iff `x<=sqrt(T/r)`. Summing gives total possible parallel capacity. This predicate is monotonic, so binary search's leftmost feasible point is the minimum time.

## 11. Mistakes and interview traps

लक्षात ठेवा: वेळ आणि क्षमतेच्या गणनेत overflow टाळायचा.

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- Use floor capacity, not nearest-integer rounding.
- Multiply bounds in `long long` to avoid overflow.
- Return the first feasible time, not any feasible midpoint.
- `r*x²` describes one mechanic's workload; do not sum repair times.
- For strict floating-point safety in variants, correct the sqrt result with integer checks.

## 12. Quick revision

थोडक्यात, वेळेवर binary search करून प्रत्येक mechanic ची क्षमता मोजणे. वेळ आणि क्षमतेच्या गणनेत overflow टाळायचा.

> **मराठी:** दोन मिनिटांच्या revision साठी pattern, मुख्य कल्पना आणि complexity आठवा.
> Binary-search time; `sum floor(sqrt(T/r))`; if sum `>=cars`, move left; answer is first feasible time.

## 13. Related problems and variations

संबंधित प्रश्नांत सर्व cars दुरुस्त करण्यासाठी लागणारा किमान वेळ यासारखी अट बदलल्यास योग्य पद्धतही तपासा.

> **मराठी:** Related problem मध्ये constraints बदलल्यास approach कसा बदलेल ते विचारा.
> LeetCode 875 (Koko Eating Bananas); 1011 (Capacity To Ship Packages); variations: change each worker's nonlinear rate or add worker availability constraints.

## 14. Self-assessment

वरील प्रश्न स्वतः सोडवून सर्व cars दुरुस्त करण्यासाठी लागणारा किमान वेळ याची उजळणी करा.

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why is feasibility monotonic in time?
2. What is the safe upper bound used in the code?
3. Why does the answer return `low`?
