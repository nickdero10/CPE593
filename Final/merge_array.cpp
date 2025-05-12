/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Final Assignment: Merge Arrays
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;

// Find the k-th smallest element in the combined array
int findKth(const vector<int>& nums1, const vector<int>& nums2, int k, int start1, int start2) {
    // returns the smallest element from either nums1 or nums2
    if (start1 >= nums1.size()) return nums2[start2 + k - 1];
    if (start2 >= nums2.size()) return nums1[start1 + k - 1];
    if (k == 1) return min(nums1[start1], nums2[start2]);

    int mid1 = INT_MAX, mid2 = INT_MAX;

    // If theres more than k/2 elements in num 1, grab the middle element
    if (start1 + k / 2 - 1 < nums1.size()) {
        mid1 = nums1[start1 + k / 2 - 1];
    }
    // If theres more than k/2 elements in num 2, grab the middle element
    if (start2 + k / 2 - 1 < nums2.size()) {
        mid2 = nums2[start2 + k / 2 - 1];
    }

    // Get rid of the smaller half that has the smaller mid value
    if (mid1 < mid2) {
        return findKth(nums1, nums2, k - k / 2, start1 + k / 2, start2);
    } else {
        return findKth(nums1, nums2, k - k / 2, start1, start2 + k / 2);
    }
}

// Computes the median using the findKth function
double computeMedian(const vector<int>& nums1, const vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    // If the size is odd, return the middle element
    if (total % 2 == 1) {
        return findKth(nums1, nums2, total / 2 + 1, 0, 0);
    // If it's even, take the two middle elements and average them
    } else {
        int left = findKth(nums1, nums2, total / 2, 0, 0);
        int right = findKth(nums1, nums2, total / 2 + 1, 0, 0);
        return (left + right) / 2.0;
    }
}

int main() {
    vector<int> nums1 = {2, 6};
    vector<int> nums2 = {4};

    double median = computeMedian(nums1, nums2);
    cout << fixed << setprecision(5) << median << endl;

    return 0;
}
