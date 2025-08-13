#include <bits/stdc++.h>
#include <iostream>
#include <utility> // use for pair
#include <vector>  //use for vector
#include <list>


using namespace std;
// STL is known as standard template library
// It is a library of
// 1.container - vector, list, map, set, and stack,
// 2.functions - also known as functors, are objects that can be used as function arguments to algorithms. They provide a way to pass a function to an algorithm, allowing you to customize its behavior.
// 3.algorithms - sort, find, and binary_search, which can be used to manipulate data stored in containers.
//  4.iterators -STL provides a range of iterators, such as forward_iterator, bidirectional_iterator, and random_access_iterator, that can be used with different types of containers.

void pair_explain()
{
    // declaring the pair
    //    data type pair name insed bracket storig element
    pair<int, int> p = {1, 2};

    // accessing the pair element
    cout << p.first << " " << p.second << endl;
    // for accessing the first element pair_name + position 1st 2nd etc

    pair<int, pair<int, int>> pair1 = {1, {3, 4}};
    cout << pair1.first << " " << pair1.second.second << " " << pair1.second.first << endl;

    // de the pair array     0     1     2
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {3, 1}};
    cout << arr[2].second << endl;

    // defining a pair
    pair<int, char> PAIR1;

    // first part of the pair
    PAIR1.first = 100;
    // second part of the pair
    PAIR1.second = 'G';

    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;
}

