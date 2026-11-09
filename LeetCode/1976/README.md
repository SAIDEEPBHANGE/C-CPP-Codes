# Number of Ways to Arrive at Destination — LeetCode 1976

## Problem, constraints आणि examples

Undirected weighted roads connect `n` cities; road times are positive. Find how many distinct paths from city `0` to city `n-1` have minimum total travel time; return modulo `1,000,000,007`.
Example: two disjoint routes `0→1→3` and `0→2→3`, each total time `5`: shortest time `5`, answer `2`. A longer route is not counted.

## Pattern clues

> **मराठी:** या clues मुळे योग्य pattern ओळखता येतो; constraints आणि relations नीट तपासा.
> | Clue | Pattern |
> |---|---|
> | positive weighted shortest paths | Dijkstra |
> | count all ways achieving best distance | shortest-distance + ways DP |
> | equal candidate distance | add predecessor path counts |

## Approaches

> **मराठी:** सोप्या उपायापासून सुरुवात करा आणि constraints नुसार योग्य optimization निवडा.
> | Method | Status | Cost |
> |---|---|---|
> | Dijkstra with `dist[]` and `ways[]` | Selected, `O((V+E)logV)` |
> | Floyd-Warshall then count paths | Not enough by itself to count paths; cubic distances and separate counting needed |
> | DFS enumerate every path | Correct for tiny graph but exponential |
> | On shorter relaxation add counts instead of replace | Incorrect; older longer-distance paths are not shortest |

## Flowchart

> **मराठी:** Flowchart मधील decision, loop आणि termination condition क्रमाने समजून घ्या.

```mermaid
flowchart TD
    A[Build undirected adjacency list] --> B[dist[0]=0; ways[0]=1; push 0]
    B --> C[Pop minimum time node]
    C --> D{Entry stale?}
    D -- Yes --> C
    D -- No --> E[Visit each neighbor v]
    E --> F{newTime < dist[v]?}
    F -- Yes --> G[Replace dist; ways[v]=ways[u]; push v]
    F -- No --> H{newTime == dist[v]?}
    H -- Yes --> I[Add ways[u] modulo MOD]
    H -- No --> J[Ignore]
    G --> K{Queue empty?}
    I --> K
    J --> K
    K -- No --> C
    K -- Yes --> L[Return ways[n-1]]
```

Shorter path resets ways; equal shortest path contributes another route.

## Selected algorithm, source-specific explanation, dry run

> **मराठी:** मुख्य observation समजल्यावर algorithm चे steps लक्षात ठेवणे सोपे होते.
> `countPaths` stores `{neighbor,time}` both directions, initializes `time[0]=0`, `ways[0]=1`, then priority-queue Dijkstra. Strict improvement replaces ways and pushes; equality adds modulo. Stale longer entries are skipped. The source also prints adjacency/debug traces to stdout, unlike a judge-only implementation.
> Dry run (two equal routes to destination):
> | Relaxation | New distance | Ways update |
> |---|---:|---|
> | `0→1` | 2 | `ways[1]=1` |
> | `0→2` | 2 | `ways[2]=1` |
> | `1→3` | 5 | `ways[3]=1` |
> | `2→3` | 5 | equal: `ways[3]=2` |

## Edge cases

> **मराठी:** Boundary, duplicate आणि off-by-one cases स्वतंत्रपणे तपासा.
> A one-city graph has one zero-edge path; equal shortest routes add ways; positive road times are required by the method.

## Complexity, correctness, traps

> **मराठी:** Input size आणि प्रत्येक operation कितीदा चालतो यावरून complexity ठरवा.
> `O((V+E)logV)` time, `O(V+E)` storage for adjacency, distance, ways and heap. Correctness: Dijkstra finalizes shortest distances for positive edge weights; each shortest predecessor either improves target (replace count) or ties it (add count), so ways matches all shortest paths.
> Trap: use `long long` for distances; roads are undirected; modulo on each tie addition. Positive weights are important for processing path counts before destination pop. Remove debug printing in a strict submission environment.

## Quick revision, variations, self-check

पुनरावलोकन: कमी distanceवर ways replace, tieवर add करा.
Dijkstra relaxation has two branches: `<` replace, `==` add. Related: shortest path counts, DAG path DP, weighted graph traversal.

1. Why set ways to predecessor count on strict improvement?
2. What happens on equal distance?
3. Why is stale heap entry skipped?
4. Why do positive weights matter to this counting approach?
