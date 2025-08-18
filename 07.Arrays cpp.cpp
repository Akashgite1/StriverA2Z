#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//! -------------------------------->  Array problems in cpp  <-----------------------------------------
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

//^                               Easy quation of array


//! Q finding the largest elemnt in tha Array
void large_elemenet_arry(int arr[], int n)
{
    // Brute force solution for this is to sort the arry
    // return the last element of the array
    // sort(arr);
    // cout<<arr[n-1]; where the n is the size of the array

    // optimal solution
    // consider 1st element of the array as largest
    int i = 0;
    int max = arr[i];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "largest element is the array is " << max;
}

//! Q finding the second largest element in the array
void second_largest(int arr[], int n)
{
    // int large = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i]>large)
    //     {
    //         large = arr[i];
    //     }

    // }
    // cout<<"largest element is the array is "<<large<<endl;

    // int second_largest = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i]>second_largest && arr[i]!=large)
    //     {
    //         second_largest =  arr[i];
    //     }

    // }
    // cout<<"second largest ele in the array is "<<second_largest;

    int largest = arr[0];
    int second_largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second_largest)
        {
            second_largest = arr[i];
        }
    }
    cout << "second largest element in arry is " << second_largest << endl;
}

//! Q finding the smallest element in the array
void smallest_ele(int arr[], int n)
{
    int small = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
        }
    }
    cout << "the smallest element is arry is " << small;
}

//! Q finding the second smallest element in the array
void second_small_ele(int arr[], int n)
{
    int small = arr[0];
    int second_smallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < small)
        {
            second_smallest = small;
            small = arr[i];
        }
        else if (arr[i] != small && arr[i] < second_smallest)
        {
            second_smallest = arr[i];
        }
    }
    cout << "second smallest in the arry is " << second_smallest;
}

//! check if the array is sorted or not
int check_sorted_array(int arr[], int n)
{
    // checking if the array is sorted or not
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            return false;
        }
    }
    return true;

    // for (int i = 0; i < n - 1; i++) {
    //     if (arr[i] > arr[i + 1]) {
    //         return false;
    //     }
    // }
    // return true;
}

