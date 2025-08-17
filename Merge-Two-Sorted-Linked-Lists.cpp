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
// create a linked list
ListNode *CreateLinkedList(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }

    ListNode *temp = new ListNode(arr[index]);
    temp->next = CreateLinkedList(arr, index + 1, size);
    return temp;
}
// print linked list
void printList(ListNode *head)
{
    ListNode *temp;
    temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *head = NULL;
        if (list1->val < list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }

        ListNode *temp = head;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1)
            temp->next = list1;
        else
            temp->next = list2;

        return head;
    }
};

int main()
{
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 5};
    // create linked lists
    ListNode *list1 = CreateLinkedList(arr1, 0, 3);
    ListNode *list2 = CreateLinkedList(arr2, 0, 3);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // merge
    Solution sol;
    ListNode *merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// class ListNode{
// public:
//     int val;
//     ListNode *next;

//     ListNode(int value){
//         val = value;
//         next = NULL;
//     }
// };
// // create a linked list
// ListNode *CreateLinkedList(int arr[], int index, int size){
//     if(index==size){
//         return NULL;
//     }

//     ListNode *temp = new ListNode(arr[index]);
//     temp->next = CreateLinkedList(arr, index+1, size);
//     return temp;

// }
// //print linked list
// void printList(ListNode *head){
//     ListNode *temp;
//     temp = head;
//     while(temp){
//         cout << temp->val << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// class Solution{
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
//         vector<int>ans1;
//         vector<int>ans2;

//         ListNode *temp1 = list1;
//         while (temp1)
//         {
//             ans1.push_back(temp1->val);
//             temp1 = temp1->next;
//         };

//         ListNode *temp2 = list2;
//         while (temp2)
//         {
//             ans2.push_back(temp2->val);
//             temp2 = temp2->next;
//         };

//         // merge the two vectors
//         vector<int> merged = ans1;
//         merged.insert(merged.end(), ans2.begin(), ans2.end());

//         //sort the merged vector
//         sort(merged.begin(), merged.end());

//         //convert back to linked list
//         if(merged.empty()){
//             return NULL;
//         }

//         ListNode *head = new ListNode(merged[0]);
//         ListNode *curr = head;
//         for(int i=1; i<merged.size(); i++){
//             curr->next = new ListNode(merged[i]);
//             curr = curr->next;
//         }
//         return head;

//     }
// };

// int main(){
//     int arr1[] = {1,2,4};
//     int arr2[] = {1,3,5};
//     //create linked lists
//     ListNode *list1 = CreateLinkedList(arr1,0,3);
//     ListNode *list2 = CreateLinkedList(arr2,0,3);

//     cout << "List 1: ";
//     printList(list1);

//     cout << "List 2: ";
//     printList(list2);

//     // merge
//     Solution sol;
//     ListNode *merged = sol.mergeTwoLists(list1, list2);

//     cout << "Merged List: ";
//     printList(merged);

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
// // create a linked list
// ListNode *CreateLinkedList(int arr[], int index, int size)
// {
//     if (index == size)
//     {
//         return NULL;
//     }

//     ListNode *temp = new ListNode(arr[index]);
//     temp->next = CreateLinkedList(arr, index + 1, size);
//     return temp;
// }
// // print linked list
// void printList(ListNode *head)
// {
//     ListNode *temp;
//     temp = head;
//     while (temp)
//     {
//         cout << temp->val << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         ListNode dummy(0);
//         ListNode *tail = &dummy;

//         while (list1 && list2)
//         {
//             if (list1->val < list2->val)
//             {
//                 tail->next = list1;
//                 list1 = list1->next;
//             }
//             else
//             {
//                 tail->next = list2;
//                 list2 = list2->next;
//             }
//             tail = tail->next;
//         }

//         // If one list is not finished, append it
//         if (list1) tail->next = list1;
//         if (list2) tail->next = list2;

//         return dummy.next;
//     }
// };

// int main()
// {
//     int arr1[] = {1, 2, 4};
//     int arr2[] = {1, 3, 5};
//     // create linked lists
//     ListNode *list1 = CreateLinkedList(arr1, 0, 3);
//     ListNode *list2 = CreateLinkedList(arr2, 0, 3);

//     cout << "List 1: ";
//     printList(list1);

//     cout << "List 2: ";
//     printList(list2);

//     // merge
//     Solution sol;
//     ListNode *merged = sol.mergeTwoLists(list1, list2);

//     cout << "Merged List: ";
//     printList(merged);

//     return 0;
// }