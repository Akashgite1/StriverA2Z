#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// ! Strings
//~ common operations on strings
// prefix of the string
// suffix of the string
// reverse the string
// check palindrome
// check two string are equal or not

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

    // build in function 
    // reverse(s.begin(), s.end());  // reverse the string in O(n) time 
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
char toLowerCase(char character){
    if (character >= 'A' && character <= 'Z')
    {
        // character in upperace ( a - A ) its get the new lower case char
        // small char a value is 97 and z is 122 total 26 char 
        // for ex charcter = E then E - A = 4 then 4 + a = e 
        // return character + ('a' - 'A');
         return character + 32; 
        // if the char is E = 69 + 32 = 101 = e 
    }
    return character;
 
    // build in function 
    // return tolower(character);
    // return character | 32; // 32 is the difference between the ASCII values of
    

    //! char and their values 
    // a  =  97             A  =  65
    // b  =  98             B  =  66
    // c  =  99             C  =  67
    // d  =  100            D  =  68
    // e  =  101            E  =  69
    // f  =  102            F  =  70
    // g  =  103            G  =  71
    // h  =  104            H  =  72
    // i  =  105            I  =  73
    // j  =  106            J  =  74
    // k  =  107            K  =  75
    // l  =  108            L  =  76
    // m  =  109            M  =  77
    // n  =  110            N  =  78
    // o  =  111            O  =  79
    // p  =  112            P  =  80
    // q  =  113            Q  =  81
    // r  =  114            R  =  82
    // s  =  115            S  =  83
    // t  =  116            T  =  84
    // u  =  117            U  =  85
    // v  =  118            V  =  86
    // w  =  119            W  =  87
    // x  =  120            X  =  88
    // y  =  121            Y  =  89
    // z  =  122            Z  =  90
}

//! to convert the lower case char to upper case char 
char uppercase_char(char character){

    if(character >= 'a' && character <= 'z'){
        return character - 32;
        //return character + ('A' - 'a');
        // if the char is e = 101 - 32 = 69 = E
    }
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

//! divide the whole string into the substring
// ex string = abcde  then the substring are a, ab, abc, abcd, abcde
// we can also called it prefix of the string
// we can do this by using the substr function and without using the substr function

//~ without using the substr function
void printing_sub_string_without_builtInFunction(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 1; j <= s.size() - i; j++)
        {
            for (int k = i; k < i + j; k++)
            {
                cout << s[k];
            }
            cout << endl;
        }
    } // O(n^3) time complexity
}

//~ using the substr function
void printing_sub_string_using_substr(string s)
{
    
    for (int i = 0; i < s.size(); i++)
    {
        cout<< s.substr(0, i+1)<<endl;
    } // O(n^2) time complexity
}

// substr get start index and end index and return the substring 
// for ex string = "akash" then the substr(0, 2) = ak 


//! prefix of the string
// string = "abcd" then the prefix are a, ab, abc, abcd
// for finding the prefix of string we can simply use substr function
void print_prefix(string s){
// print all substring at O(n^2) time complexity
// string akash substr are a, ak, aka, akas, akash 
    for(int i = 0; i < s.size(); i++){
        cout<<s.substr(0, i+1)<<endl;
    }

    // for printing the perticular substring we can provide its staring ending index
    // cout<<s.substr(0, 2); // ak 
}

//! suffix of the string
// last charcher of string is suffix of the string its reverse of the prefix
// for finding the suffix of string we can simply use substr function
void print_suffix(string s){
    // print all substring at O(n^2) time complexity
    // string akash substr are h, sh, ash, kash, akash 
    for(int i = 0; i < s.size(); i++){
        cout<<s.substr(i)<<endl;
    }

    // for printing the perticular substring we can provide its staring ending index
    // cout<<s.substr(0, 2); // ak 
}

//! string matching algortihm 
//~ brute force algorithm
bool string_matching (string s, string pattern){
    int n = s.size();
    int m = pattern.size();
    for(int i = 0; i <= n - m; i++){
        int j = 0;
        while(j < m && s[i+j] == pattern[j]){
            j++;
        }
        if(j == m){
            return true;
        }
    }
    return false;
    // time complexity is O(n*m) where n is the size of the string and m is the size of the pattern
    // we are keeping two pinters i poiting the string s and j is poiting on pattern
    // we are checking both string equality in runtime and if j secceed to reach
    // ints ending then we can say that the patter is found in the string 
}

//! string pattern matching algorithm optimal solution 
//~ KMP algorithm knuth morris pratt algorithm 



int main()
{

    //! string store the char in array type index
    // 0 1 2 3 4  at last it store null so the operation stop
    // a k a s h null
    // so we can acces the string elements like
    // cout<<s[3] so it print s as output
    // declaration of string
    // string s = "akash gite";
    // cout<<s;

    //! concating the strings adding two strings
    // string s1 = "Akash ";
    // string s2 = "Gite";

    //! string s3 = s1 + s2; cout<<s3;
    // std::string s = "Hello, World!";
    // std::string part = "World";

    //! size_t pos = s.find(part);
    // if (pos != std::string::npos) {
    //     std::cout << "Substring found at position: " << pos << std::endl;
    // } else {
    //     std::cout << "Substring not found." << std::endl;
    // }

    //! reverse the string
    // string s = "akash"; // reverse is hsaka
    // cout<<reverse_string(s);

    //! check the string is palindrome or not
    // string s = "abcba"; // ans is true
    // cout<<checkPalindrome(s);

    //! string compression
    // string s = "aaabcccd"; // ans is 3a1b3c1d
    // Solution sol;
    // cout << sol.compressedString(s);

    //! rotate string
    // string A = "abcde", B = "cdeab"; // ans is true
    // cout << rotateString(A, B);

    //! printing the substring 
    // string s = "abcde";
    // printing_sub_string_without_builtInFunction(s);
    //printing_sub_string_using_substr(s);
    
    //! prefix of the string
    // string s = "akash";
    // print_prefix(s);

    //! suffix of the string
    // string s = "akash";
    // print_suffix(s);

    //! string matching algorithm
    string s = "abccdeethopp";
    string pattern = "tho";
    cout<<string_matching(s, pattern);

    return 0;
}