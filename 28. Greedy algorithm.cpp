#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// Greedy algorithm is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most immediate benefit. Greedy algorithms are used for optimization problems. An optimization problem can be solved using Greedy if the problem has the following property: At every step, we can make a choice that looks best at the moment, and we get the optimal solution of the complete problem.

//! Assign cookies
// g = [1,2,3], s = [1,1]  Output: 1 tc O(nlogn) sc O(1)
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0;
    for (int j = 0; i < g.size() && j < s.size(); j++)
    {
        if (g[i] <= s[j])
            i++;
    }
    return i;
}

//! fractionalknapsack problem
// The greedy choice is to always pick the next item whose weight is maximum. This will give the optimal solution.
// Time complexity: O(nlogn)
// Space complexity: O(1)

bool compare(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<pair<int, int>> arr, int n)
{
    sort(arr.begin(), arr.end(), compare);

    double total = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].second <= W)
        {
            total += arr[i].first;
            W = W - arr[i].second;
        }
        else
        {
            // add the fraction of the last item
            total += arr[i].first * ((double)W / arr[i].second);
            break;
        }
    }
    return total;
}

//! Function to find the minimum coins needed for a given value
vector<int> getMinCoins(int value, int n, vector<int> &coins)
{
    vector<int> ans;

    // Iterate over coins from the largest to the smallest
    for (int i = n - 1; i >= 0; i--)
    {
        while (value >= coins[i])
        {
            value -= coins[i];
            ans.push_back(coins[i]); // Add the coin to the result
        }
    }

    // vecotor [1, 2, 5, 10, 20, 50, 100, 500, 1000 ,1]
    return ans;
}

//! return both the count and the list of coins
pair<int, vector<int>> getMinCoins(int value, vector<int> &coins)
{
    vector<int> usedCoins; // To store the coins used
    int count = 0;         // To count the number of coins used
    int n = coins.size();

    int i = n - 1; // Start from the largest coin
    while (value > 0 && i >= 0)
    {
        if (coins[i] <= value)
        {
            value -= coins[i];             // Subtract the coin value from the target value
            usedCoins.push_back(coins[i]); // Store the coin
            count++;                       // Increment the count
        }
        else
        {
            i--; // Move to the next smaller coin
        }
    }

    return {count, usedCoins}; // Return both the count and the list of coins
}

//! valid parenthesis checker
bool checkValidString(string s)
{
    // min max approach
    int min = 0;
    int max = 0;

    for (int i = 0; i < s.size(); i++)
    {
        // if its a opening bracket
        if (s[i] == '(')
        {
            min = min + 1;
            max = max + 1;
        }
        else if (s[i] == ')')
        {
            min = min - 1;
            max = max - 1;
        }
        else
        {
            min = min - 1;
            max = max + 1;
        }
        if (min < 0)
            min = 0;
        if (max < 0)
            return false;
    }
    return (min == 0);
}

//! N meetings in one room
// Comparator function to sort by end time
bool comp(const tuple<int, int, int> &m1, const tuple<int, int, int> &m2)
{
    return get<1>(m1) < get<1>(m2); // Compare by end time
}

int maxMeeting(vector<int> start, vector<int> end)
{
    int n = start.size();
    vector<tuple<int, int, int>> meetings; // Tuple to store start, end and position

    //! Store the start, end and position of the meeting
    //! storing starting time of meeting with ending and meeting number or position
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({start[i], end[i], i + 1});
    }

    //! Sort the meetings by end time
    sort(meetings.begin(), meetings.end(), comp);

    int count = 1; // Count of meetings
    // poiting to the first pair so we can compair it with the next pair
    int last_end = get<1>(meetings[0]); // End time of the first meeting

    //! Traverse the meetings
    for (int i = 1; i < n; i++)
    {
        // comaparing two pairs
        if (get<0>(meetings[i]) > last_end)
        {            // If the start time is greater than the end time
            count++; // Increment the count
            // update the next pair
            last_end = get<1>(meetings[i]); // Update the end time
        }
    }

    return count; // Return the count

    // we can return start and end time of meeting as well and the its position as well well since we are storing start and end time and postion of meeting

    // return the start and end time with its position
    // it will return those meeting which are selected that done in minimum time
    // return meetings;
}

