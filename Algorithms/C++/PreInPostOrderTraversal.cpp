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

void preOrder(int index)
{
    cout << mappy[index]->value << " ";
    if (mappy[index]->left != -1) preOrder(mappy[index]->left);
    if (mappy[index]->right != -1) preOrder(mappy[index]->right);
}

void inOrder(int index)
{
    if (mappy[index]->left != -1) inOrder(mappy[index]->left);
    cout << mappy[index]->value << " ";
    if (mappy[index]->right != -1) inOrder(mappy[index]->right);
}

void postOrder(int index)
{
    if (mappy[index]->left != -1) postOrder(mappy[index]->left);
    if (mappy[index]->right != -1) postOrder(mappy[index]->right);
    cout << mappy[index]->value << " ";
}

int main()
{
    int nodes; cin >> nodes;
    for(int i=0; i<nodes; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        mappy[i] = new Node(a, b, c);
    }
    preOrder(0);
    cout << endl;
    inOrder(0);
    cout << endl;
    postOrder(0);
    cout << endl;
}
