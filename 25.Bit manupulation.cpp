#include <bits/stdc++.h>
#include <iostream>


using namespace std;

//! bit manipulation
// all bitwise operators

//~ 1. AND &
// in & operation if both the bits are 1 then the result is 1
// suppose n = 13; 1101 and m = 11; 1011
// 1 1 0 1
// 1 0 1 1
// 1 0 0 1 --> 9

//~ 2. OR |
// in | operation if any of the bit is 1 then the result is 1
// suppose n = 13; 1101 and m = 11; 1011
// 1 1 0 1
// 1 0 1 1
// 1 1 1 1 --> 15

//~ 3. XOR ^
// in ^ operation if both the bits are different then the result is 1
// suppose n = 13; 1101 and m = 11; 1011
// 1 1 0 1
// 1 0 1 1
// 0 1 1 0 --> 6

//~ 4. NOT ~
// in ~ operation if the bit is 1 then the result is 0
// suppose n = 13; 1101
// ~n = -14

//~ 5. Left shift <<
// in << operation the bits are shifted to the left
// suppose n = 13; 1101
// n << 1 = 11010 --> 26

//~ 6. Right shift >>
// in >> operation the bits are shifted to the right
// suppose n = 13; 1101
// n >> 1 = 0110 --> 6

// how to calculate the binary to decimal using 2^index and bit representation
/*
   13 in binary 1 1 0 1
                   ------> binary indeixng <---------
    1   1   0   1 --> binary representation of 13
    4   3   2   1 --> index
    1*2^3 + 1*2^2 + 0*2^1 + 1*2^0
    8   4   2   1 = 13

   for converting to decimal value get bit multiply by 2^index
   2^0 = 1  2^3 = 8   2^6 = 64   2^9 = 512    2^12 = 4096
   2^1 = 2  2^4 = 16  2^7 = 128  2^10 = 1024  2^13 = 8192
   2^2 = 4  2^5 = 32  2^8 = 256  2^11 = 2048  2^14 = 16384

   2^15 = 32768      2^18 = 262144      2^21 = 2097152
   2^16 = 65536      2^19 = 524288      2^22 = 4194304
   2^17 = 131072     2^20 = 1048576     2^23 = 8388608

*/
//! Function to convert decimal to binary
string decimalToBinary(int n)
{
    string s = "";
    while (n != 0)
    {
        if (n % 2 == 1)
            s = "1" + s;
        else
            s = "0" + s;
        n = n / 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

//! binary to decimal
int binaryToDecimal(int n)
{
    int ans = 0;
    int x = 1;
    while (n > 0)
    {
        int y = n % 10;
        ans += x * y;
        x *= 2;
        n /= 10;
    }
    return ans;
}

//! swap  two numbers using XOR
void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

//! check kth bit is set or not using left shift
bool checkKthBit(int n, int k)
{
    // k -1 works when we consider 1 based indexing
    // if (n & (1 << (k - 1)) != 0) return true;
    if (n & (1 << k) != 0)
        return true;

    else
        return false;
}

//! check the kth bit is set or not using right shift
bool checkKthBitRightShift(int n, int k)
{
    // k - 1  works when its 1 based indexing
    // if ((n >> (k - 1)) & 1 == 1) return true;
    if ((n >> k) & 1 == 1)
        return true;

    else
        return false;
}

//! set kth bit
void setithBit(int &n, int k)
{
    n = n | (1 << k);

    // suppose n = 5; 101
    // k = 1; 001
    // 1 << k = 010
    // n | (1 << k)
    // in or operation if any of the bit is 1 then the result is 1
    // 101
    // 010
    // 111 --> 7
}

//! clearing the ith bit
void clearithBit(int &n, int k)
{
    n = n & (~(1 << k));
    // n = 5; 101
    // k = 2; 010

    // 1 << k = 100
    // ~(1 << k) = 011
    // n & ~(1 << k) = 101 & 011 = 001
    // n = 1
    // 1 in decimal
    // in and operation if both the bits are 1 then the result is 1
}

//! toggle the ith bit
void toggleithBit(int &n, int k)
{
    n = n ^ (1 << k);
    // n = 5; 101
    // k = 2; 010

    // 1 << k = 100
    // n ^ (1 << k) = 101 ^ 100 = 001
    // n = 1
    // 1 in decimal
    // in xor operation if both the bits are different then the result is 1
    // toggle the bit means if the bit is 1 then make it 0 and if the bit is 0 then make it 1
    // If ‘N’ = 12 and ‘K’ = 2:
    // The binary representation of 12 is ‘1100’, after toggling rightmost 2 bits, it becomes ‘1111’ i.e. 15. Hence, the answer is 15.
}

//! toggle the bits upto k place
int toggleKBits(int n, int k)
{

    //  toggele bits
    // If the bit is 0, it becomes 1.
    // If the bit is 1, it becomes 0.
    // upto to given kth option    3 2 1 0 <--index
    // for example 12 in binary is 1 1 0 0  k = 2
    // so we have to toggel the bits upto 2th index

    // <-------------- code -------------->
    int mask = (1 << k) - 1;
    return n ^ mask;

    // 12 in binary
    // 1100

    // the mask process we are shifting the 1 0001 left shift by k time
    // k = 2 0100 it become 4 (0100 is 4 in decimal)
    // minus the 1 form 4
    // int mask become 3 in binary // 0 0 1 1

    // now or with n note:--> in the OR operation any of the bit is 1 then result of it 1

    // n = 12 in binary
    // 1 1 0 0
    // 0 0 1 1
    // 1 1 1 1 --> become in decimal (15)
}

//! remove the last set bit or the rightmost set bit
int removeLastSetBit(int n)
{
    return n & (n - 1);

    // n = 12 in binary
    // 1 1 0 0
    // 1 0 1 1 --> 11
    // 1 0 0 0 --> 8
    // 1 0 0 0 --> 8 in decimal
}

//! count the number of set bits
int countSetBits(int n)
{
    int count = 0;
    while (n > 1)
    {
        if (n % 2 == 1)
            count++;
        n = n / 2;
    }
    if (n == 1)
        count++;
    return count;

    // n = 12 in binary 1 1 0 0
    // 12%2=0 count = 0 12/2=6 n = 6
    // 6%2=0 count = 0 6/2=3 n = 3
    // 3%2=1 count = 1 3/2=1 n = 1
    // 1%2=1 count = 2 1/2=0 n = 0
    // count = 2
}

//! count the set bits from 1 to n
int countSetBitsFrom1ToN(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += countSetBits(i);
    }
    return count;

    // 1 to n = 12
    // binary        decimal     set bits
    // 0  0  0  1      1           1
    // 0  0  1  0      2           1
    // 0  0  1  1      3           2
    // 0  1  0  0      4           1
    // 0  1  0  1      5           2
    // 0  1  1  0      6           2
    // 0  1  1  1      7           3
    // 1  0  0  0      8           1
    // 1  0  0  1      9           2
    // 1  0  1  0      10          2
    // 1  0  1  1      11          3
    // 1  1  0  0      12          2

    // total set bits = 1 + 1 + 2 + 1 + 2 + 2 + 3 + 1 + 2 + 2 + 3 + 2 = 22
}

// count the number of set bits optimal approach
int countSetBitsOptimal(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
    // TC = O(number of set bits)
    // SC = O(1)
}

// check if the number is odd or even
bool isOdd(int n)
{
    return (n & 1);
    // if the last bit is 1 then the number is odd
    // if the last bit is 0 then the number is even

    // bit  flip in & operation like  only 1 & 1 = 1 otherwise 0
    // 5 in binary 101
    // 1 in binary 001
    // 5 & 1
    // 1 0 1
    // 0 0 1
    // 0 0 1 --> 1 output is 1 the number is odd

    // 1 & 1 = 1
    // 4 & 1 = 0 even
    // 1  0  0
    // 0  0  1
    // 0  0  0 --> 0 output is 0 the number is even
}

// check if the number is power of 2
bool isPowerOf2(int n)
{

    if (n <= 0)
        return false;
    return (n & (n - 1)) == 0;

    // if the number is power of 2 then the number is 1
    // if the number is not power of 2 then the number is 0

    // 4 in binary 100
    // 3 in binary 011
    // 4 & 3
    // 1 0 0
    // 0 1 1
    // 0 0 0 --> 0 output is 0 the number is not power of 2

    // 4 in binary 100
    // 3 in binary 011
    // 4 & 4
    // 1 0 0
    // 1 0 0
    // 1 0 0 --> 4 output is 4 the number is power of 2
    // TC = O(1)
    // SC = O(1)

    // Approach Bit Manipulation
    // if the number is power of 2 then in its binary atleast one bit is set
    // so if we do n & (n-1) then the result is 0
    // suppose n = 16
    // 16 in binary 10000
    // 16 - 1 = 15
    // 15 in binary 01111
    // 10000
    // 01111
    // 00000  so the number is power of 2

    // suppose n = 10
    // 10 in binary 1010
    // 10 - 1 = 9
    // 9 in binary 1001
    // 1010
    // 1001
    // 1000 so the number is not power of 2
}

// brute force approach to find the power of 2
int powerOf2(int n)
{
    int count = 0;
    while (n > 1)
    {
        n = n / 2;
        count++;
    }
    return count;
    // n = 16
    // 16/2 = 8 count = 1
    // 8/2 = 4 count = 2
    // 4/2 = 2 count = 3
    // 2/2 = 1 count = 4
    // n = 1 return 4

    // n =10
    // 10/2 = 5 count = 1
    // 5/2 = 2 count = 2
    // 2/2 = 1 count = 3
}

// divid two integers without using division and multiplication operator
int divide(int divisor, int dividend)
{
    if (dividend == divisor)
        return 1;

    bool sign = true;
    if (dividend >= 0 && divisor < 0)
        sign = false;

    else if (dividend <= 0 && divisor > 0)
        sign = false;

    long n = abs(dividend);
    long m = abs(divisor);

    divisor = abs(divisor);

    long quaotient = 0;

    while (n >= m)
    {
        int cnt = 0;
        while (n >= (m << (cnt + 1)))
        {
            cnt += 1;
        }

        quaotient += 1 << cnt;
        n -= m << cnt;
    }

    if (quaotient == (1 << 31) && sign)
        return INT_MAX;

    if (quaotient == (1 << 31) && !sign)
        return INT_MIN;

    return sign ? quaotient : -quaotient;
}

// for counting the number of bits to we have to flip to convert A to B
// we have to only flip those bits which are different in A and B
// for example
// A = 10; 1  0  1  0  B = 7;  0  1  1  1

// for making 10 to 7 we have to flip 3 bits we dont have to change the
// same bits like 1 and 1 we have to only change those bit that are different
// from each other like 1 and 0 or 0 and 1

// so we have to do use XOR and get the A XOR B for count the number of set bits

// for example A = 10 ^ B = 7;
// 1  0  1  0
// 0  1  1  1
// 1  1  0  1 --> 13
// answer is 13 but we just somehow calculate result set bits then we get the answer number of  bit required to convert A to B

// we can count the set bits by two approach
// 1. we can check each bit by using the result = a ^ b and then check each bit by using the result & (1<<i)
// using result = a ^ b
// result & (1<<i)  this will give the number of set bits
// for example 13 & (1<<0) = 1
// 13 & (1<<1) = 0
// 13 & (1<<2) = 1
// 13 & (1<<3) = 1
// so the output is 3

// and check each time of divion that remender is 1 or 0
// and check each time of divion that remender is 1 or 0
// if it is 1 then increment the count
// for example 13/2 = 6 remender = 1 count = 1
// 6/2 = 3 remender = 0 count = 1
// 3/2 = 1 remender = 1 count = 2
// 1/2 = 0 remender = 1 count = 3
// therefore the output is 3

// mininum bit flip to convert A to B
int minBitFlip(int a, int b)
{
    int count = 0;
    int c = a ^ b;
    for (int i = 0; i <= 31; i++)
    {
        // checking if the ith bit is set or not
        if (c & (1 << i))
            count++;
    }
    return count;
    
}

int HowManyBitsToFlip(int a, int b)
{
    int count = 0;
    int c = a ^ b;
    while (c > 0)
    {
        if (c % 2 == 1)
            count++;
        c = c / 2;
    }
    return count;

    // int a = 10; // 1010
    // int b = 7;  // 0111
    // a ^ b = 1010 ^ 0111 = 1101
}

// single number in the arra
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;

    // TC = O(n)
    // SC = O(1)

    // 2 2 1 1 3
    // 2^2^1^1^3
    // 2^2 = 0  1^1 = 0  0^3 = 3
    // tharefore the output is 3
}

