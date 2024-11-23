#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//! slidng window and two pointer

//? 1. Longest Substring Without Repeating Characters (Leetcode 3)
// brute force approach finding the all the substring and checking if it has repeating characters or not
// string s = "abcabcbb"; // ans = 3
// substring = "abc", "bca", "cab", "abc", "bcb", "cbb" // abc is the longest substring without repeating characters

int longestSubString(string s)
{
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            bool flag = false;
            vector<int> freq(256, 0);
            for (int k = i; k <= j; k++)
            {
                freq[s[k]]++;
                if (freq[s[k]] > 1)
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                count = max(count, j - i + 1);
            }
        }
    }
    return count;
    // time complexity is O(n^3)
    // space complexity is O(1)
}

//! better solution using hashingmap
int longestSubString_better(string s)
{
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        vector<int> freq(256, 0);
        for (int j = i; j < n; j++)
        {
            freq[s[j]]++;
            if (freq[s[j]] > 1)
            {
                break;
            }
            count = max(count, j - i + 1);
        }
    }
    return count;
    // time complexity is O(n^2)
    // space complexity is O(1)
}

//! optimized approach using sliding window
int Longest_Sub_String_Without_Reapiting_char(string ans)
{
    int hashmaps[256] = {-1};
    fill(hashmaps, hashmaps + 256, -1); // Initialize all values to -1
    int n = ans.size();
    int r = 0;
    int l = 0;
    int maxLen = 0;

    while (r < n)
    {
        if (hashmaps[ans[r]] >= l)
        {
            l = hashmaps[ans[r]] + 1; // Move the left pointer to one
                                      // position after the last seen index
        }
        hashmaps[ans[r]] = r;            // Update the last seen index of the current character
        maxLen = max(maxLen, r - l + 1); // Update the maximum length found
        r++;                             // Move the right pointer
    }
    return maxLen;
}

//! 1004. Max Consecutive Ones III
int longestOnes(vector<int> &nums, int k)
{
    int maxlen = 0;
    int r = 0;
    int l = 0;
    int len = 0;
    int zeros = 0;
    int n = nums.size();

    while (r < n)
    {
        // r poiting 0
        if (nums[r] == 0)
            zeros++;

        // if we acceding k
        while (zeros > k)
        {
            if (nums[l] == 0)
                // reduce the zeros upto k
                zeros--;
            // moves l to next 0
            l++;
        }
        // if we are under the k limit so we can calculate the substring len
        if (zeros <= k)
        {
            // calculate the substring length
            len = r - l + 1;
            // check currnt string lenght if greater then previous one
            maxlen = max(maxlen, len);
        }
        // moving the r to next
        r++;
    }
    return maxlen;
}

//! Fruit Into Baskets
int totalFruits(vector<int> &arr)
{
    map<int, int> mpp;
    int l = 0;
    int r = 0;
    int maxlen = 0;

    while (r < arr.size())
    {
        mpp[arr[r]]++;
        if (mpp.size() > 2)
        {
            while (mpp.size() > 2)
            {
                mpp[arr[l]]--;

                if (mpp[arr[l]] == 0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }
        if (mpp.size() <= 2)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}

//! 424. Longest Repeating Character Replacement
int characterReplacement(string s, int k)
{

    int l = 0;
    int r = 0;

    int hash[26] = {0};
    int maxfreq = 0;
    int maxlen = 0;

    while (r < s.size())
    {
        // Update the frequency of the character at the right pointer
        hash[s[r] - 'A']++;

        // Update maxfreq dynamically by checking the frequency of the
        // current character
        maxfreq = max(maxfreq, hash[s[r] - 'A']);

        // Check if the current window is invalid
        while ((r - l + 1) - maxfreq > k)
        {
            // Shrink the window from the left
            hash[s[l] - 'A']--;

            // Update maxfreq to reflect the current window's frequencies
            maxfreq = *max_element(hash, hash + 26);

            l++; // Move the left pointer to shrink the window
        }

        // Update maxlen if the window is valid
        maxlen = max(maxlen, r - l + 1);

        r++; // Expand the window by moving the right pointer
    }

    return maxlen;
}

//! 930. Binary Subarrays With Sum
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int n = nums.size();
    // Edge case: All zeros
    bool allzero = true;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            allzero = false;
            break;
        }
    }
    if (allzero && goal == 1)
        return 0;
    if (allzero && n > 0)
        return n * (n + 1) / 2;

    // Count subarrays using prefix sum and hashmap
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1; // Initialize for cases where prefix sum == goal
    int subArray_count = 0, sum = 0;

    for (int j = 0; j < n; j++)
    {
        sum += nums[j];
        if (prefixSum.find(sum - goal) != prefixSum.end())
        {
            subArray_count += prefixSum[sum - goal];
        }
        prefixSum[sum]++;
    }

    return subArray_count;
}

//! 1248. Count Number of Nice Subarrays
int f(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0, j = 0;
    int count = 0;
    int total = 0;
    while (j < n)
    {
        count += nums[j] % 2;

        while (count > k)
        {
            count -= nums[i] % 2;
            i++;
        }

        total += j - i + 1;
        j += 1;
    }

    return total;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    int lessThanEqualK = f(nums, k);
    int lessThanK = f(nums, k - 1);

    return lessThanEqualK - lessThanK;
}

