#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//! doubly linked list
// in sinly ll we can only go one direction that means ones we start we can only
// forward to next Node
// in doubly link list we can go both backword  and forward from a Node

//! implemenation of class for doubly linked list similar singly one just
// added one pointer back pointer which points previous Node from the current one
class Node
{
    public:
    // integer data
    int data;
    // pointer that pointing out interger data
    Node *next;
    // pointer for pointing the privious element
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

//!  traversel function for linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *convertArr2DLL(vector<int> &arr)
{
    //  first element int the array is head of link list
    Node *head = new Node(arr[0]);
    // previous pointing to the head
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        // creating new node with its next pointing null and back point pre
        Node *temp = new Node(arr[i], nullptr, prev);
        // linking the node
        prev->next = temp;
        // moving to next node
        prev = temp;
    }
    return head;
}

//! deletion in doubly linked list delete head
Node *delete_head(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

//! delete the last element of DLL
Node *delete_Tail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

//! delete Kth element from the DLl
Node *delete_kth_node(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    // going to the kth node
    int cnt = 0;       // keep the track of number of node
    Node *temp = head; // declaring the pointer to the head
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break; // if cnt and k is equal then we are in the kth position node
        // moving the kthpointer to next node
        temp = temp->next;
    }

    // pointer which point temp back node
    Node *prev = temp->back;
    // points temp next node
    Node *front = temp->next;

    // its check there is only single node in linklist which temp pointing
    //    null<--prev<--node-->next-->null both the pointer are pointing to null
    if (prev == NULL && front == NULL)
    {
        return NULL;
    }
    // if only pre is pointing to the null that means the temp is pointing to the head node
    else if (prev == NULL)
    {
        return delete_head(head);
    }
    // if only front is poiting to null that means the temp is currently in tail or last node of linklist
    else if (front == NULL)
    {
        return delete_Tail(head);
    }

    // changing the pointer from temp to is next node
    prev->next = front;
    // changing the back pointer from the temp to its back node
    front->back = prev;

    // free the temp next and prev pointers
    temp->next = NULL;
    temp->back = NULL;

    // delete the temp node
    delete temp;
    return head;
}

//! insertion in doubly link list
// insertion before head
Node *insertion_before_head(Node *head, int element)
{
    // created a new node which next pointer is pointing to head and back will be pointing to null
    Node *newHead = new Node(element, head, nullptr);

    // now shift the head pointer to our new created head
    head->back = newHead;
    // returning the newhead
    return newHead;
}

