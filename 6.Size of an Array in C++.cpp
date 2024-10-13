#include <iostream> 
using namespace std; 

  // we can calculate the size of an array using sizeof() operator trick. First, we find the size occupied by the whole array in the memory and then divide it by the size of the type of element stored in the array. This will give us the number of elements stored in the array.

int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5 }; 

	// Size of one element of an array 
	cout << "Size of arr[0]: " << sizeof(arr[0]) << endl; 
     

	// Size of array 'arr' 
	cout << "Size of arr: " << sizeof(arr) << endl; 

	// Length of an array 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << "Length of an array: " << n << endl; 

	return 0; 
}
