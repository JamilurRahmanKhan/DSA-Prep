// 142. Linked List Cycle II
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

// Function to detect cycle and return start node
ListNode* detectCycle(ListNode* head) {
    if(!head || !head->next) return NULL;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            break;;
        }
    }
    if(slow != fast)
    {
        return NULL;
    }

    ListNode *p = head;
    while(p != slow)
    {
        p = p->next;
        slow = slow->next;
    }
    return slow;
}

// Utility function to create linked list from array
ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Utility to print list up to N nodes (to avoid infinite loop if cycle exists)
void printList(ListNode* head, int limit = 15) {
    ListNode* temp = head;
    int count = 0;
    while (temp && count < limit) {
        cout << temp->val << " -> ";
        temp = temp->next;
        count++;
    }
    if (temp) cout << "... (cycle detected)";
    cout << endl;
}

int main() {
    int arr[] = {3, 2, 0, -4};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createLinkedList(arr, size);

    // Create a cycle: connect last node (-4) to node with value 2
    head->next->next->next->next = head->next;

    cout << "List with possible cycle: ";
    printList(head);

    ListNode* cycleStart = detectCycle(head);

    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}