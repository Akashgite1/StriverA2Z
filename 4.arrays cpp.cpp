#include <iostream>

using namespace std;

int main()
{
    // Array Declaration in C++
    /* Here,
      int: It is the type of data to be stored in the array. 
      arr: It is the name of the array.

      5- It is the size of the array which means only 5 elements can be stored in the array.*/

    int arr[5];

    // Initialization of Array in C++

     // 1. Initialize Array with Values in C++
         int arr[5] = {1, 2, 3, 4, 5};

     // 2. Initialize Array with Values and without Size in C++  
         int arr[] = {1, 2, 3, 4, 5};

     //  3. Initialize Array after Declaration (Using Loops)
        for (int i = 0; i < 10; i++) 
        {
           //arr[i] = value;
        }
     
     //  4. Initialize an array partially in C++
     //  Here, we have declared an array ‘partialArray’ with size ‘5’ and with values ‘1’ and ‘2’ only. So, these values are stored at the first two indices, and at the rest of the indices ‘0’ is stored.

         int partialArray[5] = {1, 2};


    return 0;
}