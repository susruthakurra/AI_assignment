districts = [
    "Adilabad", "Bhadradri", "Hyderabad", "Jagtial", "Jangaon",
    "Jayashankar", "Jogulamba", "Kamareddy", "Karimnagar", "Khammam",
    "Komaram Bheem", "Mahabubabad", "Mahabubnagar", "Mancherial",
    "Medak", "Medchal", "Mulugu", "Nagarkurnool", "Nalgonda",
    "Narayanpet", "Nirmal", "Nizamabad", "Peddapalli", "Rajanna",
    "Rangareddy", "Sangareddy", "Siddipet", "Suryapet",
    "Vikarabad", "Wanaparthy", "Warangal Rural", "Warangal Urban", "Yadadri"
]

colors = ["Red", "Green", "Blue", "Yellow"]

neighbors = {
    "Adilabad": ["Komaram Bheem", "Nirmal", "Mancherial"],
    "Komaram Bheem": ["Adilabad", "Mancherial"],
    "Nirmal": ["Adilabad", "Nizamabad", "Jagitial"],
    "Mancherial": ["Adilabad", "Komaram Bheem", "Peddapalli"],
    "Jagitial": ["Nirmal", "Karimnagar", "Peddapalli"],
    "Karimnagar": ["Jagitial", "Rajanna", "Siddipet"],
    "Peddapalli": ["Jagitial", "Mancherial"],
    "Rajanna": ["Karimnagar", "Siddipet"],
    "Nizamabad": ["Nirmal", "Kamareddy"],
    "Kamareddy": ["Nizamabad", "Medak"],
    "Medak": ["Kamareddy", "Sangareddy", "Siddipet"],
    "Sangareddy": ["Medak", "Vikarabad", "Medchal"],
    "Medchal": ["Sangareddy", "Hyderabad", "Rangareddy"],
    "Hyderabad": ["Medchal", "Rangareddy"],
    "Rangareddy": ["Hyderabad", "Vikarabad", "Mahabubnagar"],
    "Vikarabad": ["Sangareddy", "Rangareddy"],
    "Mahabubnagar": ["Rangareddy", "Narayanpet", "Wanaparthy"],
    "Narayanpet": ["Mahabubnagar"],
    "Wanaparthy": ["Mahabubnagar", "Nagarkurnool"],
    "Nagarkurnool": ["Wanaparthy", "Nalgonda"],
    "Nalgonda": ["Nagarkurnool", "Suryapet", "Yadadri"],
    "Suryapet": ["Nalgonda", "Khammam"],
    "Yadadri": ["Nalgonda", "Jangaon"],
    "Jangaon": ["Yadadri", "Warangal Urban"],
    "Warangal Urban": ["Jangaon", "Warangal Rural"],
    "Warangal Rural": ["Warangal Urban", "Mulugu"],
    "Mulugu": ["Warangal Rural", "Jayashankar"],
    "Jayashankar": ["Mulugu", "Bhadradri"],
    "Bhadradri": ["Jayashankar", "Khammam"],
    "Khammam": ["Bhadradri", "Suryapet", "Mahabubabad"],
    "Mahabubabad": ["Khammam", "Warangal Rural"],
    "Jogulamba": ["Nagarkurnool"],
    "Siddipet": ["Medak", "Karimnagar", "Rajanna"]
}

def is_valid(district, color, assignment):
    for n in neighbors.get(district, []):
        if n in assignment and assignment[n] == color:
            return False
    return True

def backtrack(assignment):
    if len(assignment) == len(districts):
        return assignment

    for d in districts:
        if d not in assignment:
            for color in colors:
                if is_valid(d, color, assignment):
                    assignment[d] = color
                    result = backtrack(assignment)
                    if result:
                        return result
                    del assignment[d]
            return None

solution = backtrack({})

print("Solution:")
for d in solution:
    print(d, "->", solution[d])
