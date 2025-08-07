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

//& !-------------------------> 2-d DP quations ----------------------------------!

//! Ninjas training problem 
 class Ninja_traning
 {
    public: 
    // ^ simple recursion  TC = O(3^n) SC = O(n)
    int solve(int day,  int lastTask, vector<vector<int>>& points){
        // base case 
        if(day == 0){
            int maxi = 0;
            // since ninja have 3 task to do in single day
            for(int task = 0; task < 3; task++){
               // make sure selected task is not same as last task 
               if(task != lastTask){
                   maxi = max(maxi,points[0][task]);
               } 
            }
            return maxi; 
        }

        // if its not 0th day that means it not last recursion call
        int maxi = 0; 
        for(int task = 0; task < 3; task++){
            // make sure selected task is not same as last task 
            if(task != lastTask){
                int point = max(maxi,points[day][task] + solve(day-1,task,points));
                maxi = max(maxi,point);
            }
        }
        return maxi;

    }
    // ^ Memoization  TC = O(n) SC = O(n) + stack space O(n)
    int solve1(int day, int lastTask, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        /*
          declaration of dp vector for this 
          vector<vector<int>> dp(n, vector<int>(4, -1));
          its a vector by vector of size n there are 4 column in it at each 
          sub vector and all filled with -1 initially 
        */

        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != lastTask)
                {
                    maxi = max(maxi, points[0][task]);
                }
            }
            return dp[day][lastTask] = maxi;
        }
        
        // if the subproblem is solved before 
        if (dp[day][lastTask] != -1)return dp[day][lastTask];

        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != lastTask)
            {
                int point = max(maxi, points[day][task] + solve1(day - 1, task, points, dp));
                maxi = max(maxi, point);
            }
        }
        return dp[day][lastTask] = maxi;
    }

    // ^ Tabulation  TC = O(n) SC = O(n) avoiding stack space
    int solve2(int n, vector<vector<int>> &points)
    {
        // Initialize a vector to store the maximum points for the previous day's activities
        vector<int> prev(4, 0);

        // Initialize the DP table for the first day (day 0)
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

        // Iterate through the days starting from day 1
        for (int day = 1; day < n; day++)
        {
            // Create a temporary vector to store the maximum points for the current day's activities
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++)
            {
                temp[last] = 0;
                // Iterate through the tasks for the current day
                for (int task = 0; task <= 2; task++)
                {
                    if (task != last)
                    {
                        // Calculate the points for the current activity and add it to the
                        // maximum points obtained on the previous day (stored in prev)
                        temp[last] = max(temp[last], points[day][task] + prev[task]);
                    }
                }
            }
            // Update prev with the maximum points for the current day
            prev = temp;
        }

        // The maximum points for the last day with any activity can be found in prev[3]
        return prev[3];
    }
 }; 

//! Unique Paths
class UniquePaths {
    public:
    //^ simple recursion  TC = O(2^(m+n)) SC = O(m+n)
    int solve(int i, int j){
        // base case 
        if(i == 0 && j == 0) return 1; // only one way to reach the starting point 
        if(i < 0 || j < 0) return 0; // out of bounds 

        int up = solve(i-1,j); // move up
        int left = solve(i,j-1); // move left
        return up + left; // total ways to reach the point

    }

    //^ Memoization  TC = O(m*n) SC = O(m+n) + stack space O((m-1) + (n-1)) recursion call
    int solve1(int i, int j, vector<vector<int>>&dp){
        // base case 
        if(i == 0 && j == 0) return 1; // only one way to reach the starting point 
        if(i < 0 || j < 0) return 0; // out of bounds 

        if(dp[i][j] != -1) return dp[i][j]; // check if already calculated 

        int up = solve1(i-1,j,dp); // move up
        int left = solve1(i,j-1,dp); // move left
        return dp[i][j] = up + left; // total ways to reach the point

    }

