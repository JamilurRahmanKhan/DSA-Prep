// Using Recursion
#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int value)
    {
        val = value;
        next = NULL;
    }
};
 
// Insert the Node at end using Recursion
ListNode *CreateLinkedList(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }

    ListNode *temp;
    temp = new ListNode(arr[index]);
    temp->next = CreateLinkedList(arr, index + 1, size);

    return temp;
}

class Solution {
public:

    ListNode *reverse(ListNode *curr, ListNode *prev){
        if(curr==NULL)
        {
            return prev;
        }

        ListNode *fut = NULL;
        fut = curr->next;
        curr->next = prev;
        prev = curr;

        return reverse(fut, curr);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head, NULL);
    }
};

// Print Linked List
void printList(ListNode* head) {
    ListNode* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    ListNode *Head, *Tail;
    Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};

    Head = CreateLinkedList(arr, 0, 5);

    cout << "Original List: ";
    printList(Head);

    Solution sol;
    Head = sol.reverseList(Head);

    cout << "Reversed List: ";
    printList(Head);

    return 0;
}












// Using Array
// #include <iostream>
// #include <vector>

// using namespace std;

// class ListNode
// {
// public:
//     int val;
//     ListNode *next;

//     ListNode(int value)
//     {
//         val = value;
//         next = NULL;
//     }
// };
 
// // Insert the Node at end using Recursion
// ListNode *CreateLinkedList(int arr[], int index, int size)
// {
//     if (index == size)
//     {
//         return NULL;
//     }

//     ListNode *temp;
//     temp = new ListNode(arr[index]);
//     temp->next = CreateLinkedList(arr, index + 1, size);

//     return temp;
// }

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         vector<int> ans;
//         ListNode *temp = head;

//         while(temp!=NULL){
//             ans.push_back(temp->val);
//             temp = temp->next;
//         };

//         int i = ans.size()-1;
//         temp = head;

//         while(temp){
//             temp->val = ans[i];
//             i--;
//             temp = temp->next;
//         }
//         return head;
//     }
// };

// // Print Linked List
// void printList(ListNode* head) {
//     ListNode* temp = head;
//     while(temp){
//         cout << temp->val << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main()
// {

//     ListNode *Head, *Tail;
//     Head = NULL;

//     int arr[] = {2, 4, 6, 8, 10};

//     Head = CreateLinkedList(arr, 0, 5);

//     cout << "Original List: ";
//     printList(Head);

//     Solution sol;
//     Head = sol.reverseList(Head);

//     cout << "Reversed List: ";
//     printList(Head);

//     return 0;
// }












// #include <iostream>
// #include <vector>

// using namespace std;

// class ListNode
// {
// public:
//     int val;
//     ListNode *next;

//     ListNode(int value)
//     {
//         val = value;
//         next = NULL;
//     }
// };
 
// // Insert the Node at end using Recursion
// ListNode *CreateLinkedList(int arr[], int index, int size)
// {
//     if (index == size)
//     {
//         return NULL;
//     }

//     ListNode *temp;
//     temp = new ListNode(arr[index]);
//     temp->next = CreateLinkedList(arr, index + 1, size);

//     return temp;
// }

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *curr = head, *prev = NULL, *fut = NULL;

//         while(curr){
//             fut = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = fut;
//         }
//         head = prev;
//         return head;
//     }
// };

// // Print Linked List
// void printList(ListNode* head) {
//     ListNode* temp = head;
//     while(temp){
//         cout << temp->val << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main()
// {

//     ListNode *Head, *Tail;
//     Head = NULL;

//     int arr[] = {2, 4, 6, 8, 10};

//     Head = CreateLinkedList(arr, 0, 5);

//     cout << "Original List: ";
//     printList(Head);

//     Solution sol;
//     Head = sol.reverseList(Head);

//     cout << "Reversed List: ";
//     printList(Head);

//     return 0;
// }



