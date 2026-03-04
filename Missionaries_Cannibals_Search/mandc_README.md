# Missionaries and Cannibals Problem using BFS and DFS

Problem Description

The Missionaries and Cannibals problem is a classical Artificial Intelligence search problem.

Three missionaries and three cannibals are on the left side of a river with a boat. The objective is to move all of them to the right side of the river safely.

Constraints

1. The boat can carry at most two people at a time.
2. At any time, cannibals cannot outnumber missionaries on either side of the river.
3. The boat cannot cross the river without at least one person.

Problem Formulation

State Space
All possible valid configurations of missionaries, cannibals, and boat position on the two sides of the river.

State Representation
Each state is represented as:

(Missionaries_left, Cannibals_left, Boat_position)

Example
(3,3,Left) represents all missionaries and cannibals on the left side with the boat.

Initial State
(3,3,Left)

Goal State
(0,0,Right)

Actions

1. Move one missionary across the river.
2. Move two missionaries across the river.
3. Move one cannibal across the river.
4. Move two cannibals across the river.
5. Move one missionary and one cannibal across the river.

The actions are valid only if the resulting state satisfies the problem constraints.

Breadth First Search (BFS)

Breadth First Search is an uninformed search strategy that explores the state space level by level. It begins from the initial state and systematically expands all possible states that can be reached in one move before moving to states that require two moves, and so on.

BFS uses a queue data structure to store the states that need to be explored. When a state is expanded, all its valid successor states are generated according to the allowed actions and constraints of the problem. These successor states are added to the end of the queue so they can be explored later.

In the Missionaries and Cannibals problem, BFS starts with the initial state (3,3,Left). From this state, the algorithm generates all possible valid moves, such as moving one cannibal or two cannibals to the other side, provided the constraints are not violated. Each newly generated state is placed into the queue and explored in the order it was generated.

This process continues until the goal state (0,0,Right) is reached. Since BFS explores states level by level, it guarantees that the first time the goal state is reached corresponds to the shortest sequence of moves needed to solve the problem.

Depth First Search (DFS)

Depth First Search is another uninformed search strategy that explores the state space by going as deep as possible along one branch before backtracking to explore other branches.

DFS uses a stack data structure to keep track of states. The algorithm begins with the initial state and pushes it onto the stack. It then expands the most recently generated state and continues exploring deeper states along that path.

For the Missionaries and Cannibals problem, DFS starts from the initial state (3,3,Left) and generates successor states based on the possible actions. One of these states is selected and explored further. This process continues until either the goal state is reached or no further valid states can be generated from the current path.

If the search reaches a state from which no valid moves are possible, the algorithm backtracks to a previous state and explores a different branch of the state space.

Unlike BFS, DFS does not guarantee the shortest path to the goal state. However, DFS often uses less memory compared to BFS because it stores only the current path and a small number of unexplored alternatives.

Comparison of BFS and DFS

1. BFS explores states level by level, while DFS explores deeper states first.
2. BFS uses a queue data structure, whereas DFS uses a stack.
3. BFS guarantees the shortest path to the goal, while DFS does not guarantee the shortest path.
4. BFS generally requires more memory compared to DFS.

Implementation

The Missionaries and Cannibals problem is implemented using both BFS and DFS algorithms in the C programming language.
