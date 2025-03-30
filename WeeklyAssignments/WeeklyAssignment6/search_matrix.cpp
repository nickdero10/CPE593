/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Weekly Assignment 6: Searching
*/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100
#define MAX_M 100

bool search(vector<vector<int>>& grid, int target){
    if(grid.empty() || grid[0].empty()) return false;

    int N = grid.size();
    int M = grid[0].size();

    int left = 0;
    int right = N * M - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = grid[mid / M][mid % M];
        
        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main(){
    int rows, cols, target;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    cout << "Enter matrix values in row-wise order: ";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << "Enter target value: ";
    cin >> target;

    if(search(grid, target)){
        cout << "Target " <<  target << " found.";
    }else{
        cout << "Target " << target << " not found.";
    }
}