void vector_explain()
{
    //! Declare Vector in C++
    // vector<dataType> vectorName;
    vector<int> values;

    //! pushing  the values in vector
    // push_back always puts a new element at the end of the vector
    // vector_name.push_back(insertion element);
    // or
    // vector_name.emplace_back(2); this more faster then push_back

    // values.push_back(1); // inserting 1 in array size:1
    // cout << values[0] << endl;
    // values.emplace_back(21); // inserting 2 in array size of array is 2
    // cout << values[1] << endl;

    // vector<pair<int, int>> ele;

    // ele.push_back({1, 2});

    // vector<int> v(5); // declared vector of size 5 {0,0,0,0,0}

    // vector<int> vec(5, 100); // {100 ,100 ,10 ,100 ,100}
    // cout << vec[1] << endl;

    // copy data form one cointainer or vector to another one

    vector<int> v1(5, 10); //{10,10,10,10,10}
    vector<int> v2(v1);    //{10,10,10,10,10}
    for (int i = 0; i <= 5; i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;

    //! iterator in vectors
    vector<int>::iterator it = v1.begin();
    it++;
    cout << *(it) << " ";

    it = it + 2;
    cout << *(it) << " ";

    // different types of iterators
    //  vector<int>::iterator it = v1.end();
    //  vector<int>::iterator it = v1.rend(); reverse end
    //  vector<int>::iterator it = v1.rbegin(); reverse begin

    // looping the vector
    cout << "printing the loops " << endl;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    // in the short way we use auto
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    // auto is usefull tool it automatically assign data-type for the data
    // int a = 5; insted of int i can write auto
    // auto a = 5; it automatically define integer data-type accourding the data

    for (auto it : v1)
    {
        cout << it << " ";
    }
    cout << endl;

    //! deletion in vector            printing before the vector
    vector<int> del{10, 20, 30, 50, 60};
    for (auto it : del)
    {
        cout << it << " ";
    }
    //                            0  1  2  3  4
    del.erase(del.begin() + 1); // {10,20,30,50,60} begin in 0 and +1 is 20
    // printing after the erase opration
    cout << endl;
    for (auto it : del)
    {
        cout << it << " ";
    } //{10,30,50,60}
    cout << endl;
    // erase multiple elements
    del.erase(del.begin() + 2, del.begin() + 4); //{10,20,30,50,60} +2 means 30 and +4 means 60

    for (auto it : del)
    {
        cout << it << " ";
    }
    cout << endl;

    // insertion in vector
    //  insert allows you to select new element's position.

    vector<int> in(2, 100);           //{100, 100}
    in.insert(in.begin(), 300);       //{ 300, 100 , 100}
    in.insert(in.begin() + 1, 2, 10); //{300 , 10 , 10, 100, 100}

    // insert a intire vector into anothor vector
    vector<int> ex(2, 50); //{50, 50}
    // we can copy the vector ex in vector in
    in.insert(in.begin(), ex.begin(), ex.end()); //{50,50,300,10,10,100,100}
    for (auto it : in)
    {
        cout << it << " ";
    }

    cout << in.size(); // provide the how many element in present in vector

    //{10,50}
    ex.pop_back(); //{10} 50 will be remove

    // swap two vectors
    //  v1-> {10,20}
    //  v2-> {30,40}

    v1.swap(v2); // v1->{30,40} v2->{10,20}

    ex.clear(); // clear or erase intire vector

    cout << ex.empty(); // if its empty return true else false
}

void list_explains()
{
    // declaration of list
    list<int> ls;

    // pushing in list
    ls.push_back(2);    //{2}
    ls.emplace_back(4); //{2,4}

    // pushing at first its less constly then vector
    ls.push_front(5);       //{5,2,4}
    ls.emplace_front(2);    //{2,5,2,4}

    for (auto it : ls){ cout << it << " "; }

    // rest same as vector
    //begin() end rend rbegin insert size and swap earse as well

}

void deque_explains()
{
    deque<int> dq;

    dq.push_back(1);    //{1}
    dq.emplace_back(3); //{1,3}

    dq.push_front(4);   //{4,1,3}
    dq.emplace_front(3); //{3,4,1,3}

    dq.pop_back(); //{3,4,1}
    dq.pop_front(); //{4,1}

   // rest will be same as vector

}

void stack_explain()
{
    stack<int> st;
    
    st.push(1); //{1}
    st.push(2); //{2,1}
    st.push(3); //{3,2,1}
    st.push(3); //{3,3,2,1}

    st.emplace(4); //{4,3,3,2,1}

    cout<<st.top()<<endl; // prints 4 

    st.pop(); // 4 erase her

    cout<< st.top(); // top of stack is 3 since 4 is poped 

    cout<<st.size();

    cout<<st.empty();

    stack<int>s1,s2;
    s1.swap(s2);

}

void Queue_explain()
{
    queue<int> q;

    q.push(1); //{1}
    q.push(2); //{1,2}
    q.push(3); //{1.2,3}

    cout<<q.front(); // 1
    cout<<q.back(); //3

    q.pop(); // {2,3}

    cout<<q.front(); // 2,3

    // size swap empty same as stack

} 

void priority_queue_explain()
{
    priority_queue<int>pq;

    pq.push(5); //5
    pq.push(2); //{5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); //{10,8,5,2}

    cout<<pq.top(); //prints 10

    pq.pop(); //{8,5,2}

    cout<<pq.top(); // prints 8
    
    //size and empty functions are same 

    // minumum heap 
    priority_queue<int, vector<int>, greater<int>> q;

    q.push(12);
    q.push(3);
    q.push(6);
    q.emplace(1);

    cout<<pq.top(); 

}

void set_explain()
{
    // stores everything in sorted manner & unique 
    set<int> st;

    st.insert(1); //{1}
    st.insert(2); //{1.2}
    st.insert(2); //{1,2}
    st.insert(4); //{1,2,4}
    st.emplace(3); //{1,2,3,4}

    // begin() , end() , rbegin() rend size() empty swap are same as above

    //{1,2,3,4}
    auto it1 = st.find(3);

    auto it2 = st.find(5);

    st.erase(4); // takes logarithmic time for erase

    int cnt = st.count(1);
    cout<<cnt;

    auto it3 =st.find(3);

    //{1,2,3,4,5}
    auto it4 =st.find(2);
    auto it5 =st.find(4);

    st.erase(it4, it5); // after erase { 1 4 5 } [first , last]

    // lower and upperbound are the same function 
    // auto it = st.lower_bound(2);
    // auto it = st.upper_bound(3);

}

void multiset_explain()
{
    //  same as set but her duplicate element is also strores 
    // suppose you save 2 three time {2 2 2} when you use erase(2) 
    // all 2 are erased from the set 

    multiset<int>ms;

    ms.insert(1); //{1}
     ms.insert(1); //{1,1}
      ms.insert(1); //{1,1,1}

      ms.erase(1); // all 1's erased

      int cnt = ms.count(1);

      ms.erase(ms.find(1)); //only a single one erased

     // ms.erase(ms.find(1), ms.find(1)+2);

}

void unordered_set_explain()
{
    unordered_set<int> ust;
    
    // operations done in O(1)
    // 

    // lower_bound() and upper_bound() function
    // does not works , rest all functions are same 
    // as above, it does not stores in any 
    // perticular order it has a better complaxity
    // then set in most cases, except some when collision heppens
}

void map_explain()
{
    // her everything is stored in sorted manner
    map<int, int> mpp;

    map<int , pair<int,int>> mpp1;

    map <pair<int,int>,int> mpp2;

    mpp[1] = 2;
    mpp.insert({3,2});

   // mpp.emplace({2,4});

//    mpp[{2,3}] = 10;
//    {
//     {1,2}
//     {2,4}
//     {3,1}
//    }

   for(auto it : mpp)
   {
    cout<<it.first<<" "<<it.second<<endl;
   }
   
   cout<<mpp[1];
   cout<<mpp[5];

   auto it  = mpp.find(3);
   //cout<<*(it).second;

   auto it1 = mpp.find(5);

   // erase swap size empty are same

}

void multimap_explain()
{
    // same as map but her you can store dublicate keys and everything in 
    // sorted order 
}

void unorderedMap_explain()
{
    // works in O(1)
    // its has unique keys but its not sorted
}

bool comp(pair<int,int> p1, pair<int,int>p2)
{
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;

    if(p1.first > p2.first) return true;
    return false;
}

void someExtra_explain()
{    
    // sorting from the starting to end 
    // {5,2,1,4,3}
    //  sort(a, a+5); or sort(a, a+n) {1,2,3,4,5}
   // sort(v.begin(), v.end());       {1,2,3,4,5}

   // sort(a, a+n ,greater<int>) sort in dessending oreder

   // greater is inbuilt comptetar

   pair<int,int> a[] ={{1,2},{2,1},{4,1}};
   // sort it according to second element 
   // if second element is same then sort 
   // it accourding  to first element but in descending 

   // we sorting accourding to our requirments
   int n =3;
   sort(a,a+n, comp);

   int num = 7;

   int cnt = __builtin_popcount(num); // return the number of set bits ex {011} 2 set bits

   cout<<cnt; // for 7 there are 3 set bits present 

   // if the numbe is long long 
   long long num1 = 1878543973498;
   cout<<__builtin_popcountll(num1);


   string s ="123";
   sort(s.begin(),s.end());

   do
   {
    cout<< s <<endl;
   } while (next_permutation(s.begin(),s.end()));
   
   // 1    2   3   4   5   6   there 6 possiible combinations 
   // 123 132 213 231 312 321

   
  //  int maxi = *max_element(a,a+n); return max element 

}

int main()
{
    // pair function call
    // pair_explain();

    // calling the vector function
    // vector_explain();

    // calling the list function
    // list_explains();

    // calling the deque function
    // deque_explains();

       //stack_explain();
       
       //Queue_explain();

       //set_explain();

       someExtra_explain();

    return 0;
}