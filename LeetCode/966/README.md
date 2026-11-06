# Vowel Spellchecker — LeetCode 966

## Problem and judge interface

vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries); return a matched word per query.

## Identification evidence

Its exact, lowercase and devoweled lookup indexes enforce the three ordered match rules of problem 966.

## Main flow

```mermaid
flowchart TD
 A([Start]) --> B[Build exact, lowercase and devoweled indexes]
 B --> C[Process the next query by ordered rules]
 C --> D{Exact, lowercase, or devoweled match?}
 D -- Yes --> E[Append the winning original spelling]
 D -- No --> F[Append empty string]
 E --> G{More work remains?}
 F --> G
 G -- Yes --> C
 G -- No --> H([Return result])
```

## Important branch / loop

```mermaid
flowchart TD
 A[Normalize one query and test exact set first] --> B{Did exact lookup succeed?}
 B -- Yes --> C[Return the query unchanged]
 B -- No --> D[Try lowercase lookup, then devoweled lookup, else empty]
 C --> E([Continue or return as indicated])
 D --> E
```

## Core logic and invariants

Preprocessing stores exact words plus first-seen original spellings for lowercase and vowel-starred lowercase keys. Each query tests exact match, then case-only match, then vowel-error match, otherwise emits an empty string.

## Complexity

For total input characters C, expected O(C) time and O(C) hash storage.

## Comparison and optimization

Precomputed indexes avoid scanning the whole word list for every query; exact-match precedence is preserved.

## Compile and run

The `.cpp` is the original standalone source, including its local `main()` demonstration where present. Compile and run from the repository root with a C++17 compiler:

```text
g++ -std=c++17 LeetCode\966\966.cpp -o solution.exe
.\solution.exe
```

For LeetCode, adapt the implementation to the required class/method signature and omit the local `main()` and demonstration helpers; use the judge-provided node types. Notes above identify method-name or behavior differences. The moved source bytes have not been edited.
