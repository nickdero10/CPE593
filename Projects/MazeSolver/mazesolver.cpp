/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Project 2: Maze Solver
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Maze{
    vector<string> map;
    pair <int, int> start, end;
};

bool readFile(Maze& maze){
    // Reads the file path and returns false if couldn't find file
    string path = "C:/Users/nickd/CPE593/Projects/MazeSolver/maze3.txt";
    ifstream file(path);
    if(!file.is_open()){
        return false;   
    }

    string line;

    // Reads file line by line and adds it to the map
    while(getline(file, line)){
        maze.map.push_back(line);
    }

    return true;
}

bool SE_Check(Maze& maze){
    // Checks each spot for either an S or E
    for (int i = 0; i < maze.map.size(); ++i) {
        for (int j = 0; j < maze.map[i].size(); ++j) {
            // Finds S and E and marks location for each
            if (maze.map[i][j] == 'S') maze.start = {i, j};
            if (maze.map[i][j] == 'E') maze.end = {i, j};
        }
    }
    return true;
}

void printMaze(const Maze& maze){
    // Prints maze row by row
    cout << "Maze with all paths replaced by '*': " << endl;

    for(const auto& row : maze.map){
        cout << row << endl;
    }
}

bool isValid(const Maze& maze, int x, int y){
    // Checks if the point is in the bounds of the maze
    return x >= 0 && y >= 0 && 
    x < maze.map.size() && y < maze.map[0].size() &&
    // The maze has to be either a . or the start or end
    (maze.map[x][y] == '.' || maze.map[x][y] == 'S' || maze.map[x][y] == 'E');
}

void dfs(Maze& maze, int x, int y, vector<pair<int, int>>& path,
         vector<vector<bool>>& visited,
         vector<vector<pair<int, int>>>& solutions) {

    // Checks to see if the point is valid or visited
    if (!isValid(maze, x, y) || visited[x][y]) return;

    // Made it through maze (backtracking)
    if (make_pair(x, y) == maze.end) {
        // Adds the endpoint to the path
        path.push_back({x, y});
        // Stores it as a valid path
        solutions.push_back(path);
        // Backtracks and removes the endpoint
        path.pop_back();
        return;
    }

    // Mark the position as visited and add it to the path
    visited[x][y] = true;
    path.push_back({x, y});

    // Mapping all directions to move in
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int d = 0; d < 4; ++d) {
        // Recursion to move thorugh maze with dfs and find correct path
        dfs(maze, x + dx[d], y + dy[d], path, visited, solutions);
    }

    // Removes the current cell and makes path 
    // unvisited so it can be used in other paths
    path.pop_back();
    visited[x][y] = false;
}

void markPaths(Maze& maze, const vector<vector<pair<int, int>>>& solutions) {
    for (const auto& path : solutions) {
        for (const auto& p : path) {
            // Reads the path and changes every . to a *
            if (maze.map[p.first][p.second] == '.')
                maze.map[p.first][p.second] = '*';
        }
    }
}

void printSolutions(const vector<vector<pair<int, int>>>& solutions) {
    // If maze can't be solved
    if (solutions.empty()) {
        cout << "Maze could not be solved";
        return;
    }

    // Marks every point on the path for each different solution
    for (int i = 0; i < solutions.size(); ++i) {
        cout << "Path " << i + 1 << ": ";
        for (const auto& p : solutions[i]) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    Maze maze;

    // If the file can't be read
    if (!readFile(maze)) {
        cout << "Failed to read maze file." << endl;
        return 0;
    }

    SE_Check(maze);
    vector<pair<int, int>> path;
    vector<vector<pair<int, int>>> solutions;
    vector<vector<bool>> visited(maze.map.size(), vector<bool>(maze.map[0].size(), false));

    dfs(maze, maze.start.first, maze.start.second, path, visited, solutions);
    markPaths(maze, solutions);
    printMaze(maze);
    printSolutions(solutions);

    return 0;
}