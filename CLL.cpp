/*
 * FILE SUMMARY:
 * This code implements a Circular Singly Linked List (CLL).
 * Unlike a standard linked list, the last node in this list points back to the head, creating a circle.
 * It supports operations like adding/deleting from head/tail, searching, and circular traversal.
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
class CLL
{
public:
    Node *head;

    // Constructor: Initializes an empty list by setting head to NULL.
    CLL()
    {
        head = NULL;
    }

    // Destructor: Iterates through the circular list to delete all nodes and free memory.
    // It breaks the circle and deletes nodes one by one until the list is empty.
    ~CLL()
    {
        if (head == NULL)
            return;

        Node *curr = head->next;
        Node *temp = NULL;

        while (curr != head)
        {
            temp = curr;
            curr = curr->next;
            delete temp;
        }

        delete head;
        head = NULL;
    };

    // Creates a new node and inserts it at the beginning.
    // Since it's circular, it also traverses to the last node to update its 'next' pointer to the new head.
    void addtohead(int val)
    {
        Node *newnode = new Node();
        newnode->data = val;
        if (head == NULL)
        {
            head = newnode;
            head->next = head;
        }
        else
        {
            Node *curr = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    // Traverses the circular list using a do-while loop to print data values.
    // The loop ensures the head is printed first and stops when it circles back to the head.
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << nl;
            return;
        }
        else
        {
            Node *curr = head;
            do
            {

                cout << curr->data << sp;
                curr = curr->next;

            } while (curr != head);
        }
    };

    // Creates a new node and appends it to the end of the list.
    // It traverses to the current last node, links it to the new node, and points the new node back to head.
    void addtotail(int val)
    {
        Node *newnode = new Node;
        newnode->data = val;
        if (head == NULL)
        {
            head = newnode;
            head->next = head;
        }
        else
        {
            Node *curr = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = newnode;
            newnode->next = head;
        }
    }

    // Checks if the list is empty by verifying if the head pointer is NULL.
    bool isEmpty()
    {
        return head == NULL;
    }

    // Searches for a specific value in the list.
    // Returns the 0-based index if found, or -1 if the value is not present.
    int findnode(int val)
    {
        if (isEmpty())
        {
            return -1;
        }
        Node *curr = head;
        int idx = 0;
        if (curr->data == val)
        {
            return idx;
        }
        else
        {
            curr = curr->next;
            idx = 1;
            while (curr != head)
            {
                if (curr->data == val)
                {
                    return idx;
                }
                else
                {
                    curr = curr->next;
                    idx++;
                }
            }
        }
        return -1;
    }

    // Deletes the node at the head position.
    // If the list has multiple nodes, it finds the last node to update its 'next' pointer before deleting the head.
    void deletefromhead()
    {
        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return;
        }
        else if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *curr = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = head->next;
            delete head;
            head = curr->next;
        }
    }

    // Deletes the last node in the list.
    // It traverses to the second-to-last node and updates its 'next' pointer to point to the head, deleting the old tail.
    void deleteformtail()
    {
        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return;
        }
        else if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *curr = head;
            while (curr->next->next != head)
            {
                curr = curr->next;
            }
            delete curr->next;
            curr->next = head;
        }
    }

    // Deletes a node at a specific numeric position (0-based index).
    // It handles cases for head deletion and invalid positions.
    void deletenode(int pos)
    {
        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return;
        }
        else if (pos < 0)
        {
            cout << "Invalid position" << nl;
            return;
        }
        else if (pos == 0)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *curr = head;
            Node *prev = NULL;
            int idx = 0;
            while (curr->next != head && idx < pos)
            {
                prev = curr;
                curr = curr->next;
                idx++;
            }
            if (idx != pos)
            {
                cout << "Invalid position" << nl;
                return;
            }
            else
            {
                prev->next = curr->next;
                delete curr;
            }
        }
    }

    // Counts and returns the total number of nodes in the circular list.
    int count()
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            Node *curr = head;
            int count = 0;
            do
            {
                count++;
                curr = curr->next;

            } while (curr != head);

            return count;
        }
    }

    // Inserts a new value (newval) after the first occurrence of a specific value (val).
    // Note: There is a logic error in the original code's "not found" block (unreachable code after return), but the logic attempts to traverse, find the target, and relink pointers.
    void insertafter(int val, int newval)
    {

        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return;
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
                cout << "Value not found" << nl;
                return;

                Node *newnode = new Node;
                newnode->data = newval;

                if (curr->next == head)

                {
                    curr->next = newnode;
                    newnode->next = head;
                }

                else
                {
                    newnode->next = curr->next;
                    curr->next = newnode;
                }
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CLL cll;
    cll.addtohead(10);
    cll.addtotail(50);
    cll.addtotail(10);
    cll.addtotail(70);
    cll.display();
    cout << nl;
    int y = cll.findnode(70);
    cout << y << nl;
    int x = cll.count();
    cout << x << nl;

    return 0;
}