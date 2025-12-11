# Data Structures & Algorithms - College Coursework

## 🎓 Overview
This repository contains my personal coursework and implementations for the **Data Structures** subject at college. It serves as a portfolio of my understanding of fundamental computer science concepts, implemented in **C++**.

The code provided here covers the implementation of various linear and non-linear data structures from scratch, along with practical applications and a comprehensive study guide.

## 📂 Repository Contents

### 1. Linked Lists
Implementations of different types of linked lists with various operations (Insertion, Deletion, Reversal, Searching).
* **`Linked_list1.cpp`**: A comprehensive Singly Linked List implementation including advanced operations like finding min/max, copying lists, and updating specific nodes.
* **`Doublylinkedlist.cpp`**: Implementation of a Doubly Linked List allowing bidirectional traversal.
* **`CLL.cpp`**: Circular Linked List implementation where the tail points back to the head.

### 2. Stacks
* **`Stack_using_array.cpp`**: Stack implementation using fixed-size arrays.
    * *Applications included:* Parenthesis balancing, String reversal, Palindrome checking, Decimal to Binary conversion, and Infix to Postfix expression conversion/evaluation.
* **`Stack_using_linkedlist.cpp`**: Dynamic Stack implementation using a linked list to handle flexible memory usage.

### 3. Queues
* **`Queue.cpp`**: Implementation of a **Circular Queue** using arrays. [cite_start]Includes features for bulk enqueue/dequeue operations and available space calculation.

### 4. Trees
* **`Tree.cpp`**: Binary Search Tree (BST) implementation.
    * *Features:* Insertion, Deletion (handling all cases), Search, Tree Size, Max Depth, and Traversals (Inorder, Preorder, Postorder).

### 5. Help.txt (Study Guide & Cheat Sheet)
A comprehensive reference file (`Help.txt`) compiled to aid in revision and understanding of core concepts. It includes:
* **Sorting Algorithms Analysis**: A detailed breakdown of different sorting techniques:
    * *Iterative:* Selection, Bubble, and Insertion Sort.
    * *Recursive:* Merge Sort and Quick Sort.
    * *Non-Comparison:* Counting Sort and Radix Sort.
    * *Comparison Table:* A summary of Best/Average/Worst time complexities and Space complexity for each.
***STL Containers**: Usage patterns and method summaries for **Vectors**, **Deque**, **Pairs**, and **Sets**.
* **Data Structure Comparisons**: Differences between **Ordered Containers** (Red-Black Trees) and **Unordered Containers** (Hash Tables) regarding performance (O(log n) vs O(1)) and memory usage.
***Mathematical Utilities**: Functions for Base Conversion (Decimal to Base-N), Prime Checking, and Min/Max finding logic.

## 🚀 How to Run
To compile and run any of the C++ files, you can use a standard compiler like `g++`.

**Example:**
```bash
# Compile the Tree implementation
g++ Tree.cpp -o tree_program

# Run the executable
./tree_program
