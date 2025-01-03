#include<iostream>

using namespace std;

// declaring the 3d array or the 3 dimentional array

// making the custom 3d array
struct Element
{
    int value;
    int row;
    int col;

    bool operator>(const Element &other) const
    {
        return value > other.value;
    }
};

// making the function for storing the element in the 3d array and accesing it 
void insert(int arr[3][3][3], int x, int y, int z, int value){

    arr[x][y][z] = value;

    cout<<arr[x][y][z]<<endl;
}

int main (){
    // Declaring 3D array 
     //data_type array_name[x][y][z];
     //   data_type: Type of data to be stored in each element.
     //   array_name: name of the array
     //   x: Number of 2D arrays.
     //   y: Number of rows in each 2D array.
     //   z: Number of columns in each 2D array.

     //example 
        //int arr[3][3][3];


    return 0;
}