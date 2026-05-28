# Game Search Algorithms in Artificial Intelligence

## Overview

This project implements important adversarial search algorithms used in Artificial Intelligence using the Tic Tac Toe game environment.

The project demonstrates how AI agents analyze game states, evaluate possible moves, and select optimal actions in competitive environments.

The following algorithms were implemented:

1. Minimax Search Algorithm
2. Alpha-Beta Pruning
3. Heuristic Alpha-Beta Search
4. Monte Carlo Tree Search (MCTS)

---

## Problem Environment

### Tic Tac Toe

A Tic Tac Toe game environment was created to test all implemented algorithms.

The game environment supports:

* Board creation
* Move generation
* Winner detection
* Draw detection
* Turn-based gameplay

All algorithms use this environment to evaluate moves and make decisions.

---

## Files Included

| File Name              | Description                                        |
| ---------------------- | -------------------------------------------------- |
| game.py                | Contains the Tic Tac Toe game environment          |
| minimax.py             | Implements the Minimax algorithm                   |
| alphabeta.py           | Implements Alpha-Beta pruning                      |
| heuristic_alphabeta.py | Implements Heuristic Alpha-Beta Search             |
| mcts.py                | Implements Monte Carlo Tree Search                 |
| test_cases.py          | Contains test cases for validating implementations |

---

## Implementation Details

### Minimax Algorithm

The Minimax algorithm recursively explores all possible game states and selects the optimal move for the maximizing player while assuming that the opponent also plays optimally.

---

### Alpha-Beta Pruning

Alpha-Beta pruning improves the Minimax algorithm by eliminating unnecessary branches in the search tree using alpha and beta values.

---

### Heuristic Alpha-Beta Search

This implementation extends Alpha-Beta pruning using:

* Depth-limited search
* Heuristic evaluation function

The heuristic function estimates board quality without exploring the complete game tree.

---

### Monte Carlo Tree Search (MCTS)

Monte Carlo Tree Search selects moves using random simulations and chooses the move with the highest simulation score.

---

## Test Cases

### Test Case 1 — Minimax Algorithm

Initial Board State:

```text id="gpx2vq"
X | O | X
---------
O | X |  
---------
  |   | O
```

Operation:

* The Minimax algorithm explores all possible future game states recursively.
* The maximizing player attempts to obtain the highest score.

Expected Behaviour:

* The algorithm identifies a winning path for player X.
* A positive score is returned.

Sample Output:

```text id="cik14k"
Minimax Score: 1
```

---

### Test Case 2 — Alpha-Beta Pruning

Initial Board State:

```text id="uj2x8p"
X | O | X
---------
O | X |  
---------
  | O |  
```

Operation:

* Alpha-Beta pruning searches the game tree while avoiding unnecessary branches.
* Alpha and Beta values are updated during traversal.

Expected Behaviour:

* Optimal move is selected.
* Some branches are pruned without affecting the final decision.

---

### Test Case 3 — Heuristic Alpha-Beta Search

Initial Board State:

```text id="ikgw40"
X | X |  
---------
O | O |  
---------
  |   |  
```

Operation:

* Depth-limited search is performed.
* The heuristic evaluation function estimates board quality.

Expected Behaviour:

* The algorithm evaluates intermediate board states using heuristic scores.
* Best move is selected based on estimated utility.

---

### Test Case 4 — Monte Carlo Tree Search (MCTS)

Initial Board State:

```text id="81a8k9"
X | O |  
---------
  | X |  
---------
O |   |  
```

Operation:

* Multiple random simulations are performed from possible moves.
* Scores are updated based on simulation outcomes.

Expected Behaviour:

* The move with the highest simulation score is selected.
* Random playout statistics guide the final decision.

---

## Technologies Used

* Python
* Artificial Intelligence Search Algorithms
* Game Tree Search Techniques

---

## Conclusion

This project successfully demonstrates the implementation of important game search algorithms used in Artificial Intelligence. The algorithms were tested using the Tic Tac Toe game environment and produced correct decision-making behavior.
