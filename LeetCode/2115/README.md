# Find All Possible Recipes from Given Supplies

**LeetCode ID:** 2115
**Source file(s):** `2115.cpp` (originally `findAllRecipes.cpp`)
**Identification evidence:** The original filename, declared signature, and distinctive behavior described below uniquely identify this problem; no number was inferred from a filename alone.

## Expected input/output or judge interface

findAllRecipes(recipes,ingredients,supplies). Inputs follow the problem constraints; the output is the documented scalar, sequence, or design-object behavior. The description below reflects the implementation actually present in the source.

## Main flow

```mermaid
flowchart TD
    A([Start]) --> B[Read problem inputs]
    B --> C[Initialize required algorithm state]
    C --> D{More work?}
    D -- No --> Z([Return result])
    D -- Yes --> E{recipe indegree becomes zero?}
    E -- Yes --> F[add recipe to results and release dependents]
    E -- No --> G[leave unavailable]
    F --> D
    G --> D
```

## Important branch and loop flow

```mermaid
flowchart TD
    A([Inspect next item]) --> B{recipe indegree becomes zero?}
    B -- Yes --> C[add recipe to results and release dependents]
    B -- No --> D[leave unavailable]
    C --> E[Preserve the stated algorithm invariant]
    D --> F[Keep prior state and advance]
    E --> G{More work?}
    F --> G
    G -- Yes --> A
    G -- No --> H([Produce output])
```

## Core logic and invariant

Builds ingredient-to-recipe edges for non-supplies, computes indegrees, and performs Kahn topological processing from recipes requiring only supplies.
The key branch/loop rule above is applied once per relevant item; the algorithm relies on that rule to preserve its state and produce the required result.

## Optimization / comparison

Indegree counts only ingredients not initially supplied; reaching zero means every dependency is available.

## Complexity

Expected O(V+E) time and O(V+E) space, excluding string hashing costs.

## Compile and run

The repository file includes a standalone demonstration `main()`; it is not a raw LeetCode submission unit. From the repository root, with a C++17 compiler:

```powershell
g++ -std=c++17 LeetCode\2115\2115.cpp -o solution.exe
.\solution.exe
```

For LeetCode's class-method judge, copy the relevant class/method or design-class API and omit the demo `main()` and local harness. Adapt free-function implementations to the requested `Solution` class signature where necessary. See the source caveat above for any compile blocker.
