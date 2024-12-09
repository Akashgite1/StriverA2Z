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



int main()
{

    // greedy algorithm and its solution
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
    vector<int> start = {10, 12, 20};
    vector<int> end = {20, 25, 30};
    cout << maxMeeting(start, end) << endl; // 4

    return 0;
}
