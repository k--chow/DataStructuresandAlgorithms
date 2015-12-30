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



