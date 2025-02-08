#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//! binary tree structure 
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//! Recursion is the process in which a function calls itself unit a base condition is reached.
//~ a base condition is a condition where the recursion stops.
//~ recursion means repeating the same thing again and again.

//! print 1 to n using recursion 
//? Yes, for a void function, it does not return anything, and the base case just stops execution.
void print(int n){
 
    // base condition where the recursion stops 
    // stop condition 
    // if we print n inside the base case it will print our last recursion
    // condition in which we have to stop 
    if(n== 0) return ;
     
    // elements will be printed in decreasing order 5 4 3 2 1 
    // first element will be printed
    cout<<n << " ";
    // recursive call 
    
    // element printed in incresing order 1 2 3 4 5 
    // after the recursive call element will be printed 
    print(n-1);
    // printitng the current n number 

}

//! for an int function, the base case must return a value, which can then be used in recursive calls.
int print1toN(int n){
    //? when base case hit it will return base case base case will print at new line 
    if(n == 0) return 0;  // Base case returns 0
   
    //? call the recursive function and the print the current condition recursive call 
    return print1toN(n - 1);  // Recursive call returns something
    // print 5 and return for 5-1 = 4 print : 5
    // print 4 and return for 4-1 = 3 print : 5 4
    // print 3 and return for 3-1 = 2 print : 5 4 3
    // print 2 and return for 2-1 = 1 print : 5 4 3 2
    // print 1 and return for 1-1 = 0 print : 5 4 3 2 1
    // print 0 and return for 0-1 = -1 print : 5 4 3 2 1 0
    cout<<n << " ";  // Print the current number
}

//! factorial using recursion 
int fact(int n){
    // base case 
    if(n == 0 || n == 1) return 1;
    
    // recursive call 
    return n * fact(n-1);
}

//! height of binary tree using recursion 
int height(Node* root){
    // base case 
    if(root == NULL) return 0;
    
    // left height recursive call goes upto the leaf node 
    int leftHeight = height(root->left);
    // right height recursive call goes upto the leaf node 
    int rightHeight = height(root->right);
    
    // return the max in between left and right height 
    return max(leftHeight, rightHeight) + 1; 
}  

//! sort an array using recursion and insert element using loop
void sort(int arr[], int n){
    // base case 
    if(n == 1) return;
    
    // hypothesis 
    sort(arr, n-1);
    
    // induction 
    int lastElement = arr[n-1];
    int j = n-2;
    
    while(j >= 0 && arr[j] > lastElement){
        // shifting the elements
        arr[j+1] = arr[j];
        j--;
    }
    // last element will be inserted at the correct position
    arr[j+1] = lastElement;
}

//! both insert element and sort array using recursion
void insert(vector<int> &arr, int temp) {
    if (arr.empty() || arr.back() <= temp) {
        arr.push_back(temp);
        return;
    }
    
    // recursion happend for removing the last element of array 
    // it will run unitl the base case hit 
    int last = arr.back();
    arr.pop_back();   // Remove last element
    insert(arr, temp); // Recursive call to insert temp in the reduced array
    // this will only run when the base case hit 
    arr.push_back(last); // Push back the removed element
}

void sortArray(vector<int> &arr) {
    if (arr.size() <= 1) return; // Base case
    
    int temp = arr.back();
    arr.pop_back(); // Remove last element
    sortArray(arr); // Recursively sort remaining array
    insert(arr, temp); // Insert the removed element in sorted order
}

//! sort stack using recursion
//
void insertElement(stack<int> &st, int top)
{
    if (st.empty() || st.top() <= top)
    {
        st.push(top);
        return;
    }
    int temp = st.top();
    st.pop();
    insertElement(st, top);
    st.push(temp);
}
// remove the element from stck until the last element left
//  since the last element is itself smallest element largest element and sorted
//  since its a single element
void sortStack(stack<int> &st)
{
    if (st.empty())
        return;
    int top = st.top();
    st.pop();
    sortStack(st);
    insertElement(st, top);
} //^ tc : O(n^2) sc : O(n)

int main(){
   //!--------------------->  recursion  <---------------------

    //? print 1 to n using recursion 
    // print(5);
    // cout << endl;
    // cout << print1toN(5) << endl;

    //? factorial using recursion
    // cout << fact(5) << endl; // 120
    // cout << fact(0) << endl; // 1 
    // cout << fact(1) << endl; // 1
    // cout << fact(2) << endl; // 2

    //? height of binary tree using recursion
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // cout << height(root) << endl; // 3

    //? sort an array using recursion and insert element using loop
    // int arr[] = {5, 4, 3, 2, 1};
    // sort(arr, 5);
    // for(int i = 0; i < 5; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //? both insert element and sort array using recursion
    // vector<int> arr = {5, 4, 3, 2, 1};
    // for (int i = 0; i < arr.size(); i++){
    //     cout << arr[i] << " ";
    // }cout << endl;
    // sortArray(arr);
    // for(int i = 0; i < 5; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    
    //? sort stack using recursion
    // stack<int> st;
    // st.push(5);
    // st.push(4);
    // st.push(3);
    // st.push(2);
    // st.push(1);
    // sortStack(st);
    // while(!st.empty()){
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;



    return 0;
 
}