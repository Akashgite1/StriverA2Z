#include<bits/stdc++.h>
#include<iostream>

using namespace std;
//! ----------------------> Dynamic Programming in Cpp <-------------------------
// two types of dynamic programming 
// 1) top down approach --> memoization 
// 2) bottom up approach --> tabulation

// !-----------------------------! 1-D problems !-----------------------------------!

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
    // space complexity can be reduced to O(1) 
    int fib1(int n){
        if(n <= 1) return n;
        int a = 0, b = 1, c;
        for(int i = 2; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

};

//! climing stairs 
class climing{
    public:
    // space complexity can be reduced to O(1) 
    int fib1(int n){
        if(n <= 1) return 1;
        int a = 1, b = 1, c;
        for(int i = 2; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

//! frog jump 
class frog{
    public: 
    //^ simple recursion  TC = O(2^n) SC = O(n) 
    int solve(int n, vector<int> height){
        // base case 
        if(n == 0){
            return 0; 
        }

        // jump 1 step
        int jump1 = solve(n-1,height) + abs(height[n] - height[n-1]); 
        
        // jump 2 step
        int jump2 = INT_MAX;
        if(n > 1){
            jump2 = solve(n-2,height) + abs(height[n] - height[n-2]);
        }
        return min(jump1,jump2);
    }

    //^  Memoization   TC = O(n)  SC = O(n) + stack space O(n) 
    // vector<int> dp(n+1,-1);
    // int frog_jump(int n, vector<int> height){
    //     // base case 
    //     if(n == 0){
    //         return 0; 
    //     }
    //     if(dp[n] != -1) return dp[n];
    //     // jump 1 step
    //     int jump1 = frog_jump(n-1,height) + abs(height[n] - height[n-1]); 
    //     // jump 2 step
    //     int jump2 = INT_MAX;
    //     if(n > 1){
    //         jump2 = frog_jump(n-2,height) + abs(height[n] - height[n-2]);
    //     }
    //     return dp[n] = min(jump1,jump2);
    // }

    //^ Tabulation  TC O(n) SC O(n)  avoid the stack space of recursion || space optimization O(1)
    // vector<int> frog_jump(int n, vector<int> height){
    //     vector<int> dp(n+1,0);
    //     dp[1] = 0;
    //     for(int i = 2; i <= n; i++){
    //         int jump1 = dp[i-1] + abs(height[i] - height[i-1]);
    //         int jump2 = INT_MAX;
    //         if(i > 1){
    //             jump2 = dp[i-2] + abs(height[i] - height[i-2]);
    //         }
    //         dp[i] = min(jump1,jump2);
    //     }
    //     return dp;
    // }

    // Driver Code
    int minCost(vector<int> &height)
    {
        // Code here
        // recursive solution
        int n = height.size();
        vector<int> dp(n + 1, -1);
        return solve(n - 1, height);
    }
};

// frog jump II her we have to jump the frog upto k steps insted of 1 or 2 steps
class jumpII{
    public:
    //^ simple recursion  TC = O(k^n) SC = O(n) 
    int cost(int k, int n, vector<int>&arr){
        // base case 
        if(n == 0) return 0;
        int mincost = INT_MAX; 
        for(int jump=1; jump<k; jump++){
            if(n-jump >= 0){
                int temp = cost(k,n-jump,arr) + abs(arr[n] - arr[n-jump]);
                mincost = min(mincost,temp);
            }
        }
        return mincost; 
    }

    //^ Memoization  TC = O(n) SC = O(n) + stack space O(n)
    int cost1(int k, int n, vector<int>&arr, vector<int>&dp){
        // base case 
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n]; 
        dp[n] = INT_MAX;  
        for(int i=1; i<=k; i++){
            if(n-i >= 0){
                int temp = cost1(k,n-i,arr,dp) + abs(arr[n] - arr[n-i]);
                dp[n] = min(dp[n],temp);
            }
        }
        return dp[n]; 
    }

    //^ tabulation TC = O(n) SC = O(n) || space optimization O(1)
    int cost2(int k, int n, vector<int> &arr)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = INT_MAX;
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
                }
            }
        }
        return dp[n];
    }
};

