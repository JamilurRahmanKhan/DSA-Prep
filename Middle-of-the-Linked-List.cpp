// 876. Middle of the Linked List
#include <iostream>
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

ListNode* CreateLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to find the middle of the linked list
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;       
        fast = fast->next->next; 
    }

    return slow; 
}

int main() {
    int arr[] = {4, 5, 1, 9, 7, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = CreateLinkedList(arr, size);

    cout << "Original List: ";
    printList(head);

    ListNode* mid = middleNode(head);

    cout << "Middle Node Value: " << mid->val << endl;

    return 0;
}