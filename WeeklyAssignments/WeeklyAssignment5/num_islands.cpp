/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Weekly Assignment 5: Graph Algorithm
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Initializing the size of rows and collumns cause matrix
const int rows = 5;
const int cols = 4;

// Function for BFS
void BFS(int n, int m, char graph[rows][cols]) {
    // Start Queue
    queue<pair<int, int>> Q;

    // Setting up directions as Up, Down, Left, Right
    int directions[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; 

    // Visited gets set to 0
    graph[n][m] = '0';
    // Add the first visited cell to the queue 
    Q.emplace(n, m);

    while (!Q.empty()) {

        // get to the front of the queue and remove the processed location
        auto [currentN, currentM] = Q.front();
        Q.pop();


        // Explores every direction
        for (auto& dir : directions) {
            int newN = currentN + dir[0], newM = currentM + dir[1];


            // Checks if the new position is either land or water
            if (newN >= 0 && newN < rows && newM >= 0 && newM < cols && graph[newN][newM] == '1') {
                graph[newN][newM] = '0'; // Mark as visited
                Q.emplace(newN, newM); // Adds the new visited spot to the queue
            }
        }
    }
}

// Function to count the number of islands
int numIslands(char graph[rows][cols]) {
    int islands = 0;
    
    // Run through the whole grid
    for (int n = 0; n < rows; n++) {
        for (int m = 0; m < cols; m++) {
            // If the spot is 1, add 1 to the island count and start the BFS
            if (graph[n][m] == '1') {
                islands++;
                BFS(n, m, graph);
            }
        }
    }
    return islands;
}

int main() {
    char graph[rows][cols] = {
        {'0', '1', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '0'},
        {'1', '1', '0', '1'}
    };

    cout << "Number of Islands: " << numIslands(graph) << endl;
    return 0;
}
