# Bayesian Network Explanation

## Introduction
A Bayesian Network is a probabilistic graphical model used to represent uncertain knowledge using probability theory.

It represents variables and their dependencies using a directed acyclic graph (DAG).

---

## Example Used

Rain → Traffic → Late to College

In this example:
- Rain affects Traffic
- Traffic affects whether a student becomes late to college

---

## Variables

### 1. Rain
Represents whether it is raining or not.

States:
- Yes
- No

---

### 2. Traffic
Represents traffic conditions.

Traffic depends on Rain.

States:
- Heavy
- Normal

---

### 3. Late
Represents whether the student is late to college.

Late depends on Traffic conditions.

States:
- Late
- Not Late

---

## Conditional Probability Tables (CPD)

### Rain Probability
- P(Rain = Yes) = 0.3
- P(Rain = No) = 0.7

### Traffic Probability
Traffic depends on Rain.

### Late Probability
Late depends on Traffic.

---

## Inference
Inference is performed using the Variable Elimination algorithm.

The program calculates the probability of being late given evidence about rain conditions.

Example:
P(Late | Rain = Yes)

---

## Applications of Bayesian Networks
- Medical Diagnosis
- Weather Prediction
- Risk Assessment
- AI Decision Making
- Recommendation Systems

---

## Conclusion
Bayesian Networks provide a powerful method for representing uncertainty and performing probabilistic reasoning in Artificial Intelligence systems.
