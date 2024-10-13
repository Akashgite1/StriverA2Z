#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// print array function
void p(int arr[], int n)
{
    cout << "printing the Array " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// selection sort algorithm
// its work on the select the minimum from the array
// swap with first element and after swap with i+1

void selection_sort(int arr[], int n)
{
    // for each i=1 j runs n times
    for (int i = 0; i < n; i++)
    {
        // assume the minimum value is at i
        int min_index = i;

        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        // swap function
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;

        // we can use in built function as well works same
        // swap(arr[i], arr[min_index]);
    }
}

void bubble_Sort(int arr[], int n) 
{
    //write your code here
    for (int i = 0; i < n; i++)
    {   
        int didswap = 0;
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didswap = 1;
            }
        }
        // if the array is sorted its break it
        if(didswap == 0) {
            break;
        }
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <=n-1; i++)
    {   int j = i;
        while (j > 0 && arr[j-1] > arr[j])
        {
            // swap function 
            int temp;
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }
}


int main()
{
    int arr[] = {90, 5, 12, 34, 56, 7, 9};
    int n = 7;

    p(arr, n);
    // selection_sort(arr,n);
    // p(arr,n);

    // bubble_Sort(arr, n);
    // p(arr, n);

    insertion_sort(arr,n);
    p(arr,n);

    return 0;
}