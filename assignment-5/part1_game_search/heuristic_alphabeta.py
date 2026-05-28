from game import TicTacToe

def evaluate(game):
    if game.winner("X"):
        return 10
    if game.winner("O"):
        return -10
    return 0

def heuristic_alphabeta(game, depth, alpha, beta, is_maximizing, max_depth):
    score = evaluate(game)
    if abs(score) == 10 or game.is_draw() or depth == max_depth:
        return score
    if is_maximizing:
        best = -1000
        for move in game.available_moves():
            game.board[move] = "X"
            value = heuristic_alphabeta(
                game,
                depth + 1,
                alpha,
                beta,
                False,
                max_depth
            )
            game.board[move] = " "
            best = max(best, value)
            alpha = max(alpha, best)
            if beta <= alpha:
                break
        return best
    else:
        best = 1000
        for move in game.available_moves():
            game.board[move] = "O"
            value = heuristic_alphabeta(
                game,
                depth + 1,
                alpha,
                beta,
                True,
                max_depth
            )
            game.board[move] = " "
            best = min(best, value)
            beta = min(beta, best)
            if beta <= alpha:
                break
        return best
