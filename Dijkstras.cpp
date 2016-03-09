#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unordered_map>
using namespace std;

void d(vector< vector<int> > & matrix, vector<int> & visited, int start, int end)
{

}

int main()
{
    vector< vector<int> > matrix(7);
    vector<int> visited(7, 0);

    for(int i=0; i< matrix.size(); i++)
    {
        for(int j=0; j< matrix.size(); j++)
        {
            matrix[i].push_back(-1);
        }

    }

    matrix[0][1] = 7;
    matrix[1][0] = 7;
    matrix[0][3] = 5;
    matrix[3][0] = 5;
    matrix[3][1] = 9;
    matrix[1][3] = 9;

    for(int i=0; i< matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


}
