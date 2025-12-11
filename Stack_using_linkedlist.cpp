/*
 * FILE SUMMARY:
 * This code implements a Stack data structure using a singly linked list.
 * This approach allows for a dynamic stack size (limited only by memory) compared to a fixed-array implementation.
 * The 'head' of the linked list acts as the 'top' of the stack.
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
    Node *next;
};

class Stack
{
public:
    Node *head;

    // Constructor: Initializes the stack with the head (top) set to NULL.
    Stack()
    {
        head = NULL;
    }

    // Checks if the stack is empty (i.e., if head is NULL).
    bool isEmpty()
    {
        return head == NULL;
    }

    // Pushes a new value onto the stack.
    // It creates a new node and inserts it at the head of the list (making it the new top).
    void push(int val)
    {
        Node *top = new Node;
        top->data = val;

        top->next = head;
        head = top;
    }

    // Removes and returns the top element of the stack.
    // It deletes the head node and moves the head pointer to the next node. Throws error on underflow.
    int pop()
    {
        if (isEmpty())
        {
            throw "Stack underflow";
        }
        else
        {
            Node *curr = head;
            head = head->next;
            int val = curr->data;
            return val;
            delete curr;
        }
    }

    // Returns the value of the top element without removing it.
    int peek()
    {
        return head->data;
    }

    // Traverses the linked list from head (top) to end to print all elements in the stack.
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << nl;
            return;
        }

        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << sp;
            curr = curr->next;
        }
    }

    // Searches for a value in the stack.
    // Returns the 0-based index from the top if found, otherwise returns INT_MIN.
    int search(int val)
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << nl;
            return INT_MIN;
        }

        Node *curr = head;
        int idx = 0;
        while (curr != NULL)
        {
            if (curr->data == val)
            {

                return idx;
            }

            curr = curr->next;
            idx++;
        }
        return INT_MIN;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Stack s;
    try
    {
        s.pop();
    }
    catch (char const *e)
    {
        cout << e << nl;
    }
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    cout << nl;
    try
    {
        s.pop();
    }
    catch (char const *e)
    {
        cout << e << nl;
    }
    s.display();
    cout << nl;
    cout << s.peek() << nl;
    if (s.search(30) != INT_MIN)
    {
        cout << "Element " << 30
             << " found! Its 0-based index from the top is: "
             << s.search(30) << nl;
    }
    else
    {
        cout << "Element not found" << nl;
    }
    return 0;
}