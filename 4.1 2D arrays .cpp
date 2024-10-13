#include <iostream>

using namespace std;

// 2D Arrays
// Accessing the 2d arrays
// Inserting the elements in 2D arrays
// Accessing the elements in 2D arrays using the loop

int main()
{
    //! Two-Dimensional Arrays
    //  A 2D array is also known as a matrix (a table of rows and columns).

    //! declaration 2D array
    // first 2 is the size of the row
    // second 3 is the size of colume
    int matrix[2][3] = {{1, 4, 2}, {3, 6, 8}};

    /*
                column_0   column_1   column_2
         row_0     1         4          2

         row_1     3         6          8

    */

    //! Access the Elements of a 2D Array
    // cout << matrix[0][2];
    // cout << endl;
    // at row 0 and colume 2 we have stored 2

    //! Change Elements in a 2D Array
    // matrix[0][1] = 10;
    // cout << matrix[0][1];
    // at row 0 and column 1 the element is 4
    // we changed it to 10 and print it

    //! using the loop to access the 2D array
    //  for (int i = 0; i < 2; i++)
    //  {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout<<i<<j<<":"<< matrix[i][j]<<endl;
    //     }
    //  }

    // inserting the elements in 2D array using loop

    int matrix_1[10][10];

    for (int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;

        for (int j = 0; j < 10; j++)
        {

            matrix_1[10][10] = n;
        }

        /* code */
    }
    
    

    return 0;
}