//! witout using pair using struct
// Comparator function defined outside the class
// struct Meeting
// {
//     int start;
//     int end;
//     int pos;
// };
// bool comp(Meeting m1, Meeting m2)
// {
//     if (m1.end == m2.end)
//         return m1.pos < m2.pos; // Sort by position if end times are the same
//     return m1.end < m2.end;
// }
// int maxMeetings(vector<int> &start, vector<int> &end)
// {
//     int n = start.size();
//     vector<Meeting> meetings(n);
//     for (int i = 0; i < n; i++)
//     {
//         meetings[i].start = start[i];
//         meetings[i].end = end[i];
//         meetings[i].pos = i + 1;
//     }
//     // Use the free function comparator for sorting
//     sort(meetings.begin(), meetings.end(), comp);
//     int count = 1; // First meeting is always selected
//     int lastEndTime = meetings[0].end;
//     for (int i = 1; i < n; i++)
//     {
//         if (meetings[i].start > lastEndTime)
//         {
//             count++;
//             lastEndTime = meetings[i].end;
//         }
//     }
//     return count;
// }

//! jump game
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int maxjump = 0;

    for (int i = 0; i < n; i++)
    {
        if (i > maxjump)
            return false;
        maxjump = max(maxjump, i + nums[i]);
    }
    return true;
}

//! Jump game II
int jump(vector<int> &nums)
{
    int jump = 0, l = 0, r = 0;
    int n = nums.size();

    while (r < n - 1)
    {
        int farth = 0;

        for (int i = l; i <= r; i++)
        { // Loop from l to r
            farth = max(farth, i + nums[i]);
        }

        l = r + 1; // Update the left pointer
        r = farth; // Update the right pointer
        jump++;    // Increment the jump count
    }

    return jump;
}

//! Minimum Platforms
int findPlatform(vector<int> &arr, vector<int> &dep)
{
    // optimal solution
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0;
    int j = 0;
    int cnt = 0;
    int maxcnt = 0;

    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        maxcnt = max(maxcnt, cnt);
    }
    return maxcnt;
}

//! job sequencing problem
// 1. Using struct
// We define a struct to store each job's ID, deadline, and profit. This allows us to neatly organize and manage the job-related data

// struct Job
// {
//     int id;       // Job ID
//     int deadline; // Deadline of the job
//     int profit;   // Profit of the job
// };

// // Comparator function to sort jobs by profit in descending order
// bool compare(const Job &a, const Job &b)
// {
//     return a.profit > b.profit;
// }

// vector<int> jobSequencing(vector<Job> &jobs, int n)
// {
//     // Sort jobs by profit in descending order using the comparator
//     sort(jobs.begin(), jobs.end(), compare);

//     vector<bool> slots(n, false); // To track available slots
//     vector<int> result(2, 0);     // Store total jobs and total profit

//     // Iterate over the jobs
//     for (size_t i = 0; i < jobs.size(); i++)
//     {
//         // Check available slots from job deadline backwards
//         for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--)
//         {
//             if (!slots[j])
//             {
//                 slots[j] = true;             // Mark slot as occupied
//                 result[0]++;                 // Increment job count
//                 result[1] += jobs[i].profit; // Add job profit
//                 break;
//             }
//         }
//     }

//     return result;
// }

//! 2. Using tuple
// tuple allows you to store different types of data in a single object, which is helpful here as each job consists of three data types (int).
// bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
//     return get<2>(a) > get<2>(b);  // Sort by profit (third element)
// }
// vector<int> jobSequencing(vector<tuple<int, int, int>>& jobs, int n) {
//     sort(jobs.begin(), jobs.end(), compare);  // Sort jobs by profit
//     vector<bool> slots(n, false);  // To track available slots
//     vector<int> result(2, 0);  // Store total jobs and total profit
//     for (int i = 0; i < n; i++) {
//         for (int j = min(n, get<1>(jobs[i])) - 1; j >= 0; j--) {  // Get the deadline from the tuple
//             if (!slots[j]) {
//                 slots[j] = true;  // Mark slot as occupied
//                 result[0]++;  // Increment job count
//                 result[1] += get<2>(jobs[i]);  // Add job profit
//                 break;
//             }
//         }
//     }
//     return result;
// }

