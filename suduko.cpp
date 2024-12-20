// design a suduko
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void printBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int board[9][9], int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int board[9][9]) {
    int row, col;
    bool empty = false;

    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty) break;
    }

    if (!empty) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            board[row][col] = 0; 
        }
    }

    return false;
}

void inputBoard(int board[9][9]) {
    cout << "Enter the Sudoku puzzle (use 0 for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << "Enter value for position (" << i + 1 << "," << j + 1 << "): ";
            cin >> board[i][j];
            if (board[i][j] < 0 || board[i][j] > 9) {
                cout << "Invalid input. Enter values between 0 and 9.\n";
                j--; 
            }
        }
    }
}

int main() {
    int board[9][9];

    inputBoard(board);

    cout << "\nEntered Sudoku Puzzle:\n";
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "\nSolved Sudoku Puzzle:\n";
        printBoard(board);
    } else {
        cout << "\nNo solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}
