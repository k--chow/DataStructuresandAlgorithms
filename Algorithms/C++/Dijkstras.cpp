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

//Dijkstra's Algorithm with no priorty queue

void d(vector< vector<int> > & matrix, vector<int> & visited, vector<int> & dist, int start, int end)
{
    //parameter start
    visited[start] = 1;
    deque<int> q;
    dist[start] = 0;
    for (int i=0; i<matrix[start].size(); i++)
    {
        if (matrix[start][i] != -1 && matrix[start][i] < dist[i]) //edge exists and smaller
        {
            //update the distance
            dist[i] = dist[start] + matrix[start][i];
        }
    }
    //above is only for the first neighbors
    //now add to queue if its unvisited and smallest

}

void d2(vector< vector<int> > & matrix, vector<int> & visited, vector<int> & dist, int start, int end)
{
    visited[start] = 1;

    for(int i=0; i< matrix[start].size(); i++)
    {
        if (matrix[start][i] != -1 && visited[i] == 0) //reachable and unvisited
        {
            if (dist[start] + matrix[start][i] < dist[i])
            {
                dist[i] = dist[start] + matrix[start][i];
            }
        }
    }

    if (visited[end] == 1)
    {
        return;
    }
    else
    {
        int low = 100000;
        int node;
        for(int i=0; i<dist.size(); i++)
        {
            if (dist[i] < low && visited[i] == 0)
            {
                low = dist[i];
                node = i;
            }
        }
        if (low == 100000)
        {
            return;
        }
        else
        {
            d2(matrix, visited, dist, node, end);
        }
    }
}

int main()
{
    vector< vector<int> > matrix(7);
    vector<int> visited(7, 0);
    vector<int> distance(7, 100000);

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
    matrix[1][2] = 8;
    matrix[2][1] = 8;
    matrix[1][4] = 7;
    matrix[4][1] = 7;
    matrix[2][4] = 5;
    matrix[4][2] = 5;
    matrix[3][4] = 15;
    matrix[4][3] = 15;
    matrix[3][5] = 6;
    matrix[5][3] = 6;
    matrix[5][4] = 8;
    matrix[4][5] = 8;
    matrix[4][6] = 9;
    matrix[6][4] = 9;
    matrix[5][6] = 11;
    matrix[6][5] = 11;

    for(int i=0; i< matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    distance[0] = 0;
    d2(matrix, visited, distance, 0, 6);

    for(int i=0; i<distance.size(); i++)
    {
        cout << distance[i] << endl;
    }


}
