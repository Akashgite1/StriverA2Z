#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

//!--> medium level array Quations

// two sum problem
std::pair<int, int> two_sum_using_pair(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // Return -1, -1 if no such pair exists
}

int two_sum(int arr[], int n, int target)
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if (arr[i] + arr[j] == target)
    //         {
    //             cout<<i<<" "<<j;
    //         }
    //     }
    // } // Tc = O(n) * O(n) = O(n^2) SC = O(1)

    //! better solution using maps
    // unordered_map<int, int> numMap;

    // // Build the hash table
    // for (int i = 0; i < n; i++)
    // {
    //     numMap[arr[i]] = i;
    // }

    // // Find the complement
    // for (int i = 0; i < n; i++)
    // {
    //     int complement = target - arr[i];
    //     if (numMap.count(complement) && numMap[complement] != i)
    //     {
    //         // return {i, numMap[complement]};
    //         cout << i << numMap[complement];
    //         break;
    //     }
    // }

    // optimal
    // two pointer approach where the two pointer are
    // left and right left point 1st index and last points to last index
    //    left        right
    //   [4, 1, 2, 3, 1]
    // we just check left + right = target is yes then return left and right index
    // if not then we increment left++ and decrement right-- for next iterantion

    int left = 0;
    int right = n - 1;
    sort(arr, arr + n);

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return left, right;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right++;
        }
    }
}

void Sort_an_array_of_zeros_once_and_two(int arr[], int n)
{
    // brute force solution just sort and return the array
    //  sort(arr,arr+n);  // TC = O(n log n) SC = O(1)
    //  print_array(arr,n);

    // using counters
    // int count_0 = 0;
    // int count_1 = 0;
    // int count_2 = 0;

    // // get the count of element of 0s 1s and 2s in the array
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == 0)
    //     {
    //         count_0++;
    //     }
    //     else if (arr[i] == 1)
    //     {
    //         count_1++;
    //     }
    //     else
    //     {
    //         count_2++;
    //     }
    // }

    // // rewrite the element in the array from counts of each element
    // int i = 0, j = 0, k = 0;

    // // Rewrite 0s
    // for (i = 0; i < count_0; i++)
    // {
    //     arr[i] = 0;
    // }

    // // Rewrite 1s
    // for (j = i; j < i + count_1; j++)
    // {
    //     arr[j] = 1;
    // }

    // // Rewrite 2s
    // for (k = j; k < j + count_2; k++)
    // {
    //     arr[k] = 2;
    // }

    //         l m              h    l m      h         lm   h
    // nums[] = {2, 0, 2, 1, 1, 0}   {0,0,2,1,1,2}  {0,0,2,1,1,2}
    //        lmh loop end her
    // {0,0,1,1,2,2}

    //! optimal using Dutch National flag algorithm.
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    // TC = O(n) SC = O(1)

    print_array(arr, n);
}

