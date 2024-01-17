#include <stdio.h>

#define N 9

// Function to print the Sudoku grid
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a digit can be placed in a particular cell
int isSafe(int board[N][N], int row, int col, int num) {
    // Check if 'num' is not present in the current row, current column, and the 3x3 grid
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num || board[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle using backtracking
int solveSudoku(int board[N][N]) {
    int row, col;

    // Find the first empty cell
    int isEmpty = 1;
    for (row = 0; row < N && isEmpty; row++) {
        for (col = 0; col < N && isEmpty; col++) {
            if (board[row][col] == 0) {
                isEmpty = 0;
            }
        }
    }

    // If no empty cell is found, the puzzle is solved
    if (isEmpty) {
        return 1;
    }

    // Try placing digits from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            // Place the digit if it's safe
            board[row][col] = num;

            // Recur to solve the rest of the puzzle
            if (solveSudoku(board)) {
                return 1; // Puzzle is solved
            }

            // If placing the digit doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // No valid digit found, backtrack
    return 0;
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board)) {
        printf("Sudoku solution:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
