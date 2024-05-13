
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// pre-order
void pre_order(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
    }
}
// In-order
void In_order(Node *root)
{
    if (root != NULL)
    {
        In_order(root->left);
        cout << root->data << " ";
        In_order(root->right);
    }
}
// Post-order
void Post_order(Node *root)
{
    if (root != NULL)
    {
        Post_order(root->left);
        Post_order(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 17);
    cout << " Pre-order ";
    pre_order(root);
    cout << endl;
    cout << " In-order ";
    In_order(root);
    cout << endl;
    cout << " Post-order ";
    Post_order(root);
    return 0;
}