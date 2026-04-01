import itertools

letters = ('T', 'W', 'O', 'F', 'U', 'R')
digits = range(10)

for perm in itertools.permutations(digits, len(letters)):
    mapping = dict(zip(letters, perm))

    if mapping['T'] == 0 or mapping['F'] == 0:
        continue

    TWO = 100*mapping['T'] + 10*mapping['W'] + mapping['O']
    FOUR = 1000*mapping['F'] + 100*mapping['O'] + 10*mapping['U'] + mapping['R']

    if TWO + TWO == FOUR:
        print("Solution:")
        print(mapping)
        print(TWO, "+", TWO, "=", FOUR)
        break
