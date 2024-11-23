#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

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

//* balance paranthesis using stack
bool balance_paranthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            char ch = st.top();
            st.pop();
            if (s[i] == ')' && ch != '(')
            {
                return false;
            }
            if (s[i] == '}' && ch != '{')
            {
                return false;
            }
            if (s[i] == ']' && ch != '[')
            {
                return false;
            }
        }
    }
    return st.empty();
}

//* min stack using stack
class min_stack
{
public:
    stack<pair<int, int>> s;
    void push(int val)
    {
        if (s.empty())
        {
            // for the first value
            s.push({val, val});
        }
        else
        {
            //
            int mn = min(val, s.top().second);
            s.push({val, mn});
        }
    }

    int getMin()
    {
        return s.top().second;
    }

    int top()
    {
        return s.top().first;
    }

    void pop()
    {
        s.pop();
    }
};

//! arthmatic expression evaluation
//* prefix infix postfix conversion

int precedence(char c)
{
    // lowest precedence
    if (c == '+' || c == '-')
    {
        return 1;
    }
    // medium precedence
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    // highest precedence
    else if (c == '^')
    {
        return 3;
    }
    // any other character
    return 0;
}

// infix to postfix conversion
string infix_to_postfix(string s)
{
    int i = 0;
    stack<char> st;
    string ans = ""; // Initialize as an empty string
    int n = s.size();

    while (i < n)
    {
        // if ith character is an operand
        if ((s[i] >= 'A' && s[i] <= 'Z') || // Uppercase
            (s[i] >= 'a' && s[i] <= 'z') || // Lowercase
            (s[i] >= '0' && s[i] <= '9'))   // Digits
        {
            ans += s[i]; // Append operand to result
        }
        // if ith character is '('
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        // if ith character is ')'
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
            {             // Check if stack is not empty before popping
                st.pop(); // pop '('
            }
        }
        // if ith character is an operator
        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]); // Push the current operator onto the stack
        }
        i++;
    }

    // pop all the operators left in the stack
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

// infix to prefix conversion
string infix_to_prefix(string s)
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }
    string ans = infix_to_postfix(s);
    reverse(ans.begin(), ans.end());
    return ans;
}

// prefix to infix conversion
string prefix_to_infix(string s)
{
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || // Uppercase
            (s[i] >= 'a' && s[i] <= 'z') || // Lowercase
            (s[i] >= '0' && s[i] <= '9'))   // Digits
        {
            st.push(string(1, s[i])); // Append operand to result
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("(" + op1 + s[i] + op2 + ")");
        }
    }
    return st.top();
}

// prefix to postfix conversion
string prefix_to_postfix(string s)
{
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || // Uppercase
            (s[i] >= 'a' && s[i] <= 'z') || // Lowercase
            (s[i] >= '0' && s[i] <= '9'))   // Digits
        {
            st.push(string(1, s[i])); // Append operand to result
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push(op1 + op2 + s[i]);
        }
    }
    return st.top();
}

// postfix to infix conversion
string postfix_to_infix(string s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || // Uppercase
            (s[i] >= 'a' && s[i] <= 'z') || // Lowercase
            (s[i] >= '0' && s[i] <= '9'))   // Digits
        {
            st.push(string(1, s[i])); // Append operand to result
        }
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            st.push("(" + op1 + s[i] + op2 + ")");
        }
    }
    return st.top();
}

// postfix to prefix conversion
string postfix_to_prefix(string s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || // Uppercase
            (s[i] >= 'a' && s[i] <= 'z') || // Lowercase
            (s[i] >= '0' && s[i] <= '9'))   // Digits
        {
            st.push(string(1, s[i])); // Append operand to result
        }
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            st.push(s[i] + op1 + op2);
        }
    }
    return st.top();
}

//* monotonic stack means stack in which all the elements are in increasing or decreasing order
//* Next Greater Element
// brtute force approach
vector<int> next_greater_element(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                ans[i] = nums[j];
                break;
            }
        }
    }
    return ans;
}

// optimal using stack approach
vector<int> next_greater_element_using_stack(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1); // Initialize answer vector with -1
    stack<int> st;          // Stack to store indices

    for (int i = 0; i < n; i++)
    {
        // While stack is not empty and current element is greater than the element
        // at the index stored at the top of the stack
        while (!st.empty() && nums[i] > nums[st.top()])
        {
            ans[st.top()] = nums[i]; // Update the answer for the index at the top of the stack
            st.pop();                // Pop the index after updating
        }

        st.push(i); // Push current index to the stack
    }

    return ans;
}