//! insertion before the Tail
Node *insert_before_tail(Node *head, int element)
{
    // if the ll has only one element then its a head of ll
    // so we simply call insert head of liniked list
    if (head->next == NULL)
    {
        return insertion_before_head(head, element);
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    // a pointer which points tails back
    Node *prev = tail->back;

    // creating the new node
    Node *newnode = new Node(element, tail, prev);

    // prev next pointing to new node
    prev->next = newnode;
    // tail is last element and its back is pointing two the new node
    tail->back = newnode;
    return head;
}

//! insertion before the Kth element
Node *insert_before_kth(Node *head, int k, int element)
{
    if (k == 1)
    {
        return insertion_before_head(head, element);
    }

    Node *temp = head;
    int cnt = 0;
    while (temp->next != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *newnode = new Node(element, temp, prev);

    prev->next = newnode;
    temp->back = newnode;
    return head;
}

void insertBeforeNode(Node *node, int val)
{
    Node *prev = node->back;
    Node *newnode = new Node(val, node, prev);
    prev->next = newnode;
    node->back = newnode;
}

//! reverse the DLL using data swap brute force
void reverse_DLL(Node *head)
{
    Node *temp = head;
    stack<int> st;

    // storing the element fromt ll to stack
    while (temp != NULL)
    {
        // push the ll data into stack
        st.push(temp->data);
        // move the temp in ll for getting the next data
        temp = temp->next;
    }

    // rewrite the element inside the ll from the stack
    // restarting the temp to head
    temp = head;

    while (temp != NULL)
    {
        // temp 1st element
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    //! O(n) + O(n) = O(2n) TC
    //! O(n) SC
}

//! reverse the DLL using link swaping
Node *reverse_DLL_linkSwap(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    // Initialize a pointer to
    // the previous node
    Node *prev = NULL;

    // Initialize a pointer to
    // the current node
    Node *current = head;

    // Traverse the linked list
    while (current != NULL)
    {
        // Store a reference to
        // the previous node
        prev = current->back;

        // Swap the previous and
        // next pointers
        current->back = current->next;

        // This step reverses the links
        current->next = prev;

        // Move to the next node
        // in the original list
        current = current->back;
    }

    return prev->back;
}

// find the the mid of LL
void findMiddle(Node *head)
{
    // Write your code here
    // Node *temp = head;
    // int cnt = 0;
    // while (temp != NULL)
    // {
    //     cnt++;
    //     temp = temp->next;
    // }

    // int mid = (cnt / 2) + 1;
    //  reset the temp
    // temp = head;

    // while (temp != NULL)
    // {
    //     mid--;
    //     if (mid == 0)
    //         break;
    //     temp = temp->next;
    // }

    // return temp;

    // using the Tortoise and Hare algorithm
    // How it works:

    // Slow pointer (slow): Moves one step at a time.
    // Fast pointer (fast): Moves two steps at a time.

    // When the fast pointer reaches the end of the list, the slow pointer will be at the middle node. This method is efficient and widely used to find the middle of a linked list.

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}

int main()
{
    //! vector<int> arr = {2, 3, 4, 5};
    // we are not passing the null ptr since we are already declare them if there only one value so dydefualt the pointer next back will be nullptr so we dont need to pass them again again
    // Node *head = convertArr2DLL(arr);
    // print(head);

    // //! deleting the head of linked list
    // vector<int> arr = {2, 3, 4, 5};
    // Node* head = convertArr2DLL(arr);
    // head = delete_head(head);
    // print(head);

    //! deleting the Tail of linked list
    // vector<int> arr = {2, 3, 4, 5};
    // Node* head = convertArr2DLL(arr);
    // head = delete_Tail(head);
    // print(head);

    //! delete the kth node from the DLL
    // vector<int> arr = {2, 3, 4, 5};
    // Node* head = convertArr2DLL(arr);
    // head = delete_kth_node(head,1);
    // print(head);

    //! insert before the head
    //  vector<int> arr = {2, 3, 4, 5};
    // Node* head = convertArr2DLL(arr);
    // head = insertion_before_head(head,1);
    // print(head);

    // //! insertion before the tail
    // vector<int> arr = {2, 3, 4, 5};
    // Node* head = convertArr2DLL(arr);
    // head = insert_before_tail(head,1);
    // print(head);

    //! insertion before kth node
    // vector<int> arr = {2, 3, 4, 5};
    // Node* head = convertArr2DLL(arr);
    // head = insert_before_kth(head,1,70);
    // print(head);

    //! insert Before  Node in DLL
    // vector<int> arr = {2, 3, 4, 5};
    // Node* head = convertArr2DLL(arr);
    // insertBeforeNode(head->next->next, 40);
    // print(head);

    //! reverse the linked list using the data swap
    // vector<int> arr = {2, 3, 4, 5};
    // Node* head = convertArr2DLL(arr);
    // reverse_DLL(head);
    // print(head);

    //! reverse the ll using link switching
    // vector<int> arr = {2, 3, 4, 5};
    // Node *head = convertArr2DLL(arr);
    // head = reverse_DLL_linkSwap(head);
    // print(head);

    //! find the mid of liked List
    vector<int> arr = {2, 3, 4, 5,7,8,20};
    Node *head = convertArr2DLL(arr);
    findMiddle(head);

    

    return 0;
}