int Majority_Element(int nums[], int n)
{
    // nums = [2,2,1,1,1,2,2]
    //! brute force
    // for (int i = 0; i < n; i++)
    // {
    //     int count = 0;
    //     for(int i = 0; i<n; i++)
    //     {
    //         for(int j = 0; j<n; j++)
    //         {
    //             if(nums[j] == nums[i] )
    //             {
    //                 count++;
    //             }
    //         }
    //         if(count > n/2) {return nums[i];}
    //         else{count = 0;}
    //     }
    //     return{};
    // } // TC = O(n^2) Sc = O(1)

    //! better solution using hashing
    // map<int, int> mpp;

    // // for the frequency of element in the hashmap
    // for (int i = 0; i < nums.size(); i++) {
    //     mpp[nums[i]]++;
    // }

    // // since in the map elements store like key pair<int,int> where
    // // 1st int is element and second one its frequency so it.second is
    // // used for access the second pair of map same of vector and set
    // for (auto it : mpp) {
    //     if (it.second > (nums.size() / 2)) {
    //         return it.first;
    //     }
    // }
    // return {};

    //!---> optimal Moore's Voting Algorithm
    int count = 0;
    int element;

    // moores voting algo
    for (int i = 0; i < n; i++)
    {

        if (count == 0)
        {              // 7 5 7 5 1 1 5 5 7 5 5 7 7 5 5 5 5
            count = 1; // 2 1 2 1 0 1 0 1 0 1 2 1 0 1 2 3 4
            element = nums[i];
        }
        else if (nums[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    // if we do not found the element or there is not mejority
    // element in the array
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == element)
        {
            count1++;
        }
    }
    if (count1 > (n / 2))
    {
        return element;
    }
    return -1;
}

int Maximum_Subarray_Sum(int arr[], int n)
{
    // brute solution
    // int lenght = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0; // 1 3
    //     for (int j = i; j < n; j++)
    //     {
    //         sum = sum + arr[j];

    //         if (sum == k)
    //         {
    //             lenght = max(lenght, j - i + 1);
    //         }
    //     }
    // }
    // cout << lenght;

    //! optimal Kadane's Algorithm
    // nums = [-2,1,-3,4,-1,2,1,-5,4]  Output: 6
    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        maxi = max(maxi, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
    // TC = O(n) SC= O(1)
}

void Best_Time_to_Buy_and_Sell_Stock(int arr[], int n)
{
    // [7,1,5,3,6,4]

    int mini = arr[0]; //
    int profit = 0;    //

    for (int i = 1; i < n; i++)
    {
        int cost = arr[i] - mini;

        if (cost > profit)
        {
            profit = cost;
        }

        // max_profit = max(max_profit,cost);

        if (arr[i] < mini)
        {
            mini = arr[i];
        }
    }
    cout << profit;
}

void Rearrange_Array_Elements_by_Sign(int arr[], int n)
{

    //! brute force solution
    // int n = nums.size();
    // vector<int> positive;
    // vector<int> negative;

    // for (int i = 0; i < n; i++) {
    //     if (nums[i] > 0) {
    //         positive.push_back(
    //             nums[i]); // TC = O(n)+ O(n) SC = O(n/2) + O(n/2)= O(n)
    //     }

    //     if (nums[i] < 0) {
    //         negative.push_back(nums[i]);
    //     }
    // }
    // nums.clear();

    // int posIndex = 0, negIndex = 0;
    // while (posIndex < positive.size() && negIndex < negative.size()) {
    //     nums.push_back(positive[posIndex++]);
    //     nums.push_back(negative[negIndex++]);
    // }
    // return nums;

    // ! optimal solution
    // vector<int> ans(n, 0);
    //     int positive = 0;
    //     int negative = 1;

    //     for (int i = 0; i < n; i++) {
    //         if (nums[i] < 0) {
    //             ans[negative] = nums[i];
    //             negative = negative + 2;
    //         } else {
    //             ans[positive] = nums[i];
    //             positive = positive + 2;
    //         }
    //     }
    //     return ans;
}

void Next_Permutation(int arr[], int n)
{
    // brute force using in built function called next_permutation
    // next_permutation(ans.begin(),ans.end());
    // int result = next_permutation(arr, arr+n);
    // TC = O(n)

    // optimal solution   [2,1,5,4,3,0,0]
    //  finding the longest prefix match and this is your
    // break point
    int index = -1;
    // finding the breakpoint
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {              //  0  1  2  3  4  5  6
            index = i; //[ 2, 1, 5, 4, 3, 0, 0 ]
            break;     //                 i  n-1
        }
    }
    // i i+1
    //  5 6    4 5   3 4   2 3   1 2
    // [0,0]  [3,0] [4,3] [5,4] [1,5] since 1<5 conditon
    // become true now we update the index to break point
    // index index become 1

    // if the index is stil =-1 that means the array is like
    // 5 4 3 2 1 where each element is like i < i+1 false
    // 2<1 false 3<2 4<3 5<4 all false
    // in this case we have to just reverse the array
    // [5 4 3 2 1] so the next permutation become
    // [1 2 3 4 5]
    if (index == -1)
    {
        reverse(arr, arr + n);
        // return arr;
    }

    // after the finding the break point now we have to
    // find the next greater element and swap with our
    // break point element  //  0  1 / 2  3  4  5  6
    //[ 2, 1/, 5, 4, 3, 0, 0 ]
    // her at index 1 break point lies we have to find
    // the next greater element in right side of array
    // so the options are 5, 4, 3, 0, 0 so we have find
    // the element that greter then our break point element
    // and less then other element present at right side
    // for this we run loop from i=n-1; last element of the array
    // to the break point index 1 backwords
    // checking the wich one in greater then i > index
    // after finding the largest we just swap them

    for (int i = n - 1; i > index; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }

    // after the swapping with brakepoint element with next greater
    // element the array look like  {2, 3, 5, 4, 1, 0, 0}.
    // but we can see the right half remains sorted in decreasing
    // 5 4 1 0 0 it should look like 0 0 1 4 5 for the correct answer
    // so we just reverse it form arr+index+1 means
    //  0  1  2  3  4  5  6   so index + 1 = 1+1 = 2
    // {2, 3, 5, 4, 1, 0, 0}.     5 to n end of the array
    reverse(arr + index + 1, arr + n);
    // after the reverse the answer looks like
    //{2, 3, 0, 0, 1, 4, 5}
    print_array(arr, n);

    // TC = O(n) + O(n) + O(n) two loop + 1 reverse
    // == O(3n) worse case the avarage case it goes
    // O(2N)
    // SC = O(1)
}

void Leaders_in_an_Array(int arr[], int n)
{
    // [10, 22, 12, 3, 0, 6]  so the leaders in the array are
    // the element in the array said to be leader if
    // that element is greter then all element on its right side
    // let take 10 its not a leader becuse its not greter then
    // 22 lets take 22 and compair with all right side elements
    // 22>12 true 22>3 22> 0 and 22> 6 so the 22 its the leader

    //  10, 22, 12, 3,0,6  L-> 22 12 6
    // vector<int> ans;

    // for (int i = 0; i < n; i++)
    // {
    //     bool valid = true;
    //     for (int j = i + 1; j < n; j++) {
    //         if (arr[i] > arr[j]) {
    //             valid = false;
    //             break;
    //         }
    //     }

    //     if (valid)
    //     {
    //         ans.push_back(arr[i]);
    //     }
    // }
    // for (int it : ans)
    // {
    //     cout << it << " ";
    // } // O(n^2) sc = O(n)

    // optimal solution
    int maxi = INT_MIN;
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
        }

        maxi = max(maxi, arr[i]);
    }
    for (int it : ans)
    {
        cout << it << " ";
    }
    // TC = O(n) SC = O(n)
}

