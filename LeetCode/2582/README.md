# 2582 — Pass the Pillow

## 1. Understanding

या प्रश्नाचा गाभा म्हणजे दोन्ही टोकांना दिशा बदलणाऱ्या pillow ची स्थिती.

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> `n` people stand in a line; a pillow moves one person per second, reversing direction at either endpoint. Return the person holding it after `time` seconds, starting at person 1.

## 2. Worked examples and edge cases

उदाहरणे आणि सीमाप्रकरणांत दोन्ही टोकांना दिशा बदलणाऱ्या pillow ची स्थिती कशी लागू होते ते पाहा.

> **मराठी:** उदाहरणातील input पासून output पर्यंत प्रत्येक बदल समजून घ्या.
> For `n=4`, positions repeat every `2*(4-1)=6` seconds. At time 5, person 2 holds the pillow. At time 6, it is back at person 1. For `n=2`, the pillow alternates every second.

## 3. Pattern identification + cheat sheet

येथे मुख्य pattern म्हणजे पूर्ण फेरीतील phase वरून स्थिती काढणे; वरील तुलना लक्षात घ्या.

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> This is **periodic motion / modular arithmetic**.
> | Quantity | Meaning |
> |---|---|
> | `n-1` | Seconds to travel one direction |
> | `2*(n-1)` | Full out-and-back cycle |
> | `time % cycle` | Position within the current cycle |

## 4. Approaches

पद्धतींची तुलना करताना पूर्ण फेरीतील phase वरून स्थिती काढणे याचा वेळ आणि जागेवरील परिणाम पाहा.

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> Simulate one handoff per second: correct, `O(time)`. The source folds time into one cycle and computes the position in `O(1)`. A common incorrect shortcut is `time % n`, because endpoint reversals change the period.

## 5. Flowchart

आकृतीमध्ये पूर्ण फेरीतील phase वरून स्थिती काढणे ही प्रक्रिया क्रमाने दाखवली आहे.

> **मराठी:** Flowchart मध्ये प्रत्येक decision, loop आणि loop कधी थांबतो ते पाहा.

```mermaid
flowchart TD
    A[Compute cycle = 2*(n-1)] --> B[phase = time % cycle]
    B --> C{phase < n?}
    C -->|yes| D[Position = 1 + phase]
    C -->|no| E[Position = n - (phase - (n-1))]
    D --> F[Return position]
    E --> F
```

The first branch moves right from person 1; the second moves left after reaching person `n`.

## 6. Algorithm and intuition

मूळ कल्पना: पूर्ण फेरीतील phase वरून स्थिती काढणे.

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> The motion is a triangular wave. During phase `0...n-1`, position is `1+phase`. During phase `n...2(n-1)-1`, subtract elapsed reverse steps from `n`. Modulo removes complete cycles.

## 7. Code explanation

Code मधील state आणि updates हे पूर्ण फेरीतील phase वरून स्थिती काढणे या कल्पनेशी जोडून वाचा.

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `passThePillow` computes `cycle`, reduces time, then applies the forward or backward formula. Assumes `n>=2`; for `n=1`, the cycle becomes zero and modulo is invalid, but the problem constraints exclude that case.

## 8. Dry run

Dry run मध्ये पूर्ण फेरीतील phase वरून स्थिती काढणे कसे घडते ते प्रत्येक टप्प्यावर तपासा.

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> `n=4,time=5`: cycle `6`, phase `5`. Since `5<4` is false, position = `4-(5-3)=2`.
> | Time | Phase | Person |
> |---:|---:|---:|
> | 0 | 0 | 1 |
> | 3 | 3 | 4 |
> | 5 | 5 | 2 |
> | 6 | 0 | 1 |

## 9. Complexity

पूर्ण फेरीतील phase वरून स्थिती काढणे यासाठी लागणारा वेळ आणि अतिरिक्त जागा वरील bounds मध्ये दिली आहेत.

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> `O(1)` time and `O(1)` space.

## 10. Correctness

योग्यतेचा युक्तिवाद पूर्ण फेरीतील phase वरून स्थिती काढणे यावर आधारित आहे; वरील अटी तपासा.

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> Each complete out-and-back traversal has exactly `2(n-1)` handoffs and returns to person 1 in the same direction. Modulo therefore preserves the current phase. The piecewise formulas count the forward and reverse steps respectively, yielding the correct holder.

## 11. Mistakes and interview traps

लक्षात ठेवा: टोक गाठल्यावर दिशाबदलाचा क्षण काळजीपूर्वक मोजायचा.

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- People are numbered from 1, so add one in the forward branch.
- Full period is `2(n-1)`, not `2n`.
- At the endpoint, direction reverses without an extra second.
- Handle `n=1` if adapting beyond stated constraints.

## 12. Quick revision

थोडक्यात, पूर्ण फेरीतील phase वरून स्थिती काढणे. टोक गाठल्यावर दिशाबदलाचा क्षण काळजीपूर्वक मोजायचा.

> **मराठी:** दोन मिनिटांच्या revision साठी pattern, मुख्य कल्पना आणि complexity आठवा.
> `p=time%(2*(n-1))`; if `p<n`, answer `p+1`; else answer `n-(p-(n-1))`.

## 13. Related problems and variations

संबंधित प्रश्नांत दोन्ही टोकांना दिशा बदलणाऱ्या pillow ची स्थिती यासारखी अट बदलल्यास योग्य पद्धतही तपासा.

> **मराठी:** Related problem मध्ये constraints बदलल्यास approach कसा बदलेल ते विचारा.
> Circular-array movement and Josephus-style modular problems; variations: find direction too, start from another position, or use an arbitrary cycle path.

## 14. Self-assessment

वरील प्रश्न स्वतः सोडवून दोन्ही टोकांना दिशा बदलणाऱ्या pillow ची स्थिती याची उजळणी करा.

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why is the period twice the one-way travel time?
2. What is the position at `time=n-1`?
3. Why is modulo `n` incorrect?
