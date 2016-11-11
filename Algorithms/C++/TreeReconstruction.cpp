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
    int value;
    Node* left;
    Node* right;
    Node(int value): left(NULL), right(NULL)
    {
        this->value = value;
    };

};

unordered_map<int, int> position;
vector<int> postOrder;
vector<int> inOrder;

Node* reconstructTree(int start, int end, int i)
{
    //cout << "called " << start << " " << end << endl;
    if (start > end) return NULL;
    //find root
    int rootValue;
    int rootIndex;
    for(; i<postOrder.size(); i++)
    {
        //if postOrder[i] is in between start and end in inOrder
        if (position[postOrder[i]] >= start && position[postOrder[i]] <= end)
        {
            rootValue = postOrder[i];
            break;
        }
    }
    //cout << "hello" << endl;
    //cout << rootValue << endl;
    Node* node = new Node(rootValue);
    rootIndex = position[rootValue];
    //cout << rootIndex << endl;

    node->left = reconstructTree(start, rootIndex-1, i);
    node->right = reconstructTree(rootIndex+1, end, i);
    return node;
}

int main()
{
    int nodes; cin >> nodes;

    stack<int> s;
    for(int i=0; i<nodes; i++)
    {
        int in; cin >> in;
        s.push(in);
    }
    for(int i=0; i<nodes; i++)
    {
        int in; cin >> in;
        position[in] = i;
        postOrder.push_back(s.top());
        inOrder.push_back(in);
        s.pop();
    }
    Node* root = reconstructTree(0, inOrder.size()-1, 0);
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* current = q.front();
        cout << current->value << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
        q.pop();
    }



}
