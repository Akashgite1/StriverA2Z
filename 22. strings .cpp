#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//! two pointer function for reversing the string
string reverse_string(string s)
{
    int n = s.size();
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        swap(s[start++], s[end--]);
    }
    return s;
}

//! check palindrome afer the reversing the string remains same then the string is
//! palidrome for example abcba after reversing abcba
bool checkPalindrome(string s)
{
    int n = s.size();
    int start = 0;
    int end = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}

//! filtering the
bool isAlphanumeric(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

//! converting the uppercase char to lowercase and return it
char toLowerCase(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + ('a' - 'A');
    }
    return c;
}

//! 3163. String Compression III
class Solution
{
public:
    string compressedString(string word)
    {
        int n = word.size();

        string comp = "";
        int i = 0;

        while (i < n)
        {
            int count = 0;
            char ch = word[i];
            // i in the index  & count of one char is less then 9
            // and the current word if equal to current char
            while (i < n && count < 9 && word[i] == ch)
            {
                count++;
                i++;
            }
            //
            comp += to_string(count) + ch;
        }
        return comp;
    }
};

//! 796. Rotate String
bool rotateString(string A, string B)
{
    if (A.size() != B.size())
    {
        return false;
    }
    return (A + A).find(B) != string::npos;

    // if (A.size() != B.size())
    //     return false;
    // string doubled = B + B;                 // Concatenate s with itself
    // return doubled.find(A) != string::npos; // Check if goal is a substring of doubled

    // if (A == B) return true;
    //     int n = A.size();
    //     for (int i = 0; i < n; i++) {
    //         rotate(B.begin(), B.begin() + 1, B.end());
    //         if (B == A)
    //             return true;
    //     }
    //     return false;

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
    // std::string s = "Hello, World!";
    // std::string part = "World";

    // size_t pos = s.find(part);
    // if (pos != std::string::npos) {
    //     std::cout << "Substring found at position: " << pos << std::endl;
    // } else {
    //     std::cout << "Substring not found." << std::endl;
    // }

    // reverse the string
    // string s = "akash"; // reverse is hsaka
    // cout<<reverse_string(s);

    // check the string is palindrome or not
    // string s = "abcba"; // ans is true
    // cout<<checkPalindrome(s);

    // string compression
    // string s = "aaabcccd"; // ans is 3a1b3c1d
    // Solution sol;
    // cout << sol.compressedString(s);

    // rotate string 
    // string A = "abcde", B = "cdeab"; // ans is true
    // cout << rotateString(A, B);
    



    return 0;
}