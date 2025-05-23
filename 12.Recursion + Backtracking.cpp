#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//! binary tree structure
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//! Recursion is the process in which a function calls itself unit a base condition is reached.
//~ a base condition is a condition where the recursion stops.
//~ recursion means repeating the same thing again and again.

//! print 1 to n using recursion
//? Yes, for a void function, it does not return anything, and the base case just stops execution.
void print(int n){

    // base condition where the recursion stops
    // stop condition
    // if we print n inside the base case it will print our last recursion
    // condition in which we have to stop
    if (n == 0)
        return;

    // elements will be printed in decreasing order 5 4 3 2 1
    // first element will be printed
    cout << n << " ";
    // recursive call

    // element printed in incresing order 1 2 3 4 5
    // after the recursive call element will be printed
    print(n - 1);
    // printitng the current n number
}

//! for an int function, the base case must return a value, which can then be used in recursive calls.
int print1toN(int n){
    //? when base case hit it will return base case base case will print at new line
    if (n == 0)
        return 0; // Base case returns 0

    //? call the recursive function and the print the current condition recursive call
    return print1toN(n - 1); // Recursive call returns something
    // print 5 and return for 5-1 = 4 print : 5
    // print 4 and return for 4-1 = 3 print : 5 4
    // print 3 and return for 3-1 = 2 print : 5 4 3
    // print 2 and return for 2-1 = 1 print : 5 4 3 2
    // print 1 and return for 1-1 = 0 print : 5 4 3 2 1
    // print 0 and return for 0-1 = -1 print : 5 4 3 2 1 0
    cout << n << " "; // Print the current number
}

//! factorial using recursion
int fact(int n){
    // base case
    if (n == 0 || n == 1)
        return 1;

    // recursive call
    return n * fact(n - 1);
}

//! height of binary tree using recursion
int height(Node *root){
    // base case
    if (root == NULL)
        return 0;

    // left height recursive call goes upto the leaf node
    int leftHeight = height(root->left);
    // right height recursive call goes upto the leaf node
    int rightHeight = height(root->right);

    // return the max in between left and right height
    return max(leftHeight, rightHeight) + 1;
}

//! sort an array using recursion and insert element using loop
void sort(int arr[], int n){
    // base case
    if (n == 1)
        return;

    // hypothesis
    sort(arr, n - 1);

    // induction
    int lastElement = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > lastElement)
    {
        // shifting the elements
        arr[j + 1] = arr[j];
        j--;
    }
    // last element will be inserted at the correct position
    arr[j + 1] = lastElement;
}

//! both insert element and sort array using recursion
void insert(vector<int> &arr, int temp){
    if (arr.empty() || arr.back() <= temp)
    {
        arr.push_back(temp);
        return;
    }

    // recursion happend for removing the last element of array
    // it will run unitl the base case hit
    int last = arr.back();
    arr.pop_back();    // Remove last element
    insert(arr, temp); // Recursive call to insert temp in the reduced array
    // this will only run when the base case hit
    arr.push_back(last); // Push back the removed element
}

void sortArray(vector<int> &arr){
    if (arr.size() <= 1)
        return; // Base case

    int temp = arr.back();
    arr.pop_back();    // Remove last element
    sortArray(arr);    // Recursively sort remaining array
    insert(arr, temp); // Insert the removed element in sorted order
}

//! sort stack using recursion
void insertElement(stack<int> &st, int top)
{
    if (st.empty() || st.top() <= top)
    {
        st.push(top);
        return;
    }
    int temp = st.top();
    st.pop();
    insertElement(st, top);
    st.push(temp);
}
// remove the element from stck until the last element left
//  since the last element is itself smallest element largest element and sorted
//  since its a single element
void sortStack(stack<int> &st)
{
    if (st.empty())
        return;
    int top = st.top();
    st.pop();
    sortStack(st);
    insertElement(st, top);
} //^ tc : O(n^2) sc : O(n)

