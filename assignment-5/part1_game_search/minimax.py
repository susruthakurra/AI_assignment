from game import TicTacToe

def minimax(game, depth, is_maximizing):

    if game.winner("X"):
        return 1

    if game.winner("O"):
        return -1

    if game.is_draw():
        return 0

    if is_maximizing:
        best_score = -1000

        for move in game.available_moves():
            game.board[move] = "X"

            score = minimax(game, depth + 1, False)

            game.board[move] = " "

            best_score = max(score, best_score)

        return best_score

    else:
        best_score = 1000

        for move in game.available_moves():
            game.board[move] = "O"

            score = minimax(game, depth + 1, True)

            game.board[move] = " "

            best_score = min(score, best_score)

        return best_score