// using reverse loop approach
vector<int> next_greater_element_using_stack_using_revers_loop(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1); // Initialize answer vector with -1
    stack<int> st;          // Stack to store the next greater elements

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // Pop elements from the stack that are less than or equal to the current element
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }

        // If stack is not empty, the top of the stack is the next greater element
        if (!st.empty())
        {
            ans[i] = st.top();
        }

        // Push the current element to the stack
        st.push(nums[i]);
    }

    return ans;
}

// next greater element II (circular array)
// brute force approach
vector<int> find_next_greater(vector<int> num)
{
    vector<int> ans(num.size(), -1);
    int n = num.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < i + n; j++)
        {
            int index = j % n;
            if (num[index] > num[i])
            {
                ans[i] = num[index];
                break;
            }
        }
    }

    return ans;
}

// optimal approach
vector<int> find_next_greater_element(vector<int> num)
{
    vector<int> ans(num.size(), -1);
    stack<int> st;

    for (int i = 2 * num.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && num[i % num.size()] >= num[st.top()])
        {
            st.pop();
        }
        if (i < num.size())
        {
            if (!st.empty())
            {
                ans[i] = num[st.top()];
            }
        }
        st.push(i % num.size());
    }
    return ans;
}

// next smaller elment from the left side brute force approach
vector<int> next_smaller_element_brute_force(vector<int> &nums)
{
    int n = nums.size();
    // [4, 5, 2, 10, 8]
    //  0  1  2  3   4  i-1  0-1 = -1
    //
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
            {
                ans[i] = nums[j];
                break;
            }
        }
    }
    return ans;
}

// optimal approach using stack
vector<int> privious_small_elemenet(vector<int> &num)
{
    int n = num.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= num[i])
        {
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();

        st.push(num[i]);
    }
    return ans;
}

// online stock span
 

int main()
{
    //! creating the class object using that object we can access the class
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
    // Queue_implementation_using_linked_list q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    // cout << q.getFront() << endl;
    // q.pop();
    // cout << q.getFront() << endl;
    // cout << q.getSize() << endl;
    // q.pop();
    // q.pop();
    // cout << q.getFront() << endl;

    //! balance paranthesis using stack
    // string s = "{[()]}";
    // if (balance_paranthesis(s))
    // {
    //     cout << "Balanced" << endl;
    // }
    // else
    // {
    //     cout << "Not Balanced" << endl;
    // }

    //! min stack using stack
    // min_stack s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // cout << s.getMin() << endl;

    //! infix to postfix conversion
    // string s = "(p + q) * (m - n)";
    // cout << infix_to_postfix(s) << endl;

    //! infix to prefix conversion
    // string s1 = "*-A/BC-/AKL";
    // cout << infix_to_prefix(s1) << endl;

    //! prefix to infix conversion
    // string s2 = "*-A/BC-/AKL";
    // cout << prefix_to_infix(s2) << endl;

    //! prefix to postfix conversion
    // string s3 = "*-A/BC-/AKL";
    // cout << prefix_to_postfix(s3) << endl;

    //! postfix to infix conversion
    // string s4 = "ABC/-AK/L-*";
    // cout << postfix_to_infix(s4) << endl;

    //! postfix to prefix conversion
    // string s5 = "ABC/-AK/L-*";
    // cout << postfix_to_prefix(s5) << endl;

    //! Next Greater Element
    // vector<int> nums = {2, 1, 3 , 6, 5, 4 , 8};
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    // vector<int> ans = next_greater_element(nums);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    //! next greater element using reverse lopp
    // vector<int> ans1 = next_greater_element_using_stack_using_revers_loop(nums);
    // for (int i = 0; i < ans1.size(); i++)
    // {
    //     cout << ans1[i] << " ";
    // }
    // cout << endl;

    //! Next Greater Element using stack
    // vector<int> ans1 = next_greater_element_using_stack(nums);
    // for (int i = 0; i < ans1.size(); i++)
    // {
    //     cout << ans1[i] << " ";
    // }
    // cout << endl;

    //! Next Greater Element II (Circular Array)
    //! brute force approach
    // vector<int> nums1 = {1, 2, 1};
    // vector<int> ans2 = find_next_greater(nums1);
    // for (int i = 0; i < ans2.size(); i++)
    // {
    //     cout << ans2[i] << " ";
    // }
    // cout << endl;

    //! optimal approach
    // vector<int> nums1 = {1, 2, 1};
    // vector<int> ans2 = find_next_greater_element(nums1);
    // for (int i = 0; i < ans2.size(); i++)
    // {
    //     cout << ans2[i] << " ";
    // }
    // cout << endl;

    //! next smaller element from the left side brute force approach
    // vector<int> nums = {4, 5, 2, 10, 8};
    // vector<int> ans = next_smaller_element_brute_force(nums);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    //! optimal approach
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> ans = privious_small_elemenet(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    

    return 0;
}