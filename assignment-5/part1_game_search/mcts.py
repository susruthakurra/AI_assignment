import random
from game import TicTacToe

def random_playout(game, current_player):

    players = ["X", "O"]

    while True:

        if game.winner("X"):
            return "X"

        if game.winner("O"):
            return "O"

        if game.is_draw():
            return "Draw"

        move = random.choice(game.available_moves())

        game.make_move(move, current_player)

        current_player = players[(players.index(current_player) + 1) % 2]


def monte_carlo_tree_search(game, simulations=100):

    move_scores = {}

    for move in game.available_moves():

        move_scores[move] = 0

        for _ in range(simulations):

            new_game = TicTacToe()
            new_game.board = game.board[:]

            new_game.make_move(move, "X")

            winner = random_playout(new_game, "O")

            if winner == "X":
                move_scores[move] += 1

            elif winner == "O":
                move_scores[move] -= 1

    best_move = max(move_scores, key=move_scores.get)

    return best_move