// subset using bit manipulation
vector<vector<int>> subset(vector<int> &nums)
{

    int n = nums.size();
    vector<vector<int>> ans;
    // loop from 0 to 2^n 1 times
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> v;

        for (int j = 0; j < n; j++)
        {
            // if the ith bit is set 
            // then we are storing the jth number element from the array 

            if (i & (1 << j)) // check the ith bit is set or not that means if the result is any integer except 0 we are storing the jth element from the array in the vector as an subset  
            {
                v.push_back(nums[j]);
            }
        }
        // puhsing the single vector as an subset in the vector of vector or 2D vector
        ans.push_back(v);
    }
    return ans;
    // for example nums = {1, 2, 3} 2^n = 2^3 = 8
    // subset are [] [1] [2] [3] [1, 2] [1, 3] [2, 3] [1, 2, 3]
    //            1   2   3   4     5      6      7       8

    // first we go form  0 to 2^n - 1
    // then we go from 0 to n
    // then we check if the ith bit is set or not
    // for 2^3 = 8
    // 3 2 1 0
    // 0 0 0 0  []    (0 & (1 << j)) 0 & 1 = 0  0 & 2 = 0  0 & 4 = 0
    // 0 0 0 1  [1]   (1 & (1 << j)) 1 & 1 = 1
    // 0 0 1 0  [2]   (2 & (1 << j)) 2 & 1 = 0 
    // 0 0 1 1  [1, 2] (3 & (1 << j)) 3 & 1 = 1  3 & 2 = 2
    // 0 1 0 0  [3]  (4 & (1 << j)) 4 & 1 = 0
    // 0 1 0 1  [1, 3] (5 & (1 << j)) 5 & 1 = 1  
    // 0 1 1 0  [2, 3] (6 & (1 << j)) 6 & 1 = 0  6 & 2 = 2
    // 0 1 1 1  [1, 2, 3] (7 & (1 << j)) 7 & 1 = 1  7 & 2 = 2  7 & 4 = 4
    

    // subset are stored in the vector vector like
    // vector = {[],
    //          [1],
    //          [2],
    //          [3],
    //          [1, 2],
    //          [1, 3],
    //          [2, 3],
    //          [1, 2, 3]
    // }

    // TC = O(2^n)
    // SC = O(n * 2^n)
}