//! Delete the middle element of the stack using recursion
void deleteMiddleElement(stack<int> &st, int k)
{
    if (k == 1)
    {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    deleteMiddleElement(st, k - 1);
    st.push(temp);
}

//! Revere stack using recursion
void insertAtBottom(stack<int> &st, int top)
{
    // Base case
    if (st.empty())
    {
        st.push(top);
        return;
    }

    // recursion step
    int temp = st.top();
    st.pop();
    insertAtBottom(st, top);

    // works after the base case hit
    st.push(temp);

    // Push 5
    // Insert 4 → removes 5, pushes 4, then 5
    // Insert 3 → removes 4, 5, pushes 3, then 4, 5
    // Insert 2 → removes 3, 4, 5, pushes 2, then 3, 4, 5
    // Insert 1 → removes 2, 3, 4, 5, pushes 1, then 2, 3, 4, 5
}

void reverseStack(stack<int> &st)
{
    // Base case
    if (st.size())
        return;

    // recursion step
    int temp = st.top();
    st.pop();
    reverseStack(st);
    // Recursive Calls of reverseStack(st)
    // Remove 1
    // Remove 2
    // Remove 3
    // Remove 4
    // Remove 5
    // Now stack is empty.
    // excute after the base case hit
    insertAtBottom(st, temp);
}

//! K-th symbol in grammar
void kthSymbol(int n, int k){
    if (n == 1 && k == 1)
    {
        cout << 0 << endl;
        return;
    }
    int mid = pow(2, n - 1) / 2;
    if (k <= mid)
    {
        kthSymbol(n - 1, k);
    }
    else
    {
        kthSymbol(n - 1, k - mid);
    }
}

//! Tower of Hanoi
void towerOfHanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Move 1 from " << a << " to " << c << endl;
        return;
    }
    towerOfHanoi(n - 1, a, c, b);
    cout << "Move " << n << " from " << a << " to " << c << endl;
    towerOfHanoi(n - 1, b, a, c);
}

//! String to integer stringAtoi
int stringAtoi(string str, int n)
{
    if (n == 0)
        return 0;

    // Extract the last digit from the string
    // n - 1 is pointing the last element of the string
    // from minusing the '0' we get the integer value of the string
    int digit = str[n - 1] - '0';

    // recursive call
    // decrease the size of the string by 1
    int smallAns = stringAtoi(str, n - 1);

    // stringAtoi("1234") -> calls stringAtoi("123")  
    // stringAtoi("123") -> calls stringAtoi("12")  
    // stringAtoi("12") -> calls stringAtoi("1")  
    // stringAtoi("1") -> calls stringAtoi("")  // Base case (returns 0)

    // after reaching the base case it will start returning the value

    //     Returning and Multiplication Starts (Unwinding)
    // return 0 * 10 + 1 = 1
    // return 1 * 10 + 2 = 12
    // return 12 * 10 + 3 = 123
    // return 123 * 10 + 4 = 1234 
    return smallAns * 10 + digit;
}

//! Count good numbers
// brute force 
//  #define MOD 1000000007
// int countGoodNumbers(long long n)
// {
//     long long count = 0;
//     for (long long i = 1; i <= n; i++)
//     {
//         if (i % 2 == 0)
//             count = (count * 4) % MOD;
//         else
//             count = (count * 5) % MOD;
//     }
//     return count;
// }

//! Optimized solution using recursion TC : O(logn) 
class Solution{
public:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp)
    {
        // we are incresing the base as even power to the exp
        // each recursion we are dividing it by 2 to we can reduce the exponet
        // ones the exponent become 0 or 1 we can return 1 since 1^0 = 1
        if (exp == 0)
            return 1; // Base case: anything^0 = 1

        // recursion step minimizing the exponent
        long long half = power(base, exp / 2); // base = 5  and exponet 2/2=0
        // storing the result by multiplying it with itself get the mod to
        // reduce the answer size
        long long result = (half * half) % MOD; // 5^2 = 25  4^2 = 16

        if (exp % 2)
            result = (result * base) % MOD; // If odd, multiply once more
        return result;
    }

    int countGoodNumbers(long long n)
    {
        // get the total number or even places in n
        long long evenPos = (n + 1) / 2; // Number of even positions
        // get the total number of odd position in n
        long long oddPos = n / 2; // Number of odd positions

        // call the recursive power function to multiply the 5 with total number
        // of even positions in n = 4  (4+1)/2  5/2 = 2 even index in n odd
        // positions in n = 4  4/2 = 2 odd index in n
        return (power(5, evenPos) * power(4, oddPos)) % MOD;
    }
};

