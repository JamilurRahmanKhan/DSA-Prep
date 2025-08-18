// 2095. Delete the Middle Node of a Linked List
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

// Delete the middle node and return the head
ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) return nullptr; 

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}

int main() {
    int arr[] = {4, 5, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = CreateLinkedList(arr, size);

    cout << "Original List: ";
    printList(head);

    head = deleteMiddle(head);

    cout << "List After Deletion: ";
    printList(head);

    return 0;
}