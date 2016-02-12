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



void sort(int a[])
{
    for(int i=1; i<5; i++)
    {
        int key = a[i];
        int j = i;

        while (key < a[j-1])
        {

            //j is on the left
            //i is the key
            j--;
            //swap
            a[i] = a[j];
            a[j] = key;
            i--;

        }
        cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl;
        cout << endl;
        //cout << j << endl;

    }
}

int main()
{
    int a[5] = {5, 4, 3, 2, 1};
    sort(a);
    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;
    cout << a[3] << endl;
    cout << a[4] << endl;

}