//! 3. Using pair
// pair is a simpler version of a tuple and can be used if you are just working with two pieces of data, but for the job sequencing, we can use it for pairing the deadline and profit, with the job ID being handled separately
// struct Job {
//     int id;
//     pair<int, int> deadline_profit;  // Pair of deadline and profit
// };
// bool compare(Job a, Job b) {
//     return a.deadline_profit.second > b.deadline_profit.second;  // Sort by profit
// }
// vector<int> jobSequencing(vector<Job>& jobs, int n) {
//     sort(jobs.begin(), jobs.end(), compare);  // Sort jobs by profit
//     vector<bool> slots(n, false);  // To track available slots
//     vector<int> result(2, 0);  // Store total jobs and total profit
//     for (int i = 0; i < n; i++) {
//         int deadline = jobs[i].deadline_profit.first;
//         for (int j = min(n, deadline) - 1; j >= 0; j--) {
//             if (!slots[j]) {
//                 slots[j] = true;  // Mark slot as occupied
//                 result[0]++;  // Increment job count
//                 result[1] += jobs[i].deadline_profit.second;  // Add profit
//                 break;
//             }
//         }
//     }
//     return result;
// }

//! 135. Candy
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> left(n, 1), right(n, 1);

    // Calculating the left candy distribution
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
    }

    // Calculating the right candy distribution
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
    }

    // Calculating the total candies
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += max(left[i], right[i]);
    }

    return sum;
}

//! Shortest Job first
long long solve(vector<int> &bt)
{
    // code here
    sort(bt.begin(), bt.end());
    int time = 0;
    int waitingTime = 0;
    int n = bt.size();

    for (int i = 0; i < n; i++)
    {
        waitingTime += time;

        time += bt[i];
    }
    return (waitingTime / n); // O(n) + O(n log n) TC and sc O(1)
}

//! insert interveals
// given the intervals array [1,3],[6,9], and we have to merge an interval in it [2,5]
// so there will be no overlapping intervals [1,5],[6,9]
vector<vector<int>> insert(vector<vector<int>> &in, vector<int> &newinterval)
{

    vector<vector<int>> result;
    int n = in.size();
    int i = 0;

    // we are pushing the smaller intervals then newintervals in result
    // array
    while (i < n && in[i][1] < newinterval[0])
    {
        result.push_back(in[i]);
        i++;
    }

    // merging the overlapping for fitting the intervals in array by updting
    // the newintervals
    while (i < n && in[i][0] <= newinterval[1])
    {
        // changing the start of new interval
        newinterval[0] = min(newinterval[0], in[i][0]);

        // changing the end of interval
        newinterval[1] = max(newinterval[1], in[i][1]);

        i++;
    }

    // pushing the new interval on its correct position
    result.push_back(newinterval);

    // push remeaining intevals into result array
    while (i < n)
    {
        result.push_back(in[i]);
        i++;
    }
    return result;
}

//! merge two intervals
// given two intervals [1,3] and [2,6] we have to merge them [1,6]
// if they are not overlapping then we will return them as it is
// if they are overlapping then we will merge them
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;

    if (intervals.size() == 0)
    {
        return intervals;
    }

    // sort the intervals in the array
    sort(intervals.begin(), intervals.end());

    // storing the starting of interval in temp vector
    vector<int> temp = intervals[0];

    for (auto i : intervals)
    {
        // checking if the ending of privios interval is less then equal to
        // its next intervals staring [1,2] [3 4]   i[0] poiting
        if (i[0] <= temp[1])
        {
            temp[1] = max(i[1], temp[1]);
        }
        else
        {
            result.push_back(temp);
            temp = i;
        }
    }
    result.push_back(temp);
    return result;
}