//! Generate all binary strings without consecutive 1's
void generateBinaryStrings(int n, string s, char last)
{
    // base condition
    if (n == 0){
        cout << s << endl;
        return;
    }
    generateBinaryStrings(n - 1, s + "0", '0'); // Always include '0'
    if (last != '1')
        generateBinaryStrings(n - 1, s + "1", '1'); // Include '1' only if the last was not '1'
}

//! Generate Parenthesis using Recursion 
class parenthesis{ 
    public: 
    //! first approach using recursion and backtracking 
    vector<string> result;

    bool isvalid(string s){ // o(n) time complexity sc : O(1)
        int balance = 0;
        for(char c : s){
            if(c == '('){
                balance++;
            }else{
                balance--;
            }
            if(balance < 0){
                return false;
            }
        }
        return balance == 0;
    }

    void generate(string& s, int n){
        
        // how many time recursion will work so the total number of combination are 2*n
        // suppose the value of n = 2 so the total combination will be 2*2 = 4 

        // base case
        if(s.size() == 2*n){
            // checking the valid parenthesis 
            if(isvalid(s)){
                result.push_back(s);
            }
            return;
        }
        
        // typical backtracking first try all possible open bracket then close bracket
        // recursive call  first try for open bracket 
        s.push_back('(');
        generate(s, n);
        s.pop_back();   // undo for the open bracket

        // recursive call   second try for close bracket
        s.push_back(')');
        generate(s, n);
        s.pop_back();  // undo for the close bracket 

    }

    vector<string> generatepararenthesis(int n){
        // time complexity : O(2^n) sc : O(2^n) 
        string s = "";
        generate(s , n);
        return result;
    }
    
    //! Second Approach only using recursion 
    //! more simple solution using recursion plus open and close bracket logic
    string generateallpossible(int open, int close, string s)
    {
        // base case
        if (open == 0 && close == 0)
        {
            result.push_back(s);
            return s;
        }

        // recursive call
        if (open > 0)
        {
            generateallpossible(open - 1, close, s + "(");
        }
        if (close > open)
        {
            generateallpossible(open, close - 1, s + ")");
        }

        return s;
    }
    // time complexity : O(2^n) sc : O(2^n) just remove the extra of O(n) required for 
    // checking the valid parenthesis 

};

//! Print all Subset of a string using recursion
void solve(string input,  string output){
    // base case
    if(input.size() == 0){
        cout << output << endl;
        return;
    }
    
    // we are not including input char
    string output1 = output; 
    // we are including input char 
    string output2 = output;
    
    // since we are taking input push input into the output 2
    output2.push_back(input[0]);
    
    // now remove it from the input  //-abc -> bc -> c -> "" 
    input.erase(input.begin() + 0);
    
    // now call for not adding
    solve(input, output1); //
    // now call for adding 
    solve(input, output2);

}

string subset(string input){
    string output = "";
    solve(input, output);
    return output; // Tc : O(2^n) Sc : O(2^n)

}

//! subset of the number using recursion
class Subsets{
public:
    void solve(vector<int> &nums, int idx, vector<int> &temp, vector<vector<int>> &result)
    {
        // idex goes to out of bound then we return the temp
        if (idx >= nums.size())
        {
            result.push_back(temp);
            return;
        }

        // firse we include the element in the temp
        temp.push_back(nums[idx]);
        // recursive call
        solve(nums, idx + 1, temp, result);
        // then we remove the element from the temp
        temp.pop_back();
        // recursive call
        solve(nums, idx + 1, temp, result);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> temp;
        vector<vector<int>> result;
        solve(nums, 0, temp, result);

        return result;
    }
};

