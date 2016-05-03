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

//structs have automatic public classes
struct Node
{
    int value;
    Node *left;
    Node *right;
    Node() : value(0), left(NULL), right(NULL){}
};

//classes have automatic private classes
class BinaryTree
{
    private:
        Node* root;
    public:
        BinaryTree() : root(NULL)
        {

        }

        Node* getRoot()
        {
            return root;
        }

        Node* find(int key)
        {
            Node* current = root;
            while(1)
            {
                if (current == NULL)
                {
                    return NULL;
                }

                if (current->value == key)
                {
                    return current;
                }
                else if(key < current->value)//go left
                {
                    current = current->left;
                }
                else //go right
                {
                    current = current->right;
                }
            }
        }

        void deleteNode(int value)
        {
            Node* node = find(value);
            delete node;
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

        void displayTree(Node* node)
        {
            if (node == NULL)
            {
                return;
            }
                cout << " " << node->value << " " << endl;
                cout << "/" << " " << "|" << endl;
                displayTree(node->left);
                displayTree(node->right);
        }
        /*
        void displayTree2(Node* node, int counter)
        {
            Node* current = node;
            //display root first
            cout << node->value << endl;
            Node* parent = current;
            while(1)
            {
                for(int i=0; i<counter; i++)
                {
                    displayTreePrimer(current);
                }
                counter*=2; //double counter
            }


        }

        void displayTreePrimer(Node* node)
        {
            cout << node->left->value << " " node->right-> value << " ";
        }*/

};

int main()
{
    BinaryTree Test;
    Test.insert(5);
    Test.insert(6);
    Test.insert(4);
    Test.insert(3);
    Test.displayTree(Test.getRoot());
    Test.deleteNode(5);
    Test.displayTree(Test.getRoot());
}
