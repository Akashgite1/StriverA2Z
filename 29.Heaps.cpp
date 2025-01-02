#include<bits/stdc++.h>
#include<iostream>

using namespace std;

//! Heaps also know as (priority queues) are a type of binary tree that satisfies the heap property. The heap property states that a parent node must be greater than or equal to its child node.

// heap implementation using arrays

class heap{

    public: 
    int arr[100];
    int size = 0;

    // constructor
    heap(){
        size = 0;
    }
    
    // function for inserton in heap
    void insert(int val){
        // increse the size of the heap
        size++;
        
        // insert the value at the last index
        // get the last index since size is always poiting the current empty index or the last index
        int index = size;
        // insert the value at the last index
        arr[index] = val;
    }

    

}

    // if the right child is greater than the root node
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    // if the largest is not the root node
    if (largest != i)
    {
        // swap the root node with the largest child
        swap(arr[i], arr[largest]);
        // call the heapify function recursively
        heapify(arr, n, largest);
    }
}

//! heapify function for min heap
void heapify_min(int arr[], int n, int i)
{

    // following the 1 based indexing
    int smallest = i;      // root node
    int left = 2 * i + 1;      // point left child
    int right = 2 * i + 2; // point right child

    // if the left child is smaller than the root node
    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }

    // if the right child is smaller than the root node
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    // if the smallest is not the root node
    if (smallest != i)
    {
        // swap the root node with the smallest child
        swap(arr[i], arr[smallest]);
        // call the heapify function recursively
        heapify_min(arr, n, smallest);
    }
}

//! check if the arr if min heap or not
bool isMaxHeap(int arr[], int n)
{
    // Your code goes here
    // Traverse all non-leaf nodes
    for (int i = 0; i <= (n / 2) - 1; i++)
    {
        // follow the 1 based indexing 
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check the left child
        if (left < n && arr[i] < arr[left])
        {
            return false;
        }

        // Check the right child
        if (right < n && arr[i] < arr[right])
        {
            return false;
        }
    }
    return true;
}



int main()
{
    //! heap implementation using arrays and its operations insert and delete
    // making the object of the heap class
    // MAX_heap h;
    // // calling the function insert using the object we just created
    // h.insert(60); // at index 1
    // h.insert(50); // at index 2
    // h.insert(40); // at index 3
    // h.insert(30); // at index 4
    // h.insert(20); // at index 5
    // h.print();    // 40 20 30 10
    // // deleting the root node
    // h.delete_From_Heap();
    // h.print(); // 30 20 10
    // h.insert(70);
    // h.print(); // 70 30 10 20

    //! heapify function converting any normal array to heap
    int arr[] = { 20, 15, 40, 50, 100, 25, 45};
    int n = 7;
    //! checking only the root node becuse using the formula 2*i + 1 and 2*i + 2 we can check root corresponding left and right child nodes 
    for (int i = n / 2; i >= 1; i--)
    {
        heapify_min(arr, n, i);
    }
    // printing the heapified array 
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

    // check if the array is max heap or not
    // int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
    // int n = 8;
    // cout << isMaxHeap(arr, n);


    return 0;
}