# SMARTSEARCHTOOL

A search engine implementation that leverages the Trie data structure and the Knuth-Morris-Pratt (KMP) algorithm for efficient string searching.

## Trie Data Structure

A Trie, also known as a digital tree or prefix tree, is a type of search tree used to store a dynamic set or associative array where the keys are usually strings. It is particularly efficient for scenarios where common prefixes are shared among keys.

### Key Characteristics:
- **Structure:** Nodes in a Trie do not store the key themselves. Instead, the position of a node represents part of the key. Each node represents a common prefix among the strings associated with that node.
- **Prefix Sharing:** All descendants of a node share a common prefix. The root node is associated with the empty string.
- **Key Storage:** Keys are typically associated with leaf nodes, but some internal nodes may also be associated with keys of interest. Not every node necessarily holds a key.

### Applications:
- **Efficient Lookup:** Tries provide faster lookup times in the worst case, O(m), where m is the length of the search string, compared to hash tables which may experience collisions and have a worst-case time complexity of O(N).
- **Collision-Free:** Tries inherently avoid key collisions, as they store keys in a tree structure rather than using hashing.
- **Ordering:** Tries can provide alphabetical ordering of entries by key, which is useful for applications requiring sorted results.

### Complexities:
- **Insert:** O(m) - where m is the length of the string.
- **Delete:** O(m) - where m is the length of the string.
- **Search:** O(m) - where m is the length of the string.
- **Space Complexity:** O(n*m) - where n is the number of strings and m is the average length of the strings.

## Knuth-Morris-Pratt (KMP) Algorithm

The KMP algorithm is an efficient string matching algorithm used to find occurrences of a word (or pattern) within a main text (or string). It preprocesses the pattern to build a partial match table (also known as the "prefix" table), which is used to skip unnecessary comparisons in the search process.

### Key Characteristics:
- **Preprocessing:** The algorithm builds a partial match table for the pattern, which helps in skipping over parts of the text that have already been matched, thus improving efficiency.
- **Time Complexity:** The preprocessing step takes O(m) time, where m is the length of the pattern. The search process also takes O(n) time, where n is the length of the text.
- **Applications:** KMP is useful in various applications, including text editors, search engines, and DNA sequence analysis.

### Complexities:
- **Preprocessing Time:** O(m) - where m is the length of the pattern.
- **Search Time:** O(n) - where n is the length of the text.
- **Space Complexity:** O(m) - where m is the length of the pattern (for storing the partial match table).

## Usage

To use the SmartSearchTool, you need to:

1. Load the data into the Trie.
2. Choose from the search options:
   - Exact match search
   - Prefix search
   - Universal search using KMP algorithm for pattern matching

Feel free to explore the functionalities and optimize the search operations with the powerful combination of Trie and KMP.