void Longest_Consecutive_Sequence(int arr[], int n)
{
    //  nums = [100,4,200,1,3,2]  Output: 4
    // The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    // brute force solution
    // int longest = 1;

    // for (int i = 0; i < n; i++)
    // {
    //     int x = arr[i];
    //     int count = 1;

    //     for (int i = 0; i < n; i++)
    //     {
    //         if (arr[i] == x + 1)
    //         {
    //             x = x + 1;
    //             count = count + 1;
    //         }

    //     }
    //      longest = max(longest, count);

    // }
    // cout<< longest;  // TC = O(n^2) SC = O(1)

    // better solution using sort
    // sort(nums.begin(), nums.end());

    //     int longestStreak = 1;
    //     int currentStreak = 1;

    //     for (int i = 1; i < nums.size(); i++) {
    //         if (nums[i] != nums[i - 1]) {
    //             if (nums[i] == nums[i - 1] + 1) {
    //                 currentStreak++;
    //             } else {
    //                 longestStreak = max(longestStreak, currentStreak);
    //                 currentStreak = 1;
    //             }
    //         }
    //     }
    //    return max(longestStreak, currentStreak);
    // TC = O(2n) SC = O(1)

    // optimal solution
}

void Set_Matrix_Zeroes(int arr[4][4], int n , int m)
{
    //    int matrix = [[1,1,1],     if we founde any element 0
    //                  [1,0,1],     so set entire row and column
    //                  [1,1,1]]     0s

    // output          [[1,0,1],
    //                  [0,0,0],
    //                  [1,0,1]]

    // int n = matrix.size();
    // int m = matrix[0].size();

    // vector<int> row(n, 0);
    // vector<int> col(m, 0);

    // for(int i=0; i<n; i++)
    // {
    //     for(int j =0; j<m; j++)
    //     {
    //         if(matrix[i][j] == 0)
    //         {
    //             row[i] = 1;
    //             col[j] = 1;
    //         }
    //     }
    // }

    // for(int i = 0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)
    //     {
    //         if(row[i]==1 || col[j]==1)
    //         {
    //             matrix[i][j] = 0;
    //         }
    //     }
    // }
    // TC = (n*m) + (n*m) = O(2*n*m)
    // SC = O(n+m)
}

void rotate_array_ninty_degree(int arr[3][3], int n, int m)
{
    //  original          after rotating by 90
    // [[1,2,3],          [[7,4,1]
    // [4,5,6],            [8,5,2]
    // [7,8,9]]            [9,6,3]]
    
    //  brute force solution using the another array for 
    // storing the rotated array

    // int ans[4][4];

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         ans[j][n-1-i] = arr[i][j];
    //     }
    // }

    // // Printing the rotated 2D array
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // optimal solution using tranpose of matrix where the each col
    // become row her 1 2 3 are colume elements and they become row element by transpse method
    // after we the swap each row for rotating the array
    //  [[1,2,3],          [1 4 7]       [7 4 1]
    //  [4,5,6],    -->    [2 5 8]  -->  [8 5 2]
    // [7,8,9]]            [3 6 9]       [9 6 3]
    //  orinal array     transpose       after reverse 
        // int n = matrix.size();

        // for(int i =0; i<n; i++)
        // {
        //     for(int j=i+1; j<n; j++)
        //     {
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }

        // for(int i=0; i<n; i++)
        // {
        //     reverse(matrix[i].begin(), matrix[i].end());
        // }

}

void Spiral_Matrix_print(int arr[4][4], int n, int m)
{
    /*
      matrix = [[1,2,3],  so its print like 1 2 3 6 9 8 7 4 5 
               [4,5,6],
               [7,8,9]]
    */
   // optimal solution 
   
}


int main()
{

    int nums[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 3;
    int m = 3;
    // int target = 9;

    // std::pair<int, int> result = two_sum(nums, n, target);
    // if (result.first != -1 && result.second != -1)
    //     std::cout << "Indices: " << result.first << ", " << result.second << std::endl;
    // else
    //     std::cout << "No pair found" << std::endl;

    // two_sum(nums, n, target);

    // Sort_an_array_of_zeros_once_and_two(nums, n);

    // cout << Majority_Element(nums, n);

    // cout << Maximum_Subarray_Sum(nums, n);

    // Best_Time_to_Buy_and_Sell_Stock(nums, n);

    // Next_Permutation(nums, n);

    // Leaders_in_an_Array(nums, n);

       rotate_array_ninty_degree(nums,n,m);

    return 0;
}