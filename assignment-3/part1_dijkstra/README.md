# Part 1: Dijkstra’s Algorithm (Shortest Path in Cities)

## Objective

This program finds the **shortest distance and path between cities** using **Dijkstra’s Algorithm**.

It simulates a real-world problem like:

> “What is the shortest route from Hyderabad to other cities?”

---

## What is Dijkstra’s Algorithm?

Dijkstra’s Algorithm is used to find the **shortest path from one source node to all other nodes** in a graph.

### Key idea:

* Start from a source node
* Always pick the **closest unvisited node**
* Update distances of its neighbors
* Repeat until all nodes are visited

---

## How we represent the problem

* Each **city = node**
* Distance between cities = **edge weight**
* Stored using an **adjacency matrix**

---

## File Structure

```
part1_dijkstra/
│
├── dijkstra.c        → Main program (reads input + calls algorithm)
├── utils.c           → Dijkstra logic implementation
├── utils.h           → Function declarations
├── graph_data.txt    → Input file (cities + distances)
└── README.md         → Documentation
```

---

## Input Format (graph_data.txt)

```
<number of cities>
<city1>
<city2>
...
<cityN>

<adjacency matrix>
```

---

### Sample Input 1

```
5
Hyderabad
Chennai
Bangalore
Mumbai
Delhi

0 630 570 710 1550
630 0 350 1330 2200
570 350 0 980 2150
710 1330 980 0 1400
1550 2200 2150 1400 0
```

---

### Sample Input 2

```
4
A
B
C
D

0 2 0 6
2 0 3 8
0 3 0 1
6 8 1 0
```

---

## How to Compile and Run

Open terminal inside `part1_dijkstra`:

```
gcc dijkstra.c utils.c -o dijkstra
./dijkstra
```

---

## Sample Output

```
Hyderabad → Bangalore
Distance: 570
Path: Hyderabad -> Bangalore
```

---

## Code Explanation

### dijkstra.c (Main File)

This file:

* Reads input from file
* Stores city names
* Stores graph (distance matrix)
* Calls Dijkstra function

Important parts:

```c
FILE *file = fopen("graph_data.txt", "r");
```

→ Opens input file

```c
fscanf(file, "%d", &n);
```

→ Reads number of cities

```c
fscanf(file, "%s", cities[i]);
```

→ Reads city names

```c
dijkstra(graph, n, start, cities);
```

→ Calls algorithm

---

### utils.c

#### 1. minDistance()

```c
int minDistance(int dist[], int visited[], int n)
```

Finds: The closest unvisited node

---

#### 2. dijkstra()

Main logic:

```c
dist[start] = 0;
```

→ Distance to source is 0

Then loop:

* Pick nearest node
* Mark visited
* Update neighbors

---

#### 3. Relaxation Step

```c
if (dist[u] + graph[u][v] < dist[v])
```

 This checks:

> “Is this a shorter path?”

If yes → update distance

---

#### 4. Parent Array (for path)

```c
parent[v] = u;
```

This helps reconstruct:
Actual path, not just distance

---

#### 5. printPath()

Recursive function:

```c
printPath(parent, j, cities);
```

Prints:

```
Hyderabad -> Mumbai -> Delhi
```
