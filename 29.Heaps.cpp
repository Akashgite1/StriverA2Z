#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//! Heaps also know as (priority queues) are a type of binary tree that satisfies the heap property. The heap property states that a parent node must be greater than or equal to its child node.
//~ heaps problems mostly based on sorting where we use the heap sort
//~ heap is a complete binary tree there two types of heap max heap and min heap
//~ max heap the root node is the largest element in the tree
//~ min heap the root node is the smallest element in the tree
//~ hepify is the process of converting the normal array into the heap

// heap implementation using arrays time complexity O(logn) for insertion and deletion
//! implementing the max heap using arrays
class MAX_heap
{

public:
    // declared the array of size 100
    int arr[100];
    int size = 0;

    // constructor
    // why constructor is used?
    MAX_heap()
    {
        // setting the first index to -1 since we are not using the 0th index
        arr[0] = -1;
        // setting the size to 0 since there is nothing in the heap
        size = 0;
    }

    // function for inserton in heap
    void insert(int val)
    {
        // increse the size of the heap
        size++;

        // insert the value at the last index
        // get the last index since size is always poiting the current empty index or the last index
        int index = size;
        // insert the value at the last index
        arr[index] = val;

        // swapping thd inserted value to its correct position in the heap
        // run unit the root node and if the root node come then stop since there is no other parent node for the first root node
        while (index > 1)
        {
            // get the parent index of the current index
            int parent = index / 2;

            // if the index is greater than its parent then swap the values
            if (arr[parent] < arr[index])
            {
                // swap the values
                swap(arr[parent], arr[index]);
                // upadate the index to current swapped parent so we can check the next value with its parent
                index = parent;
            }
            // if the index is not greater than its parent then break the loop
            else
                return;
        }
    }

    // function for printing the heap array
    void print()
    {
        // starting from 1 since there is nothing in the 0th index
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // deletion in heap
    void delete_From_Heap()
    {

        if (size == 0)
        {
            cout << "Heap is empty nothing to delete" << endl;
            return;
        }

        // this process also called as heapify
        // swap the root node with the last node not exactly swap nut declaring the last node as the root node
        arr[1] = arr[size];
        size--;

        // take root node to its correct position
        int i = 1;
        while (i <= size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            // if the current root node is smaller then its left child and the left child is greater than the right child then swap the root node with the left child
            if (left <= size && arr[i] < arr[left])
            {
                // swap the current root node with the left child
                swap(arr[i], arr[left]);
                // update the root node to the left child for further checking
                i = left;
            }
            // if the current root node is smaller then its right child and the right child is greater than the left child then swap the root node with the right child
            else if (right <= size && arr[i] < arr[right])
            {
                // swap the current root node with the right child
                swap(arr[i], arr[right]);
                // update the root node to the right child for further checking
                i = right;
            }
            else
            {
                return;
            }
        }
    }
};

//! heapify function for converting any normal arry to max heap
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Assume root is the largest
    int left = 2 * i;      // Left child index
    int right = 2 * i + 1; // Right child index

    // If the left child is larger than the root
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }

    // If the right child is larger than the largest
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    // If the largest is not root, swap and heapify
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

//! heapify function for min heap
void heapify_min(int arr[], int n, int i)
{

    int smallest = i;      // root node
    int left = 2 * i + 1;  // point left child
    int right = 2 * i + 2; // point right child

    // if the left child is smaller than the root node
    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }

    // if the right child is smaller than the root node
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    // if the smallest is not the root node
    if (smallest != i)
    {
        // swap the root node with the smallest child
        swap(arr[i], arr[smallest]);
        // call the heapify function recursively
        heapify_min(arr, n, smallest);
    }
}

//! check if the arr if min heap or not
bool isMaxHeap(int arr[], int n)
{
    // Your code goes here
    // Traverse all non-leaf nodes
    for (int i = 0; i <= (n / 2) - 1; i++)
    {
        // follow the 1 based indexing
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check the left child
        if (left < n && arr[i] < arr[left])
        {
            return false;
        }

        // Check the right child
        if (right < n && arr[i] < arr[right])
        {
            return false;
        }
    }
    return true;
}

