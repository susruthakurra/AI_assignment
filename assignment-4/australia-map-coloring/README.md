# Australia Map Coloring using CSP

## Problem :

Implement the Map Coloring problem for the seven regions of Australia:
WA, NT, Q, SA, NSW, V, T

The goal is to assign colors to each region such that no two adjacent regions have the same color.

## Sample Input

Variables:

```
WA, NT, Q, SA, NSW, V, T
```

Domain:

```
{Red, Green, Blue}
```

Constraints (Adjacency):

```
WA: NT, SA
NT: WA, SA, Q
Q: NT, SA, NSW
SA: WA, NT, Q, NSW, V
NSW: Q, SA, V
V: SA, NSW
T: None
```

## What is CSP?

A Constraint Satisfaction Problem (CSP) consists of:

* Variables: Regions
* Domain: Possible colors
* Constraints: No adjacent regions share the same color

## Approach Used

We use Backtracking Search:

1. Pick an unassigned region
2. Assign a color
3. Check constraints
4. Recurse
5. Backtrack if needed

## Sample Output

```
Solution:
WA -> Red
NT -> Green
Q -> Red
SA -> Blue
NSW -> Green
V -> Red
T -> Red
```

## Note :
* Tasmania (T) has no neighbors, so it can take any color.
* Output may vary since multiple valid solutions exist.
