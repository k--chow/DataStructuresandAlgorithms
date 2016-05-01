#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node() : value(0), left(NULL), right(NULL){}
};

class BinaryTree
{
    private:
        Node* root;
    public:
        BinaryTree() : root(NULL)
        {

        }

        Node* find(int key)
        {

        }

        void insert(int value)
        {
            Node* newNode = new Node;
            newNode->value = value;
            //check if root is null
            if (root == NULL)
            {
                root = newNode;
            }
            else //traverse and insert
            {
                Node* current = root;
                Node* parent; //needed
                while (true)
                {
                    parent = current;
                    if (value > current->value) //go right
                    {
                        current = current->right;

                        if (current == NULL) //insert here
                        {
                            parent->right = newNode;
                            return;
                        }

                    }
                    else //go left
                    {
                        current = current->left;

                        if (current == NULL)
                        {
                            parent->left = newNode;
                            return;
                        }
                    }
                }

            }
        }

        void traverse()
        {

        }

        void displayTree()
        {
            cout << root->value << endl;
            cout << root->left->value << endl;
            cout << root->right->value << endl;
        }

};

int main()
{
    BinaryTree Test;
    Test.insert(5);
    Test.insert(6);
    Test.insert(4);
    Test.displayTree();
}
