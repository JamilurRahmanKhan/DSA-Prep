// Merge K Sorted Linked Lists

#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* mergerTwoSortedLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val <= l2->val) {
            l1->next = mergerTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergerTwoSortedLists(l1, l2->next);
            return l2;
        }
    }

    ListNode* positionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if (start > end) return NULL;
        if (start == end) return lists[start];

        int mid = start + (end - start) / 2;
        ListNode* l1 = positionAndMerge(start, mid, lists);
        ListNode* l2 = positionAndMerge(mid + 1, end, lists);

        return mergerTwoSortedLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return NULL;
        return positionAndMerge(0, k - 1, lists);
    }
};

// ------- Utility Functions --------
ListNode* createLinkedList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// -------- Main --------
int main() {
    // Example: merging 3 sorted linked lists
    vector<int> arr1 = {1, 4, 5};
    vector<int> arr2 = {1, 3, 4};
    vector<int> arr3 = {2, 6};

    ListNode* l1 = createLinkedList(arr1);
    ListNode* l2 = createLinkedList(arr2);
    ListNode* l3 = createLinkedList(arr3);

    vector<ListNode*> lists = {l1, l2, l3};

    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    cout << "Merged Linked List: ";
    printList(result);

    return 0;
}