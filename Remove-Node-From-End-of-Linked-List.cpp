#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        for (int i = 0; i < n; i++)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            ListNode *result = head->next;
            delete (head);
            return result;
        }

        ListNode *prev = head;
        while (temp && temp->next)
        {
            prev = prev->next;
            temp = temp->next;
        }

        ListNode *delNode = prev->next;
        prev->next = delNode->next;
        delete (delNode);

        return head;
    }
};

// Utility function: create linked list from vector
ListNode *createList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *current = head;
    for (size_t i = 1; i < vals.size(); i++)
    {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Utility function: print linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution sol;

    // Example 1
    vector<int> vals1 = {1, 2, 3, 4};
    ListNode *head1 = createList(vals1);
    cout << "Original list: ";
    printList(head1);
    head1 = sol.removeNthFromEnd(head1, 2);
    cout << "After removal: ";
    printList(head1);

    // Example 2
    vector<int> vals2 = {5};
    ListNode *head2 = createList(vals2);
    cout << "Original list: ";
    printList(head2);
    head2 = sol.removeNthFromEnd(head2, 1);
    cout << "After removal: ";
    printList(head2);

    // Example 3
    vector<int> vals3 = {1, 2};
    ListNode *head3 = createList(vals3);
    cout << "Original list: ";
    printList(head3);
    head3 = sol.removeNthFromEnd(head3, 2);
    cout << "After removal: ";
    printList(head3);

    return 0;
}










// #include <iostream>
// #include <vector>
// using namespace std;

// /**
//  * Definition for singly-linked list.
//  */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution {
// public:
//     int getLengthOfLinkedList(ListNode *head)
//     {
//         int lenght = 0;
//         ListNode *temp = head;
//         while(temp)
//         {
//             lenght++;
//             temp = temp->next;
//         }
//         return lenght;
//     }

//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int l = getLengthOfLinkedList(head);
//         if(n==l)
//         {
//             ListNode *temp = head->next;
//             delete(head);
//             return temp;
//         }

//         int travel_from = l-n;
//         ListNode *prev = NULL;
//         ListNode *temp = head;

//         while(travel_from--)
//         {
//             prev = temp;
//             temp = temp->next;
//         }
//         prev->next = temp->next;
//         delete(temp);

//         return head;
//     }
// };

// // Utility function: create linked list from vector
// ListNode* createList(const vector<int>& vals) {
//     if (vals.empty()) return nullptr;
//     ListNode* head = new ListNode(vals[0]);
//     ListNode* current = head;
//     for (size_t i = 1; i < vals.size(); i++) {
//         current->next = new ListNode(vals[i]);
//         current = current->next;
//     }
//     return head;
// }

// // Utility function: print linked list
// void printList(ListNode* head) {
//     while (head) {
//         cout << head->val;
//         if (head->next) cout << " -> ";
//         head = head->next;
//     }
//     cout << endl;
// }

// int main() {
//     Solution sol;

//     // Example 1
//     vector<int> vals1 = {1,2,3,4};
//     ListNode* head1 = createList(vals1);
//     cout << "Original list: ";
//     printList(head1);
//     head1 = sol.removeNthFromEnd(head1, 2);
//     cout << "After removal: ";
//     printList(head1);

//     // Example 2
//     vector<int> vals2 = {5};
//     ListNode* head2 = createList(vals2);
//     cout << "Original list: ";
//     printList(head2);
//     head2 = sol.removeNthFromEnd(head2, 1);
//     cout << "After removal: ";
//     printList(head2);

//     // Example 3
//     vector<int> vals3 = {1,2};
//     ListNode* head3 = createList(vals3);
//     cout << "Original list: ";
//     printList(head3);
//     head3 = sol.removeNthFromEnd(head3, 2);
//     cout << "After removal: ";
//     printList(head3);

//     return 0;
// }

