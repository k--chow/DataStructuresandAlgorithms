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
int arr[] = {1, 2, 6, 3, 1, 0 ,4};
int arr2[] = {2, 1};
//int arr[] = {3, 2, 1};
//my code is broken, I give up for now.

double medianOfThree(int a, int b, int c) //returns median of 3 for pivot
{
    if (arr[a] > arr[b])
    {
        if (arr[b] >= arr[c]) return arr[b];
        if (arr[b] < arr[c]) return min(arr[a], arr[c]);
    }
    else if (arr[b] > arr[a])
    {
        if (arr[a] >= arr[c]) return arr[a];
        if (arr[a] < arr[c]) return min(arr[b], arr[c]);
    }

        return arr[b];
}

void test_sort(int left, int right)
{
    arr[0] = 99;
}

//swap function
void swapIt(int &A, int &B) //swaps two elements
{
    int temp = A;
    A = B;
    B = temp;
}

//insertion sort for size <= 3
void manual_sort(int left, int right)
{
    int size = right-left + 1;
    if (size <= 1) return;
    for(int i=left+1; i<right; i++)
    {
        //find where to insert
        int j = i;
        while (j > 0 && arr[j-1] > arr[j])
        {
            //swap arr[j-1] and arr[j]
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }

    }
}

void manualSort(int left, int right)
{
      int size = right-left+1;
      if(size <= 1)
         return;                       //no sort necessary
      if(size == 2){
         if( arr[left] > arr[right] )
            swapIt(arr[left], arr[right]);
            return;}
      else  //size==3, so 3-sort left, center (right-1) & right
    {

         if( arr[left] > arr[right-1] )
            swapIt(arr[left], arr[right-1]);                //left, center
         if( arr[left] > arr[right] )
            swapIt(arr[left], arr[right]);                  //left, right
         if( arr[right-1] > arr[right] )
            swapIt(arr[right-1], arr[right]);               //center, right
    }
}  //end manualSort()



//partition function
int partitionIt(int left, int right, double pivot) //splits array
{
    //partition algorithm
    //partition(int left, int right, pivot, array)
    int leftMark = left;
    int rightMark = right;
    while (1)
    {
        while (arr[++leftMark] < pivot)
        {

        }

        while (arr[--rightMark] > pivot)
        {

        }

        if (leftMark >= rightMark)
        {
            break;

        }
        else
        {
            swapIt(arr[leftMark], arr[rightMark]);
        }


    }
    return leftMark;
    //find largest element to left of pivot
    //find smallest element to right of pivot
    //if left index is greater than right index, swap them, else break
    //return largest element to left of pivot (leftMark)
}

void quick_sort(int leftIndex, int rightIndex) //call itself
{
    if ((rightIndex - leftIndex + 1) <= 3)//manual sort
    {
        manual_sort(leftIndex, rightIndex);
        cout << "MANUAL SORT: " << leftIndex << " " << rightIndex << endl;
     }
    else
    {
    //get median of 3
    double pivot = medianOfThree(leftIndex, (leftIndex+rightIndex)/2 ,rightIndex);
    //int pivot = (leftIndex + rightIndex)/2;
    //partition with pivot
    int part = partitionIt(leftIndex, rightIndex, pivot);
    cout << "PART: " << part << endl;
    //quicksort left
    //quick_sort(leftIndex, part-1);
    //quicksort right
    quick_sort(part+1, rightIndex);

    }
}





int main()
{
    //manual_sort(0, 2);
    //cout << medianOfThree(0, 3, 6) << endl;
    manualSort(0, 6);
    //swapIt(arr[2], arr[6]); //broken swapIt function
    for(int i=0; i<7; i++)
    {
        cout << arr[i] << " ";
    }
}
