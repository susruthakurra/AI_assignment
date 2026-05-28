from game import TicTacToe
from minimax import minimax

game = TicTacToe()

game.board = [
    "X", "O", "X",
    "O", "X", " ",
    " ", " ", "O"
]

score = minimax(game, 0, True)

print("Minimax Score:", score)