// single number in the array single number III
vector<int> singleNumberIII(vector<int> &nums){
    // example nums = {1, 2, 1, 3, 2, 5}
    int n = nums.size();
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ nums[i];
    }

    long int rightmost = xorr & -(long long )xorr;

    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & (1 << rightmost))
        {
            a = a ^ nums[i];
        }
        else
        {
            b = b ^ nums[i];
        }
    }
    return {a, b};
    // TC = O(n)
    // SC = O(1)
}


//!------> Advance Maths Questions using Bit Manipulation  ------------------->
// print the prime factors of the number prime factors means the number that is divisible by the number
bool prime(int n)
{
    for (int i = 2;  i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}


void primeFactors(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n = n / i;
            }
            cout << i << " " << count << endl;
        }
    }
    if (n > 1)
    {
        cout << n << " " << 1 << endl;
    }
}

// print all devisors of the number
void allDevisors(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i)
            {
                cout << n / i << " ";
            }
        }
    }
}

//  Sieve of Eratosthenes algorithm for prime numbers 
void sieve_Eratosthenes(int N) {
    
    vector<int> prime(N+1, 1);  // Create a boolean array and initialize all entries as true.
    prime[0] = prime[1] = 0;    // 0 and 1 are not prime numbers.

    for (int i = 2; i * i <= N; i++) {
        if (prime[i] == 1) {    // If i is prime
            for (int j = i * i; j <= N; j += i) {
                prime[j] = 0;   // Mark all multiples of i as not prime
            }
        }
    }

    // Output all prime numbers
    for (int i = 2; i <= N; i++) {
        if (prime[i] == 1)
            cout << i << " ";
    }
}

