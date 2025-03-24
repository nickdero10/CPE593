/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Project 1: Piper Probe
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// Setting up pipe inserts
const vector<vector<int>> pipes = {
    {},         // 0: No Pipe
    {1,1,1,1},  // 1: Up, Down, Left, Right Pipe
    {1,1,0,0},  // 2: Up, Down Pipe
    {0,0,1,1},  // 3: Left, Right Pipe
    {1,0,0,1},  // 4: Up, Right Pipe
    {0,1,0,1},  // 5: Down, Right Pipe
    {0,1,1,0},  // 6: Down, Left Pipe
    {1,0,1,0}   // 7: Up, Left Pipe
};

// Setting up directions for movement
const vector<pair<int, int>> directions = {
    {-1,0}, // Up
    {1,0},  // Down
    {0,-1}, // Left
    {0,1}   // Right
};

// Checks if the next spot is a pipe that can be connected
bool canMove(int prevPipe, int nextPipe, int dir){
    // If theres no pipe in the next spot it can't move
    if(nextPipe == 0){
        return false;
    }
    int backwards = dir ^ 1;
    // Returns true only if the current pipe connects to the next pipe in both directions
    return pipes[prevPipe][dir] && pipes[nextPipe][backwards];
}

/*
N = Height of map
M = Width of map
R = Vertical location of probe
C = Horizontal location of probe
L - Length of probe
*/

// BFS function to explore the pipes
int bfs(vector<vector<int>>& map, int R, int C, int L){
    int N = map.size(), M = map[0].size();

    // Create the queue and the visited set
    queue<pair<int, int>> Q;
    set<pair<int, int>> visited;

    Q.push({R,C});
    visited.insert({R,C});

    // Starts the count as the first spot of the piperprobe and length to check how much is left
    int count = 1, length = 1;

    // Limits moves to how much length is left
    while(!Q.empty() && length < L){
        int size = Q.size();
        for (int i = 0; i < size; i++){
            auto [r, c] = Q.front(); 
            Q.pop();
            int currPipe = map[r][c];

            // Checks all 4 directions for the columns and rows
            for(int d = 0; d < 4; d++){
                int nextr = r + directions[d].first;
                int nextc = c + directions[d].second;

                if(nextr >= 0 && nextr < N && nextc >= 0 && nextc < M // Checks to see if movement is in bounds
                    && visited.find({nextr,nextc}) == visited.end()   // Checks to see if the pipes been visited yet
                    && canMove(currPipe, map[nextr][nextc], d)){      // Checks to see if the canMove function returned true
                        Q.push({nextr,nextc});
                        visited.insert({nextr,nextc});
                        count ++;
                }
            }
        }
        length ++;
    }
    return count;
}

int main(){
    int T;
    cout << "Insert Number of Test Cases: ";
    cin >> T;

    while(T--){
        int N, M, R, C, L;
        cout << "Insert 'Map Height', 'Map Width', 'Horizontal Position for PiperProbe', 'Vertical Position for PiperProbe', 'Length of PiperProbe'" << endl;
        cout << "Insert Map" << endl;
        cin >> N >> M >> R >> C >> L;

        vector<vector<int>> map(N, vector<int>(M));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> map[i][j];
            }
        }
        cout << bfs(map, R, C, L) << endl;
    }
    return 0;
}