#include <bits/stdc++.h>
#include <set>
#include <iostream>

using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// easy quation of array
// Q finding the largest elemnt in tha array
void large_elemenet_arry(int arr[], int n)
{
    // brute force solution for this is to sort the arry
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

// home work right rotating by k places

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

// finding the missing numbers from the array

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

int find_the_subArray_equal_to_k(int A[], int N, int K)
{

}

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



int main()
{

    int arr[] = {1, 2, 3, 1, 1, 1, 1};
    int n = 7;
    int k = 3;

    // int arr1[] = {1,2,0,4,0,6,7};
    // int m = 7;

    // large_elemenet_arry(arr,n);
    // second_largest(arr,n);

    // smallest_ele(arr,n);
    // second_small_ele(arr,n);

    // boolen function alwasy use cout for see the result
    // cout<< check_sorted_array(arr,n);

    // cout<< remove_duplicate(arr1,m)<<endl;
    // for (int i = 0; i < m; i++)
    // {
    //     cout<<arr1[i];
    // }

    // left_rotate_array(arr1,m);

    // left_rotate_by_k_places(arr1,m,3);

    // move_zeros_to_end(arr1,m);

    // vector<int> a = {1, 2, 3, 4, 5};
    // vector<int> b = {2, 3, 4, 6};
    // vector<int> result = Union_of_two_sorted_Arrays(a, b);

    // cout << "Union : ";
    // for (int i : result) {
    //     cout << i << " ";
    // };

    // vector<int> a = {1, 2, 3, 4, 5};
    // vector<int> b = {2, 3, 4, 6};
    // vector<int> ans = Union_of_two_sorted_Arrays(a, b);

    // cout << "Union : ";
    // for (int i : ans) {
    //     cout << i << " ";
    // };

    // missing_no_in_array(arr, n);

    // Max_Consecutive_number_of_one(arr,n);

    // Find_element_that_appears_once(arr, n);

    Longest_Subarray_with_sum_K(arr, n, k);

    return 0;
}