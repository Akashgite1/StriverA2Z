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

int main (){
    
    return 0;
}