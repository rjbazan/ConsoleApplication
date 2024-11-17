#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <iostream>
#include <vector>

class GameLogic {
private:
    char board[3][3];
    char playerSymbol;
    char aiSymbol;

public:
    GameLogic();
    void displayBoard() const;
    bool checkWinner(char symbol) const;
    bool isDraw() const;
    int evaluate() const;
    int minimax(int depth, bool isMaximizing);
    std::pair<int, int> findBestMove();
    void playGame();
};

#endif // GAMELOGIC_H