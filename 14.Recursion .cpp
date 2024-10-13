#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//  when a function call itself until a spevified
//  condition is met
// recursive function with no stoping condition
// void print()
// {
//     cout<<"1";
//     print();
// }

// recursion with specified conditon to stop
// int c = 1;

// void print1()
// {
//     if(c==5) {return;}
//     cout<<c;
//     c++;
//     print1();
// }

// problem: print the name n times without using the loops
void p(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << "akash" << " ";
    p(i + 1, n);
}

// prints i to n using recursion
// 1 2 3 4 5
void p1(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << i << " ";
    p1(i + 1, n);
}

// print n to 1 means if n=3 it print like 3 2 1
// printing in the reverse order
// 5 4 3 2 1 at n = 5
void p2(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    cout << i << " ";
    p2(i - 1, n);
}

// printing 1 to n using reverse technique
// 1 2 3 4 5
void p3(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    // function call
    p3(i - 1, n);

    cout << i << " ";
}

// print n to 1
void p4(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        p4(n - 1);
    }
}

// fibonacci series Nth number using recursion
// 0 1 1 2 3 5 8 13 21 34 55 89 144
int fib(int n)
{
    // base condition and stopping condition
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // recursive call also known as recurence relation
    return fib(n - 1) + fib(n - 2);
}

// getting the degit from the integer and print its name like 1 =  one
// 421 = four two one

void printDigit(int n, string arr[])
{
    // base case
    if (n == 0)
        return;

    // geting the number from the last of the integer
    int degit = n % 10;
    n = n / 10;

    // recursive call for the next degit
    printDigit(n, arr);

    // printing the degit name
    cout << arr[degit] << "  ";
}

// sort the array using recursion
void insert(vector<int> &v, int temp)
{
    // base condition when the array is empty or the last element is less than the temp
    if (v.empty() || v.back() <= temp)
    {
        v.push_back(temp);
        return;
    }

    int val = v.back();
    v.pop_back();

    insert(v, temp);

    v.push_back(val);
}

// removing all element form the vector
void sort(vector<int> &v)
{
    // base conditon when there only one element left since single element is itself sorted
    if (v.size() <= 1)
        return;

    // poiting the last element of the array
    int temp = v.back();
    // removing the last element
    v.pop_back();

    // recursive call for the rest of the array
    sort(v);
    // inserting the poped element in its correct position
    insert(v, temp);
}
// tc o(n^2) sc o(n) for the stack space used by the recursion

// sort a stack using recursion
void insert(stack<int> &s, int temp)
{
    // Base condition: stack is empty or top element is less than or equal to temp
    if (s.empty() || s.top() <= temp)
    {
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();

    // Recursive call to insert the element in the correct position
    insert(s, temp);

    s.push(val);
}

void sort(stack<int> &s)
{
    // Base condition: stack has only one element or is empty
    if (s.size() <= 1)
        return;

    // Pop the top element
    int temp = s.top();
    s.pop();

    // Recursive call to sort the remaining stack
    sort(s);

    // Insert the popped element back in sorted order
    insert(s, temp);
}

// Function to print the stack
void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// reverse a stack using recursion
void insertAtBottom(stack<int> &St, int element)
{
    if (St.empty())
    {
        St.push(element);
        return;
    }

    int cur_top_el = St.top();
    St.pop();
    insertAtBottom(St, element);
    St.push(cur_top_el);
}

void Reverse(stack<int> &St)
{
    if (St.empty())
    {
        return;
    }
    int top = St.top();
    St.pop();

    Reverse(St);
    insertAtBottom(St, top);
}


int main()
{

    // cout<<fib(12);
    //  string arr[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    //  int n ;
    //  cin>>n;

    // cout<<endl<<endl<<endl;
    // printDigit(n,arr);
    // cout<<endl<<endl<<endl;

    //    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    //     sort(v);

    //     for (int num : v)
    //     {
    //        cout << num << " ";
    //     }
    //     cout << endl;

    //! stack sorting
    stack<int> s;
    // Inserting elements into the stack
    s.push(3);
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(2);

    cout << "Original Stack: ";
    printStack(s); // Print original stack

    // Sorting the stack
    sort(s);

    cout << "Sorted Stack: ";
    printStack(s); // Print sorted stack

    return 0;
}
