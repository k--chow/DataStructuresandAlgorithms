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
#include <queue>
#include <tuple>
using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> t; //tuple of vertex 1, vertex 2, cost

struct Compare
{
    bool operator() (t a, t b)
    {
        return get<2>(a) > get<2>(b);
    }
};

priority_queue< t, vector<t>, Compare> pq; //next node, cost
//spit out edge
void prims(vector< vector<int> >& adj)
{
    //add first edges
    string output = "";
    int totalCost = 0;
    vector<bool> visited(adj.size(), 0);
    visited[0] = 1;
    for(int j=0; j<adj[0].size(); j++)
    {
        if (adj[0][j] != -1 && !visited[j]) pq.push(make_tuple(0, j, adj[0][j]));
    }
    while (!pq.empty()) {
        t next = pq.top();
        int currV = get<0>(next), nextV = get<1>(next), cost = get<2>(next);
        pq.pop();
        if (!visited[nextV]) {
            visited[nextV] = 1;
            output += to_string(currV) + "->" + to_string(nextV) + " ";
            totalCost += cost;
            for(size_t j=0; j<adj[0].size(); j++) {
                if (adj[nextV][j] != -1 && !visited[j]) pq.push(make_tuple(nextV,j, adj[nextV][j]));
            }
        }
    }
    cout << "Output: " << output << endl;
    cout << "Total Cost: " << totalCost << endl;
}

int main()
{
    //graph
    int n, e; cin >> n >> e;
    vector< vector<int> > adjMatrix(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            adjMatrix[i].push_back(-1);
        }
    }

    for(int i=0; i<e; i++) {
        int v1, v2, w; cin >> v1 >> v2 >> w;
        v1-=1, v2-=1;
        adjMatrix[v1][v2] = w;
        adjMatrix[v2][v1] = w;
    }
    prims(adjMatrix);

}

//start from node 0
//set this node to visited
//add all its edges into priority_queue
//add to output, add to total cost
//while pq is not empty -
//dequeue and check if new node is visited
//if unvisited, get cost, add to output, add all its edges into pq
//print output string, total cost
