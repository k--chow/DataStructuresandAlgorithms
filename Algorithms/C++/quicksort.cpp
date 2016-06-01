#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void quick_sort(int leftIndex, int rightIndex, vector<int> & arr) //call itself
{
    //
}

//partition function
int partitionIt(int left, int right, double pivot, vector<int> & arr) //splits array
{
    //partition algorithm
    //partition(int left, int right, array)
    // find largest element to left of pivot
    //find smallest element to right of pivot
    //if left index is greater than right index, swap them
    //return largest eleemnt to left of pivot
}

double medianOfThree(int a, int b, int c) //returns median of 3 for pivot
{
    if (a > b)
    {
        if (b >= c) return b;
        if (b < c) return c;
    }
    else if (b > a)
    {
        if (a >= c) return a;
        if (a < c) return c;
    }
    else // b = a
    {
        return b;
    }
}

//swap function
void swapIt(int A, int B, vector<int> & arr) //swaps two elements
{
    int temp = arr[A];
    arr[A] = arr[B];
    arr[B] = temp;
}

int main()
{

}
