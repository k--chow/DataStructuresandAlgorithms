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
#include <queue>
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

        //This method inOrder() traverses a tree in ascending order
        void inOrder(Node* node)
        {
            if (node != NULL)
            {
                inOrder(node->left);
                cout << node->value << endl;
                inOrder(node->right);
            }

        }

        //This method traverses a tree in Preorder.
        void preOrder(Node* node)
        {
            if (node != NULL)
            {
                cout << node ->value << endl;
                preOrder(node->left);
                preOrder(node->right);
            }
        }
        //This method traverses a tree in Postorder.
        void postOrder(Node* node)
        {
            if (node != NULL)
            {
                postOrder(node->left);
                postOrder(node->right);
                cout << node->value << endl;
            }
        }


        void displayTree(Node* node)
        {
            queue<Node*> q;
            q.push(node);
            while(!q.empty())
            {
                node = q.front();
                cout << node->value << " ";
                q.pop();
                //queue up neighbors/children
                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }


            }
        }

        void minimumValue()
        {
            Node* current = root;
            while (current->left != NULL)
            {
                current = current->left;
            }
            cout << "The minimum value in this tree is: " << current->value << endl;
        }

        void maximumValue()
        {
            Node* current = root;
            while (current->right != NULL)
            {
                current = current->right;
            }
            cout << "The maximum value in this tree is: " << current->value << endl;
        }



};

int main()
{
    BinaryTree Test;
    Test.insert(5);
    Test.insert(6);
    Test.insert(4);
    Test.insert(3);
    Test.displayTree(Test.getRoot());
    /*
    Test.inOrder(Test.getRoot());
    Test.preOrder(Test.getRoot());
    Test.postOrder(Test.getRoot());
    Test.minimumValue();
    Test.maximumValue();*/
}