    //^ Tabulation  TC = O(m*n) SC = O(m*n) avoiding stack space
    int solve2(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 0)); // create a dp table 

        // base case 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[i][j] = 1; // only one way to reach the starting point 
                else{
                    if(i > 0) dp[i][j] += dp[i-1][j]; // move up
                    if(j > 0) dp[i][j] += dp[i][j-1]; // move left
                    dp[i][j] = dp[i][j]; // total ways to reach the point
                }
            }
        }
        return dp[m-1][n-1]; // return the total ways to reach the bottom right corner 
    }

    //^ Tabulation with Space Optimization TC = O(m*n) SC = O(n) avoiding stack space
    int solve3(int m, int n){
        vector<int> prev(n, 0); // create a dp table 

        // base case 
        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0); // create a dp table 
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) curr[j] = 1; // only one way to reach the starting point 
                else{
                    if(i > 0) curr[j] += prev[j]; // move up
                    if(j > 0) curr[j] += curr[j-1]; // move left
                }
            }
            prev = curr; // update the previous row with the current row 
        }
        return prev[n-1]; // return the total ways to reach the bottom right corner 
    }

};

//!3363. Find the Maximum Number of Fruits Collected
class Fruits{
    public:
    //^ simple recursion  
    int n; 
    int child1Collected(vector<vector<int>>& fruits) {
        // collecting the digoanal fruits from i to j 
        int count = 0; 
        for (int k = i; k <= j; k++) {
            count += fruits[k];
        }
        return count;
    }

    int child2Collected(int i, int j, vector<vector<int>>& fruits) {
        // base case 
         if( i <0 || i>= n || j < 0 || j >= n) return 0; // out of bounds case
        
        // reach to the last room the fruit is already collected by child 1 that why we return 0
        if(i == n-1 && j == n-1) return 0; // last row and first column case
        
        // cant go other side of digoanal and cant collect digonal fruits 
        // if you go other side then less moves reamin go back to last Room
        if(i == j || i > j) return 0; 


        int bottomLeft =fruits[i][j] + child2Collected(i + 1, j - 1, fruits);
        int bottomDown = fruits[i][j] + child2Collected(i + 1, j, fruits);
        int bottomRight = fruits[i][j] + child2Collected(i + 1, j + 1, fruits);
        
        // return the maximum of the three options
        return max({bottomLeft, bottomDown, bottomRight});

    }

    int child3Collected(int i, int j, vector<vector<int>>& fruits) {
        // base case 
        if( i <0 || i>= n || j < 0 || j >= n) return 0; // out of bounds case
        
        // reach to the last room the fruit is already collected by child 1 that why we return 0
        if(i == n-1 && j == n-1) return 0; // last row and first column case
        
        if(i == j || i > j) return 0; // cant go other side of digoanal and cant collect digonal fruits
        
        // collect the fruits from the digoanal and its child 
        // child 1 collected fruits from i to j 
        // child 2 collected fruits from i+1 to j-1 
        // child 3 collected fruits from i+1 to j+1
        int upRight =fruits[i][j] + child3Collected(i-j,j+1, fruits);
        int right = fruits[i][j] + child3Collected(i, j+1, fruits);
        int bottomRight = fruits[i][j] + child3Collected(i+1, j+1, fruits);
        
        // return the maximum of the three options
        return max({upRight, right, bottomRight});

    }

    //! memorization 
    // 2-d since two parameters are changing
    vector<vector<int>> dp2, dp3;
    int child1Collected(vector<vector<int>>& fruits) {
        // collecting the digoanal fruits from i to j
        int count = 0;
        for (int k = 0; k < n; k++) {
            count += fruits[k][k];
            fruits[k][k] = 0;
        }
        return count;
    }

