#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Algorithms
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    public:
        bool binarySearch(int low, int high, int target)
        {
            int mid = (low+high) >> 1;
            if (low > high) //definitely not found
            {
                return false;
            }
            if (target > mid) //larger, go right half
            {
                low = mid+1;
                binarySearch(low, high, target);
            }
            else if (target < mid)//smaller go left half
            {
                high = mid;
                binarySearch(low, high, target);
            }
            else // found!
            {
                return true;
            }

        };

};
