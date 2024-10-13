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



int main()
{
  // fuction call
  int n = 5;
  print(n);

  // fuction call 
  int s = sum(1,5);
  cout<<s;



  return 0;
}