    //! memorization
    int child2Collectedmemo(int i, int j, vector<vector<int>>& fruits) {
        // base case
        if (i < 0 || i >= n || j < 0 || j >= n)
            return 0; // out of bounds case

        // reach to the last room the fruit is already collected by child 1 that
        // why we return 0
        if (i == n - 1 && j == n - 1)
            return 0; // last row and first column case

        // cant go other side of digoanal and cant collect digonal fruits
        // if you go other side then less moves reamin go back to last Room
        if (i == j || i > j)
            return 0;

        if (dp2[i][j] != -1)
            return dp2[i][j]; // check if already calculated

        int bottomLeft =
            fruits[i][j] + child2Collectedmemo(i + 1, j - 1, fruits);
        int bottomDown = fruits[i][j] + child2Collectedmemo(i + 1, j, fruits);
        int bottomRight =
            fruits[i][j] + child2Collectedmemo(i + 1, j + 1, fruits);

        // return the maximum of the three options
        return dp2[i][j] = max({bottomLeft, bottomDown, bottomRight});
    }

    int child3Collectedmemo(int i, int j, vector<vector<int>>& fruits) {
        // base case
        if (i < 0 || i >= n || j < 0 || j >= n)
            return 0; // out of bounds case

        // reach to the last room the fruit is already collected by child 1 that
        // why we return 0
        if (i == n - 1 && j == n - 1)
            return 0; // last row and first column case

        if (i == j || j > i)
            return 0; // cant go other side of digoanal and cant collect digonal
                      // fruits

        if (dp3[i][j] != -1)
            return dp3[i][j]; // check if already calculated

        int upRight = fruits[i][j] + child3Collectedmemo(i - 1, j + 1, fruits);
        int right = fruits[i][j] + child3Collectedmemo(i, j + 1, fruits);
        int bottomRight =
            fruits[i][j] + child3Collectedmemo(i + 1, j + 1, fruits);

        // return the maximum of the three options
        return dp3[i][j] = max({upRight, right, bottomRight});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        dp2.resize(n, vector<int>(n, -1)); // Initialize dp table with -1
        dp3.resize(n, vector<int>(n, -1)); // Initialize dp table with -1
        
        //! simple recursion
        // // collect digoanal fruits only 
        // int c1 = child1Collected(fruits); 
        // // required the recursion for child 2 by sending the array and its starting postion
        // int c2 = child2Collected(0, n-1,fruits);
        // // required the recursion for child 3 by sending the array and its starting postion
        // int c3 = child3Collected(n-1, 0,fruits);
        // return c1 + c2 + c3; // return the total fruits collected by all three children

        //! memoization approach
        int c1 = child1Collected(fruits);
        int c2 = child2Collectedmemo(0, n - 1, fruits);
        int c3 = child3Collectedmemo(n - 1, 0, fruits);
        return c1 + c2 + c3; 
}



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
     //  //! simple recursion
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
     //  cout << obj5.solve(nums, nums.size() - 1) << endl;
     //! memoization
     //  cout << obj5.rob(nums) << endl;
     //! tabulation
     //  cout << obj5.solve2(nums) << endl;
     // //! tabulation with space optimization 
     // cout << obj5.robII(nums) << endl;

    //^ Ninja Training Problem 
     // Ninja_traning obj6;
     // vector<vector<int>> points = {{1,2,3},{4,5,6},{7,8,9}};
     // int n = points.size();
     // vector<vector<int>> dp(n, vector<int>(4, -1)); // Initialize dp table
     // cout << obj6.solve(n-1, 3, points) << endl; //! Simple Recursion
     // cout << obj6.solve1(n-1, 3, points, dp) << endl; //! Memoization
     // cout << obj6.solve2(n, points) << endl; //! Tabulation

    
    //^ Unique Paths
     // UniquePaths obj;
     // int m = 3, n = 7;                        // 3 rows and 7 columns
     // cout << obj.solve(m - 1, n - 1) << endl; // simple recursion
     // vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize dp table
     // cout << obj.solve1(m - 1, n - 1, dp) << endl; // memoization
     // cout << obj.solve2(m, n) << endl; // tabulation
     // cout << obj.solve3(m, n) << endl; // tabulation with space optimization

    


    return 0;
}