//! convert min heap to max heap
class Solution
{
public:
    void heapify_max(vector<int> &arr, int n, int i)
    {
        int largest = i;       // Assume the root is the largest
        int left = 2 * i + 1;  // Left child index
        int right = 2 * i + 2; // Right child index

        // If left child exists and is larger than the current largest
        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        // If right child exists and is larger than the current largest
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        // If the largest is not the root, swap and recurse
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify_max(arr, n, largest); // Recurse to maintain heap property
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N)
    {

        for (int i = N / 2; i >= 0; i--)
        {
            heapify_max(arr, N, i);
        }
    }
};

//! heap sort time complexity O(nlogn)
//~ heap sort work
// 1. convert the array into a max heap
// 2. swap the first node with the last node
// 3. make the array again a max heap
// 4. repeat the process until the array is sorted
void heapSort(int arr[], int n)
{
    // convert the array into a max heap now the max element is at the root
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // we are starting from the last index and every time we are reducing the size of the array by 1 since the last element is already sorted and we are placing the max element at the last index
    for (int i = n - 1; i > 0; i--)
    {
        // replacing the first node with the last node or root node with the last node
        swap(arr[0], arr[i]);

        // making the array again a max heap
        heapify(arr, i, 0);
    }
}

//! kth largest element in an array using heap
int kth_largest_element(vector<int> arr, int k)
{
    int n = arr.size();

    // declaring the min heap since we want the kth largest element
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // insert the elements of the array into the max heap
    for (int i = 0; i < n; i++)
    {
        min_heap.push(arr[i]);

        // if it exceeds the kth element then pop the top element
        if (min_heap.size() > k)
        {
            min_heap.pop();
        }
    }

    // return the kth largest element
    return min_heap.top();
}

//! kth smallest element in an array using heap
int kth_smallest_element(vector<int> arr, int k)
{

    int n = arr.size();

    // declaring the max heap since we want the kth smallest element
    priority_queue<int> max_heap;

    for (int i = 0; i < n; i++)
    {

        // insert the elements of the array into the min heap
        max_heap.push(arr[i]);

        if (max_heap.size() > k)
        {
            max_heap.pop();
        }
    }

    return max_heap.top(); // return the kth smallest element
} // tc O(nlogk) sc O(k)

// we can push all the element in queue and then pop the top element k times
// then also we get the kth largest element
int kth(vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // Push all the elements in the queue
    for (int i = 0; i < arr.size(); i++)
    {
        min_heap.push(arr[i]);
    }

    // Pop the top element k times
    while (min_heap.size() > k)
    {
        min_heap.pop();
    }
    // Return the kth largest element
    return min_heap.top();
}

//! sort k sorted array using heap
// given a k sorted array we have to sort the array
// ex arr = {6,5,3,2,8,10,9} k = 3
// output = {2,3,5,6,8,9,10}
vector<int> K_Sorted_array(vector<int> arr, int k)
{

    // create the answer vector for storing the sorted array
    vector<int> ans;

    // create the min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // push the first k elements in the min heap
    for (int i = 0; i <= k; i++)
    {
        min_heap.push(arr[i]);
    }

    // push the top element in the answer vector
    ans.push_back(min_heap.top());

    // push the remaining elements in the min heap
    for (int i = k + 1; i < arr.size(); i++)
    {
        min_heap.push(arr[i]);
        ans.push_back(min_heap.top());
        min_heap.pop();
    }

    // push the remaining elements in the answer vector
    while (!min_heap.empty())
    {
        ans.push_back(min_heap.top());
        min_heap.pop();
    }

    // return the answer vector
    return ans;
}

