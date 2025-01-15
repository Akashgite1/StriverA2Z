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
char toLowerCase(char character)
{
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
char uppercase_char(char character)
{

    if (character >= 'a' && character <= 'z')
    {
        return character - 32;
        // return character + ('A' - 'a');
        //  if the char is e = 101 - 32 = 69 = E
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
        cout << s.substr(0, i + 1) << endl;
    } // O(n^2) time complexity
}

// substr get start index and end index and return the substring
// for ex string = "akash" then the substr(0, 2) = ak

//! prefix of the string
// string = "abcd" then the prefix are a, ab, abc, abcd
// for finding the prefix of string we can simply use substr function
void print_prefix(string s)
{
    // print all substring at O(n^2) time complexity
    // string akash substr are a, ak, aka, akas, akash
    for (int i = 0; i < s.size(); i++)
    {
        cout << s.substr(0, i + 1) << endl;
    }

    // for printing the perticular substring we can provide its staring ending index
    // cout<<s.substr(0, 2); // ak
}

//! suffix of the string
// last charcher of string is suffix of the string its reverse of the prefix
// for finding the suffix of string we can simply use substr function
void print_suffix(string s)
{
    // print all substring at O(n^2) time complexity
    // string akash substr are h, sh, ash, kash, akash
    for (int i = 0; i < s.size(); i++)
    {
        cout << s.substr(i) << endl;
    }

    // for printing the perticular substring we can provide its staring ending index
    // cout<<s.substr(0, 2); // ak
}

//! string matching algortihm
//~ brute force algorithm
bool string_matching(string s, string pattern)
{
    int n = s.size();
    int m = pattern.size();
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && s[i + j] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
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
vector<int> LPS(string pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool KMP(string s, string pattern)
{
    int n = s.size();
    int m = pattern.size();
    vector<int> lps = LPS(pattern);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (s[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            return true;
        }
        else if (i < n && s[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return false;
}

//! daily coding problem 1400. Construct K Palindrome Strings
bool string_palindrome(string s, int k){
    // given string s and integer k we have to return true if we can 
    // construct k palindrome strings from the given string s 
    // false otherwise 

    int n = s.size();

    // single character itself is a palindrome 
    // s = abc  'a' 'b' 'c' are itself palindrome  
    // so if the size of string is equal to k that means we can create k palindromes
    if(n == k) return true; 

    //~ how many palindrome we can create form the a perticular string 
    //~ we can create exactly string s that much palindrome from a string 
    // if the size if 6 that means we can create 6 palindrome from the string 
    // since the char itself is a palindrome 

    //~ if the size of k is greater then the string size then we return false 
    // ex string  = abc the size is 3 and can create 3 palindrome max from this
    // so if the k is greater then the string size we cant create k palindrome 
    if(k > n) return false;  

    // only one case left where the size of string is greater then k 
    // ex  string = "annabelle" k = 2 
    // if the character come even number of times then first we can put in center
    // then we can put them at start and at end 
    // ababccddee is a string 
    // freq of each char is a = 2, b = 2, c = 2, d = 2, e = 2 
    // put a at center          aa 
    // put b at start and end   baaab
    // put c at start and end   cbaaabc
    // put d at start and end   dcbaaabcd
    // put e at start and end   edcbaaabcde  created a palindrome from string

    //~ her actually the odd freq char decide how many palindrome we can create
    // ex string = "ababcx" k = 2 
    // even freq char = a = 2, b = 2
    // odd freq char = c = 1, x = 1   
    // string form form even freq char = abba  
    // string from from odd freq char = 'c'   'x' 
    // we can put one odd freq string into even freq string 
    // string become string =  abcba  and odd remain 'x' 
    // so we get 2 palindrome string 

    // but what if the k is 1 
    // ex string = "ababcx" k = 1 
    // even freq char = a = 2, b = 2 
    // odd freq char = c = 1, x = 1
    // string form from even freq char = abba   odd = 'c' 'x' 
    // her we can put one odd freq char into even freq string 
    // string become string = abcba  and odd remain 'x' 
    // so that why the odd freq char decide how many palindrome we can create 
    // her we can se we cannon create one palindrome from the string 
    // that why we return false 

    // for this problem we have to just check the odd char frq is less then k or not 

    // if the odd freq char is less then or equal to k then we return true 
    // ex string  = ababac k = 1  even char = a = 3, b = 2 
    // odd char = c = 1   (k = 1 )  
    // we can put one char inside the even string to make it palindrome 
    // c goes inside the string = abacaba  so we can create 1 palindrome 
    // hence we can return true

    // EX string = "annabellex"   k = 2 
    // even len string = anna 
    // evene lent string  = elle 
    // odd len string = "b" "x" 
    // condition odd len string is less then or equal to k true and we can 
    // put b in firt string and x in second string hence it true 
 
     vector<int> freq(26, 0);
        for (auto it : s) {
            freq[it - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                count++;
            }
        }
        // if (count <= k)
        //     return true;
        // else
        //     return false;
        return count <= k;
 
}

//! daily leetcode check if a parentheses string can be valid 2116
bool canBeValid(string s, string lock)
{
    int n = s.length();
    if (n % 2 != 0)
    {
        return false;
    }
    // we keep two stack one for open close brackets and one for the opening
    // brackets only we are not putting the character but its index in the
    // stack
    stack<int> open;
    stack<int> open_close;

    // put the index in the stack
    for (int i = 0; i < n; i++)
    {
        // if the char is 0 that means its open
        // closed char so put in open close stack
        if (lock[i] == '0')
        {
            open_close.push(i);
        }
        // if the char is opening char and its value is 1 that means is
        // strictly open
        else if (s[i] == '(')
        {
            open.push(i);
        }
        // else the char is strict closing that means we have to find the
        // its opening char
        else if (s[i] == ')')
        {
            // we check in the open stack any open char available or not
            // if available we pop it
            if (!open.empty())
            {
                open.pop();
            }
            // is the open is not available then we check in the closing
            // stack that any convertable open close bracket availabe if yes
            // then we pop it
            else if (!open_close.empty())
            {
                open_close.pop();
            }
            // for the closing if there is no closing or opening bracket
            // available that means we cant balance it and return false
            else
            {
                return false;
            }
        }
    }

    // the case where all brackets are open or close bracket
    // s = ((((  locked = 0 0 0 0
    // open = 1 2 3 4  open_close = 1 2 3 4 both cancel out with each other
    // since we can convert two of them to make valid parenthesis so the
    // answer is true if all the brackets can be converted into open close
    // brackets then
    while (!open.empty() && !open_close.empty() &&
           open.top() < open_close.top())
    {
        // we are chaging one so pop both
        open.pop();
        open_close.pop();
    }

    return open.empty(); // tc O(n) sc O(n) 
}
// solution without using the stack 
bool isValid (string s, string lock ){
    int n = s.length(); 
    // if the size is odd then it cannon be balanced
    if (n % 2 != 0) return false; 
    
    // left to right traversal 
    int open = 0; 
    for(int i=0; i<n; i++){

        if(s[i] == '(' || lock[i] == '0'){
            open++; }
        else {
            open--;
        }

        if(open < 0) return false;
    }

    // right to left traversal
    int close = 0; 
    for(int i=n-1; i>=0; i--){
        if(s[i] == ')' || lock[i] == '0'){
            close++;
        }
        else {
            close--;
        }

        if(close < 0) return false;
    }
    return true;

}

//! daily leetcode 3233 minimum length of string after operations 
int minimum_lenght(string s){
    int n = s.size();
    
    vector<int> freq(26, 0);
    int deleted = 0; 
    for(auto it : s){
        freq[it - 'a']++;

        if(freq[it - 'a'] == 3){
            freq[it - 'a'] -=  2;
            deleted += 2;
        }
    } 
    
    // int count = 0; 
    // for(int i=0; i<26; i++){
    //     count += freq[i];
    // }
    // return count; 

    // there are total n character and we delete deleted much character 
    return n - deleted;


    // approach 2 
    // obeservation 
    //            i
    // string = aaaaa odd number of char 
    // observation if i poiting in middle and we are deleting left and right side
    // same element for the minimum number of char freq or count so at last only 
    // one remains 

    //      l i  r
    //  a  a  a  a  a  delete l and r
    //     a  a  a     delete l and r
    //        a        only single char remains 

    // for the even case there is always two char remains 
    // string = aaaaaa even number of char 
    //      l i  r
    //  a  a  a  a  a  a  delete l and r
    //   l  i  r   
    //   a  a  a  a     delete l and r
    //      a     a     only two char remains
    //  a   a           
    // for the odd count char only one char remains and for the even count char
    // two char remains 
    // new approach 
    // get all elements freq 
    
    // vector<int> freq(26, 0);
    // for(auto it : s){
    //     freq[it - 'a']++;
    // }

    // int result = 0; 

    // for(int i=0; i<26; i++){

    //     if(freq[i] == 0) continue;

    //     // if its even 
    //     if(freq[i] % 2 == 0){
    //         result += 2;
    //     }
    //     // if its odd 
    //     else {
    //         result += 1;
    //     }
    // }
    // return result;

    
}


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
    // printing_sub_string_using_substr(s);

    //! prefix of the string
    // string s = "akash";
    // print_prefix(s);

    //! suffix of the string
    // string s = "akash";
    // print_suffix(s);

    //! string matching algorithm
    // string s = "abccdeethopp";
    // string pattern = "tho";
    // cout << string_matching(s, pattern);
    
    //! constructing the k palindrome strings 
    // string s = "annabelle"; int k = 2;
    // string s = "yzyzyzyzyzyzyzy"; int k = 2; 
    // cout<<canConstruct(s, k);

    //! check if a parentheses string can be valid 2116 
    // string s = "((()))";
    // string lock = "010101";
    // cout<<canBeValid(s, lock);

    //! minimum length of string after operations 
    // string s = "abaacbcbb";
    // string s1 = s = "aa";
    // cout<<minimum_lenght(s);
    // cout<<minimum_lenght(s1);

    
    return 0;
}