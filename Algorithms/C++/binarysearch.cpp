#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//no index returned
bool binarySearch(int low, int high, int target)
        {
            int mid = (low+high) >> 1;
            if (low > high) //definitely not found
            {
                cout << "not found!" << endl;
                return false;
            }
            if (target > arr[mid]) //larger, go right half
            {
                low = mid+1;
                binarySearch(low, high, target);
            }
            else if (target < arr[mid])//smaller go left half
            {
                high = mid;
                binarySearch(low, high, target);
            }
            else // found!
            {
                cout << "found!" << endl;
                return true;
            }

        };

/*
Loop Invariant:

Initialization:
The element is between low and high, or not in the array at all.

Maintenance:
The element is between low and high, where we reset low or high, since it is sorted,
we can conclude it is between the two pointer still.

Termination: Eventually, the pointers become equal or the low pointer surpasses the high pointer.
In the first case, the element is found, and it is between the two pointers (as it is the pointer),
or the element is not in.
*/
