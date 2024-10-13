// C++ Program to Illustrate How to Access Array Elements 
#include <iostream> 
using namespace std; 

 //! accessing and inserting the elements in the array

     //! Update Array Element or insert in the array 
       /*To update an element in an array, we can use the index which we want to update enclosed within the array subscript operator and assign the new value.

          arr[i] = new_value;
          arr[0] = 10;
    
       */

    //! Accessing the array Element 
      // cout << "arr[0]: " << arr[0] << endl;


int main() 
{ 
	int arr[3]; 

	// Inserting elements in an array 
	// arr[0] = 10; 
	// arr[1] = 20; 
	// arr[2] = 30; 

    // Inserting elements in an array using loop
    for (int i = 0; i < 3; i++)
    {    int n; // declare the variable for storing the element
         cin>>n; // getting the input
         arr[i] = n; // storing the input
    }
    
	// Accessing and printing elements of the array 
	 // cout << "arr[0]: " << arr[0] << endl; 
	 // cout << "arr[1]: " << arr[1] << endl; 
	 // cout << "arr[2]: " << arr[2] << endl; 
    
    // Accesing the array Element using the loop 
    // we also call it traverse of an array where 
    // We can traverse over the array with the help  of a loop using indexing in C++
     for (int i = 0; i < 3; i++)
     {
        cout<<arr[i]<<" ";
     }
    
	return 0; 
}
