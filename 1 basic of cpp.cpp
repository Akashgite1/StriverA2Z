#include <iostream>

using namespace std;

void reverse_string (string s)
{
    for (int i = s.length() - 1; i >= 0; i--)
    {
        cout << s[i];
    }
}

// reverse a string using two pointers approach
void reverse_string_two_pointer(string &s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    cout << s;
}



int main()
{
    // for printing anything on the console we use
    // cout << "hello";

    //  for getting the output from the console we use
    // int x;
    // cin >> x;
    // cout << x;

    // we have the data-type for each data for
    // example integers,floting numbers,characters
    // strings

    // data-types int- integers
    // flot- floting point
    // char - characters
    // string - for strings

    // how we get input in each data type lets see

    // getting input for integer
    // int n;
    // cin >> n;
    // cout << n;
    // cout << endl;

    //  getting for floting point
    // float p;
    // cin >> p;
    // cout << p;
    // cout << endl;

    //  for char
    // char l;
    // cin >> l;
    // cout << l;
    // cout << endl;

    //  for string
    // string o;
    // cin >> o;
    // cout << o;
    // cout << endl;

    //  conditional statements
    //  if
    // else
    // programming problem
    // wap that takes input as age and print you are
    // and adult or not

    // int age;
    // cin >> age;
    // if (age >= 18)
    // {
    //     cout << "you are not an adult";
    // }

    string s;
    cin >> s;
    reverse_string_two_pointer(s);
    
    

    return 0;
}