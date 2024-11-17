#include "GameLogic.h"

GameLogic::GameLogic() : playerSymbol('X'), aiSymbol('O') {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void GameLogic::displayBoard() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "--+---+--\n";
    }
}

bool GameLogic::checkWinner(char symbol) const {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }
    // Check diagonals
    return ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol));
}

bool GameLogic::isDraw() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int GameLogic::evaluate() const {
    if (checkWinner(aiSymbol)) return 10;
    if (checkWinner(playerSymbol)) return -10;
    return 0;
}

int GameLogic::minimax(int depth, bool isMaximizing) {
    int score = evaluate();
    if (score == 10 || score == -10) return score;
    if (isDraw()) return 0;

    if (isMaximizing) {
        int best = std::numeric_limits<int>::min();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = aiSymbol;
                    best = std::max(best, minimax(depth + 1, false));
                    board[i][j] = ' '; // Undo move
                }
            }
        }
        return best;
    }
    else {
        int best = std::numeric_limits<int>::max();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = playerSymbol;
                    best = std::min(best, minimax(depth + 1, true));
                    board[i][j] = ' '; // Undo move
                }
            }
        }
        return best;
    }
}

std::pair<int, int> GameLogic::findBestMove() {
    int bestVal = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = { -1, -1 };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = aiSymbol;
                int moveVal = minimax(0, false);
                board[i][j] = ' '; // Undo move

                if (moveVal > bestVal) {
                    bestMove = { i, j };
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

void GameLogic::playGame() {
    while (true) {
        displayBoard();

        // Human turn
        int row, col;
        std::cout << "Enter your move (row and column): ";
        std::cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move, try again!\n";
            continue;
        }
        board[row][col] = playerSymbol;

        if (checkWinner(playerSymbol)) {
            displayBoard();
            std::cout << "You win!\n";
            break;
        }
        if (isDraw()) {
            displayBoard();
            std::cout << "It's a draw!\n";
            break;
        }

        // AI turn
        std::pair<int, int> bestMove = findBestMove();
        board[bestMove.first][bestMove.second] = aiSymbol;
        if (checkWinner(aiSymbol)) {
            displayBoard();
            std::cout << "AI wins!\n";
            break;
        }
        if (isDraw()) {
            displayBoard();
            std::cout << "It's a draw!\n";
            break;
        }
    }
};