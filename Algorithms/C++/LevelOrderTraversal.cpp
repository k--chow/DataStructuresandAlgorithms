#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node
{
    int left, right, value;
    Node(int value, int left, int right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    };

};

unordered_map<int, Node*> mappy;

int main()
{
    int nodes; cin >> nodes;
    for(int i=0; i<nodes; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        mappy[i] = new Node(a, b, c);
    }
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int current = q.front(); q.pop();
        cout << mappy[current]->value << " ";
        if (mappy[current]->left != -1) q.push(mappy[current]->left);
        if (mappy[current]->right != -1) q.push(mappy[current]->right);
    }
}
