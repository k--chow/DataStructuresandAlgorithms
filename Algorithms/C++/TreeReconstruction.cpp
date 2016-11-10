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
    Node* left, right;
    Node(int value): left(NULL), right(NULL)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    };

};

unordered_map<int, Node*> mappy;
unordered_map<int, int> position;

int main()
{
    int nodes; cin >> nodes;
    vector<int> postOrder;
    vector<int> inOrder;
    stack<int> s;
    for(int i=0; i<nodes; i++)
    {
        int in; cin >> in;
        s.push(in);
    }
    for(int i=0; i<nodes; i++)
    {
        int in; cin >> in;
        mappy[in] = new Node(in);
        position[in] = i;
        postOrder.push_back(s.top());
        s.pop();
    }
    Node* root = postOrder[0];
    //traverse through
    for(int i=1; i<nodes; i++)
    {

    }


}
