#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//! linkded list
//! constructor is a special type of function called to create an object
// struct node
// {
//     public:
//     int data;
//     node* next;
//     node(int data1, node* next1)
//     {
//         data = data1;
//         next = next1;
//     }
//      defined the new function or constructor to
//      automaticaly define the next pointer to null
//      or we can last pointer to null so we dont have
//      to pass the nullptr again and again
//      node(int data1)
//     {
//         data = data1;
//         next = nullptr;
//     }
// };

// in struct there is problem we dont get the features of oops object orinted programming thats we use class insted of struct both work same but class has more features then the struct
class node
{
public:
    int data;
    node *next;

    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }

    // defined the new function or constructor to
    // automaticaly define the next pointer to null
    // or we can last pointer to null so we dont have
    // to pass the nullptr again and again
    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

//! funtion to convert the arr to ll
node *convertArr2LL(vector<int> &arr)
{
    // head of the linklist is alwasys pointing the
    //  first element int the array
    node *head = new node(arr[0]);
    // mover which first pointing to the head
    node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        // storing the data inside the
        node *temp = new node(arr[i]); // Create a new node for each array element
        mover->next = temp;            // Link the current node to the new node
        mover = temp;                  // Move the mover pointer to the new node
    }
    return head;
}

//! how to print the lenght of ll
int lenghtofLL(node *head)
{
    int cnt = 0;
    node *temp = head;
    while (temp != nullptr)
    {
        // move temp to next data type
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

//! check if the element present in the linklist or not
int checkifpresent(node *head, int val)
{
    node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

//! function for deleting the head of linklist
node *deleteHead(node *head)
{
    // edge case if head is null that means no element is present in linklist
    if (head == NULL)
        return head;
    node *temp = head;

    // shift the head to next data element
    head = head->next;

    // now delete the head  we can use free() or delete function for deletion
    free(temp);

    // returning the new head
    return head;
}

//! function for deleting the last element or tail of the linked list
node *deleteLast_element(node *head)
{
    // IF there is only one element in Linked list
    if (head == NULL || head->next == NULL)
        return NULL;
    // storing the head in temp variable
    node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // free the temp->next element
    free(temp->next);
    // set the temp->next as null
    temp->next = nullptr;

    // returning the head
    return head;
}

//! deleting the kth or nTH position form the liskedlist
node *deleteKth_node(node *head, int k)
{
    if (head == NULL)
        return head;

    // kth element is 1 that means its a head node
    if (k == 1)
    {
        // store the current head in temp node
        node *temp = head;
        // moves the head from current node to the next node
        head = head->next;
        // free the stored head
        free(temp);
        // return the new head
        return head;
    }
    // counter for keep track number of node
    int count = 0;
    node *temp = head;
    node *prev = NULL;
    while (temp != NULL)
    {
        count++;

        if (count == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

//! delete the nth element or value form ll
node *delete_element(node *head, int element)
{
    if (head == NULL)
        return head;

    if (head->data == element)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node *temp = head;
    node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

//! insert the element in the head
node *insertHead(node *head, int val)
{
    // creating a new node and iserting the val and link it with head
    node *temp = new node(val, head);
    // since the temp is new node and its link with head so its become new head
    return temp;

    // return new node(val,head); single line code for insertion in head
}

//! insert the element at the tail or at the last of linkedlist
node *insertion_Tail(node *head, int val)
{ // if there is no node so we are creating one and returing it
    if (head == NULL)
    {
        // creating and returning the new node with x element
        return new node(val);
    }

    // making the temp pointer to head for traversal in LL
    node *temp = head;
    // running the loop unitl we find out the temp next null
    while (temp->next != NULL)
    {
        // when we find out that temp next is null we just move
        // to one place where our last element lies
        temp = temp->next;
    }
    // created new node called newnode
    node *newnode = new node(val);

    // temp next currently pointing null so her we change its pointer to the
    // our new created node and its pointer is bydefult is opointing to null
    temp->next = newnode;

    // returning the head
    return head;
}

//! inserting the element in Kth position in ll
node *insertion_at_Kth(node *head, int val, int k)
{
    // if the ll is empty so we create new node
    if (head == NULL)
    {

        if (k == 1)
        {
            return new node(val);
        }
        else
        {
            return head;
        }
    }
    // if the ll is not empty and position is 1 so we have to insert a head
    // position and link our new node to head
    if (k == 1)
    {
        // creating new node and linking it with head and returing it
        return new node(val, head);
    }

    int cnt = 0;
    node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == (k - 1))
        {
            node *x = new node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

node *insertion_before_element(node *head, int val, int element)
{

    if (head == NULL)
    {

        return NULL;
    }

    if (head->data == element)
    {
        // creating new node and linking it with head and returing it
        return new node(val, head);
    }

    node *temp = head;
    while (temp->next != NULL)
    {

        if (temp->next->data == element)
        {
            node *x = new node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//! reverse the linklist
node *reverseList(node *head)
{

    if (head == NULL || head->next == NULL) return head;

    node *temp = head;
    stack<int> st;

    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;

    // brute force O(2n) TC                                                                                                             
    // O(N) SC
}

//! optimal solution for reversing the ll
node* reverse_ll(node* head)
{
    if(head == NULL || head->next == NULL) return head;

    node* temp = head;
    node* prev = NULL;
    while (temp != NULL)
    {
        node* front = temp->next; 
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;

}


//! traversing function for linked_list
// note: we can take void and node* as function type both works fine
void traverse(node *head)
{
    // loop run until the head element point to nullptr or last
    //  element
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    // vector<int> arr = {2,3,4,5};
    //! declairng the pointer to the datatype
    //! new keyword will help to access the memory location

    // node* y = new node(arr[0], nullptr);
    // cout<<y;

    //! if dont want to pass the nullpointer again again
    //! we can simply define the new constructer or function
    //! in struct to do this

    //  node* y = new node(arr[0]);
    //  cout<<y; // prints the memory address
    //  cout<<y->data; // print the data

    // node* head = convertArr2LL(arr);
    // cout<< head->data;

    //! traversing the
    //  node* head = convertArr2LL(arr);
    //  node* temp = head;
    //  while (temp != nullptr)
    //  {
    //     cout<<temp->data<<" ";
    //! move temp to next data type
    //     temp = temp->next;
    //  }
    //  cout<<lenghtofLL(head);
    //  cout<<checkifpresent(head,3);

    //! deleting the head node
    // vector<int> arr = {2,3,4,5};
    // node* head = convertArr2LL(arr);
    // head = deleteHead(head);
    // traverse(head);

    //! deleting the last element of linklist
    // vector<int> arr = {2,3,4,5};
    // node* head = convertArr2LL(arr);
    // head = deleteLast_element(head);
    // traverse(head);

    //! deleting the kth node form the linklist
    // vector<int> arr = {2,3,4,5};
    // node* head = convertArr2LL(arr);
    // head = deleteKth_node(head, 1);
    // traverse(head);

    //! delete nth node element from the LL
    // vector<int> arr = {2,3,4,5};
    // node* head = convertArr2LL(arr);
    // head = delete_element(head,5);
    // traverse(head);

    //! insert an element in head
    // vector<int> arr = {2,3,4,5};
    // node* head = convertArr2LL(arr);
    // head = insertHead(head,100);
    // we can do this as well
    // head = new node(100, head); O(1) complaxity
    // traverse(head);

    //! insertion an element in last
    // vector<int> arr = {2, 3, 4, 5};
    // node *head = convertArr2LL(arr);
    // head = insertion_Tail(head, 700);
    // traverse(head);

    //! insertion an element in any ll at kth position
    // t vector<int> arr = {2, 3, 4, 5};
    //  node *head = converArr2LL(arr);
    //  head = insertion_at_Kth(head, 700,1);
    //  traverse(head);

    //! insertion before the present element in the linklist
    // vector<int> arr = {2, 3, 4, 5};
    // node *head = convertArr2LL(arr);
    // head = insertion_before_element(head, 700, 5);
    // traverse(head);

    //! reverse the linked list
    // vector<int> arr = {2, 3, 4, 5};
    // node *head = convertArr2LL(arr);
    // head = reverse_ll(head);
    // traverse(head);

    return 0;
}