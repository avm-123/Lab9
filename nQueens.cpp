/*
 * Name: Aidan Militzer
 * Date Submitted: 11/21/23
 * Lab Section: 001
 * Assignment Name: Lab 9 Nqueens
 */

#include <iostream>
#include <vector>

using namespace std;

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
void solveNQueensUtil(vector<int>& board, int row, int n, vector<vector<int>>& solutions);
bool isSafe(const vector<int>& board, int row, int col);
int nQueens(int n)
{
    vector<int> board(n,-1);
     vector<vector<int>> solutions;
    solveNQueensUtil(board, 0, n, solutions);
    return solutions.size();
}
// Recursive function to find all solutions for placing queens on an nxn chessboard
void solveNQueensUtil(vector<int>& board, int row, int n, vector<vector<int>>& solutions) {
  // If all queens are placed successfully, add the solution to the list
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueensUtil(board, row + 1, n, solutions);
        }
    }
}
// Function to check if placing a queen at a specific position is safe
bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
      // Check if there is a queen in the same column or in the diagonals
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}
/*
int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}*/