//! remove deplicate element from the array
int remove_duplicate(int arr[], int n)
{
    // brute force solution
    // set<int> st;
    // for(int i = 0; i<n; i++)
    // {
    //     st.insert(arr[i]);
    // }
    // cout<< st.size();

    // optimal solution
    int i = 0;

    for (int j = 1; j < n; j++)
    {

        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

//! left rotate the array by one place
void left_rotate_array(int arr[], int n)
{
    // shifting by one place to left in the array
    // brute force solution 0 1 2 3 4
    // using another array {1,2,3,4,5}
    //   int temp[n];

    //   for (int i = 1; i < n; i++)
    //   {
    //       temp[i - 1] = arr[i];
    //   }
    //   // insert the 1st element into last
    //   temp[n - 1] = arr[0];
    //    // calling the function for printing the array
    //    print_array(temp,n); // TC = O(n) SP= O(n)

    // optimal solution using pointers
    // storing the first element of arr in variable
    // shifting elements in the array by i-1
    //  0 1 2 3 4
    // {1,2,3,4,5}
    int temp = arr[0];

    for (int i = 0; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    print_array(arr, n); // Tc=O(n) SC=O(1)
}

//! left rotate the array by k places
void left_rotate_by_k_places(int arr[], int n, int k)
{
    // brute force
    // making the temp arr for storing the k elements
    // int temp[k];
    // //now insert elements in the temp arry
    // for (int i = 0; i < k; i++)
    // {
    //     temp[i] = arr[i];
    // }
    // // now shift the k+1 elements the same array
    // for (int i = k; i < n; i++)
    // {
    //     arr[i-k] = arr[i];
    // }

    // // insert the temp to back in the array
    // int j = 0;
    // for (int i = n-k; i < n; i++)
    // {
    //      arr[i] = temp[j];
    //      j++;
    // }
    // print_array(arr,n);

    // optimize the solution for space complaxity
    // reversing from 0 to k
    reverse(arr, arr + k);
    // reversing the array from k to n
    reverse(arr + k, arr + n);
    // reversing the entire array
    reverse(arr, arr + n);
    // printing the array
    print_array(arr, n);

    /*
    void Reverse(int arr[], int start, int end)
    {
        while (start <= end)
       {
         int temp = arr[start];
         arr[start] = arr[end];
         arr[end] = temp;
         start++;
         end--;
        }
    }
    */
}

//! right rotate the array by k places
void right_rotate_by_k_places(int arr[], int n, int k)
{
    // brute force solution
    // int temp[k];
    // for (int i = 0; i < k; i++)
    // {
    //     temp[i] = arr[n - k + i];
    // }
    // for (int i = n - k - 1; i >= 0; i--)
    // {
    //     arr[i + k] = arr[i];
    // }
    // for (int i = 0; i < k; i++)
    // {
    //     arr[i] = temp[i];
    // }
    // print_array(arr, n);

    // optimal solution
    // reverse the array from 0 to n-k
    reverse(arr, arr + n - k);
    // reverse the array from n-k to n
    reverse(arr + n - k, arr + n);
    // reverse the entire array
    reverse(arr, arr + n);
    print_array(arr, n);
}

//! move all zeros to end
void move_zeros_to_end(int arr[], int n)
{
    // brute force solution
    // find non zero elements and place them into a temp array
    // vector<int> temp;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i]!=0)
    //     {
    //         temp.push_back(arr[i]);
    //     }
    // }
    // // after removing the all non zero elements from the array
    // // the array become empty now insert the all elements back
    // // from the temp array to main array
    // int non_zero_elements = temp.size();
    // for (int i = 0; i < non_zero_elements; i++)
    // {
    //     arr[i] = temp[i];
    // }

    // //mark all remaining elements as 0 from the all non zero
    // // elements to n or end of the array
    // for (int i = non_zero_elements; i <n ; i++)
    // {
    //     arr[i] = 0;
    // }

    // print_array(arr,n); // TC O(n)+ O(x) + O(n-x) = O(2n)
    // SC O(x)

    //! optimal aproach
    // we use two pointer aproach i and j  j present at -1 and i=0
    // at first we finding 0th element in the array and update
    // that elements index to j
    // at next step we just swap the 0 element with next non zero-element

    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        { // TC = O(x)
            j = i;
            break;
        }
    }
    // again run the loop for swaping the 0 element with non-zero element
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]); // TC = O(n-x)
            j++;
        }
    }
    print_array(arr, n); // TC = O(x) + O(n-x) xx get cansel
                         // TC = O(n)
                         // SC = O(1)

    /*
        int left = 0;
        for(int right = 0; right<n; right++)
        {
             if(arr[i]!= 0)
             {
                 swap(arr[right], arr[left]);
                 left++;
             }
        }

               0 1 2 3
        arr = {0,0,0,1} left = 0;  right=0;
        condition if arr[i] means 0th element is not zero then swap
        if right index element with left index element
        since the at 0th index we have the 0 so we skip swap
        right++ right moves to 1th index
        skip swap right++ right moves to 2nd index
        her also present 0 skip swap right++ 3rd index
        her we have the 1 is not equal to 0 and left is at the 0th
        so we swap the right index 3 element 1 with left index 0 element 0
        the resul array look like

        arr[] = (1,0,0,0)

   */
}

