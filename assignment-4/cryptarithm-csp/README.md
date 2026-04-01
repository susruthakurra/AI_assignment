# Cryptarithm Puzzle using CSP

## 1. Problem :

We solve the cryptarithm:

```
  TWO
+ TWO
------
 FOUR
```

Each letter represents a unique digit (0–9).

---

## 2. Constraints

* Each letter maps to a distinct digit
* No leading zeros (T ≠ 0, F ≠ 0)
* The equation must hold: TWO + TWO = FOUR

---

## 3. CSP Formulation

### Variables

```
T, W, O, F, U, R
```

### Domain

```
Digits from 0 to 9
```

### Constraints

* All digits must be unique
* Arithmetic constraint must be satisfied

---

## 4. Approach

* Generate permutations of digits
* Assign digits to letters
* Check constraints
* Stop when solution is found

---

## 5. Sample Input

```
TWO + TWO = FOUR
```

---

## 6. Sample Output

```
Solution:
{'T': 7, 'W': 3, 'O': 4, 'F': 1, 'U': 6, 'R': 8}
734 + 734 = 1468
```
