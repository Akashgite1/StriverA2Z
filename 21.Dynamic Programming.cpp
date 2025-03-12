#include<bits/stdc++.h>
#include<iostream>

using namespace std;
//! ------------------------------------->  Dynamic Programming in Cpp  <--------------------------------------------
// two types of dynamic programming 
// 1) top down approach --> memoization 
// 2) bottom up approach --> tabulation

//! Fibonacci Series using Dynamic Programming 
class fibo{
    public:
    //^ Top Down Approach --> Memoization
    int f(int n, vector<int> &dp){
        // base condition
        if(n <=1) return n;

        if(dp[n] != -1) return dp[n];
        
        return dp[n] = f(n-1,dp) + f(n-2,dp);
        // time complexity is O(n) and recursive stack space is O(n) 
        // space complexity is O(n) 
    }
    //^ Bottom Up Approach --> Tabulation
    int fib(int n , vector<int> &dp){
        if(n <= 1) return n;

        dp[0] = 0;
        dp[1] = 1;
        // avoiding the stack space of recursion 
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n]; 
        // in tabulation we avoid the stack space of recursion 
        // time complexity is O(n) and 
        // space complexity is O(n) 
    }

};


int main (){

    //^ Fibonacci Series using Dynamic Programming
    fibo obj;
    int n = 10; // 10th fibonacci number is 55
    vector<int> dp(n+1,-1); 
    cout<<obj.f(n,dp)<<endl;


    
    return 0;
}