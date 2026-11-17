#include <cstdlib>
#include <iostream>
using namespace std;

const int N = 8;
int board[N][N] = {};

bool isSafe(int row, int col) {

    // Check entire column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {

        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N; i--, j++) {

        if (board[i][j] == 1)
            return false;
    }

    // Check lower-left diagonal
    for (int i = row + 1, j = col - 1;
         i < N && j >= 0; i++, j--) {

        if (board[i][j] == 1)
            return false;
    }

    // Check lower-right diagonal
    for (int i = row + 1, j = col + 1;
         i < N && j < N; i++, j++) {

        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int row, int fixedRow) {
    if (row == N) {
        return true;
    }

    // The fixed queen is already placed in this row.
    if (row == fixedRow) {
        return solve(row + 1, fixedRow);
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solve(row + 1, fixedRow)) {
                return true;
            }

            // Backtrack: remove the queen and try another column.
            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (board[i][j] == 1 ? " Q " : " . ");
        }
        cout << '\n';
    }
}

int main() {
    int row, col;

    cout << "Enter first queen row (1-8): ";
    cin >> row;

    cout << "Enter first queen column (1-8): ";
    cin >> col;

    // Convert the user's 1-based position to 0-based array indices.
    --row;
    --col;

    if (row < 0 || row >= N || col < 0 || col >= N) {
        cout << "Invalid position\n";
        return 1;
    }

    // Place and preserve the fixed queen.
    board[row][col] = 1;

    if (solve(0, row)) {
        cout << "Solution found:\n";
        printBoard();
    } else {
        cout << "No solution for this position.\n";
    }

    return 0;
}