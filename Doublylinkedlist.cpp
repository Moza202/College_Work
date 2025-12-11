/*
 * FILE SUMMARY:
 * This code implements a Doubly Linked List (DLL).
 * Each node contains data, a 'next' pointer, and a 'prev' pointer.
 * This structure allows for bidirectional traversal and more efficient deletion of nodes when a pointer to the node is known.
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
    Node *prev;
};
class DoublyLinkedList
{
public:
    Node *head;

    // Our default constructor: Initializes an empty list.
    DoublyLinkedList()
    {
        head = NULL;
    }

    // Our destructor: Frees memory by deleting all nodes in the list.
    ~DoublyLinkedList()
    {
        if (head->prev = NULL)
        {
            delete head;
            head = NULL;
        }
        else if (!isEmpty())
        {
            while (head != NULL)
            {
                delete head->prev;
                head = head->next;
            }
            delete head;
            head = NULL;
        }
        else
        {
            return;
        }
    }

    // Check if the list is empty by checking if head is NULL.
    bool isEmpty()
    {
        return head == NULL;
    }

    // Add a node to the head of the list.
    // Updates the new node's next to old head, and old head's prev to new node.
    void addtohead(int val)

    {
        Node *p = new Node;
        p->data = val;
        p->next = NULL;
        p->prev = NULL;
        if (isEmpty())
        {
            head = p;
        }
        else
        {
            p->next = head;
            head->prev = p;
            head = p;
        }
        // cout<<"done";
    }

    // Add a node to the tail of the list.
    // Traverses to the end, links the last node to the new node, and sets the new node's prev pointer.
    void addtotail(int val)
    {
        Node *p = new Node;
        p->data = val;
        p->next = NULL;
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        if (isEmpty())
        {
            head = p;
            p->prev = NULL;
        }
        else
        {
            curr->next = p;
            p->prev = curr;
        }
    }

    // Print the list: Traverses from head to end printing data values.
    void printlist()
    {
        if (isEmpty())
        {
            cout << "List is empty\n";
            return;
        }
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << sp;
            curr = curr->next;
        }
        cout << nl;
    }

    // Delete a node from the tail of the list.
    // Finds the last node, updates the second-to-last node's next pointer to NULL, and deletes the tail.
    void deletefromtail()
    {
        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->prev->next = NULL;
            delete curr;
        }
    }

    // Find a node with a specific value.
    // Returns the index of the value if found, otherwise returns -1.
    int findnode(int val)
    {
        Node *curr = head;
        int idx = 0;

        while (curr != NULL && curr->data != val)
        {
            curr = curr->next;
            idx++;
        }
        if (curr == NULL)
        {
            return -1;
        }
        else
        {
            return idx;
        }
    }

    // delete a node from head.
    // Updates the head pointer to the second node and sets its prev pointer to NULL.
    void deletefromhead()
    {
        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *curr = head;
            head = head->next;
            head->prev = NULL;
            delete curr;
        }
    }

    // delete any node from any position by value.
    // Searches for the value and re-links the prev and next pointers of adjacent nodes to bypass the deleted node.
    void deleteNode(int val)
    {
        if (isEmpty())
        {
            cout << "List is empty" << nl;
        }
        else if (head->data == val)
        {
            Node *curr = head;
            head = head->next;
            head->prev = NULL;
            delete curr;
        }
        else
        {
            Node *curr = head;
            while (curr != NULL && curr->data != val)
            {
                curr = curr->next;
            }
            if (curr == NULL)
            {
                cout << "Node not found" << nl;
                return;
            }
            else
            {
                curr->prev->next = curr->next;
                if (curr->next != NULL)
                {
                    curr->next->prev = curr->prev;
                }
            }
        }
    }

    // Reverse the doubly linked list.
    // Swaps the 'next' and 'prev' pointers for every node in the list and updates the head.
    void reverse()
    {
        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return;
        }
        Node *curr = head;
        Node *temp = NULL;
        while (curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp != NULL)
        {
            head = temp->prev;
        }
    }

    // Insert a node after a given node (identified by value 'data').
    // Finds the target node and inserts the new node, updating up to four pointers (prev/next of new and adjacent nodes).
    void insertAfter(int data, int val)
    {
        Node *curr = head;
        while (curr != NULL && curr->data != data)
        {
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "Node not found" << nl;
            return;
        }
        else
        {
            Node *p = new Node;
            p->data = val;
            if (curr->next == NULL)
            {
                curr->next = p;
                p->prev = curr;
                p->next = NULL;
                return;
            }
            else
            {
                p->next = curr->next;
                p->prev = curr;
                curr->next->prev = p;
                curr->next = p;
                return;
            }
        }
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    DoublyLinkedList dll;
    dll.addtohead(10);
    dll.addtohead(20);
    dll.printlist();
    dll.deletefromtail();
    // dll.printlist();
    // dll.deletefromtail();

    dll.isEmpty() ? cout << "List is empty" << nl : cout << "List is not empty" << nl;
    (dll.findnode(10)) == -1 ? cout << "Node not found" << nl : cout << "Node found at index " << dll.findnode(10) << nl;
    (dll.findnode(20)) == -1 ? cout << "Node not found" << nl : cout << "Node found at index " << dll.findnode(20) << nl;
    dll.addtotail(300);
    dll.addtohead(1000);
    dll.addtohead(500);
    dll.printlist();
    dll.deletefromhead();
    dll.printlist();
    dll.reverse();
    dll.printlist();
    dll.insertAfter(20, 250);
    dll.printlist();
    return 0;
}