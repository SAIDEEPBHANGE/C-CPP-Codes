# Revised Repository Organization Action Plan

## Approval gate

This is a proposal only. No folders, filenames, source files, or documentation will be changed until this plan is explicitly approved.

## Goals

- Organize files by their actual content so related examples can be found quickly.
- Rename `College Codes/` to the clearer `College-Codes/`.
- Group root-level data structures and algorithms into focused folders.
- Give every identified LeetCode problem its own numbered folder.
- Keep every existing source file and its code unchanged.

## Proposed target structure

```text
C-CPP-Codes/
|-- README.md
|-- ACTION-PLAN.md
|-- folder-structure.txt
|-- C-CPP-Codes-Structure.txt
|-- Propmt.txt
|-- Data-Structures/
|   |-- Graphs/
|   |-- Linked-Lists/
|   |-- Queues/
|   |-- Stacks/
|   `-- Trees/
|-- Algorithms/
|   |-- Dynamic-Programming/
|   |-- Math/
|   |-- Searching/
|   `-- Sorting/
|-- College-Codes/
|   |-- Algorithms/
|   |-- Cryptography/
|   |-- Graphics/
|   |-- Memory/
|   |-- Networking/
|   `-- Other/
`-- LeetCode/
    |-- <problem-number>/
    |   |-- <problem-number>.cpp
    |   `-- README.md
    `-- Unidentified/
```

The final subfolder assignment will be based on file contents, not only filenames. If a category needs to be adjusted after inspection, `folder-structure.txt` will be updated to match the approved final structure.

## Root-file classification

The current root examples will be moved without editing their contents. The initial classification is:

- `Data-Structures/Trees/`: `BinarySearchTree.cpp`
- `Data-Structures/Linked-Lists/`: `LinkedList.cpp`, `CircularLinkedList.cpp`, `DoublyLinkedList.cpp`
- `Data-Structures/Stacks/`: `Stack.cpp`, `DynamicStack.cpp`
- `Data-Structures/Queues/`: `Queue.cpp`, `QueueArr.cpp`, `QueueLinkedList.cpp`, `QueueCircularLinkedList.cpp`
- `Data-Structures/Graphs/`: `Graph.cpp`
- `Algorithms/Searching/`: `SearchAlgorithm.cpp`
- `Algorithms/Sorting/`: `SortAlgorithm.cpp`
- `Algorithms/Dynamic-Programming/`: `KnapsackProblem.cpp`, `LongestCommonSubsequence.cpp`
- `Algorithms/Math/`: `FibonacciSequence.cpp`

Each file will be reviewed before moving so that this preliminary classification can be corrected if its implementation differs from its filename.

## College code classification

`College Codes/` will become `College-Codes/`. Its files will be reviewed and grouped by their implementation:

- Searching and sorting examples in `College-Codes/Algorithms/`
- Cipher and encryption examples in `College-Codes/Cryptography/`
- Bezier and X-pattern examples in `College-Codes/Graphics/`
- `malloc` and array-allocation examples in `College-Codes/Memory/`
- IEEE and frame-format examples in `College-Codes/Networking/`
- Games, number exercises, checks, and any genuinely uncategorized exercises in `College-Codes/Other/`

No file will be discarded because it is ambiguous. An uncertain file will remain in `Other/` with its original name.

## LeetCode organization and problem-number recovery

Each identified problem will use this format:

```text
LeetCode/
`-- 355/
    |-- 355.cpp
    `-- README.md
```

The source content will not be rewritten. Where a file currently uses a class or solution name instead of a problem number, the number will be recovered in this order:

1. Use an existing numeric filename or an exact problem number already present in comments.
2. Inspect the class name, method signature, parameters, constraints, and algorithm behavior.
3. Match those facts against known LeetCode problem metadata or the repository history.
4. Use an external reference only when the code description uniquely identifies the problem.
5. Record the evidence for the mapping before moving or renaming the file.

Problem numbers will never be guessed. If a file cannot be uniquely identified, it will go under `LeetCode/Unidentified/` using a stable descriptive name based on the existing filename or the solution's clearly understood purpose. For example:

```text
LeetCode/
`-- Unidentified/
    `-- descriptive-solution-name/
        |-- descriptive-solution-name.cpp
        `-- README.md
```

The descriptive name will be chosen to be searchable and will not alter the source code. The README will clearly mark the problem number as unknown and explain what evidence was checked. Duplicate or conflicting mappings will never silently overwrite one another.

After a mapping is verified, the original filename will be renamed to `<problem-number>.cpp` inside its numbered folder, as requested. The file bytes and implementation will remain unchanged.

## Per-problem README files and flowcharts

Every numbered or descriptively named solution folder will contain a `README.md` generated from and checked against its solution. Flowcharts will be used heavily so the processing flow, logic, and optimization are easy to analyze. Mermaid diagrams will be preferred because they remain readable in the repository and can be rendered by supported Markdown viewers.

Each README will include:

- Problem number and title, when confidently identified.
- Problem statement summary and expected input/output.
- A main execution-flow chart from input to final result.
- Decision and loop flowcharts for important branches or repeated processing.
- The central algorithm and why it works.
- A logic explanation connected directly to the relevant flowchart steps.
- A comparison flowchart when a straightforward approach is improved or optimized.
- An explanation of the optimization, including what bottleneck it removes.
- Important data structures or invariants.
- Time and space complexity.
- A compile/run example when the source supports standalone execution.
- A note when the file is intended for LeetCode's class-method judge format rather than standalone execution.

For unknown problem IDs, the README will use the descriptive solution name and document the verified behavior without inventing a problem number. The README files will document the code; they will not modify the source implementation.

## Documentation updates

After the organization is approved and completed:

1. Update `folder-structure.txt` to the actual final tree.
2. Update the root `README.md` with links to `Data-Structures/`, `Algorithms/`, `College-Codes/`, and `LeetCode/`.
3. Add browsing guidance for numbered LeetCode folders and their per-problem README files.
4. Add a clearly labeled list of any unresolved LeetCode mappings in `LeetCode/Unidentified/`, including their descriptive names and the evidence checked.

## Safety and verification

- Preserve the contents, extensions, and filenames of files unless a verified LeetCode number requires the planned filename normalization.
- Do not delete, merge, or rewrite source code.
- Use file hashes before and after the moves to verify that source contents are unchanged.
- Verify that every pre-existing source file has exactly one destination.
- Check for duplicate destinations and unresolved problem-number mappings before renaming.
- Review `git diff --stat`, `git diff --name-status`, and the final tree for accidental deletions or content edits.

## Completion criteria

- This plan has explicit approval before implementation starts.
- All source files are categorized by content or given a stable descriptive name when their LeetCode number is unavailable.
- `College Codes/` is replaced by `College-Codes/`.
- Identified LeetCode solutions use numbered folders containing `<number>.cpp` and `README.md`.
- Unknown-number solutions use descriptive folders and filenames with flowchart-focused `README.md` files.
- The root README and `folder-structure.txt` describe the final structure.
- Source file hashes confirm that no implementation was changed.
