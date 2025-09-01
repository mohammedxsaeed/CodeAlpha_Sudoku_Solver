/// Author : Mohammed Saeed

#include <iostream>
using namespace std;

const int N = 9; //Size of Grid of Sudoku

void printGrid(int grid[N][N]) /// Printing Full Grid
{
    for(int i = 0; i < N; i++) {
        if(i % 3 == 0 && i != 0) //for every row of 3 elements
            cout << "------+-------+------\n";
        for(int j = 0; j < N; j++) //for every coulmn of 3 elements
            {
            if(j % 3 == 0 && j != 0)
                cout << "| ";
            if(grid[i][j] == 0) /// Write 0 in Sudoku matrix means blank
                cout << ". ";
            else
                cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row, int col, int num) /// Checking function
{
    // Check row
    for(int x = 0; x < N; x++)
        if(grid[row][x] == num)
            return false;

    // Check column
    for(int x = 0; x < N; x++)
        if(grid[x][col] == num)
            return false;

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(grid[i + startRow][j + startCol] == num)
                return false;

    return true;  // Safe Number
}

bool solveSudoku(int grid[N][N], int row, int col)
 {
    if(row == N - 1 && col == N) // Sudoku is Solved!
        return true;

    if(col == N) {
        row++;
        col = 0;
    }

    if(grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    for(int num = 1; num <= N; num++) {
        if(isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if(solveSudoku(grid, row, col + 1))
                return true;
        }

        grid[row][col] = 0;
    }
    return false;
}

int main() {
    int Sudoku_grid[N][N] = {
        {0, 8, 5, 7, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 0, 5, 0, 0, 4},
        {0, 0, 0, 0, 0, 8, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 5, 8, 2},
        {0, 0, 0, 0, 7, 9, 4, 0, 0},
        {0, 0, 0, 0, 6, 0, 7, 0, 0},
        {4, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 7, 0, 0, 0, 0, 0, 0, 1},
        {9, 0, 0, 1, 3, 0, 0, 0, 0}
    };

    cout << "Original Sudoku:\n";
    printGrid(Sudoku_grid);

    if(solveSudoku(Sudoku_grid, 0, 0)) {
        cout << "\nSolved Sudoku:\n";
        printGrid(Sudoku_grid);
    } else {
        cout << "\nNo solution exists!\n"; //for safety
    }

    return 0;
}
