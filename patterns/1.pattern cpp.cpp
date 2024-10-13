#include <iostream>

using namespace std;
/*
   taking the input as n and print same number of "*" in row and column
   for Ex n=4
   * * * *
   * * * *
   * * * *
   * * * *
*/

void print_1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print_2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print_3(int n)
{
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print_4(int n)
{
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void print_5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print_6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print_7(int n)
{
    for (int i = 0; i <= n; i++)
    {
        // space(n-i-1)
        for (int j = 0; j < n - i - 1; j++)
        {
            cout <<" ";
        }

        // star(2*i+1)
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // space (n-i-1)
        for (int j = 0; j < n - i - 1; j++)
        {
            cout <<" ";
        }
        cout<<endl;
    }
}

void print_8(int n)
{
    for (int i = 0; i <= n; i++)
    {
        
        for (int j = 0; j < i; j++)
        {
            cout <<" ";
        }

        // 
        for (int j = 0; j < 2*n-(2*i+1); j++)
        {
            cout << "*";
        }

       
        for (int j = 0; j < i; j++)
        {
            cout <<" ";
        }
        cout<<endl;
    }
} 

void print_9(int n)
{
    for (int i = 0; i <= n; i++)
    {
        // space(n-i-1)
        for (int j = 0; j < n - i - 1; j++)
        {
            cout <<" ";
        }

        // star(2*i+1)
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // space (n-i-1)
        for (int j = 0; j < n - i - 1; j++)
        {
            cout <<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i <= n; i++)
    {        
        for (int j = 0; j < i; j++)
        {
            cout <<" ";
        }

        // 
        for (int j = 0; j < 2*n-(2*i+1); j++)
        {
            cout << "*";
        }

       
        for (int j = 0; j < i; j++)
        {
            cout <<" ";
        }
        cout<<endl;
    }
} 

void print_10(int n)
{
    for (int i = 1; i <=2*n-1; i++)
    {
        int stars = i;
        if (i>n)// i greter then n 
        {
            stars = 2*n-i;
        }
        
        for (int j = 1; j <=stars; j++)
        {
            cout<<"*";
        }
        cout<<endl;  
    } 
}

void print_11(int n)
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i%2==0){ start = 1; }  // 1 
                                   

        else{ start = 0;} // 0

        for (int j = 0; j<=i; j++) 
        {
            cout<<start; 

            start = 1 - start;
        } 
        cout<<endl;  
    }
}

void print_12(int n)
{  
    int space = 2*(n-1);
    
    for (int i = 1; i <=n; i++)
    {
        
        // nums 
       for (int j = 1; j <=i ; j++)
       {
           cout<<j;
       }
       // space 
       for (int j = 1; j<=space; j++)
       {
          cout<<" ";
       }
       

       // nums
       for (int j = i; j >=1; j--)
       {
         cout<<j;
       }
       cout<<endl;
       space -= 2;
       
    }
    
}


int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        /* code */
        print_12(n);
    }

    // online compiler run for test cases
    // t = 2 that means there are two test cases
    // first is 3
    // second is 5

    // output
    // 2
    // 3
    // ***
    // ***
    // ***
    // 5
    // *****
    // *****
    // *****
    // *****
    // *****
    return 0;
}