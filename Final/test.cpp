#include <iostream>

using namespace std;


// Since the question specifically said "two pre-sorted arrays" I decided to use arrays for the function but the function
// could easily be adopted to intake two vectors and then just get the size of each vector in the beginning of the function
double find_median(int arr1[], int m, int arr2[], int n) 
{
    int middle = (m + n + 1) / 2;

    if(m <= n)
    {
        // Essentially does binary search on the smaller array
        int midpoint = m/2;

        int low = 0, high = m;
        while (low <= high) 
        {
            // Both arrays will be split into a left and right portion
            int i = (low + high) / 2;
            int j = middle - i;

            // Get the max and min of each array when split at the specific index
            int maxLeft_arr1;
            if (i == 0) 
            {
                maxLeft_arr1 = INT_MIN;
            } 
            else 
            {
                maxLeft_arr1 = arr1[i - 1];
            }

            int minRight_arr1;
            if (i == m) 
            {
                minRight_arr1 = INT_MAX;
            } 
            else 
            {
                minRight_arr1 = arr1[i];
            }

            int maxLeft_arr2;
            if (j == 0) 
            {
                maxLeft_arr2 = INT_MIN;
            } 
            else 
            {
                maxLeft_arr2 = arr2[j - 1];
            }

            int minRight_arr2;
            if (j == n) 
            {
                minRight_arr2 = INT_MAX;
            } 
            else 
            {
                minRight_arr2 = arr2[j];
            }


            if (maxLeft_arr1 <= minRight_arr2 && maxLeft_arr2 <= minRight_arr1) // All the left elements must be less than all the roght elements
            {
                if((m + n) % 2 == 1) // Odd number of elements
                {
                    return max(maxLeft_arr1, maxLeft_arr2); // Get the middle element
                }
                else // Even number of elements
                {
                    return (max(maxLeft_arr1, maxLeft_arr2) + min(minRight_arr1, minRight_arr2)) / 2.0; // Get average of the 2 middle elements
                }
            }
            else if (maxLeft_arr1 > minRight_arr2) // The choosen index did not split all the elements in half so we need to try another index
            {
                high = i - 1;
            }
            else
            {
                low = i + 1;
            }
        }
    }
    else // m > n This part is the same as above but it makes sure it is mainly searching in the smaller array
    {
        int midpoint = n/2;

        int low = 0, high = n;
        while (low <= high)
        {
            int i = (low + high) / 2;
            int j = middle - i;

            int maxLeft_arr2;
            if (i == 0) {
                maxLeft_arr2 = INT_MIN;
            } else {
                maxLeft_arr2 = arr2[i - 1];
            }

            int minRight_arr2;
            if (i == n) {
                minRight_arr2 = INT_MAX;
            } else {
                minRight_arr2 = arr2[i];
            }

            int maxLeft_arr1;
            if (j == 0) {
                maxLeft_arr1 = INT_MIN;
            } else {
                maxLeft_arr1 = arr1[j - 1];
            }

            int minRight_arr1;
            if (j == m) {
                minRight_arr1 = INT_MAX;
            } else {
                minRight_arr1 = arr1[j];
            }

            if (maxLeft_arr2 <= minRight_arr1 && maxLeft_arr1 <= minRight_arr2)
            {
                if((m + n) % 2 == 1) // Odd number of elements
                {
                    return max(maxLeft_arr2, maxLeft_arr1);
                }
                else // Even number of elements
                {
                    return (max(maxLeft_arr2, maxLeft_arr1) + min(minRight_arr2, minRight_arr1)) / 2.0;
                }
            }
            else if (maxLeft_arr2 > minRight_arr1)
            {
                high = i - 1;
            }
            else
            {
                low = i + 1;
            }
        }
    }

    return -1;
}


int main()
{
    // Input sample 1
    int nums1[] = {2, 6};
    int nums2[] = {4};

    double median = find_median(nums1, 2, nums2, 1);  // Correctly outputs a median of 4

    cout << median <<"\n";


    // Input sample 2
    int nums3[] = {5, 8};
    int nums4[] = {9, 11};

    double median2 = find_median(nums3, 2, nums4, 2); // Correctly outputs a median of 8.5

    cout << median2 <<"\n";

    // My testing example
    // int nums5[] = {1};
    // int nums6[] = {3, 5, 7, 9};

    // double median3 = find_median(nums5, 1, nums6, 4); // Correctly outputs 5.0

    // cout << median3 <<"\n";

    return 0;
}