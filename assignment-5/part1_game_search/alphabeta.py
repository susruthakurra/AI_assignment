from game import TicTacToe

def alphabeta(game, depth, alpha, beta, is_maximizing):

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
            score = alphabeta(game, depth + 1, alpha, beta, False)
            game.board[move] = " "
            best_score = max(best_score, score)
            alpha = max(alpha, score)
            if beta <= alpha:
                break
        return best_score
    else:
        best_score = 1000
        for move in game.available_moves():
            game.board[move] = "O"
            score = alphabeta(game, depth + 1, alpha, beta, True)
            game.board[move] = " "
            best_score = min(best_score, score)
            beta = min(beta, score)
            if beta <= alpha:
                break
        return best_score
