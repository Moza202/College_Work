/*
 * FILE SUMMARY:
 * This code implements a Binary Search Tree (BST).
 * It supports standard BST operations such as insertion, deletion, and searching.
 * It also includes traversal methods (Inorder, Preorder, Postorder) and utility functions to calculate size and depth.
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define vi vector<int>
#define sp " "
#define all(x) (x).begin(), (x).end()

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int item)
    {
        data = item;
        left = right = nullptr;
    }
};

class Tree
{
public:
    Node *root;
    Tree() { root = nullptr; }

private:
    // Helper function for recursion insertion.
    // Places data in the left subtree if smaller than root, or right subtree if larger.
    Node *insertp(Node *root, int data)
    {
        // if the tree is empty
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        { // if the tree is not empty and the data member is less than the root data member
            if (data < root->data)
            {
                root->left = insertp(root->left, data);
            }
            // if the tree is not empty and the data member is greater than the root data member
            else
            {
                root->right = insertp(root->right, data);
            }
            // update the root pointer and return it
            return root;
        }
    }

    // Recursively calculates the number of nodes in the tree.
    int sizep(Node *node)
    {
        if (node == NULL)
            return 0;
        else
            return sizep(node->left) + 1 + sizep(node->right);
    }

    // Helper for Inorder traversal (Left, Root, Right).
    void inorderp(Node *node)
    {
        if (node == NULL)
            return;
        inorderp(node->left);
        cout << node->data << sp;
        inorderp(node->right);
    }

    // Helper for Preorder traversal (Root, Left, Right).
    void preorderp(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->data << sp;
        preorderp(node->left);
        preorderp(node->right);
    }

    // Helper for Postorder traversal (Left, Right, Root).
    void postorderp(Node *node)
    {
        if (node == NULL)
            return;
        postorderp(node->left);
        postorderp(node->right);
        cout << node->data << sp;
    }

    // Finds the node with the minimum value (leftmost node).
    Node *minp(Node *node)
    {
        if (node == NULL)
            return NULL;
        else if (node->left == NULL)
            return node;
        else
            return minp(node->left);
    }

    // Finds the node with the maximum value (rightmost node).
    Node *maxp(Node *node)
    {
        if (node == NULL)
            return NULL;
        else if (node->right == NULL)
            return node;
        else
            return maxp(node->right);
    }

    // Recursively calculates the maximum depth (height) of the tree.
    // we need to find the max depth of the tree
    int maxDepthp(Node *node)
    {
        if (node == NULL)
            return 0;
        else
        {

            int ldepth = maxDepthp(node->left);
            int rdepth = maxDepthp(node->right);

            return max(ldepth, rdepth) + 1;
        }
    }

    // Helper for recursive deletion.
    // Handles three cases: leaf node, one child, or two children (uses successor for replacement).
    Node *deletep(Node *root, int data)
    {
        if (root == NULL)
            return root;
        if (data < root->data)
            root->left = deletep(root->left, data);
        else if (data > root->data)
            root->right = deletep(root->right, data);
        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = minp(root->right);
            root->data = temp->data;
            root->right = deletep(root->right, temp->data);
        }
        return root;
    }

    // Helper to recursively search for a value in the tree.
    Node *searchp(Node *node, int data)
    {
        if (node == NULL || node->data == data)
            return node;
        if (data < node->data)
            return searchp(node->left, data);
        else
            return searchp(node->right, data);
    }

    // Helper to recursively free memory for all nodes (used by destructor).
    void freep(Node *node)
    {
        if (node == NULL)
            return;
        freep(node->left);
        freep(node->right);
        delete node;
    }

public:
    // insert a new node in the tree.
    // Calls the private recursive insert function.
    void insert(int data)
    {
        root = insertp(root, data);
    }

    // calculate the size of the tree.
    // Calls the private recursive size function.
    int size()
    {
        return sizep(root);
    }

    // inorder traversal of the tree.
    // Public interface for inorder traversal.
    void inorder()
    {
        inorderp(root);
    }

    // preorder traversal of the tree.
    // Public interface for preorder traversal.
    void preorder()
    {
        preorderp(root);
    }

    // postorder traversal of the tree.
    // Public interface for postorder traversal.
    void postorder()
    {
        postorderp(root);
    }

    // we need to find the minimum value node in the tree.
    // Public interface to find minimum value.
    Node *min_member()
    {
        return minp(root);
    }

    // we need to find the maximum value node in the tree.
    // Public interface to find maximum value.
    Node *max_member()
    {
        return maxp(root);
    }

    // Public interface to get tree height.
    int maxDepth()
    {
        return maxDepthp(root);
    }

    // Public interface to delete a node by value.
    void delete_node(int data)
    {
        root = deletep(root, data);
    }

    // Public interface to search for a value.
    Node *search(int data)
    {
        return searchp(root, data);
    }

    // Destructor: Cleans up memory.
    ~Tree()
    {
        freep(root);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Tree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    cout << "Inorder traversal: ";
    tree.inorder();
    cout << nl;
    cout << "Preorder traversal: ";
    tree.preorder();
    cout << nl;
    cout << "Postorder traversal: ";
    tree.postorder();
    cout << nl;
    cout << "Size of the tree: " << tree.size() << nl;
    cout << "Maximum depth of the tree: " << tree.maxDepth() << nl;
    Node *minNode = tree.min_member();
    if (minNode)
        cout << "Minimum value node: " << minNode->data << nl;
    Node *maxNode = tree.max_member();
    if (maxNode)
        cout << "Maximum value node: " << maxNode->data << nl;
    int key = 40;
    Node *searchNode = tree.search(key);
    if (searchNode)
        cout << "Node with key " << key << " found." << nl;
    else
        cout << "Node with key " << key << " not found." << nl;
    tree.delete_node(20);
    cout << "Inorder traversal after deletion: ";
    tree.inorder();
    cout << nl;

    return 0;
}