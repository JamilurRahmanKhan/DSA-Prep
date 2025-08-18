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

void deleteNode(ListNode* node) {
    ListNode *prev = NULL;

    while (node != NULL && node->next != NULL)
    {
        node->val = node->next->val;
        prev = node;
        node = node->next;
    }
    prev->next = NULL;
    delete(node);
}

int main() {
    int arr[] = {4, 5, 1, 9};
    int size = sizeof(arr)/sizeof(arr[0]);

    ListNode* head = CreateLinkedList(arr, size);

    cout << "Original List: ";
    printList(head);

    ListNode* nodeToDelete = head->next;

    deleteNode(nodeToDelete);

    cout << "List After Deletion: ";
    printList(head);

    return 0;
}






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
//         next = nullptr;
//     }
// };

// ListNode *CreateLinkedList(int arr[], int size)
// {
//     if (size == 0)
//         return nullptr;

//     ListNode *head = new ListNode(arr[0]);
//     ListNode *temp = head;

//     for (int i = 1; i < size; i++)
//     {
//         temp->next = new ListNode(arr[i]);
//         temp = temp->next;
//     }

//     return head;
// }

// void printList(ListNode *head)
// {
//     ListNode *temp = head;
//     while (temp)
//     {
//         cout << temp->val;
//         if (temp->next)
//             cout << " -> ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void deleteNode(ListNode *node)
// {
    // node->val = node->next->val;
    // node->next = node->next->next;
// }

// int main()
// {
//     int arr[] = {4, 5, 1, 9};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     ListNode *head = CreateLinkedList(arr, size);

//     cout << "Original List: ";
//     printList(head);

//     ListNode *nodeToDelete = head->next;

//     deleteNode(nodeToDelete);

//     cout << "List After Deletion: ";
//     printList(head);

//     return 0;
// }