//! union of two sorted arrays
vector<int> Union_of_two_sorted_Arrays(vector<int> a, vector<int> b)
{
    // brute force solution for finding union on two sets
    // {1,2,4,5}
    // {2,3,4,5,6}
    // un {1,2,3,4,5,6}
    // set<int> st;
    // int n = a.size();
    // int m = b.size();

    // for (int i = 0; i < n; i++){
    //     st.insert(a[i]);
    // }

    // for (int i = 0; i < m; i++){
    //     st.insert(b[i]);
    // }

    // // converting the set into vector
    // vector<int> result(st.begin(), st.end());
    // return result;

    // optimal approach using two pointer approach

    int n = a.size();
    int m = b.size();

    int i = 0;
    int j = 0;
    // a={1,2,4,5}
    // b={2,3,4,5,6}
    // un {1,2,3,4,5,6}
    vector<int> ans;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            if (ans.size() == 0 || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    while (j < m)
    {
        if (ans.size() == 0 || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }

    while (i < n)
    {
        if (ans.size() == 0 || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }

    return ans;
}

//! intersection of two sorted arrays
void intersection_of_arrays(int arr1[], int arr2[], int n, int m)
{
    int i = 0;
    int j = 0;

    vector<int> ans;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    for (auto it : ans)
    {
        cout << it;
    }
}

//! missing number in the array
void missing_no_in_array(int arr[], int n)
{
    //! brute force solution for this is
    // for (int i = 1; i < n; i++){
    //     // its basicaly the counter
    //     int counter = 0;

    //     // seariching the element like linerar search
    //     for (int j = 0; j < n; j++){
    //         if (arr[j] == i){
    //              counter = 1;
    //              break;
    //         }
    //                             //Tc = n*n O(n^2)
    //                             //SC = O(1)
    //     }

    //     // if counter returns 0 that means the element is
    //     // not present in the array in range 1 to n
    //     if(counter == 0){ cout<< i; }
    //! }

    // better solution using hasharray
    // we have to declare the hash array size of n+1
    // since array follows 0 based indexing if we suppose
    // the n=5 and we declare hash[n] so it will create
    // the array up to only that why we have to use n+1

    // declaring the hashArray with all 0 elements
    //  int hash_arr[n+1]={0};

    // //now  update the frequency of array elements in hashmap
    // // arr[] = (1 2 4 5) n = 5
    // //           0 1 2 3 4 5
    // // hashmap ={0,1,1,0,1,1}
    // for (int i = 0; i < n; i++)
    // {
    //     // if the element present it update it to 1
    //     hash_arr[arr[i]]=1;      //TC O(n)
    // }

    // for (int i =1; i < n; i++)
    // {
    //     if (hash_arr[i] == 0 )   //TC O(n)
    //     {
    //         cout<<i;
    //     }

    // } //TC = O(N) + O(n) = O(2n)
    // Sc = O(n)

    // optimal solution
    // there are 2 optimal solution available for this problem
    // her we use formula of sum = n * (n+1)/2;
    // and we get summetion of the array elements

    // int sum = n*(n+1)/2;     // n=5   5*(5+1)/2 = 30/2 =15
    // int ans = 0;
    // for (int i = 0; i <n-1; i++)
    // {
    //     ans = ans + arr[i];
    // }

    // // we minus the sum with summetion of array element for getting
    // // the missing number  return sum-ans;
    // cout<<sum-ans;

    // another optimal solution using the XOR
    // if we do any tow same number xor we get in return 0
    // 2^2 = 0
}

//! maximum consecutive number of 1's
void Max_Consecutive_number_of_one(int arr[], int n)
{
    // arr[] = {0,1,1,0,1,1,1,0,1,1,0} max = 3

    int maxi = 0;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            if (count > maxi)
            {
                maxi = count;
            }
            // max ( maxi , count) did the same thing if we declare
            // maxi =  max (maxi, count
        }
        else
        {
            count = 0;
        }
    }
    cout << maxi;
}

//! find element that apprears once
void Find_element_that_appears_once(int arr[], int n)
{
    // brute force solution
    // for (int i = 0; i <n; i++)
    // {
    //     int num = arr[i];
    //     int count = 0;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (arr[j] == num)
    //         {
    //             count++;
    //         }

    //     }
    //     if (count == 1)
    //     {
    //         cout<< num;
    //     }
    // } TC = O(n) * O(n) = O(n^2)  SC = O(1)

    // better solution is to use hashing
    // declare the hash array size of max element present in the array
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }

    int hashmap[maxi + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        hashmap[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hashmap[i] == 1)
        {
            cout << i;
        }
    }
    // TC = O(n) + O(n) + (n) = O(3n)
    // SC = O(x)

    // int xorr  =0;
    // for (int i = 0; i < n; i++)
    // {
    //     xorr = xorr ^ arr[i];
    // }
    // cout<<xorr;
    // TC = O(n)
    // SC = O(1)
}


