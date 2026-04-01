# Telangana Map Coloring using Constraint Satisfaction Problem (CSP)

## 1. Problem Overview

The Map Coloring Problem is a classic example of a Constraint Satisfaction Problem (CSP) in Artificial Intelligence.

In this task, we model the 33 districts of Telangana as a CSP where:

* Each district must be assigned a color
* Adjacent districts must not share the same color

The objective is to find a valid coloring of the map such that all constraints are satisfied.

---

## 2. CSP Formulation

### Variables

Each district is treated as a variable:

```
Adilabad, Bhadradri, Hyderabad, Jagitial, Jangaon,
Jayashankar, Jogulamba, Kamareddy, Karimnagar, Khammam,
Komaram Bheem, Mahabubabad, Mahabubnagar, Mancherial,
Medak, Medchal, Mulugu, Nagarkurnool, Nalgonda,
Narayanpet, Nirmal, Nizamabad, Peddapalli, Rajanna,
Rangareddy, Sangareddy, Siddipet, Suryapet,
Vikarabad, Wanaparthy, Warangal Rural, Warangal Urban, Yadadri
```

### Domain

Each variable can take one of the following values:

```
{Red, Green, Blue, Yellow}
```

### Constraints

* No two neighboring districts can have the same color
* Constraints are defined using an adjacency list

Example:

```
Adilabad → Komaram Bheem, Nirmal, Mancherial  
Karimnagar → Jagitial, Rajanna, Siddipet  
Hyderabad → Medchal, Rangareddy  
Khammam → Bhadradri, Suryapet, Mahabubabad  
```

---

## 3. Approach and Algorithm

We solve the CSP using **Backtracking Search**, which is a depth-first search algorithm.

### Steps:

1. Start with an empty assignment
2. Select an unassigned district
3. Try assigning each color from the domain
4. Check if the assignment satisfies constraints
5. If valid, continue recursively
6. If a conflict occurs, backtrack and try another color

This continues until:

* A complete valid assignment is found, or
* All possibilities are exhausted

---

## 4. Sample Input

### Variables:

```
33 districts of Telangana
```

### Domain:

```
Red, Green, Blue, Yellow
```

### Constraints:

```
Defined via adjacency relationships between districts
```

---

## 5. Sample Output

```
Solution:
Adilabad -> Red
Komaram Bheem -> Green
Nirmal -> Blue
Mancherial -> Yellow
Karimnagar -> Red
Jagitial -> Green
...

```


## 6. Note:

* Output may vary since multiple valid colorings exist
* Any solution satisfying constraints is correct
* A simplified adjacency list is used for implementation
* Exact geographical borders are approximated for clarity
* Four colors are used to ensure a valid solution exists

