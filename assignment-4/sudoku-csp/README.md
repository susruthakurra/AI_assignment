# Sudoku Solver using Constraint Satisfaction Problem (CSP)

## 1. Problem:

Sudoku is a popular logic-based number placement puzzle. The objective is to fill a 9×9 grid so that:

* Each row contains numbers from 1 to 9 exactly once
* Each column contains numbers from 1 to 9 exactly once
* Each 3×3 subgrid contains numbers from 1 to 9 exactly once

This problem can be modeled as a **Constraint Satisfaction Problem (CSP)**.

---

## 2. CSP Formulation

### Variables

Each cell in the 9×9 grid is a variable:

```id="o9n2ib"
81 variables (each cell of the grid)
```

### Domain

Each variable can take values:

```id="8i4z2q"
{1, 2, 3, 4, 5, 6, 7, 8, 9}
```

### Constraints

* No duplicate numbers in any row
* No duplicate numbers in any column
* No duplicate numbers in any 3×3 subgrid

---

## 3. Input Representation

The Sudoku puzzle is represented as a 2D list.

* Filled cells → Given numbers
* Empty cells → Represented by `0`

### Sample Input

```id="9qkq8u"
[
 [5, 3, 0, 0, 7, 0, 0, 0, 0],
 [6, 0, 0, 1, 9, 5, 0, 0, 0],
 [0, 9, 8, 0, 0, 0, 0, 6, 0],
 [8, 0, 0, 0, 6, 0, 0, 0, 3],
 [4, 0, 0, 8, 0, 3, 0, 0, 1],
 [7, 0, 0, 0, 2, 0, 0, 0, 6],
 [0, 6, 0, 0, 0, 0, 2, 8, 0],
 [0, 0, 0, 4, 1, 9, 0, 0, 5],
 [0, 0, 0, 0, 8, 0, 0, 7, 9]
]
```

---

## 4. Approach and Algorithm

We solve the Sudoku using **Backtracking Search**, a standard CSP technique.

### Steps:

1. Find an empty cell (value = 0)
2. Try placing numbers from 1 to 9
3. Check if the number satisfies:

   * Row constraint
   * Column constraint
   * Subgrid constraint
4. If valid, assign and move forward recursively
5. If invalid, backtrack and try another number

This continues until the grid is completely filled.

---

## 5. Sample Output

```id="b2y0o3"
Solved Sudoku:
[5, 3, 4, 6, 7, 8, 9, 1, 2]
[6, 7, 2, 1, 9, 5, 3, 4, 8]
[1, 9, 8, 3, 4, 2, 5, 6, 7]
[8, 5, 9, 7, 6, 1, 4, 2, 3]
[4, 2, 6, 8, 5, 3, 7, 9, 1]
[7, 1, 3, 9, 2, 4, 8, 5, 6]
[9, 6, 1, 5, 3, 7, 2, 8, 4]
[2, 8, 7, 4, 1, 9, 6, 3, 5]
[3, 4, 5, 2, 8, 6, 1, 7, 9]
```

---

## 6. Time Complexity

* Worst-case complexity: O(9^(n²))
* Backtracking significantly reduces unnecessary computations through constraint checking
