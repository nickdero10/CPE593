/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Weekly Assignment 4: Hashing and Hash Tables
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i= 0; i <= 8; i++) {
            unordered_set<char> rows, columns, boxes;
            for (int j = 0; j <= 8; j++){

                // Check row
                // If the current spot isn't a empty value
                if (board[i][j] != '.') {
                    // If .find finds the value already, it won't return rows.end, and will be false
                    if (rows.find(board[i][j]) != rows.end()) return false;
                    // if rows.end is returned the value doesn't exist already and is placed in the rows set
                    rows.insert(board[i][j]);
                }

                // Same above goes for checking the columns and boxes
                
                // Check column
                if (board[j][i] != '.') {
                    if (columns.find(board[j][i]) != columns.end()) return false;
                    columns.insert(board[j][i]);
                }

                // Check box
                int rowIndex = 3 * (i / 3) + j / 3;
                int colIndex = 3 * (i % 3) + j % 3;
                if (board[rowIndex][colIndex] != '.') {
                    if (boxes.find(board[rowIndex][colIndex]) != boxes.end()) return false;
                    boxes.insert(board[rowIndex][colIndex]);
                }
            }            
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Updated Sudoku board as per your input
    vector<vector<char>> board = {
        {'9', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '5', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    bool result = sol.isValidSudoku(board);

    if (result) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is invalid." << endl;
    }

    return 0;
}
