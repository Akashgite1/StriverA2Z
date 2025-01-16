#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//~ 2657 find teh prefix common Array of Two Arrays (day-111)
vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B){
    // brute force
    int n = A.size();

    vector<int> result(n);

    // for(int i=0; i<n; i++){
    //     int count = 0;

    //     for(int j=0; j<=i; j++){

    //         for(int k=0; k<=i; k++){

    //             if(A[j] == B[k]){
    //                 count++;
    //                 break;
    //             }
    //         }
    //     }
    //     ans[i] = count;
    // }
    // return ans; // TC O(n^2) SC O(n)

    // n^2 approcah using true and false array

    // vector<int> isPresentA(n+1, false);
    // vector<int> isPresentB(n+1, false);

    // for(int i=0; i<n; i++){
    //     isPresentA[A[i]] = true;
    //     isPresentB[B[i]] = true;

    //     int count = 0;
    //     for(int j=1; j<=n; j++){
    //         // if both are true then increment the count
    //         if(isPresentA[j] && isPresentB[j]){
    //             count++;
    //         }
    //     }
    //     result[i] = count;
    // }
    // return result; // TC O(n^2) SC O(n)

    // optimal apprach using map
    unordered_map<int, int> mp;

    int count = 0;
    for (int i = 0; i < n; i++)
    {

        // put the element in map
        mp[A[i]]++;
        // if the element present in both array then the freq is must be 2
        // since its permutation problem where all elements are unique
        //  and apperaring only once in both arrays
        if (mp[A[i]] == 2)
        {
            count++;
        }

        // put the element in map from array B
        mp[B[i]]++;
        // if the element present in both array then the freq is must be 2
        if (mp[B[i]] == 2)
        {
            count++;
        }

        // store the count in the result array
        result[i] = count;
    }

    return result; // TC O(n) SC O(n)
}

//! 2429. Minimize XOR (day-112)
int setbit(int n)
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

//!  2429. Minimize XOR
int minimizeXor(int num1, int num2)
{

    int num1_set = setbit(num1); // Count set bits in num1
    int num2_set = setbit(num2); // Count set bits in num2

    // If num1 already has the same number of set bits as num2, return num1
    if (num1_set == num2_set)
    {
        return num1;
    }

    // Initialize a variable to store the result
    int result = num1;

    // If num1 has fewer set bits than num2, we need to add set bits
    if (num1_set < num2_set)
    {
        // Add set bits to the least significant positions
        for (int i = 0; i < 32; i++)
        {
            if (((result >> i) & 1) == 0)
            {
                result |= (1 << i); // Set the i-th bit
                num1_set++;
            }
            if (num1_set == num2_set)
                break;
        }
    }

    // If num1 has more set bits than num2, we need to remove set bits
    if (num1_set > num2_set)
    {
        // Remove set bits from the least significant positions
        for (int i = 0; i < 32; i++)
        {
            // right sheft the 1 to ith position and get its and 
            // if the ith position value is 1 then the result is 1 so if 
            // its result is become we can say that its ith position have 1 
            if (((result >> i) & 1) == 1)
            {
                result &= ~(1 << i); // Clear the i-th bit
                num1_set--;
            }
            if (num1_set == num2_set)
                break;
        }
    }

    return result;
}

//! 2425. Bitwise XOR of All Pairings


int main()
{

    //! 2657 find the prefix common Array of two Arrays
    // vector<int> a = {1,3,2,4};
    // vector<int> b = {3,1,2,4};
    // vector<int> ans = findThePrefixCommonArray(a,b);
    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    //! 2429. Minimize XOR
    int num1 = 10;
    int num2 = 20;
    cout << minimizeXor(num1, num2) << endl;


    return 0;
}