//! if you have given the k sorted array in the 2d array
// making the custom data and comparator function for the priority queue
// declaring the struct for the getting the element value and its row and colum value
// struct Element
// {
//     int value;
//     int row;
//     int col;
//     bool operator>(const Element &other) const
//     {
//         return value > other.value;
//     }
// };
// vector<int> mergeKArrays(vector<vector<int>> arr, int K)
// {
//     priority_queue<Element, vector<Element>, greater<Element>> minHeap;
//     vector<int> result;
//     // Push the first element of each subarray into the min-heap
//     for (int i = 0; i < arr.size(); i++)
//     {
//         minHeap.push({arr[i][0], i, 0});
//     }
//     while (!minHeap.empty())
//     {
//         // Pop the minimum element
//         Element minElem = minHeap.top();
//         minHeap.pop();
//         // Add the popped element to the result
//         result.push_back(minElem.value);
//         // If the current subarray has more elements, push the next element
//         if (minElem.col + 1 < arr[minElem.row].size())
//         {
//             minHeap.push({arr[minElem.row][minElem.col + 1], minElem.row, minElem.col + 1});
//         }
//     }
//     return result;
// }

//! merge k sorted arrays linked list
// given a vector of linked list we have to merge all the linked list into one linked list
// ex arr = {{1,3,5,7},{2,4,6,8},{0,9,10,11}}
// output = {0,1,2,3,4,5,6,7,8,9,10,11}
// we can use the priority queue for the merging the linked list
// defining the linklist
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// function for merging the linked list using the priority queue
ListNode *mergeKLists(vector<ListNode *> &lists)
{

    // Declare the priority queue (min-heap)
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>,
                   greater<pair<int, ListNode *>>>
        pq;

    // Push the head of each non-empty linked list into the priority queue
    for (auto it : lists)
    {
        if (it)
        { // Ensure the list is not empty
            pq.push({it->val, it});
        }
    }

    // Create a dummy node to simplify result list construction
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy; // Pointer for constructing the new list

    // Process nodes in the priority queue
    while (!pq.empty())
    {
        // Get the smallest node
        auto it = pq.top();
        pq.pop();

        // Add the smallest node to the new list
        temp->next = it.second;
        temp = temp->next;

        // If there's a next node in the current list, push it into the
        // queue
        if (it.second->next)
        {
            pq.push({it.second->next->val, it.second->next});
        }
    }

    // Return the head of the merged list
    return dummy->next;
}

//! Replace elements by its rank in the array
// Define a pair for heap element with value and index
using Element = pair<int, int>;
vector<int> replaceWithRank(vector<int> &arr, int N)
{

    vector<Element> indexed_arr;

    // Step 1: Create a vector of pairs (value, original index)
    for (int i = 0; i < N; ++i)
    {
        indexed_arr.push_back({arr[i], i});
    }

    // Step 2: Create a min-heap to store elements in ascending order based on value
    priority_queue<Element, vector<Element>, greater<Element>> min_heap;

    // Push all elements into the min-heap
    for (auto &elem : indexed_arr)
    {
        min_heap.push(elem);
    }

    // Step 3: Create a vector to store the ranks and a map to track the first occurrence of each value
    vector<int> result(N);
    unordered_map<int, int> rank_map;
    int rank = 1;

    // Step 4: Assign ranks based on sorted order
    while (!min_heap.empty())
    {
        Element current = min_heap.top();
        min_heap.pop();

        int value = current.first;
        int index = current.second;

        // If this value hasn't been assigned a rank before, assign it the current rank
        if (rank_map.find(value) == rank_map.end())
        {
            rank_map[value] = rank++;
        }

        // Assign the rank to the result at the original index
        result[index] = rank_map[value];
    }

    return result;
}

//! 621. Task Scheduler
int leastInterval(vector<char> &tasks, int n)
{
    // heaps + greedy solution
    vector<int> mp(26, 0);

    // Count the frequency of each task
    for (char c : tasks)
    {
        mp[c - 'A']++;
    }

    int time = 0;
    // create the max heap
    priority_queue<int> pq;

    // pushing all element freq in the max heap for sorting in descending order
    for (int i = 0; i < 26; i++)
    {
        if (mp[i] > 0)
        {
            pq.push(mp[i]);
        }
    }

    while (!pq.empty())
    {
        vector<int> temp;
        for (int i = 1; i <= n + 1; i++)
        {
            if (!pq.empty())
            {
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }
        }
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] > 0)
            {
                pq.push(temp[i]);
            }
        }
        if (pq.empty()) // all processes finished
            time += temp.size();
        else
            time += n + 1; // we finished p+1 tasks above in the loop
    }
    return time; 
}