//! 435. Non-overlapping Intervals same as n meetings in one room
//  works by sorting the intervals by their end time
//  if we can to use compariter function without static keyword then we have to
//  declare it outside of class if we have to use it inside we have to use static
//  keyword before the function name our we can use inline compareter function
//  tha dont not need to write an function we can directly declare it inside the
//  the main function iteself
//!  bool compare(const vector<int>& a, const vector<int>& b)
//  {
//       return a[1] < b[1];
//  }

class Solution
{
public:
    //! use static keyword for using the comparitor function inside the class
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        if (intervals.empty())
            return 0;

        // Sort intervals based on their end times
        sort(intervals.begin(), intervals.end(), compare);

        int count = 0;                  // Count of intervals to remove
        int prev_end = intervals[0][1]; // End time of the first interval

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < prev_end)
            {
                // Overlapping interval, increment the count
                count++;
            }
            else
            {
                // Update prev_end to the current interval's end time
                prev_end = intervals[i][1];
            }
        }

        return count;
    }
};

int main()
{

    //! greedy algorithm and its solution
    //! Assign cookies
    // vector<int> g = {1,2,3};
    // vector<int> s = {1,1};
    // cout << findContentChildren(g, s) << endl; // Output: 1

    //! fractionalknapsack problem
    // int W = 50;
    // vector<pair<int, int>> arr = {{60, 10}, {100, 20}, {120, 30}}; // asnwer is 240
    // int n = sizeof(arr) / sizeof(arr[0]);
    // cout << fractionalKnapsack(W, arr, n) << endl; // 240

    //! coin change problem - minimum number of coins to make sum
    // vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    // int value = 49; // ans is 6
    // int n = coins.size();
    // vector<int> result = getMinCoins(value, coins.size(), coins);

    //!  Print the result
    // for (int coin : result) {
    //     cout << coin << " ";
    // }

    //! getting the count and the list of coins
    //  vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    //  int value = 49;
    //  pair<int, vector<int>> res = getMinCoins(value, coins);
    //  cout << "\n"
    //      << res.first << endl;
    // for (int coin : res.second)
    // {
    //     cout << coin << " ";
    // }

    //! valid parenthesis checker
    // string s = "(*))";
    // cout << checkValidString(s) << endl; // 1

    //! N meetings in one room
    // vector<int> start = {10, 12, 20};
    // vector<int> end = {20, 25, 30};
    // cout << maxMeeting(start, end) << endl; // 4

    //! jump game
    // vector<int> nums = {2, 3, 1, 1, 4};
    // cout << canJump(nums) << endl; // 1

    //! Jump game II
    // vector<int> nums = {2, 3, 1, 1, 4};
    // cout << jump(nums) << endl; // 2

    //! Minimum Platforms
    // vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    // vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    // cout << findPlatform(arr, dep) << endl; // 3

    //! job sequencing problem
    // vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    // int n = jobs.size();
    // vector<int> result = jobSequencing(jobs, n);
    // cout << "Max Jobs: " << result[0] << ", Max Profit: " << result[1] << endl;

    //! candy
    // vector<int> ratings = {1, 0, 2};
    // cout << candy(ratings) << endl; // 5

    //! Shortest Job first
    // vector<int> bt = {1, 2, 3, 4, 5};
    // cout << solve(bt) << endl; // 3

    //! insert interveals
    // vector<vector<int>> in = {{1, 3}, {6, 9}};
    // vector<int> newinterval = {2, 5};
    // vector<vector<int>> result = insert(in, newinterval);
    // for (auto i : result)
    // {
    //     cout << i[0] << " " << i[1] << endl;
    // }

    //! merge two intervals
    // vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> result = merge(intervals);
    // for (auto i : result)
    // {
    //     cout << i[0] << " " << i[1] << endl;
    // }

    //! 435. Non-overlapping Intervals
    // vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    // Solution s;
    // cout << s.eraseOverlapIntervals(intervals) << endl; // 1

    

    return 0;
}
