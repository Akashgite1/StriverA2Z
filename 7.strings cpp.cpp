#include<iostream>
// To use strings, you must include an additional header file in the source code, the <string> library:
#include<string>

using namespace std;
// strings in cpp
// Declaring the string 
// Accessing the string 

int main (){

    //C++ Strings
      // Strings are used for storing text.
      // A string variable contains a collection of characters surrounded by double quotes:

      // Declaring the string in the cpp
         string greeting ="hello";

       // print string 
         cout<<greeting;

         // in string text are store in array like strucure
         // so we can access the each part of string by its index example cout<<A[0]; prints output : A 

         /*    0   1   2  3  4 
               A   k   a  s  h
        
          */
         string A = "Akash";
         // her we print string A as 2nd nymber element 
         // hense it print small a since it available at 2nd place
         cout<<A[2];

       // for finding the lenght of the string 
       // we use nameofstring.size() or .length() function 
           int len = A.length();
           cout<<len;
          // or
           cout<<A.length();
        
        // getting input for string form the console
            string first_name;
            cin>>first_name;
            cout<<"your name is :"<<first_name;
        
        // the probleme is her that if we want print 
        // john king but it canoot get after the space 
        // so getting after the space we use getline() function 
            string fullName;
            cout << "Type your full name: ";
            getline (cin, fullName);
            cout << "Your name is: " << fullName;

         // changing the elements in string 
         //Declaring the string 
           string akash = "gite";
           int leng = akash.size();

         // changing the element at last place 
           akash[len-1] = 'o';
         
         // print the string
           cout<<akash;
           //or we can directly print the string last element
           cout<<akash[len-1]; 

    return 0;
}