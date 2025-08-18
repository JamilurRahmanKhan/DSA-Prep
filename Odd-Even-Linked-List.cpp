// 328. Odd Even Linked List
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

// Function to reorder nodes by odd-even indices
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenStart = head->next;

    while(even && even->next){
        odd->next = even->next;
        even->next = even->next->next;
        
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = CreateLinkedList(arr, size);

    cout << "Original List: ";
    printList(head);

    head = oddEvenList(head);

    cout << "Odd-Even Reordered List: ";
    printList(head);

    return 0;
}