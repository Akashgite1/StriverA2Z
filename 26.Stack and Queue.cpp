#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//*  Introduction to Stack and Queue
// Stack Implementation Using Array
// stack  operations
// 1. push() - insert the element in the stack
// 2. pop() - delete the element from the stack
// 3. top() - return the top element of the stack
// 4. empty() - check the stack is empty or not
// 5. size() - return the size of the stack

//* Queue Implementation Using Array
class stack_implementation_using_array
{
public:
    int topp = -1; // Top index of the stack
    int arr[100];  // Array to store stack elements

    // Push operation
    void push(int x)
    {
        if (topp >= 99) // Change 100 to 99 for valid index
            cout << "stack overflow" << endl;
        else
        {
            topp++;        // Move the top to the next element
            arr[topp] = x; // Store the x at top index
        }
        // O(1) time complexity
        // O(1) space complexity
    }

    // Function to get the top element
    void getTop()
    {
        if (topp == -1) // Check if stack is empty
            cout << "stack is empty" << endl;
        else
        {
            cout << arr[topp] << endl; // Print the top element
        }
        // O(1) time complexity
        // O(1) space complexity
    }

    // Pop operation
    void pop()
    {
        if (topp == -1) // Check if stack is empty
            cout << "stack is empty" << endl;
        else
        {
            topp--; // Move top index down
        }
        // O(1) time complexity
        // O(1) space complexity
    }

    // Function to get the size of the stack
    void getSize()
    {
        if (topp == -1) // Check if stack is empty
            cout << "stack is empty" << endl;
        else
        {
            cout << topp + 1 << endl; // Print the size of the stack
        }
        // O(1) time complexity
        // O(1) space complexity
    }
};

//* Queue Implementation Using Array
class Queue_implemented_using
{
public:
    int front = -1;     // Front index of the queue
    int rear = -1;      // Rear index of the queue
    int arr[100];       // Array to store queue elements
    int capacity = 100; // Capacity of the queue

    // Push operation
    void push(int x)
    {
        if (rear >= capacity - 1) // Change to capacity - 1 for valid index
            cout << "Queue is full" << endl;
        else
        {
            if (front == -1) // First element to be added
                front = 0;   // Update front to 0

            rear++;        // Move the rear index
            arr[rear] = x; // Store the element at rear index
        }
        // O(1) time complexity
        // O(1) space complexity
    }

    // Pop operation
    void pop()
    {
        if (front == -1) // Check if queue is empty
            cout << "Queue is empty" << endl;
        else
        {
            front++;          // Move front index
            if (front > rear) // Reset if queue becomes empty
            {
                front = rear = -1; // Reset front and rear
            }
        }
        // O(1) time complexity
        // O(1) space complexity
    }

    // Function to get the front element
    void getFront()
    {
        if (front == -1) // Check if queue is empty
            cout << "Queue is empty" << endl;
        else
        {
            cout << arr[front] << endl; // Print the front element
        }
        // O(1) time complexity
        // O(1) space complexity
    }

    // Function to get the size of the queue
    void getSize()
    {
        if (front == -1) // Check if queue is empty
            cout << "Queue is empty" << endl;
        else
        {
            cout << rear - front + 1 << endl; // Print the size of the queue
        }
        // O(1) time complexity
        // O(1) space complexity
    }
};

//* Stack Implementation Using Linked List
// linkded list implementation
class node
{
public:
    int data;
    node *next;

    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }

    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

//* Stack Implementation Using Linked List
class stack_implementation_using_linked_list
{
public:
    node *top = nullptr; // Pointer to the top node
    int size = 0;        // Size of the stack

    // Push operation
    void push(int x)
    {
        // Create a new node with data x
        node *temp = new node(x);
        // Link the new node to the current top
        temp->next = top;
        // Move the top to the new node
        top = temp;
        // Increase size
        size++;
    }

    // Pop operation
    void pop()
    {
        if (top == nullptr) // Check if stack is empty
        {
            cout << "Stack is empty" << endl;
            return;
        }
        // Create a temp node to store the top node
        node *temp = top;
        // Move the top to the next node
        top = top->next;
        // Delete the temp node
        delete temp;
        // Decrease size
        size--;
    }

    // Function to get the size of the stack
    int getSize()
    {
        return size;
    }

    // Function to get the top element
    int getTop()
    {
        if (top == nullptr) // Check if stack is empty
        {
            cout << "Stack is empty" << endl;
            return -1; // Return a sentinel value (or throw an exception)
        }
        return top->data; // Return the data of the top node
    }

    // For all the operations, time complexity is O(1)
    // O(1) time complexity
    // O(1) space complexity
};

//* Queue Implementation Using Linked List
class Queue_implementation_using_linked_list
{
public:
    node *front = nullptr; // Pointer to the front node
    node *rear = nullptr;  // Pointer to the rear node
    int size = 0;          // Size of the queue

    // Push operation
    void push(int x)
    {
        // Create a new node with data x
        node *temp = new node(x);
        // If front is null, move front and rear to new node
        if (front == nullptr)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            // Link the current rear to the new node
            rear->next = temp;
            // Move rear to the new node
            rear = temp;
        }
        // Increase size
        size++;
    }

    // Pop operation
    void pop()
    {
        if (front == nullptr) // Check if the queue is empty
        {
            cout << "Queue is empty" << endl;
            return;
        }
        // Create a temp node to store the front node
        node *temp = front;
        // Move front to the next node
        front = front->next;
        // Delete the temp node
        delete temp;
        // Decrease size
        size--;
    }

    // Function to get the size of the queue
    int getSize()
    {
        return size;
    }

    // Function to get the front element
    int getFront()
    {
        if (front == nullptr) // Check if the queue is empty
        {
            cout << "Queue is empty" << endl;
            return -1; // Return a sentinel value (or throw an exception)
        }
        return front->data; // Return the data of the front node
    }

    // For all the operations, time complexity is O(1)
    // O(1) time complexity
    // O(1) space complexity
};

//* implement stack using queue


int main()
{
    // creating the class object using that object we can access the class
    // functions or members function 
    // stack_implementation_using_array  is a class and s is the object 
    // now for accesing the class functions such as push(),pop(),getTop(),getSize()
    // we just have to use s front of the function name and boom we can access the function
    

    //! Stack Implementation Using Array
    // stack_implementation_using_array s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.getTop();
    // s.pop();
    // s.getTop();
    // s.getSize();
    // s.pop();
    // s.pop();
    // s.getTop();

    //! Queue Implementation Using Array
    // Queue_implemented_using q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    // q.getFront();
    // q.pop();
    // q.getFront();
    // q.getSize();
    // q.pop();
    // q.pop();
    // q.getFront();

    //! Stack Implementation Using Linked List
    // stack_implementation_using_linked_list s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // cout << s.getTop() << endl;
    // s.pop();
    // cout << s.getTop() << endl;
    // cout << s.getSize() << endl;
    // s.pop();
    // s.pop();
    // cout << s.getTop() << endl;

    //! Queue Implementation Using Linked List
    Queue_implementation_using_linked_list q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.getFront() << endl;
    q.pop();
    cout << q.getFront() << endl;
    cout << q.getSize() << endl;
    q.pop();
    q.pop();
    cout << q.getFront() << endl;



    return 0;
}