//! maximum sum of non-adjacent elements || house robber Leetcode
class Solution
{
public:
    //^ simple recursion solution TC O(2^n) SC O(n) 
    int solve(vector<int> &nums, int n)
    {
        if(n == 0) return nums[n];
        if(n < 0)return 0;

        // pick a element 
        int pick = nums[n] + solve(nums, n - 2); 
        // not pick a element 
        int notpick = solve(nums, n - 1); 

        // return max of them 
        return max(pick,notpick);
    }
    //^ Memoization Solution TC O(n) SC O(n) + stack space O(n)
    int solve1(vector<int> &nums, int n, vector<int>&dp)
    {
        if(n == 0) return nums[n];
        if(n < 0)return 0;
        if(dp[n] != -1) return dp[n];

        // pick a element 
        int pick = nums[n] + solve1(nums, n - 2,dp); 
        // not pick a element 
        int notpick = solve1(nums, n - 1,dp); 

        return dp[n] = max(pick,notpick);
    }
    //^ Tabulation Solution TC O(n) SC O(n) with no stack space O(1) 
    int solve2(vector<int> &nums){
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        if(nums.size() > 1) dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];
    }
    //^ Tabulation Solution TC O(n) SC O(1) with no stack space O(1)
    int solve3(vector<int> &nums){
        int prev_max = nums[0];
        int curr_max = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            int temp = curr_max;
            curr_max = max(prev_max + nums[i], curr_max);
            prev_max = temp;
        }
        return curr_max;
    }
    
};

//! House Robber II 
class house_robber 
{
public:
    //^ simple recursion  TC = O(2^n) SC = O(n)
    int solve(vector<int> &nums, int n)
    {
        if (n == 0)
            return nums[n];
        if (n < 0)
            return 0;

        int add = nums[n] + solve(nums, n - 2);
        int notpick = solve(nums, n - 1);

        return max(add, notpick);
    }
    //^ Memoization  TC = O(n) SC = O(n) + stack space O(n)
    int solve1(vector<int> &nums, int n, vector<int>&dp)
    {
        if (n == 0)
            return nums[n];
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int add = nums[n] + solve1(nums, n - 2, dp);
        int notpick = solve1(nums, n - 1, dp);

        return dp[n] = max(add, notpick);
    }
    // driver function for memoization problem 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n + 1, -1);
        vector<int> dp2(n + 1, -1); // Separate dp for temp2
        vector<int> temp1(nums.begin(), nums.end() - 1); // Skip last
        vector<int> temp2(nums.begin() + 1, nums.end()); // Skip first

        return max(solve1(temp1, temp1.size() - 1, dp),
                   solve1(temp2, temp2.size() - 1, dp2));
    }
    //^ Tabulation  TC = O(n) SC = O(n)
    int solve2(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n < 0)
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n-1];
    }
    //^ Tabulation TC = O(n) SC = O(1) || space optimization O(1)
    int solve3(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++)
        {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    //! tabulation driver code 
    int robII(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        
        vector<int> temp1(nums.begin(), nums.end() - 1); // Exclude last house
        vector<int> temp2(nums.begin() + 1, nums.end()); // Exclude first house
        
        return max(solve3(temp1), solve3(temp2));
    }
};


int main (){

    //^ Fibonacci Series using Dynamic Programming
    // fibo obj;
    // int n = 10; // 10th fibonacci number is 55
    // vector<int> dp(n+1,-1); 
    // cout<<obj.f(n,dp)<<endl;

    //^ Climbing Stairs
    // climing obj1;
    // cout<<obj1.fib1(5)<<endl; 

    //^ Frog Jump
    // frog obj2;
    // vector<int> height = {10,30,40,20};
    // cout<<obj2.solve(3,height)<<endl;

    //^ Frog Jump II 
    // jumpII obj3;
    // vector<int> arr = {0,1,3,6,9,12};
    // cout<<obj3.cost(3,5,arr)<<endl;
    // memoization
    // vector<int> dp(arr.size(),-1);
    // cout<<obj3.cost1(3,4,arr,dp)<<endl;

    //^ House Robber I
    // Solution obj4;
    // vector<int> nums = {2, 7, 9, 3, 1};
    //! // simple recursion
    // cout << obj4.solve(nums, nums.size() - 1) << endl;
    //! // memoization
    // vector<int> dp(nums.size(), -1);
    // cout << obj4.solve1(nums, nums.size() - 1, dp) << endl;
    //! // tabulation
    // cout << obj4.solve2(nums) << endl;
    // cout << obj4.solve3(nums) << endl;

    //^ House Robber II
    // house_robber obj5;
    // vector<int> nums = {114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240}; // answer = 4077
    // //! simple recursion 
    // // cout << obj5.solve(nums, nums.size() - 1) << endl;
    // // //! memoization
    // // cout << obj5.rob(nums) << endl;
    // // //! tabulation
    // // cout << obj5.solve2(nums) << endl;
    // //! tabulation with space optimization 
    // cout << obj5.robII(nums) << endl;
  

    return 0;
}