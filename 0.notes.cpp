//! libaray required for the copetitive programming
#include <bits/stdc++.h> // for most of the stl libraries
#include <iostream> // for input and output stream
#include <vector> // for vector
#include <algorithm> // for sort and other algorithm
#include <string> // for string
#include <unordered_map> // for unordered map
#include <map> // for map
#include <set> // for set
#include <unordered_set> // for unordered set
#include <queue> // for queue
#include <stack> // for stack
#include <list> // for list
#include <deque> // for deque
#include <forward_list> // for forward list
#include <array> // for array
#include <numeric> // for numeric
#include <utility> // for pair and other utility functions
#include <iterator> // for iterator
#include <functional> // for functional
#include <memory> // for memory
#include <typeinfo> // for type info
#include <type_traits> // for type traits
#include <bitset> // for bitset
#include <tuple> // for tuple
#include <optional> // for optional
#include <variant> // for variant
#include <any> // for any means any type of data
#include <complex> // for complex number
#include <valarray> // for valarray
#include <chrono> // for chrono
#include <random> // for random
#include <cstddef> // for cstddef
#include <cstdlib> // for cstdlib
#include <cctype> // for cctype
#include <cstring> // for cstring
#include <cstdio> // for cstdio
#include <cstdarg> // for cstdarg
#include <cmath> // for cmath
#include <ctime> // for ctime
#include <climits> // for climits
#include <cfloat> // for cfloat
#include <cstdint> // for cstdint
#include <cinttypes> // for cinttypes
#include <limits> // for limits


using namespace std;



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

//! declaring the min and max and accourding usage
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

//! swap function 
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

//! comparator function vs lambada function
// comparator function
bool compare(int a, int b)
{
    return a < b; // if a is less then b then return true
}  

// lambada function
auto comparee = [](int a, int b) { return a < b; }; // it takes two arguments and return the boolean value true or falseWe can use a lambda function to define a custom comparison function for sorting. A lambda function is an anonymous function that can be used as a function object. It is defined using the syntax [capture list] (parameters) { function body }. In this case, the lambda function takes two integers a and b as parameters and returns true if a is less than b, and false otherwise. This lambda function can be used as a custom comparison function in the sort function to sort a vector of integers in ascending order.

//! prime numbers and sieve of eratosthenes algorithm
// use for finding the prime number upto 2 to n 
// 0 1 are not prime number
// prime number are those number which are only divisible by 1 and itself 
// for example 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
// basic algorithm 
// for checking if the number is prime or not 
// you just need to run a loop from 2 to n is the number itself 
// check if you find any other number is divisible by the num if you find then you return false
//^ since the rule is simple prime number are only divisible by 1 and itself 
//! begineer approach time complexity : O(n) sc : O(1) 
// not suitable for large number like 10^6 or 10^7 
bool isprime(int n){
    if(n == 0 || n == 1){
        return false;
    }
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

// using sqrt for checking the prime numbers 
// we can use the sqrt for checking the prime number 
// for example 36 is the number
// the sqrt of 36 is 6




int main()
{
    //? prime numbers
    // primenumebrs();

    //? min and max
    // int arr[] = {5, 3, 8, 2, 10};
    // min_max(arr, 5);

    //? swap function
    // int a = 10, b = 15;
    // swap(a, b);
    // cout << a << " " << b << endl;

    //? comparator function vs lambada function
    // vector<int> v = {5, 3, 8, 2, 10};
    // sort(v.begin(), v.end(), compare);
    // for (int i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // vector<int> v = {5, 3, 8, 2, 10};
    // sort(v.begin(), v.end(), comparee);
    // for (int i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    //? sieve of eratosthenes
    // for(int i = 0; i <= 100; i++){
    //     if(isprime(i)){
    //         cout << i << " ";
    //     }
    // }
    // cout << endl;



    return 0;
}