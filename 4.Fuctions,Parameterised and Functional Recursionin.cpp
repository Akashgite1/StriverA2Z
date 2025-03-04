#include <iostream>

using namespace std;
// function are used for use the same code multiple times

// types of fuction
// 1.void fuction does not return anything
// 2.parameterised
// 3.non parameterised

// declaration of fuction
/*                           paramater type
   return type function name(parameter 1,para 2)
   {
     code block
   }

   int calculation(int a , int b)
   {
     return a+b;
   }
   return type is int
   function name is calculation
   parameter type is int
   parametrs are a and b
   inside the function we return the adition of a and b

*/

// void function doest return anything
void print(int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "hello"<<endl;
  }
}

// parameterised fuction return some value
int sum(int a,int b)
{
  return a+b;
}
// printing the array function 
void print(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        /* code */ 
         cout<<arr[i]<<" ";
    }

}
// Parameterised and Functional Recursion
// Q.Sum of first N Natural Numbers

// using arithmetic series 
void print(int n)
{
    int sum = 0;

    sum = n*(n+1)/2;

    cout<<sum;
}

// using the recursion by parameterised method 
void print1(int n , int sum)
{
     if (n < 1)
     {
        cout<<sum;
         return;
     }
     print1(n-1, sum+n);

}

// using recursion by functional method 
int print2(int n)
{
    if(n == 0) {return 0;}

    return n + print2(n-1);
}

// recursive funtion for factorial of n numbers
int fact (int n)
{
    if(n == 0){ return 1;}

    return n*fact(n-1);
}


// functional recursion 
// reverse the array using the recursion

void reverse (int arr[],int l, int r)
{
    // two pointers method in recursion
    if(l>=r) return;

    swap(arr[l],arr[r]);

    // recursion call
    reverse(arr,l+1,r-1);

}

void reverse1 (int arr[], int i,int n)
{
    // base condtion 
    if(i >= n/2) return;

    swap(arr[i],arr[n-i-1]);

    reverse1(arr,i+1,n);
}

// function for checking the palindrome or not 
// palindrome means reverse of the string will be same 
// for exmaple madam if we reverse it m a d a m it again ganerated 
// madam same as it actual string before reversing this called palin..
bool palidrome(char string[], int i, int n)
{
    if(i >= n/2) return true;

    if(string[i] != string[n-i-1])
    {
        return false;

    }
    return palidrome(string , i + 1 , n );

}

// fibonacci using the recursion 
//  we use multiple recursion calls for getting the fibonacci number

int fibonacci(int n)
{
    // base condition if the value of n is less then or equal to 1
    if(n <= 1)
    {
        return n;
    }

    // recursion call 
    // formula of the fibo f(n) = f(n-1) + f(n-2);
    int last = fibonacci(n-1);
    int second = fibonacci(n-2);

    // returning the sum of last + second element 
    return last + second;
    
}


int main (){

    // int n;
    // cin>>n;
    //print1(n,0);
    //cout<<print2(n);
    // cout<<fact(n);

    // reversing the array element 
    // int arr[] = {1 , 2, 3, 4 , 5};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // reverse(arr,0,n-1);
    // print(arr,n);

    // reverse1(arr,0,n);
    // print(arr,n);
    
    // char str[] = "skdpnyegmds";
    // int n = strlen(str);
    // cout<<palidrome(str,0,n);

    // fibonacci series nth position using the recursion 
    int n = 4;
    cout<<fibonacci(n);

    return 0;
}