//! 1358. Number of Substrings Containing All Three Characters
int numberOfSubstrings(string s)
{

    int n = s.size();
    int count = 0;

    int last[3] = {-1, -1,
                   -1}; // To track the last occurrence of 'a', 'b', and 'c'

    for (int i = 0; i < n; i++)
    {
        last[s[i] - 'a'] =
            i; // Update the last occurrence of the current character

        // Add the count of substrings ending at index `i`
        if (last[0] != -1 && last[1] != -1 && last[2] != -1)
        {
            count += 1 + min({last[0], last[1], last[2]});
        }
    }

    return count;
}

//! 1423. Maximum Points You Can Obtain from Cards
int maxScore(vector<int> &nums, int k)
{
    int n = nums.size();
    int lsum = 0, rsum = 0, maxSum = 0;

    // Calculate the initial left sum of the first k elements
    for (int i = 0; i < k; i++)
    {
        lsum += nums[i];
    }
    maxSum = lsum;

    int rindex = n - 1;

    // Sliding window: shift one card from the left side to the right side
    for (int i = k - 1; i >= 0; i--)
    {
        lsum -= nums[i];
        rsum += nums[rindex];
        maxSum = max(maxSum, lsum + rsum);
        rindex--;
    }

    return maxSum;
}

//! Longest Substring with At Most K Distinct Characters
int kDistinctChars(int k, string &s)
{
    int n = s.size();
    int i = 0, j = 0;
    map<char, int> result;
    int count = 0;
    int maxLen = 0;

    while (j < n)
    {
        // Add current character to the map and expand the window
        result[s[j]]++;

        // If the map size exceeds k, shrink the window from the left
        while (result.size() > k)
        {
            result[s[i]]--;
            if (result[s[i]] == 0)
            {
                result.erase(s[i]);
            }
            i++; // Move the left pointer to the right
        }

        // If the map size is exactly k, count the substrings

        maxLen = max(maxLen, j - i + 1);

        j++; // Move the right pointer to expand the window
    }

    return maxLen;
}

//! 992. Subarrays with K Different Integers
int f(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    int cnt = 0;
    map<int, int> result;

    while (j < n)
    {
        // updating the freq of character
        result[nums[j]]++;

        while (result.size() > k)
        {
            // decrase the freq of elements
            result[nums[i]]--;

            // remove the elment after its freq decrased
            if (result[nums[i]] == 0)
            {
                result.erase(nums[i]);
            }
            i++;
        }
        // return the count of the good subarrya
        cnt += (j - i + 1);
        // move forword the j for next subArray
        j++;
    }
    return cnt;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    // so we are getting for the first k element
    // and at next we are getting for k - 1 element
    // we just minus the k ans with k - 1

    int ans = f(nums, k) - f(nums, k - 1);
    return ans;
}

//! 76. Minimum Window Substring
string minWindow(string s, string t)
{

    int n = t.size();
    int m = s.size();
    int r = 0, l = 0, minl = INT_MAX;
    int count = 0;
    int sindex = -1;
    int hash[256] = {0};
    // hash mai t ki sari value bhrenge
    for (int i = 0; i < n; i++)
    {
        hash[t[i]]++;
    }
    while (r < m)
    {
        hash[s[r]]--;
        //+ve val dekhne ke baad
        if (hash[s[r]] >= 0)
        {
            count = count + 1;
            // hash[s[r]]--;
        }
        // we want to shrink and check
        while (count == n)
        {
            // index or min ka dhyaan rakhna hai
            if (r - l + 1 < minl)
            {
                minl = r - l + 1;
                // starting index
                sindex = l;
            }
            hash[s[l]]++; // restore hash
            if (hash[s[l]] > 0)
            {
                count--;
            }
            l++;
        }
        r++;
    }
    return sindex == -1 ? "" : s.substr(sindex, minl);
}

int main()
{
    //! Longets substring without repeating characters
    //! brute force approach
    //  string s = "abcabcbb"; // ans = 3
    //  cout << longestSubString(s) << endl;
    //  cout << longestSubString_better(s) << endl;
    //  cout << Longest_Sub_String_Without_Reapiting_char(s) << endl;

    //! 1004. Max Consecutive Ones III
    // vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    // int k = 2;
    // cout << longestOnes(nums, k) << endl;

    //! Fruit Into Baskets
    // vector<int> arr = {1,2,1,2,3};
    // cout << totalFruits(arr) << endl;

    //! 424. Longest Repeating Character Replacement
    // string s = "AABABBA";
    // int k = 1;
    // cout << characterReplacement(s, k) << endl;

    //! 930. Binary Subarrays With Sum
    // vector<int> nums = {1,0,1,0,1};
    // int goal = 2;
    // cout << numSubarraysWithSum(nums, goal) << endl;

    //! 1248. Count Number of Nice Subarrays
    // vector<int> nums = {1,1,2,1,1};
    // int k = 3;
    // cout << numberOfSubarrays(nums, k) << endl;

    //! 1358. Number of Substrings Containing All Three Characters
    // string s = "abcabc";
    // cout << numberOfSubstrings(s) << endl;

    //! 1423. Maximum Points You Can Obtain from Cards
    // vector<int> nums = {1,2,3,4,5,6,1};
    // int k = 3;
    // cout << maxScore(nums, k) << endl;

    //! Longest Substring with At Most K Distinct Characters
    // string s = "eceba";
    // int k = 2;
    // cout << kDistinctChars(k, s) << endl;

    //! 992. Subarrays with K Different Integers
    // vector<int> nums = {1,2,1,2,3};
    // int k = 2;
    // cout << subarraysWithKDistinct(nums, k) << endl;

    //! 76. Minimum Window Substring
    // string s = "ADOBECODEBANC";
    // string t = "ABC";
    // cout << minWindow(s, t) << endl;

    return 0;
}