//! power of (X , N) using bit manipulation
// work by making the power and the nuber smaller by 1 if the power is odd then multiply the ans with the number

// for example x = 2 and n = 3
// 2^3 = 2 * 2^2 = 2 * 4 = 8

// for example x = 2 and n = 21
// since power is odd then multiply the ans with the number
// we multiply the number with 2 and reduce the power by 1
// (2*2)^20/2
// 4^10
// now the power is even then multiply the number with itself and reduce the power by 2
// (4*4)^10/4   10/4 = 2
// 16^2 
// now the power is even then multiply the number with itself and reduce the power by 2
// (16*16)^2/2 
// 256^1
// now the power is odd then multiply the ans with the number
// (256*256)^1/2  1/2 = 0
// 65536
// now the power is odd then multiply the ans with the number
// (16*16)^4/8

// 2^21 = 2 * 2^20 = 2 * 1048576 = 2097152

int power(int x, int n)
{
    int ans = 1;
    int m = n;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = ans * x;
            n = n - 1;
        }
        else
        {
            x = x * x;
            n = n / 2;
        }
       
    }
    if(m < 0) ans = 1/ans;
    return ans;
}

// power of (X , N) using bit manipulation for nagative power
double power(double x, int n)
{
     double ans = 1;
        long long m = n;  // Use long long to handle negative n properly

        if (m < 0) {
            m = -m;  // Make the exponent positive for now
        }

        while (m > 0) {
            if (m % 2 == 1) {
                ans = ans * x;
                m = m - 1;
            } else {
                x = x * x;
                m = m / 2;
            }
        }

        if (n < 0) {
            ans = 1.0 / ans;  // Handle negative exponent
        }

        return ans;
}

