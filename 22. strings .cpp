#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// two pointer function for reversing the string
void reverse_string(char a[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(a[s++], a[e--]);
    }
}

// check palindrome afer the reversing the string remains same then the string is
// palidrome for example abcba after reversing abcba
bool checkPalindrome(string s)
{
    int n = s.size(); int start = 0; int end = n - 1;
    for (int i = 0; i < n; i++){
        if (s[start] != s[end]){
            return false;
        }
        else{
            start++;
            end--;
        }
    }return true;
}


// filtering the 
bool isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// converting the uppercase char to lowercase and return it 
char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}


int main()
{

    // string store the char in array type index
    // 0 1 2 3 4  at last it store null so the operation stop
    // a k a s h null
    // so we can acces the string elements like
    // cout<<s[3] so it print s as output
    // declaration of string
    // string s = "akash gite";
    // cout<<s;

    // concating the strings adding two strings
    // string s1 = "Akash ";
    // string s2 = "Gite";

    // string s3 = s1 + s2; cout<<s3;

    std::string s = "Hello, World!";
    std::string part = "World";

    size_t pos = s.find(part);
    if (pos != std::string::npos) {
        std::cout << "Substring found at position: " << pos << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }

    return 0;

    return 0;
}