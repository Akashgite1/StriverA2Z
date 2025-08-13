#include <bits/stdc++.h>
#include <iostream>
#include<map>
#include<vector>

//! HASHINGN METHODS 

using namespace std;

// Q.1 count the how mant time our input number appear in in the array
// for example we have the array =[1,2,1,3,2]
// we have to check that  how many times 2,3,4,1 appear in the array
// 2 - 2 times
// 3 - 1
// 4 - 0
// 1 - 2

// brute force solution for it
int find(int arr[], int num, int n)
{
    int count = 0; // intilize count for getting the count of numbers

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            count = count + 1;
        }
    }
    return count;
}

// calculates the frequency of each element in the array using a hash map technique
void f(int arr[], int n)
{
    // declaring the hash array stroring the frequens of elements
    int hash[13] = {0};
    for (int  i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }
    
    // getting the that how much quaries we have to find out 
    int q;
    cout<<"enter size of quary"<<endl;
    cin>>q;
    while (q--)
    {   
        // giving the number 
        int number;
        cout<<"search the element "<<endl;
        cin>>number;
        cout<<"present : "<<hash[number] <<" times"<<endl;
    }
    
}

// calculates the frequency of characters 
void freqstring (string s)
{
    // since the alphabate letter are 26 
    int hash[26] = {0};

    // storing the frequences of the characters in hash array
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] -'a'] ++;
    }

    // getting the quaries and return the answer
    int q;
    cin>>q;
    while (q--)
    {
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }

}

void check_for_freq(string s)
{
    int hash[256] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]] ++;
    }

    // getting the quaries 
    int q;
    cin>>q;
    while(q--)
    {
        char c;
        cin>>c;

        cout<<hash[c]<<endl;
    }
    
}

void freq(int arr[], int n)
{
    // printing the frequence of the elements using the map
    // map store the values like 
    // map< int,  int  >
    //      key  values
    // keys are elements from the array
    // values are count of the them 
    // <1,2> 1 is present 2 times in array 

    map<int ,int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] ++;
    }

    // printing the map elements 
    for (auto it: mpp)
    {
        cout<<it.first<<"->"<<it.second<<endl;
    }

    // for (auto it = mpp.begin(); it != mpp.end(); it++)
    // {
    //     cout<<it.first<<"->"<<it.second<<endl;
    // }
    

    // quaries 
    int q;
    cin>>q;
    while (q--)
    {
        int num;
        cin>>num;
        cout<<mpp[num]<<endl;
    }
    
}

void string_freq_usign_maps(string s)
{
    // declaring the map 
    map<char,int> mpp;
    
    // storing the freq of the characters 
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]] ++;
    }

    // printing the freq of the characters 
    for(auto it : mpp)
    {
        cout<<it.first<<"->"<<it.second<<endl;
    }
    
}

void string_freq_usign_unorderd_maps(string s)
{
    // declaring the unorderd map 
    // the only diffrence her is the map store the element in sorted way
    // and the unorderd map store with no order 
    // if the map store like 1 2 3 4 5 6
    // unorderd map store like 4 5 1 3 2 6  no order 
    unordered_map<char,int> mpp;
    
    // storing the freq of the characters 
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]] ++;
    }

    // printing the freq of the characters 
    for(auto it : mpp)
    {
        cout<<it.first<<"->"<<it.second<<endl;
    }
    
}

// Problem Statement: Given an array of size N. Find the highest and lowest frequency element.

void find_lowest_and_highest(int arr[],int n)
{
    map<int,int> mpp;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] ++;
    }

    int min = INT_MAX;
    int min_ele = -1;

    int max = INT_MIN;
    int max_ele = -1;
    
    for(auto p: mpp)
    {
        if(min > p.second)
        {
            min = p.second;
            min_ele = p.first;
        }
        if(max < p.second)
        {
            max = p.second;
            max_ele =p.first;
        }

    }

    ans.push_back(max_ele);
    ans.push_back(min_ele);

    for (auto i : ans)
    {
        cout<<i<<" ";
    }
    
    
}



int main()
{
    //! brute force method
    // getting the test cases
    // int t;
    // cin>>t;
    // int arr[] = {1, 2, 3, 4, 3, 2, 1};
       // n = legth of array
    // int n = 7;
    // for (int i = 0; i < t; i++)
    // {
         // getting the number for matching with array element 
    //     int num;
    //     cin >> num;
           // function call 
    //     cout << find(arr, num, n) <<endl;
    // }

    //! using the hashing find the count of the numbers in the array
    // getting the size of the array
    // int n;
    // cout<<"enter the size of the array"<<":";
    // cin>>n;
    // int arr[n]; // declaring the array of size n
    // for (int i = 0; i < n; i++)
    // {   
         // getting the elements in the array
    //     cout<<"insert the element "<<i<<" index"<<endl;
    //     cin>>arr[i];
    // }
    
    // f(arr,n);
    // string function call 
    // string s;
    // cin>>s;

       //freqstring(s);
    // check_for_freq(s);

    // check the freq of elements in the array using the maps
    // int arr[] ={1,2,3,4,1,3,5,12};
    // freq(arr,12);

    // string s;
    // cin>>s;
    // string_freq_usign_maps(s);

    // lowest and highest freq of elements 
       int arr[] = {2,1,1,1};
       int n = 4;

       find_lowest_and_highest(arr,n);


    return 0;
}