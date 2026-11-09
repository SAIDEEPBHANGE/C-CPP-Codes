# 2685 — Count the Number of Complete Components

## 1. Understanding

या प्रश्नाचा गाभा म्हणजे पूर्ण connected components ची मोजणी.

> **मराठी:** प्रश्नात काय दिले आहे आणि नेमके काय शोधायचे आहे, हे आधी स्पष्ट करा.
> An undirected graph component is complete when every pair of its distinct vertices has an edge. Count complete connected components.

## 2. Worked examples and edge cases

उदाहरणे आणि सीमाप्रकरणांत पूर्ण connected components ची मोजणी कशी लागू होते ते पाहा.

> **मराठी:** उदाहरणातील input पासून output पर्यंत प्रत्येक बदल समजून घ्या.
> A single isolated vertex is complete: it needs zero edges. A component of four vertices is complete when it has `4*3/2=6` undirected edges. A path of three vertices is connected but not complete.

## 3. Pattern identification + cheat sheet

येथे मुख्य pattern म्हणजे DFS ने vertices आणि त्यांचे एकूण degrees मोजणे; वरील तुलना लक्षात घ्या.

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> This is **connected components + degree/edge count invariant**.
> | Component fact | Expected in complete graph |
> |---|---|
> | `v` vertices | `v*(v-1)/2` undirected edges |
> | Sum of adjacency-list degrees | `v*(v-1)` |
> | Source DFS edge counter | Counts both directions |

## 4. Approaches

पद्धतींची तुलना करताना DFS ने vertices आणि त्यांचे एकूण degrees मोजणे याचा वेळ आणि जागेवरील परिणाम पाहा.

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> For each component, check every pair for an edge: correct but can be expensive. The source counts vertices and adjacency incidences during DFS; compare against `v*(v-1)`. A degree check (`degree==v-1` for every vertex) is another linear solution.

## 5. Flowchart

आकृतीमध्ये DFS ने vertices आणि त्यांचे एकूण degrees मोजणे ही प्रक्रिया क्रमाने दाखवली आहे.

> **मराठी:** Flowchart मध्ये प्रत्येक decision, loop आणि loop कधी थांबतो ते पाहा.

```mermaid
flowchart TD
    A[Build undirected adjacency list] --> B[Find unvisited vertex]
    B --> C[DFS component; count vertices and adjacency entries]
    C --> D{adjacency count == vertices*(vertices-1)?}
    D -->|yes| E[Increment complete count]
    D -->|no| F[Do not increment]
    E --> G{Unvisited vertices remain?}
    F --> G
    G -->|yes| B
    G -->|no| H[Return count]
```

Each undirected edge contributes two adjacency entries, which explains the factor of two.

## 6. Algorithm and intuition

मूळ कल्पना: DFS ने vertices आणि त्यांचे एकूण degrees मोजणे.

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> Build adjacency lists, DFS from each unvisited vertex, and accumulate component size `v` and total adjacency entries `d`. In a complete undirected component, every vertex has degree `v-1`, hence `d=v(v-1)`.

## 7. Code explanation

Code मधील state आणि updates हे DFS ने vertices आणि त्यांचे एकूण degrees मोजणे या कल्पनेशी जोडून वाचा.

> **मराठी:** Code मधील variable आणि condition यांचा algorithm मधील उद्देश समजून घ्या.
> `dfsAlgo` marks each vertex, increments node count, and increments edge count once for each neighbor entry. `countCompleteComponents` starts a DFS for each unvisited node and applies the formula. Its `main` demonstrates two graphs.

## 8. Dry run

Dry run मध्ये DFS ने vertices आणि त्यांचे एकूण degrees मोजणे कसे घडते ते प्रत्येक टप्प्यावर तपासा.

> **मराठी:** प्रत्येक महत्त्वाच्या step नंतर variable ची value trace करा.
> For a complete 3-node component:
> | Quantity | Value |
> |---|---:|
> | vertices | 3 |
> | adjacency entries | 6 |
> | expected `3*(3-1)` | 6 |
> | complete? | yes |

## 9. Complexity

DFS ने vertices आणि त्यांचे एकूण degrees मोजणे यासाठी लागणारा वेळ आणि अतिरिक्त जागा वरील bounds मध्ये दिली आहेत.

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> Adjacency construction and DFS: `O(V+E)` time; adjacency list and visited state use `O(V+E)` space. Recursive DFS stack is up to `O(V)`.

## 10. Correctness

योग्यतेचा युक्तिवाद DFS ने vertices आणि त्यांचे एकूण degrees मोजणे यावर आधारित आहे; वरील अटी तपासा.

> **मराठी:** Invariant किंवा तर्क वापरून algorithm योग्य उत्तर देतो हे समजून घ्या.
> DFS visits exactly one connected component and counts all its vertices and adjacency entries. For a simple undirected graph, a component is complete iff every vertex has degree `v-1`, equivalent to total degree `v(v-1)`. Therefore the equality check accepts exactly complete components.

## 11. Mistakes and interview traps

लक्षात ठेवा: प्रत्येक undirected edge degree बेरजेत दोनदा येते.

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.

- An undirected edge appears twice in adjacency lists.
- Compare against `v*(v-1)`, not `v*(v-1)/2`, for this source's counter.
- Isolated vertices qualify.
- Assumes a simple graph without self-loops or duplicate edges, as specified.
- Recursive DFS may need an iterative stack for very deep graphs in other constraints.

## 12. Quick revision

थोडक्यात, DFS ने vertices आणि त्यांचे एकूण degrees मोजणे. प्रत्येक undirected edge degree बेरजेत दोनदा येते.

> **मराठी:** दोन मिनिटांच्या revision साठी pattern, मुख्य कल्पना आणि complexity आठवा.
> DFS components, count vertices `v` and degree sum `d`; complete iff `d==v*(v-1)`.

## 13. Related problems and variations

संबंधित प्रश्नांत पूर्ण connected components ची मोजणी यासारखी अट बदलल्यास योग्य पद्धतही तपासा.

> **मराठी:** Related problem मध्ये constraints बदलल्यास approach कसा बदलेल ते विचारा.
> LeetCode 323 (Number of Connected Components); 547 (Number of Provinces); variations: test completeness by every vertex degree or count missing edges.

## 14. Self-assessment

वरील प्रश्न स्वतः सोडवून पूर्ण connected components ची मोजणी याची उजळणी करा.

> **मराठी:** उत्तर न पाहता प्रश्न सोडवा आणि तुमच्या निवडीचे कारण सांगा.

1. Why does the edge counter see each undirected edge twice?
2. Why is an isolated node complete?
3. What is the degree of every vertex in a complete component of size `v`?
