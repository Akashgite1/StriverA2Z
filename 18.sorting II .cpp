#include<bits/stdc++.h>
#include<iostream>

using namespace std;
// quick sort 
// merge sort 

void quick_sort(int arr[], int n)
{
    // at quick sort we are creating three pointers 
    // low high and pivot 
    // low preset at 0th index 
    // high shows the last index nth
    // pivot is random element form the array
    //          l             h
    // arr[] = {4,6,2,5,7,9,1,3}
    // consider the pivot as arr[first_element] low we can simple 
    // define like int pivot = arr[low];

    
}

void merge_sort(int arr[], int n)
{
    // it working by dividing sorting and merging 
    // we divide the array in half for example 
    //  {3,1,2,4,1,5,2,6,4} total elements 10 divide by 2 = 5
    //             {3,1,2,4,1,5,2,6,4,3}
    //                  /           \
    //            {3,1,2,4,1}     {5,2,6,4,3}
    //               / \           /       \
    //        {3,1,2}  {4,1}   {5,2,6}    {4,3}
    //         / \       / \      /  \     /  \
    //        /  \      /  \     /   \     /  \
    //     {3,1} {2}  {4} {1}  {5,2} {6} {4} {3}
    //       /                   / 
    //   {3} {1}              {5} {2}

    // dividing the array is complete now first 3 ,1 sorted as 1 ,3
    // merged move next we compaire it with 2 since it contains only 
    // single element and it cannot broke further we compire it with 
    // 1,3 since 2 smaller then  then the array sort & merged as 
    // 1 ,2 ,3 next sub array is 4,1 divide further as 4 , 1 
    // sort & and merged as 1,4 compair it with current array it becomme 
    // 1,1,2,3,4 moves next array 5 2 6 4 3 divide it further
    // it become 5 2 6  and 4 3 
    // it further divide it into 
    //  5 2 and 6 
    // 5 and 2 now sort and merging it become 
    // 2 ,5 since 6 is bigger then 5 then it merged with the array
    // array become 2 , 5 ,6 moving to the next array 4 3 divide it 
    // sort it and merged it become 3 4 and compair it with 2 5 6 
    // sort and merged it become 2 3 4 5 6 now compair it with 
    // 1 1 2 3 4 sub-array and 2 3 4 5 6 
    // after sorting and merging the array become 
    //  sorted array  [ 1 1 2 2 3 3 4 4 5 6 ]

    // implemanting the code
    
}

int main (){
    
    return 0;
}