#include <iostream>
#include <vector>
using namespace std;

int trappedWater(vector<int> &height) {
    // initialize values for left and right
    // Left starts at 1 and right starts at the second 
    // to last because the water cant be trapped in the first or last spot
    int left = 1;
    int right = height.size() - 2;

    // The max values are initially the left and right starting values
    int lMax = height[left - 1];
    int rMax = height[right + 1];

    // int water is used to update the value for all the trapped water
    int water = 0;

    // Loop through from left to right
    while (left <= right) {
        if (rMax <= lMax) {
            // If the max height is less than or equal to the current height, it can't trap any water here
            if (rMax > height[right]) {
                // The amount of water trapped in the spot is the max height - the current height
                water += (rMax - height[right]);
            }
            // Checks if new height is a new max and sets if it is
            rMax = max(rMax, height[right]);

            // Moves left one spot
            right -= 1;

        // same as above but for left side check
        } else { 
            if (lMax > height[left]) {
                water += (lMax - height[left]);
            }
            
            lMax = max(lMax, height[left]);

            left += 1;
        }
    }
    return water;
}

int main(){
    int n;
    cout << "Enter the number of elements in the height array: ";
    cin >> n;
    
    vector<int> height(n);
    cout << "Enter the height values: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << "Height = [";

    for (int i = 0; i < n - 1; i++) {
        cout << height[i] << ",";
    }

    cout << height[n - 1] << "]" << endl;

    cout << "Total trapped water: " << trappedWater(height) << endl;
    return 0;
}

