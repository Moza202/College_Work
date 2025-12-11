# C++ Competitive Programming Cheat Sheet

A comprehensive collection of algorithms, data structures, and theory for competitive programming.

---

## Table of Contents

- [Template & Macros](#template--macros)
- [Mathematics & Number Theory](#mathematics--number-theory)
  - [Prime Checking](#prime-checking)
  - [Base Conversion](#base-conversion)
  - [General Formulas](#general-formulas)
- [Standard Template Library (STL)](#standard-template-library-stl)
  - [Vectors](#vectors)
  - [Deque](#deque)
  - [Pairs](#pairs)
  - [Sets](#sets)
  - [Ordered vs Unordered Containers](#ordered-vs-unordered-containers)
- [Algorithms](#algorithms)
  - [Sorting Implementation](#sorting-implementation)
  - [Searching](#searching)
  - [Sorting Theory & Complexity](#sorting-theory--complexity)
- [Logic Gates](#logic-gates)

---

## Template & Macros

Standard starter template for faster I/O and common definitions.

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"
#define vi vector<int>
#define sp " "
#define all(x) (x).begin(), (x).end()
const double EPS = 1e-9;

void MOZA()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve()
{
    // Write your solution here
}

int main() {
    MOZA();
    solve();
    return 0;
}
```

---

## Mathematics & Number Theory

### Prime Checking

Checks if a number is prime in O(√N) time.

```cpp
bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0) return false;
    }
    return true;
}
```

### Base Conversion

#### Decimal to Base (Returns String)

```cpp
string decimal_to_base(int n, int base)
{
    string num = "";
    while (n)
    {
        int rem = n % base;
        num += char((rem < 10 ? rem + '0' : (rem - 10 + 'A')));
        n /= base;
    }
    reverse(num.begin(), num.end());
    return num;
}
```

#### Base to Decimal (Returns Integer)

```cpp
int base_to_decimal(string num, int base)
{
    int n = 0;
    for (int i = 0; i < num.size(); i++)
    {
        n *= base;
        n += (isdigit(num[i]) ? num[i] - '0' : num[i] - 'A' + 10);
    }
    return n;
}
```

### General Formulas

- **Odd numbers count**: `(n + 1) / 2` (Count of odd numbers from 1 to n)
- **Odd Number Expression**: `2k - 1` or `2k + 1`
- **Even Number Expression**: `2k`

---

## Standard Template Library (STL)

### Vectors

Dynamic arrays that handle memory automatically.

**Common Operations:**

- `push_back()` / `emplace_back()`: Add element to the end
- `pop_back()`: Delete the last element
- `front()` / `back()`: Access first / last element
- `size()`: Number of elements
- `empty()`: Returns 1 if empty, 0 otherwise
- `insert()`: Add element at a specific iterator
- `emplace()`: Like insert but faster (in-place construction)
- `erase()`: Delete element at iterator or range
- `reverse()`: Reverse the vector
- `*min_element()` / `*max_element()`: Find min/max in a range
- `find_if()`: Find element based on a condition

### Deque

Double-ended queue with fast insertion/deletion at both ends.

- `push_front()` / `emplace_front()`: Adds element to the beginning
- All vector operations also available

### Pairs

Container for two heterogeneous values.

```cpp
// Declaration
pair<string, int> p;
p.first = "ziad";  // Access first element
p.second = 123;    // Access second element

// Creation
auto p2 = make_pair(123, "ziad");

// Nested Pairs
pair<string, pair<int, double>> nas;
// nas.first          -> string
// nas.second.first   -> int
// nas.second.second  -> double
```

### Sets

Stores unique elements in sorted order using Red-Black Trees. No random access.

**Complexity**: Worst case O(log n)

**Common Operations:**

- `begin()` / `end()`: Iterators
- `insert(val)` / `emplace(val)`: Add element
- `erase(val)`: Remove element
- `count(val)`: Returns 1 if present (0 otherwise)
- `find(val)`: Returns iterator to element
- `clear()`: Empties the set
- `lower_bound(val)`: First element ≥ val
- `upper_bound(val)`: First element > val

**Optimization Hint:**

```cpp
auto it = s.begin();
s.emplace_hint(it, 5); // Reduces time from O(log n) to O(1)
```

### Ordered vs Unordered Containers

| Feature | Ordered (map, set) | Unordered (unordered_map) |
|---------|-------------------|---------------------------|
| **Data Structure** | Self-balancing BST | Hash Table |
| **Order** | Sorted by Key | Random/Undefined |
| **Time Complexity** | O(log n) | O(1) Avg, O(n) Worst |
| **Use Case** | Range queries, Sorted data | Fast lookups |

---

## Algorithms

### Sorting Implementation

#### Selection Sort (Ascending)

Time Complexity: O(n²)

```cpp
void mini(int arr[], int n) {
    int idx;
    for (int i = 0; i < n - 1; i++) {
        idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[idx])
                idx = j;
        }
        swap(arr[idx], arr[i]);
    }
}
```

### Searching

#### Find Maximum

```cpp
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}
```

#### Find Minimum

```cpp
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}
```

#### Manual Swap Logic

```cpp
int temp = a;
a = b;
b = temp;
```

### Sorting Theory & Complexity

Summary of sorting algorithms and their behaviors.

#### 1. Iterative (Comparison)

- **Selection Sort**: O(n²) — Finds min in unsorted part, swaps with current index. Space O(1)
- **Bubble Sort**: O(n²) — Bubbles largest element to end via adjacent swaps. Best case O(n)
- **Insertion Sort**: O(n²) — Builds sorted array one item at a time. Best case O(n)

#### 2. Recursive (Divide & Conquer)

- **Merge Sort**: O(n log n) (All cases) — Splits array, sorts halves, merges them. Space O(n)
- **Quick Sort**: O(n log n) Avg, O(n²) Worst — Uses pivots to partition. Space O(log n)

#### 3. Non-Comparison

- **Counting Sort**: O(n+k) — Frequency counting. Space O(k)
- **Radix Sort**: O(d(n+k)) — Digit-by-digit sorting

---

## Logic Gates

### XOR Gate Rule

For an XOR gate with >2 inputs:

- **Output is Logic 1** if the number of Logic 1 inputs is **Odd**
- **Output is Logic 0** otherwise

---

## Quick Reference

### Time Complexity Hierarchy

```
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2^n) < O(n!)
```

### Common STL Time Complexities

| Operation | Vector | Set | Unordered Set |
|-----------|--------|-----|---------------|
| Access | O(1) | — | — |
| Insert | O(1) amortized | O(log n) | O(1) avg |
| Delete | O(n) | O(log n) | O(1) avg |
| Search | O(n) | O(log n) | O(1) avg |

---

*Happy Coding! 🚀*