//! total number of subsequences that sum equal to k
void countSubsequence(vector<int> & arr, int k , int index, int sum , vector<vector<int>> &result, vector<int> &temp){
    if(index == arr.size()){
        if(sum == k){
           result.push_back(temp);
        }
        return;
    }

    // add the element in the temp
    temp.push_back(arr[index]);

    // add in the sum 
    sum += arr[index];

    // recursive call 
    countSubsequence(arr, k, index + 1, sum, result, temp);

    // remove the element from the temp
    temp.pop_back();

    // remove the sum
    sum -= arr[index];

    // recursive call
    countSubsequence(arr, k, index + 1, sum, result, temp);
    // time complexity : O(2^n) sc : O(2^n) since we are storing all the possible combination in worst we might have to store all the possible combination

}

//! subset sum problem
//!  Problem statement
// You are given an array 'A' of 'N' integers. You have to return true if there exists a subset of elements of 'A' that sums up to 'K'. Otherwise, return false.
bool solve(vector<int>& a, int k, int index, int sum) {
    if (index == a.size()) {
        return sum == k;  // Return true if we find a valid subset
    }

    // Take the element
    if (solve(a, k, index + 1, sum + a[index])) {
        return true;
    }

    // Not take the element
    if (solve(a, k, index + 1, sum)) {
        return true;
    }

    return false;  // No valid subset found
}

bool isSubsetPresent(int k, vector<int> &a)
{
    // Write your code here
    return solve(a, k , 0, 0);
}

//! combination sum I
// find all the combination of the element that sum up to the target
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]] 
class Combination_Sum
{
public:
    void solve(vector<int> &candidates, int target, int ind, vector<int> &temp,
               vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(temp);
            return;
        }
        if (target < 0 || ind >= candidates.size())
            return;

        // Include the current element
        temp.push_back(candidates[ind]);
        solve(candidates, target - candidates[ind], ind, temp, result);
        temp.pop_back();

        // Exclude the current element and move to the next index
        solve(candidates, target, ind + 1, temp, result);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        vector<vector<int>> result;
        solve(candidates, target, 0, temp, result);
        return result;
    }
};

//! combination sum II
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
void solve(vector<int> &candidates, int target, int ind, vector<int> &temp,
           vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(temp);
        return;
    }
    for(int i = ind; i < candidates.size(); i++){
        if(i > ind && candidates[i] == candidates[i - 1]){
            continue;
        }
        if(target - candidates[i] < 0){
            break;
        }
        temp.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1, temp, result);
        temp.pop_back();
    }

    // // Include the current element
    // temp.push_back(candidates[ind]);
    // solve(candidates, target - candidates[ind], ind + 1, temp, result);
    // temp.pop_back();

    // // Skip the duplicates
    // while (ind + 1 < candidates.size() && candidates[ind] == candidates[ind + 1])
    //     ind++;

    // // Exclude the current element and move to the next index
    // solve(candidates, target, ind + 1, temp, result);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    vector<vector<int>> result;
    solve(candidates, target, 0, temp, result);
    return result;
}

//! Subset Sums I
// Given a array arr of integers, return the sums of all subsets in the list.  Return the sums in any order 
// Input: arr = [1, 2, 3]  Output: [0, 1, 2, 3, 4, 5, 6]
class Subset_Sums_every_possible_combination
{
public:
    void solve(vector<int> &arr, int ind, int sum, vector<int> &result)
    {
        if (ind == arr.size())
        {
            result.push_back(sum);
            return;
        }

        sum += arr[ind];

        solve(arr, ind + 1, sum, result);

        sum -= arr[ind];
        solve(arr, ind + 1, sum, result);
    }
    vector<int> Sums(vector<int> &arr)
    {
        // code here
        vector<int> result;
        solve(arr, 0, 0, result);
        sort(result.begin(), result.end());
        return result;
    }
};

//! 90 subset II
void solve(vector<int>& nums, int index, vector<int> &temp, vector<vector<int>> &result)
{
    result.push_back(temp);
    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1]) continue;
        temp.push_back(nums[i]);
        solve(nums, i + 1, temp, result);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    vector<int> temp;
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    solve(nums, 0, temp, result);
    return result;
}

