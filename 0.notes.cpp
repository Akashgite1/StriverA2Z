#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print()
{
    int a, b;
    cin >> a >> b;

    //     //! Comparison Operators
    // < check left operand greter then the right operand
    //  a < b her its check whether a is greter then b or not
    bool ans = a < b;

    cout << ans << endl;

    bool c = a > b;

    cout << c;
}

void difference(int &nums, int num)

{
    // end plays role her with &nums its pass-by-reference
    // without end its pass by value or copy of it nums

    //-- pass by values and pass by refrence anolgy --

    // at pass by refrence we give actual value to the function
    // for modifiton and manuplation on it
    // &nums
    // 1.vector<int> &nums: This declares nums as a reference to a vector of integers. When you pass a vector to a function with this parameter type, you're passing a reference to the original vector. Any modifications made to nums inside the function will directly affect the original vector passed to the function. This approach is useful when you want to modify the original vector within the function without creating a copy.

    //  at pass by value we make a copy of it and give it to fucnct
    // for modification and updatation or manuplation on it
    //  num
    // 2.vector<int> nums: This declares nums as a vector of integers. When you pass a vector to a function with this parameter type, you're passing a copy of the original vector. Any modifications made to nums inside the function will not affect the original vector passed to the function. This approach is useful when you want to work with a copy of the vector without modifying the original.
}

void about_swap_function()
{
    // In the swap function, you don't need to use the address-of operator (&) because swap should take the values of the elements, not their addresses.

    // swap(num[i],num[n-1]); correct

    // swap(&num[i], &num[n-1]) wrong
}

void primenumebrs()
{
    // prime numbers are those numbers those numbers that compltely divide by
    // 1 and itself without getting any remainder behind
    // for exaple 5 is only divisible by (1,5) itself

    /*For example, some prime numbers are:
      2 (only divisible by 1 and 2)
      3 (only divisible by 1 and 3)
      5 (only divisible by 1 and 5)
      7 (only divisible by 1 and 7)
      11 (only divisible by 1 and 11)
      13 (only divisible by 1 and 13)
      */
}

// declaring the min and max and accourding usage
void min_max(int arr[], int n)
{
    int min = INT_MAX; // Initialize min to the maximum possible integer value
    int min_ele = -1;  // Initialize min_ele as -1 (a sentinel value)
                       // we can use 0 as well 

    int max = INT_MIN; // Initialize max to the minimum possible integer value
    int max_ele = -1;  // Initialize max_ele as -1 (a sentinel value)

    for (int i = 0; i < n; ++i)
    {                         // Iterating through the array
        int current = arr[i]; // Get the current element from the array

        if (current < min)
        {                  // Check if the current element is smaller than the current minimum
            min = current; // Update the minimum value
            min_ele = i;   // Update the index of the minimum value
            cout<<"min element :"<<min_ele<<endl;
        }

        if (current > max)
        {                  // Check if the current element is larger than the current maximum
            max = current; // Update the maximum value
            max_ele = i;   // Update the index of the maximum value
            cout<<"max element :"<<max_ele<<endl;
        }
    }

    //Now, let's go through the iterations with this array:

    //   Iteration 1:
    //   Current element: 5
    //   Since min is initialized to INT_MAX, 5 < INT_MAX, so min       becomes 5 and min_ele becomes 0.
    //   Since max is initialized to INT_MIN, 5 > INT_MIN, so max       becomes 5 and max_ele becomes 0.


    //   Iteration 2:
    //   Current element: 3
    //   3 < 5, so min remains 3 and min_ele remains 1.
    //   3 < 5, so max remains 5 and max_ele remains 0.


    //   Iteration 3:
    //   Current element: 8
    //   8 > 3, so min remains 3 and min_ele remains 1.
    //   8 > 5, so max becomes 8 and max_ele becomes 2.


    //   Iteration 4:
    //   Current element: 2
    //   2 < 3, so min becomes 2 and min_ele becomes 3.
    //   2 < 8, so max remains 8 and max_ele remains 2.


    //   Iteration 5:
    //   Current element: 10
    //   10 > 2, so min remains 2 and min_ele remains 3.
    //   10 > 8, so max becomes 10 and max_ele becomes 4.
    //   After the loop completes:

    //   min will hold the minimum value, which is 2.
    //   min_ele will hold the index of the minimum value, which is 3       (the position of the element 2 in the array).
    //   max will hold the maximum value, which is 10.
    //   max_ele will hold the index of the maximum value, which is 4       (the position of the element 10 in the array).


    //   So, even though min and max may seem counterintuitive given  their initializations, they correctly hold the minimum and  maximum values encountered during the iteration.
}

// swap function 
void swap(int a, int b)
{
    int temp =  a; // temp is temparary variable we assign a value to it 
     a =  b;    // a is empty and we assign the b value to a 
     b = temp;   // b is empty and we assign temp value to b 

     // suppose we have a = 10 and b = 15 
     // the temp is 0
     // at first we assign temp to a means temp is now 10
     // a is empty or containing the zero 
     // we assign the b value to a means a is now 15 
     // b is empty now 
     // we assign temp value to b which is 10 
     // so the temp is again empty and a = 15 and b = 10
}

int main()
{
    int arr[] = {5, 3, 8, 2, 10};
    int n = 5;
    min_max(arr,n);

    return 0;
}