//! Prime Factorization using Sieve


int main()
{
    //! int n = 10; // 1010 in binary
    // cout << decimalToBinary(n) << endl;

    //! binary to decimal
    // int n = 1010111; // 87 in decimal
    // cout << binaryToDecimal(n) << endl;

    //! function for swapping two numbers using XOR
    // int a = 5, b = 7;
    // cout << "before swapping " << a << " " << b << endl;
    // swap(a, b);
    // cout << "after swapping " << a << " " << b << endl;

    //! check kth bit is set or not
    // int n = 5;
    // int k = 2;
    // cout << checkKthBit(n, k) << endl; 
    // cout << checkKthBitRightShift(n, k) << endl;

    //! set kth bit
    // int n = 5; // 101
    // int k = 1;
    // setithBit(n, k);
    // cout << n << endl;

    //! clear kth bit
    // int n = 5; // 101
    // int k = 3;
    // clearithBit(n, k);
    // cout << n << endl;

    //! toggle kth bit
    // int n = 3; // 011
    // int k = 2; // 010
    // toggleithBit(n, k);
    // cout << n << endl;

    //! toggle the bits upto k place
    // int n = 12;
    // int k = 2;
    // cout << toggleKBits(n, k) << endl;

    //! remove the last set bit or the rightmost set bit
    // int n = 12; // 1100
    // cout << removeLastSetBit(n) << endl;

    //! count the number of set bits
    // int n  = 12; // 1100
    // cout << countSetBits(n) << endl;

    //! count the set bits from 1 to n
    // int n = 12;
    // cout << countSetBitsFrom1ToN(n) << endl;

    //! count the set bits optimal approach
    // int n = 10;
    // int m = 7;
    // cout << HowManyBitsToFlip(n, m);

    //! subset using bit manipulation
    // vector<int> nums = {1, 2, 3};
    // vector<vector<int>> ans = subset(nums);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //! single number in the array
    // vector<int> nums = {1, 2, 1, 3, 2, 5};
    // cout << singleNumber(nums) << endl;

    //! single number in the array single number III
    // vector<int> nums = {1, 2, 1, 3, 2, 5};
    // vector<int> ans = singleNumberIII(nums);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    //! prime factors of the number
    // int n = 12;
    // primeFactors(n);

    //! all devisors of the number
    // int n = 36;
    // allDevisors(n);

    //! sieve of Eratosthenes algorithm for prime numbers
    // int N = 10;
    // sieve_Eratosthenes(N); 

    //! power of (X , N) using bit manipulation
    // int x = 2;
    // int n = 3;
    // cout << power(x, n) << endl; // 8

    //! power of (X , N) using bit manipulation for nagative power
    // double x = 2;
    // int n = -3;
    // cout << power(x, n) << endl; // 0.125


    return 0;
}