//! 846 Hand of Straights
bool isNStraightHand(vector<int>& hand, int groupSize) {
       
}




int main()
{
    //! heap implementation using arrays and its operations insert and delete
    // making the object of the heap class
    // MAX_heap h;
    // // calling the function insert using the object we just created
    // h.insert(60); // at index 1
    // h.insert(50); // at index 2
    // h.insert(40); // at index 3
    // h.insert(30); // at index 4
    // h.insert(20); // at index 5
    // h.print();    // 40 20 30 10
    // // deleting the root node
    // h.delete_From_Heap();
    // h.print(); // 30 20 10
    // h.insert(70);
    // h.print(); // 70 30 10 20

    //! heapify function converting any normal array to heap
    // normal array converting to max heap
    // int arr[6] = {-1,54,53,55,52,50};
    // int n = 8; // Size of the array
    // // Convert the array into a max heap
    // for (int i = n / 2; i > 0; i--)
    // {
    //     heapify(arr, n, i); // Heapify each node starting from the last non-leaf node
    // }
    // // Print the max-heap
    // for (int i = 1; i <n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //! check if the array is max heap or not
    // int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
    // int n = 8;
    // cout << isMaxHeap(arr, n);

    //! convert min heap to max heap
    // Solution s;
    // vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9}; // Min heap
    // // output should be 20 18 10 12 9 9 3 6 5 8
    // int N = arr.size();
    // s.convertMinToMaxHeap(arr, N);
    // for (int i = 0; i < N; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    //! heap sort
    // int arr[] = {12, 11, 13, 5, 6, 7};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // heapSort(arr, n);
    // cout << "Sorted array is \n";
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    //! heap by the priority queue using stl
    // its by default max heap in max heap the top element is max element
    // priority_queue<int> pq;
    // pq.push(10);
    // pq.push(15);
    // pq.push(5);
    // pq.push(20);
    // // print the top element
    // cout << pq.top() << endl; // printing the top element 20
    // pq.pop(); // removing the top element
    // cout << pq.top() << endl; // 15 next max element after the poping 20
    // pq.size(); // size of the heap
    // pq.empty(); // check if the heap is empty or not

    //! declaring the min heap
    // priority_queue<int, vector<int>, greater<int>> min_heap;
    // min_heap.push(10);
    // min_heap.push(15);
    // min_heap.push(5);
    // min_heap.push(20);
    // // print the top element
    // cout << min_heap.top() << endl; // printing the top element 5
    // min_heap.pop(); // removing the top element
    // cout << min_heap.top() << endl; // 10 next min element after the poping 5
    // min_heap.size(); // size of the heap
    // min_heap.empty(); // check if the heap is empty or not

    //! kth largest element in an array using heap
    // vector<int> arr = {7, 10, 4, 3, 20, 15}; // kth largest element is 10
    // int k = 3;
    // cout << kth_largest_element(arr, k) << endl; tc O(nlogk) sc O(k)

    //! kth smallest element in an array using heap
    // vector<int> arr = {7, 10, 4, 3, 20, 15}; // kth smallest element is 7
    // int k = 2;
    // cout << kth_smallest_element(arr, k) << endl; tc O(nlogk) sc O(k)

    //! sort k sorted array using heap
    // vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    // int k = 3;
    // vector<int> ans = K_Sorted_array(arr, k); // 2 3 5 6 8 9 10
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    //! if you have given the k sorted array in the 2d array
    // vector<vector<int>> arr = {{1, 2, 3, 4}, {2, 2, 3, 4}, {5, 5, 6, 6}, {7, 8, 9, 9}};
    // int k = 4;
    // vector<int> ans = mergeKArrays(arr, k);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    return 0;
}