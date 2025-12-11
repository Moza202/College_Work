/*
 * FILE SUMMARY:
 * This code implements a Circular Queue using a fixed-size array.
 * It uses 'front' and 'rear' indices with modulo arithmetic to efficiently utilize array space,
 * connecting the end of the array back to the beginning.
 */

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define Max_Size 100

class circularQueue
{
    int arr[Max_Size];
    int rear, front;

public:
    // Constructor: Initializes the queue with front and rear set to -1 (empty).
    circularQueue()
    {
        front = rear = -1;
    }

    // Enqueue operation to add an element to the rear.
    // Calculates the new rear position using modulo arithmetic. Handles full queue condition.
    void enqueue(int val)
    {
        if ((rear + 1) % Max_Size == front)
        {
            cout << "Queue is full" << endl;
            return;
        }

        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % Max_Size;
            arr[rear] = val;
        }
    }

    // Dequeue operation to remove an element from the front.
    // Advances the front index using modulo arithmetic. Resets queue if it becomes empty.
    int dequeue()
    {
        int val = arr[front];

        if (front == -1)
        {
            throw "Queue is empty";
        }

        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % Max_Size;
        }
        return val;
    }

    // Prints all elements currently in the queue.
    // Iterates from 'front' to 'rear' handling the circular wrap-around.
    void print()
    {
        int i;
        if (front == -1)
        {
            cout << "Queue is empty" << nl;
            return;
        }
        else
        {
            cout << "Queue elements are: " << nl;
            for (i = front; i != rear; i = (i + 1) % Max_Size)
            {
                cout << arr[i] << " ";
            }
            cout << arr[i] << nl;
        }
    }

    // Calculates the number of elements currently in the queue.
    int length()
    {
        int counter = 0;

        if (front == -1)
        {
            cout << "Queue is empty" << nl;
            return 0;
        }
        else
        {
            for (int i = front; i != rear; i = (i + 1) % Max_Size)
            {
                counter++;
            }
            counter++;
            return counter;
        }
    }

    // Returns the number of empty slots remaining in the queue.
    int availableSpace()
    {
        if (front == -1)
            return Max_Size;
        return Max_Size - length();
    }

    // Bulk enqueue operation.
    // Adds 'n' elements from an array into the queue, checking for available space first.
    void enqueueN(int elements[], int n)
    {
        if (n <= 0)
        {
            cout << "Error: N must be positive" << nl;
            return;
        }

        int avail = availableSpace();
        if (n > avail)
        {
            cout << "Error: Not enough space. Available: " << avail
                 << ", Requested: " << n << nl;
            cout << "Only adding " << avail << " elements" << nl;
            n = avail;
            if (n == 0)
                return;
        }

        for (int i = 0; i < n; i++)
        {

            enqueue(elements[i]);
        }
    }

    // Bulk dequeue operation.
    // Removes 'n' elements and returns them as a dynamically allocated array.
    int *dequeueN(int n)
    {
        if (front == -1)
        {
            cout << "Queue is empty, cannot dequeue" << nl;
            return nullptr;
        }

        int currsize = length();
        if (n > currsize)
        {
            cout << "Error: Only " << currsize << " elements available, requested " << n << nl;
            cout << "Returning all available elements" << nl;
            n = currsize;
        }

        int *result = new int[n];

        for (int i = 0; i < n; i++)
        {
            result[i] = arr[front];

            dequeue();
        }
        cout << nl;

        return result;
    }

    // Searches for a target value in the queue.
    // Returns the 1-based position of the element if found, or -1 if not found.
    int searchqueue(int target)
    {
        if (front == -1)
        {
            return -1; // Queue is empty
        }

        int pos = 1;
        int i = front;

        do
        {
            if (arr[i] == target)
            {
                return pos;
            }
            pos++;
            i = (i + 1) % Max_Size;
        } while (i != (rear + 1) % Max_Size);

        return -1;
    }
};

int main()
{
    circularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();
    cout << "Number of elements in queue: " << q.length() << nl;
    int idx = q.searchqueue(20);
    idx != -1 ? cout << "Element found at position: " << idx << nl : cout << "Element not found" << nl;
    int i = q.searchqueue(220);
    i != -1 ? cout << "Element found at position: " << i << nl : cout << "Element not found" << nl;
}