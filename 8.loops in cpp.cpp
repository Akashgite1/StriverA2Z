#include <iostream>

using namespace std;

int main()
{
    // there are 3 types of loops availble in cpp
    // for loop
    // while loop
    // do-while

    // structure of for loop
    /*
     for(initialization ; condition; updation)
     {
         code statements
     }
    */
    cout << "printing the for loop ";
    for (int i = 0; i < 5; i++)
    {
        /* code */
        cout << i << ":"
             << "a" << endl;
    }

    // structure of while loop
    /*
      initialization ;
      while (condition)
      {
         code statements

        updation;
      }
    */
    cout << "printing the while loop";
    int c = 0;
    while (c < 5)
    {
        /* code */
        cout << c << ":"
             << "a" << endl;
        // i++ or i = i+1; both are same
        c++;
    }

    // structure of Do-while loop
    /*
       initialization ;
       do
        {
           statements
           updation;

        } while (condition);

    */
    cout << "printing do-while loop";
    int k = 0;
    do
    {
        cout << k << ":"
             << "a" << endl;
        k = k + 1;

    } while (k < 5);

    return 0;
}