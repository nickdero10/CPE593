/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Weekly Assignment 2: Asteroid Collision
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Initializes the stack
        vector<int> stack;

        // Itterates through the asteroids
        for (int asteroid : asteroids) {
            // Starts by setting destroyed to false
            bool destroyed = false;

            /* 
                Checks three things for a collision:
                    1. If the stack isn't empty
                    2. If the current asteroid is moving left (It's negative)
                    3. if the top of the stack is moving right (It's positive)
                If all of these apply then there is a collision
            */
            while (!stack.empty() && asteroid < 0 && stack.back() > 0) {
                // If the top asteroid is smaller than the current it gets destroyed
                if (stack.back() < -asteroid) {
                    stack.pop_back();
                    // Continue restarts the loop to check for a next collision
                    continue;
                } else if (stack.back() == -asteroid) {
                    // Both astroids destroyed
                    stack.pop_back();
                } 

                // Sets asteroid to destroyed
                destroyed = true;
                break;
            }

            // The survived asteroid is added to the stack
            if (!destroyed) {
                stack.push_back(asteroid);
            }
        }
        // returns the values of the stack
        return stack;
    }
};

void runTestCases() {
    Solution solution;
    vector<vector<int>> testCases = {
        {5, 10, -5}, // Case 1: 5 and 10 survive
        {8, -8}, // Case 2: Both destroy each other
        {10, 2, -5}, // Case 3: 10 survives, -5 is destroyed
        {-5, -10, 10, 5}, // Case 4: -5, -10 survive, 10 and 5 survive separately
        {3, 9, -2, -10} // Case 5: 3 survives, 9 vs -2 (9 survives), 9 vs -10 (-10 survives)
    };
    for (const auto& testCase : testCases) {
        vector<int> result = solution.asteroidCollision(const_cast<vector<int>&>(testCase));
        cout << "Input: ";
        for (int asteroid : testCase) {
            cout << asteroid << " ";
        }
        cout << "\nOutput: ";
        for (int asteroid : result) {
            cout << asteroid << " ";
        }
        cout << "\n---------------------\n";
    }
}

int main() {
    runTestCases();
    return 0;
}