//! -------------------------------->  Medium quation of array  <-----------------------------------------
//! Longest subarray with sum K 
int Longest_Subarray_with_sum_K(int A[], int N, int K)
{
    // Input: ‘n’ = 7 ‘k’ = 3
    // ‘a’ = [1, 2, 3, 1, 1, 1, 1]

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
    // cout << lenght; // TC = O(n^2) SC = O(1)

    // better solution
     map<int, int> preSumMap;

    int sum = 0;
    int max_length = 0;

    for (int i = 0; i < N; i++)
    {
        // calculating  the sum of sunArray
        sum = sum + A[i];

        // updating the sub array size if its equal to k
        if (sum == K)
        {
            // suppose we have the array
            //  0   1  2  3  4  5
            // {10, 5, 3, 7, 1, 9}
            // if the sub array found at 3 if we return only
            // but and size become 2 but what if we are
            // calculating from 1 becuse then it given 3 as
            // answer thats why i+1
            max_length = max(max_length, i + 1);
        }

        int remains = sum - K;

        // checking the remaining is available in map using find and also
        // check its not equal to the map last element
        if (preSumMap.find(remains) != preSumMap.end())
        {
            // Calculate the length of the subarray
            int len = i - preSumMap[remains];
            // Update the maximum length
            max_length = max(max_length, len);
        }
        
         // Store the current cumulative sum if it's not already in the map
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return max_length;
}

//! two sum problem
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

//! sort an array of 0s 1s and 2s without using extra space or sorting algo
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

//! find the majority element in the array
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

//! find the maximum subarray sum
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

//! Best time to buy and sell stock (only one transaction)
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

//! rearraange the array elements by sign 
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

//! Next permutation of the array
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

//! Learders in an Array 
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

//! longest consecutive sequence in an Array 
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

//! set matrix zeroes  (2D array) 
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

//! Rotate Array 90 degree  (2D array)
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

//! Spiral Matrix (2D array)
void Spiral_Matrix_print(int arr[4][4], int n, int m)
{
    /*
      matrix = [[1,2,3],  so its print like 1 2 3 6 9 8 7 4 5 
               [4,5,6],
               [7,8,9]]
    */
   // optimal solution 
   
}

//! find the repeating and missing number in an array
class findMissingRepeatingNumbers_IN_Array {
   public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
          long n = nums.size();
    
    long sumN = n * (n + 1) / 2;       // expected sum of 1..n
    long sumSqN = n * (n + 1) * (2*n + 1) / 6; // expected sum of squares

    long sum = 0, sumSq = 0;
    for (int x : nums) {
        sum += x;
        sumSq += 1L * x * x;
    }

    // equations:
    // A - B = sum - sumN
    // A^2 - B^2 = sumSq - sumSqN
    // => (A - B)(A + B) = diffSq
    long diff = sum - sumN;             // A - B
    long diffSq = sumSq - sumSqN;       // A^2 - B^2

    long sumAB = diffSq / diff;         // A + B

    long A = (diff + sumAB) / 2;
    long B = A - diff;

    return {(int)A, (int)B};
    }
};

//! 152. Maximum Product Subarray
class Maximum_Product_Subarray {
public:
    int maxProduct(vector<int>& nums) {
        // sliding window approach
        int n = nums.size();
        int maxProduct = nums[0];
        int currentProduct = 1;

        for (int i = 0; i < n; i++) {
            currentProduct *= nums[i];
            maxProduct = max(maxProduct, currentProduct);
            if (currentProduct == 0) {
                currentProduct = 1; // reset if product is zero
            }                           
        }
        
    }
};


int main()
{
    // vector<int> nums = {1, 2, 3, 6, 7, 5, 7};
    // findMissingRepeatingNumbers_IN_Array obj;
    // vector<int> result = obj.findMissingRepeatingNumbers(nums);
    // cout << "Repeating Number: " << result[0] << endl;
    // cout << "Missing Number: " << result[1] << endl;



    return 0;
}


