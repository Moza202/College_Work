/*
 * FILE SUMMARY:
 * This code provides a comprehensive implementation of a Singly Linked List.
 * It includes basic operations (add/delete head/tail) and advanced utility functions like finding min/max values,
 * copying lists, deleting at specific positions, and updating node values.
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

class LinkedList
{
public:
    Node *head;

    // Constructor: Initializes an empty linked list.
    LinkedList()
    {
        head = NULL;
    };

    // Print the entire list.
    // Iterates through the list nodes and prints their data fields.
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
    };

    // Add a new node at the head of the list.
    // Creates a new node and points it to the current head, updating head to the new node.
    void addTohead(int Value)
    {
        Node *p = new Node;
        p->data = Value;
        p->next = head;
        head = p;
    };

    // Add a new node at the tail of the list.
    // Traverses to the end of the list to attach the new node.
    void addToTail(int value)
    {
        Node *p = new Node;
        p->data = value;
        p->next = NULL;

        if (isEmpty())
        {
            head = p;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = p;
        }
    };

    // Delete a node from the head of the list.
    // Removes the first node and moves the head pointer to the second node.
    void deleteFromHead()
    {
        if (isEmpty())
        {
            // cout << "can't delete from head-> list is empty" << endl;
            return;
        }
        else
        {
            Node *curr = head;
            head = head->next;
            delete curr;
        }
    }

    // Delete a node from the tail of the list.
    // Finds the second-to-last node and sets its 'next' pointer to NULL, deleting the last node.
    void deleteFromTail()
    {
        if (isEmpty())
        { // (case 1 - List is empty)
            // cout << "can't delete from tail-> list is empty" << endl;
            return;
        }
        else if (head->next == NULL)
        { // (case 2 - List is only one node)
            delete head;
            head = NULL;
        }
        else
        { // (case 3 - List is more than one node)
            /// (Method 1) - Using 2 Pointers
            Node *curr = head;
            Node *prev = NULL;
            while (curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            delete curr;
            prev->next = NULL;

            /// (Method 2) - Using 1 Pointer
            /*Node* curr = head;
            while(curr->next->next != NULL){
                curr = curr->next;
            }
            delete curr->next;
            curr->next = NULL;*/
        }
    };

    // Copy the current list to another list.
    // Iterates through the current list and adds each element to the tail of the destination list 'x'.
    void copyList(LinkedList &x)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            x.addToTail(curr->data);
            curr = curr->next;
        }
        cout << "list2 in function copy()\n";
        x.printlist();
    }

    // Check if the list is empty by verifying if head is NULL.
    bool isEmpty()
    {
        return head == NULL;
    }

    // Destructor to free memory.
    // Iterates through the entire list and deletes every node to prevent memory leaks.
    ~LinkedList()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    };

    // Function to count the number of nodes in the list.
    // Traverses the list incrementing a counter.
    int getCount()
    {
        if (isEmpty())
        {
            cout << "List is empty\n";
            return -1;
        }

        int count = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        return count;
    }

    // Function to find the minimum value in the list.
    // Iterates through the list comparing node values to find the smallest one.
    int getmin()
    {
        int idx = 0;
        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return INT_MAX;
        }

        int mini = head->data;
        Node *curr = head->next;

        while (curr != NULL)
        {
            if (curr->data < mini)
                mini = curr->data;
            curr = curr->next;
            idx++;
        }

        return mini;
    }

    // Function to find the maximum value in the list.
    // Iterates through the list comparing node values to find the largest one.
    int getmax()
    {
        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return INT_MIN;
            ;
        }

        int maxi = head->data;
        Node *curr = head->next;

        while (curr != NULL)
        {
            if (curr->data > maxi)
                maxi = curr->data;
            curr = curr->next;
        }

        return maxi;
    }

    // Function to search for a value in the list.
    // Returns the 0-based index of the value if found, or -1 otherwise.
    int findNode(int Val)
    {
        if (isEmpty())
            return -1;

        Node *curr = head;
        int idx = 0;
        while (curr != NULL)
        {
            if (curr->data == Val)
                return idx;
            curr = curr->next;
            idx++;
        }
        return -1;
    }

    // Function to delete a node at a specific position.
    // Traverses to the specified index and removes the node, linking the previous node to the next.
    void Deleteat(int position)
    {
        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return;
        }
        else if (position < 0)
        {
            cout << "Invalid position" << nl;
            return;
        }
        else if (position == 0)
        {
            deleteFromHead();
            cout << "Node at position 0 deleted." << nl;
            return;
        }
        else
        {
            Node *curr = head;
            Node *prev = NULL;
            int idx = 0;
            while (curr != NULL && idx < position)
            {
                prev = curr;
                curr = curr->next;
                idx++;
            }
            if (curr == NULL)
            {
                cout << "Position out of bounds" << nl;
                return;
            }
            prev->next = curr->next;
            delete curr;
            cout << "Node at position " << position << " deleted." << nl;
        }
    }

    // This function deletes the node after a node with a specific value.
    // Finds the node with 'value' and deletes the immediate next node.
    void deleteafter(int value)
    {
        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return;
        }
        else if (head->data == value)
        {
            cout << "No node exists after the given value" << nl;
            return;
        }
        else
        {
            Node *curr = head;
            while (curr != NULL && curr->data != value)
            {
                curr = curr->next;
            }
            if (curr == NULL || curr->next == NULL)
            {
                cout << "No node exists after the given value" << nl;
                return;
            }
            else
            {
                Node *temp = curr->next;
                curr->next = temp->next;
                delete temp;
                cout << "Node after value " << value << " deleted." << nl;
            }
        }
    }

    // This function adds a new node with 'data' before the first occurrence of 'value'.
    // Keeps track of the previous node to insert the new node in between.
    void addbefore(int value, int data)
    {
        if (isEmpty())
        {
            cout << "List is empty" << nl;
            return;
        }
        else if (head->data == value)
        {
            addTohead(data);
            cout << "Node with value " << data << " added before " << value << nl;
            return;
        }
        else
        {
            Node *curr = head;
            Node *prev = NULL;
            while (curr->next != NULL && curr->data != value)
            {
                prev = curr;
                curr = curr->next;
            }
            if (curr == NULL)
            {
                cout << "Value " << value << "not found in the list ." << nl;
                return;
            }
            else
            {
                Node *newnode = new Node;
                newnode->data = data;
                newnode->next = curr;
                prev->next = newnode;
                cout << "Node with value " << data << " added before " << value << nl;
                return;
            }
        }
    }

    // This function updates the value of a node at a specific position.
    // Traverses to the node at the given index and modifies its data.
    void updatenode(int position, int newvalue)
    {
        if (isEmpty())
        {
            cout << "List is empty ." << nl;
            return;
        }
        else if (position < 0 || position >= getCount())
        {
            cout << "You have entered a position out of your list bounds." << nl;
            return;
        }
        else
        {
            Node *curr = head;
            int idx = 0;
            while (curr != NULL && idx < position) // 1 idx = 0
            {
                curr = curr->next;
                idx++;
            }
            if (curr != NULL)
            {
                curr->data = newvalue;
                cout << "Node at position " << position << " updated to " << newvalue << nl;
            }
            else
            {
                cout << "Position not found in the list." << nl;
            }
        }
    }

    // this function insert new node after specific value in  the linked list.
    // Finds the node containing 'value' and inserts a new node immediately after it.
    void insertafter(int value, int newvalue)
    {
        if (isEmpty())
        {
            cout << "List is empty ." << nl;
            return;
        }
        else if (head->data == value && head->next == NULL)
        {
            addToTail(newvalue);
            cout << "Node inserted at the tail as the only node after head." << nl;
            return;
        }
        else
        {
            Node *curr = head;

            while (curr != NULL && curr->data != value)
            {

                curr = curr->next;
            }
            if (curr != NULL)
            {
                Node *newnode = new Node;
                newnode->data = newvalue;
                newnode->next = curr->next;
                curr->next = newnode;

                cout << "Node with value " << newvalue << " inserted after " << value << nl;
            }
            else
            {
                cout << "Value " << value << " not found in the list ." << nl;
            }
        }
    };

    // This function deletes the first occurrence of a node with a specific value.
    // Finds the target node and removes it from the chain.
    void deleteval(int value)
    {
        // If list is empty
        if (isEmpty())
        {
            cout << "List is empty. Cannot delete." << nl;
            return;
        }

        // If the node to delete is the head
        if (head->data == value)
        {
            deleteFromHead();
            cout << "Value " << value << " deleted from head." << nl;
            return;
        }

        // Find the node before the one to delete
        Node *curr = head;
        while (curr->next != NULL && curr->next->data != value)
        {
            curr = curr->next;
        }

        // If value found
        if (curr->next != NULL && curr->next->data == value)
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
            cout << "Value " << value << " deleted." << nl;
        }
        else
        {
            cout << "Value " << value << " not found in the list." << nl;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LinkedList list1;
    LinkedList list2;
    list2.addTohead(5);

    list1.addTohead(5);
    list1.addTohead(10);
    list1.addTohead(15);
    list1.addTohead(1);
    list1.addTohead(2);
    list1.addTohead(3);
    list1.addTohead(4);
    list1.addTohead(12);
    list1.addTohead(6);
    list1.addTohead(7);
    list1.addTohead(8);
    list1.addTohead(100);

    list1.printlist();
    // cout << "Number of the elements in the list is : " << list1.getCount() << nl;
    // cout << "The minimum element in the list is : " << list1.getmin() << nl;
    // cout << "The maximum element in the list is : " << list1.getmax() << nl;

    if (list1.findNode(5) != -1)
        cout << "Value found at index: " << list1.findNode(5) << nl;
    else
    {
        cout << "Value not found in the list" << nl;
    }
    if (list1.findNode(100) != -1)
        cout << "Value found at index: " << list1.findNode(100) << nl;
    else
    {
        cout << "Value not found in the list" << nl;
    }
    // list1.Deleteat(3);
    // list1.Deleteat(0);
    // list1.Deleteat(12);
    // list1.Deleteat(-1);
    // list1.deleteafter(5);
    // list1.printlist();
    // list1.addbefore(10, 99);
    // list1.printlist();
    // list1.updatenode(4, 100);
    // list1.printlist();
    // list1.deleteafter(5);
    // list1.printlist();
    // list2.insertafter(5, 50);
    // list2.printlist();
    // list2.insertafter(8, 60);
    // list2.deleteval(5);
    //  list2.printlist();
    list1.updatenode(0, 500);
    list1.printlist();

    return 0;
}