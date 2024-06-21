#include <iostream>
#include <vector>

using namespace std;
void initializeBoard(vector<vector<char>>& board) {
    board = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
}
void displayBoard(const vector<vector<char>>& board) {
    cout << "Current Board State:\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}
bool isMoveValid(const vector<vector<char>>& board, int move) {
    return move >= 1 && move <= 9 && board[(move-1) / 3][(move-1) % 3] != 'X' && board[(move-1) / 3][(move-1) % 3] != 'O';
}
void updateBoard(vector<vector<char>>& board, int move, char player) {
    board[(move-1) / 3][(move-1) % 3] = player;
}
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell != 'X' && cell != 'O') return false;
        }
    }
    return true;
}
void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
int main() {
    vector<vector<char>> board;
    char currentPlayer = 'X';
    bool gameOver = false;
    do {
        initializeBoard(board);
        currentPlayer = 'X';
        gameOver = false;
        while (!gameOver) {
            displayBoard(board);
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;
            if (!isMoveValid(board, move)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }
            updateBoard(board, move, currentPlayer);
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw.\n";
                gameOver = true;
            } else {
                switchPlayer(currentPlayer);
            }
        }
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    } while (true);
    return 0;
}