//! combination sum III
class Combination_Sum_III
{
public:
    void solve(int n, int k, int index, int sum, vector<int> &temp,
               vector<vector<int>> &result)
    {

        if (index > 9)
        {
            if (sum == n && temp.size() == k)
            {
                result.push_back(temp);
            }
            return;
        }
        temp.push_back(index);
        solve(n, k, index + 1, sum + index, temp, result);
        temp.pop_back();
        solve(n, k, index + 1, sum, temp, result);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> temp;
        vector<vector<int>> result;
        solve(n, k, 1, 0, temp, result);
        return result;
    }
};

//! Letter Combinations of a Phone Number
class  Letter_Combinations
{
public:
    vector<string> result;

    void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp)
    {

        if (idx >= digits.length())
        {
            result.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string str = mp[ch];

        for (int i = 0; i < str.length(); i++)
        {

            // Do
            temp.push_back(str[i]);
            solve(idx + 1, digits, temp, mp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};

        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";

        solve(0, digits, temp, mp);

        return result;
    }
};

//^                               Hard Problem 

//! palindrome partitioning 
class palindrome_partitioning{
public:
    vector<vector<string>> result;
    bool ispalindrome(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void solve(string s, int index, vector<string> &temp){
        if(index == s.size()){
            result.push_back(temp);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(ispalindrome(s, index, i)){
                temp.push_back(s.substr(index, i - index + 1));
                solve(s, i + 1, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s){
        vector<string> temp;
        solve(s, 0, temp);
        return result;
    }
    // time complexity : O(n*2^n) sc : O(n)
};

//! Word Search
/*Space Complexity: O(L)
Time Complexity: O(M * N * 3^L)
Space Complexity is because of recursion - to store function stack context.
Time Complexity - from every block we go in three adjacent blocks (avoiding the direction we came from).
This walk can go for max of L times. So each thred at most goes L length long. -> O(3^L).
Now this is applied at each node from main calling function -> O(M * N). Therefore, O(M * N * 3^L).
*/
class Word_Search
{
public:
    int l, m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool find(vector<vector<char>> &board, int i, int j, string &word, int idx)
    {
        if (idx >= l)
            return true;

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto &dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (find(board, i_, j_, word, idx + 1))
                return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        l = word.length();
        if (m * n < l)
            return false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0] && find(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

//! N-Queens problems
// Approach-1 (Simple dfs)
// T.C : O(N!) - Read the reason above
// S.C : O(N) to store the result
class  N_Queens
{
public:
    vector<vector<string>> result;
    bool isValid(vector<string> &board, int row, int col)
    {
        // look for up
        for (int i = row; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
                return false;
        }

        // check left diagonal upwards
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        // check right diagonal upwards
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        /*
            Wait a second, Why didn't I check any squares downwards ???
            If you notice, every time I am calling dfs(board, row+1); i.e. after
            placing a Queen at a row, I move down. So, It's guaranteed I will
            not get any Queen downwards.
            Example :

            For n = 4

                    _   _    _  Q   (Put int the first row)
                    Q  _   _   _    (While putting here, I only need to see
           above of me because I have not populated any Q in downwards) _   _ Q
           _    (Same,  While putting here, I only need to see above of me
           because I have not populated any Q in downwards)

                    So, on

    */

        return true;
    }
    void solve(vector<string> &board, int row)
    {
        if (row == board.size())
        {
            result.push_back(board);
            return;
        }

        /*
            place one queen at every row and check before placing
            in every directions where there is risk if being attackes
            i.e. up, diagonally because we are placing queens from
            top row to bottom row, so we need to check if we put a queen
            vertically up in some row or diagonally upwards in some row
        */
        for (int i = 0; i < board.size(); i++)
        {
            if (isValid(board, row, i))
            {
                board[row][i] = 'Q';

                solve(board, row + 1);

                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        if (n == 0)
            return {};
        vector<string> board(n, string(n, '.'));
        // For, n = 3, board = {"...", "...", "..."} initially

        solve(board, 0);

        return result;
    }
};

//! word search problem 
// Space Complexity: O(L)
// Time Complexity: O(M * N * 3^L)
class  word_search
{
public:
    int l, m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool find(vector<vector<char>> &board, int i, int j, string &word, int idx)
    {
        if (idx >= l)
            return true;

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto &dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (find(board, i_, j_, word, idx + 1))
                return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        l = word.length();
        if (m * n < l)
            return false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0] && find(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

//! Rat in a maze
void solve(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans,
           string move, vector<vector<int>> &visited)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    // Mark as visited before making recursive calls
    visited[i][j] = 1;

    // Move Down
    if (i + 1 < n && !visited[i + 1][j] && mat[i + 1][j] == 1)
        solve(i + 1, j, mat, n, ans, move + 'D', visited);

    // Move Left
    if (j - 1 >= 0 && !visited[i][j - 1] && mat[i][j - 1] == 1)
        solve(i, j - 1, mat, n, ans, move + 'L', visited);

    // Move Right
    if (j + 1 < n && !visited[i][j + 1] && mat[i][j + 1] == 1)
        solve(i, j + 1, mat, n, ans, move + 'R', visited);

    // Move Up
    if (i - 1 >= 0 && !visited[i - 1][j] && mat[i - 1][j] == 1)
        solve(i - 1, j, mat, n, ans, move + 'U', visited);

    // Unmark before backtracking
    visited[i][j] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    if(m[0][0] == 1){
        solve(0, 0, m, n, ans, "", visited);
    }
    return ans;
}

//! word break problem
bool solve(int id, string &s, vector<string> &dict)
{
    if (id == s.size())
    {
        return true;
    }

    // if s as whole string present in the dictionary then return true
    // for example s = "s" and dict = ["s"] then return true
    if (find(dict.begin(), dict.end(), s) != dict.end())
    {
        return true;
    }

    // now we will check for all the possible substring of the string s
    for (int i = 1; i < s.size(); i++)
    {

        // get the substring of the string s
        string temp = s.substr(id, i);
        // find the substring in the dictionary
        // if found then call the recursion for the rest of the string
        if (find(dict.begin(), dict.end(), temp) != dict.end() && solve(id + i, s, dict))
        {
            return true;
        }
    }
    // if nothing found then return false
    return false;
}
bool wordBreak(string s, vector<string> &wordDict)
{

    return solve(0, s, wordDict);
}

//! M-Coloring Problem
class M_Coloring
{
public:
    bool isSafe(int node, vector<int> &color, vector<vector<int>> &adj, int col)
    {
        for (int neighbor : adj[node])
        {
            if (color[neighbor] == col)
                return false; // Adjacent node has the same color
        }
        return true;
    }

    bool solve(int node, int v, vector<int> &color, vector<vector<int>> &adj, int m)
    {
        if (node == v)
            return true; // All nodes are colored

        for (int i = 1; i <= m; i++)
        { // Try different colors
            if (isSafe(node, color, adj, i))
            {
                color[node] = i;
                if (solve(node + 1, v, color, adj, m))
                    return true; // Recursive call
                color[node] = 0; // Backtrack
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<pair<int, int>> &edges, int m)
    {
        vector<vector<int>> adj(v); // Adjacency list
        for (auto &edge : edges)
        {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }

        vector<int> color(v, 0);           // Initialize color array
        return solve(0, v, color, adj, m); // Start from node 0
    }
};

//! sudoku solver 
// rules :
// 1. Each row must have the numbers 1-9 occuring just once. 
// 2. Each column must have the numbers 1-9 occuring just once.
// 3. And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.

class Sudoku_Solver
{

public:
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            // check for the row
            if (board[i][col] == c)
                return false;
            // check for the column
            if (board[row][i] == c)
                return false;
            // check for the 3*3 grid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        // if no false return true 
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        // traverse the board 
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // find the empty cell
                if (board[i][j] == '.')
                {
                    // try all the possible number from 1 to 9 
                    for (char c = '1'; c <= '9'; c++)
                    {
                        // check if the number is valid or not 
                        if (isValid(board, i, j, c))
                        {
                            // if valid then put the number in the cell 
                            board[i][j] = c;
                            
                            // recursive call for the rest of the board if all possible combination 
                            // for board find then return true since we have to only return one 
                            // solution 
                            if (solve(board))
                                return true;
                            else
                            // remove the character
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
    // time complexity : O(9^(n^2)) n = 9 at worst case 9^81 = 981≈1.96×10^77
    //  sc : O(n^2) 
};

//! Expression Add Operators
// given a string expression  string exp = "123" and a target value target = 6 
// we have to add the operator + , - , * in between the string to get the target value 
// we have to return all the possible combination of the string that will give the target value

class Expression_Add_Operators
{
public:
    vector<string> ans;

    vector<string> addOperators(string s, int target)
    {
        helper(s, target, 0, "", 0, 0);
        return ans;
    }

    void helper(string s, int target, int i, const string &path, long eval, long residual)
    {
        // Base Case: If end of string is reached
        if (i == s.length())
        {
            if (eval == target)
            {
                ans.push_back(path);
            }
            return;
        }

        string currStr;
        long num = 0;

        // Backtracking loop
        for (int j = i; j < s.length(); j++)
        {
            // Handle leading zeros
            if (j > i && s[i] == '0')
                return;

            currStr += s[j];
            num = num * 10 + (s[j] - '0');

            if (i == 0)
            {
                // Starting case (no operator before the first number)
                helper(s, target, j + 1, path + currStr, num, num);
            }
            else
            {
                // '+' Operation
                helper(s, target, j + 1, path + "+" + currStr, eval + num, num);
                // '-' Operation
                helper(s, target, j + 1, path + "-" + currStr, eval - num, -num);
                // '*' Operation
                helper(s, target, j + 1, path + "*" + currStr, eval - residual + residual * num, residual * num);
            }
        }
    }
    // time complexity : O(4^n) sc : O(n) 
};

int main()
{
    //!--------------------->  recursion  <---------------------

    //? print 1 to n using recursion
    // print(5);
    // cout << endl;
    // cout << print1toN(5) << endl;

    //? factorial using recursion
    // cout << fact(5) << endl; // 120
    // cout << fact(0) << endl; // 1
    // cout << fact(1) << endl; // 1
    // cout << fact(2) << endl; // 2

    //? height of binary tree using recursion
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // cout << height(root) << endl; // 3

    //? sort an array using recursion and insert element using loop
    // int arr[] = {5, 4, 3, 2, 1};
    // sort(arr, 5);
    // for(int i = 0; i < 5; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //? both insert element and sort array using recursion
    // vector<int> arr = {5, 4, 3, 2, 1};
    // for (int i = 0; i < arr.size(); i++){
    //     cout << arr[i] << " ";
    // }cout << endl;
    // sortArray(arr);
    // for(int i = 0; i < 5; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //? sort stack using recursion
    // stack<int> st;
    // st.push(5);
    // st.push(4);
    // st.push(3);
    // st.push(2);
    // st.push(1);
    // sortStack(st);
    // while(!st.empty()){
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;

    //? delete the middle element of the stack using recursion
    // stack<int> st;
    // st.push(5);
    // st.push(4);
    // st.push(3);
    // st.push(2);
    // st.push(1);
    // deleteMiddleElement(st, st.size() / 2 + 1);
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;

    //? Revere stack using recursion
    // stack<int> st;
    // st.push(5);
    // st.push(4);
    // st.push(3);
    // st.push(2);
    // st.push(1);
    // reverseStack(st);
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;

    //? K-th symbol in grammar
    // kthSymbol(4, 5); // 1
    // kthSymbol(3, 3); // 1
    // kthSymbol(1, 1); // 0

    //? Tower of Hanoi
    // int n = 3;
    // char A = 'A', B = 'B', C = 'C';
    // towerOfHanoi(n, A, B, C);
    // cout << endl;
    
    //? string to integer  stringAtoi
    // string str = "12345";
    // cout << stringAtoi(str, str.size()) << endl; // 12345

    //? count good numbers
    // Solution s;
    // cout << s.countGoodNumbers(4) << endl; //50-> 564908303
    
    //? Generate all binary strings without consecutive 1's
    // generateBinaryStrings(5, "", '0');

    //? Generate Parenthesis using Recursion
    // parenthesis p;
    // vector<string> result = p.generatepararenthesis(5);
    // for(string s : result){
    //     cout << s << endl;
    // }
    // string s = p.generateallpossible(3, 3, "");
    // for(string s : p.result){
    //     cout << s << endl;
    // }

    //? print all Subset of a string using recursion
    // cout << subset("abc") << endl;

    //? subset of the number using recursion
    // Subsets s;
    // vector<int> nums = {1, 2, 3};
    // vector<vector<int>> result = s.subsets(nums);
    // for (vector<int> v : result)
    // {
    //     for (int i : v)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    //? total number of subsequences that sum equal to k
    // vector<int> arr = {1, 2, 3, 4, 5}; // 3
    // vector<vector<int>> result;
    // vector<int> temp;
    // countSubsequence(arr, 10, 0, 0, result, temp);
    // for (vector<int> v : result)
    // {
    //     for (int i : v)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    //? subset sum problem
    // vector<int> a = {1, 2, 3, 4};
    // int k = 5;
    // cout << isSubsetPresent(4, a) << endl; // 1

    //? combination sum I
    // vector<int> candidates = {2, 3, 6, 7}; combination are ( 2 2 3 ) - 7   // ( 7 ) - 7
    // int target = 7;
    // Combination_Sum c;
    // vector<vector<int>> result = c.combinationSum(candidates, target);
    // for (vector<int> v : result)
    // {
    //     for (int i : v)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }  

    //? combination sum II
    // vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    // int target = 8;
    // vector<vector<int>> result = combinationSum2(candidates, target);
    // for (vector<int> v : result)
    // {
    //     for (int i : v)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    //? Subset Sums I
    // vector<int> arr = {1, 2, 3};
    // Subset_Sums_every_possible_combination s;
    // vector<int> result = s.Sums(arr); // 0 1 2 3 4 5 6 
    // for (int i : result)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    //? 90 subset II 
    // vector<int> nums = {1, 2, 2};
    // vector<vector<int>> result = subsetsWithDup(nums);
    // for (vector<int> v : result)
    // {
    //     for (int i : v)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    //? combination sum III
    // int k = 3, n = 20; 
    // Combination_Sum_III c;
    // vector<vector<int>> result = c.combinationSum3(k, n);
    // if(result.size() == 0) cout<<"No combination found"<<endl;
    // for (vector<int> v : result)
    // {    
    //     for (int i : v)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << " subset that sum : " << n << endl;
    // }

    //? Letter Combinations of a Phone Number
    // Solution s;
    // vector<string> result = s.letterCombinations("23");
    // for (string s : result)
    // {
    //     cout << s << endl;
    // }

    //? palindrome partitioning
    // palindrome_partitioning p;
    // vector<vector<string>> result = p.partition("aab");
    // for (vector<string> v : result)
    // {
    //     for (string s : v)
    //     {
    //         cout << s << " ";
    //     }
    //     cout << endl;
    // }

    //? Word Search
    // word_search w;
    // vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // string word = "ABCCED";
    // if(w.exist(board, word)){
    //     cout << "Word found" << endl;
    // }else{
    //     cout << "Word not found" << endl;
    // }

    //? Rat in a maze
    // vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    // vector<string> result = findPath(m, 4);
    // for (string s : result)
    // {
    //     cout << s << " ";
    // }
    // cout << endl;

    //? word break problem
    // vector<string> dict = {"leet", "code"};
    // string s = "leetcode";
    // cout << wordBreak(s, dict) << endl;

    //? M-Coloring Problem
    // M_Coloring m;
    // vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    // cout << m.graphColoring(3, edges, 3) << endl;

    //? sudoku solver
    // Sudoku_Solver s;
    // vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
    //                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    // s.solveSudoku(board);
    // for (vector<char> v : board)
    // {
    //     for (char c : v)
    //     {
    //         cout << c << " ";
    //     }
    //     cout << endl;
    // }

    //? Expression Add Operators    
    Expression_Add_Operators e;
    vector<string> result = e.addOperators("123", 6);
    for (string s : result)
    {
        cout << s << endl;
    }



    return 0;
}