#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trueRoot = -1;;

void dfs(int current, int distance, int previous, vector< vector<int> >& adjList, vector<int> &ans, int & runningMax)
{
    if (distance > runningMax) {
        runningMax = distance;
        trueRoot = current;
    }
    ans[current] =  max(ans[current], distance);
    for(int i=0; i<adjList[current].size(); i++)
    {
        if (adjList[current][i] != previous) {
            dfs(adjList[current][i], distance + 1, current, adjList, ans, runningMax);
        }
    }
}

void dfs2(int current, int distance, int previous, vector< vector<int> >& adjList, vector<int> &ans, int & runningMax)
{
    for(int i=0; i<adjList[current].size(); i++)
    {
        if (adjList[current][i] != previous) {
            ans[current] = max(ans[current], ans[adjList[current][i]] - 1);
            dfs(adjList[current][i], distance + 1, current, adjList, ans, runningMax);
        }
    }
}

int main()
{
    int nodes; cin >> nodes;
    vector< vector<int> > adjList(nodes);
    vector<int> ans(nodes, 0);
    vector<int> indegree(nodes, 0);
    for(int i=0; i<nodes-1; i++)
    {
        int to, from; cin >> to >> from;
        adjList[to].push_back(from);
        adjList[from].push_back(to);
        indegree[to]++; indegree[from]++;
    }
    int runningMax = 0;
    for(int i=0; i<nodes; i++)
    {
        if (indegree[i] == 1) {
            //cout << "go " << i << endl;
            dfs(i, 0, -1, adjList, ans, runningMax);
            break;
        }
    }
    //fill(ans.begin(), ans.end(), 0);
    //runningMax = 0;
    stack<int> s;
    //s.push(trueRoot);
    //cout << "trueroot " << trueRoot << endl;

    for(int i=0; i<nodes; i++) {
        if (ans[i] == ans[trueRoot]) {
            s.push(i);
        }
    }
    dfs(trueRoot, 0, -1, adjList, ans, runningMax);
    ans[trueRoot] = runningMax;

    while (!s.empty())
    {
        ans[s.top()] = runningMax;
        s.pop();
    }
    //max(runningMax - current, current)
    dfs2(trueRoot, 0, -1, adjList, ans, runningMax);
    for(int i=0; i<nodes; i++)
    {
        //ans[i] = max (runningMax - ans[i], ans[i]);
        cout << ans[i] << endl;
    }

}
