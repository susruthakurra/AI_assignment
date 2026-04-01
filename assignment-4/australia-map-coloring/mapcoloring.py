states = ['WA', 'NT', 'Q', 'SA', 'NSW', 'V', 'T']

colors = ['Red', 'Green', 'Blue']

neighbors = {
    'WA': ['NT', 'SA'],
    'NT': ['WA', 'SA', 'Q'],
    'Q': ['NT', 'SA', 'NSW'],
    'SA': ['WA', 'NT', 'Q', 'NSW', 'V'],
    'NSW': ['Q', 'SA', 'V'],
    'V': ['SA', 'NSW'],
    'T': []
}

def is_valid(state, color, assignment):
    for n in neighbors[state]:
        if n in assignment and assignment[n] == color:
            return False
    return True

def backtrack(assignment):
    if len(assignment) == len(states):
        return assignment

    for state in states:
        if state not in assignment:
            for color in colors:
                if is_valid(state, color, assignment):
                    assignment[state] = color
                    result = backtrack(assignment)
                    if result:
                        return result
                    del assignment[state]
            return None

solution = backtrack({})

print("Solution:")
for s in solution:
    print(s, "->", solution[s])
