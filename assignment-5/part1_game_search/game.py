class TicTacToe:
    def __init__(self):
        self.board = [" " for _ in range(9)]

    def print_board(self):
        for i in range(0, 9, 3):
            print(self.board[i:i+3])

    def available_moves(self):
        return [i for i in range(9) if self.board[i] == " "]

    def make_move(self, position, player):
        if self.board[position] == " ":
            self.board[position] = player
            return True
        return False

    def winner(self, player):
        win_patterns = [
            [0,1,2], [3,4,5], [6,7,8],
            [0,3,6], [1,4,7], [2,5,8],
            [0,4,8], [2,4,6]
        ]

        for pattern in win_patterns:
            if all(self.board[i] == player for i in pattern):
                return True
        return False

    def is_draw(self):
        return " " not in self.board
