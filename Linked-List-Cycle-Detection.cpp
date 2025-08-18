/*
🐢🐇 The Tortoise and the Hare Race Analogy

Imagine a circular race track 🏟️.
	•	The slow pointer (slow) is like a 🐢 tortoise that moves 1 step at a time.
	•	The fast pointer (fast) is like a 🐇 hare that moves 2 steps at a time.

Now, there are two possibilities:

⸻

Case 1: 🚫 No Cycle

If the race track is just a straight road (like a linked list ending with NULL), then:
	•	The hare will reach the end (fall off the road, fast == NULL) before the tortoise.
	•	Since the hare disappears, they’ll never meet → no cycle.

⸻

Case 2: ✅ There is a Cycle

If the track is circular (cycle in the list):
	•	The hare moves faster, so it keeps running around the circle.
	•	The tortoise moves slower but is also inside the circle.
	•	Eventually, the hare will lap the tortoise and catch it.

*/

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
    bool hasCycle(ListNode* head) {
        // If the road is empty or only has 1 node, no chance of a cycle.
        if (!head || !head->next) return false; 

        ListNode* slow = head; 
        ListNode* fast = head; 

        while (fast && fast->next) {
            slow = slow->next;         
            fast = fast->next->next;  

            if (slow == fast) { 
                return true;
            }
        }
        return false; 
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

    int arr[] = {2, 4, 6, 8, 10};

    // ---------------- Case 1: No cycle (index = -1) ----------------
    ListNode* Head1 = CreateLinkedList(arr, 0, 5);

    Solution sol;
    bool result1 = sol.hasCycle(Head1);
    cout << (result1 ? "Cycle exists" : "No cycle") << " (Case 1)" << endl;


    // ---------------- Case 2: Cycle at index = 1 ----------------
    ListNode* Head2 = CreateLinkedList(arr, 0, 5);

    // make cycle: last node points to index 1 (value = 4)
    ListNode* tail = Head2;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = Head2->next;  // cycle created

    bool result2 = sol.hasCycle(Head2);
    cout << (result2 ? "Cycle exists" : "No cycle") << " (Case 2)" << endl;

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
//     bool hasCycle(ListNode* head) {

//         vector<ListNode *> visited;
//         ListNode *temp = head;

//         while(temp){
//             for(auto node: visited){
//                 if(node == temp->next){
//                     return true;
//                 }
//             }
//             visited.push_back(temp);
//             temp = temp->next;
//         }
//         return false;
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

//     int arr[] = {2, 4, 6, 8, 10};

//     // ---------------- Case 1: No cycle (index = -1) ----------------
//     ListNode* Head1 = CreateLinkedList(arr, 0, 5);

//     Solution sol;
//     bool result1 = sol.hasCycle(Head1);
//     cout << (result1 ? "Cycle exists" : "No cycle") << " (Case 1)" << endl;


//     // ---------------- Case 2: Cycle at index = 1 ----------------
//     ListNode* Head2 = CreateLinkedList(arr, 0, 5);

//     // make cycle: last node points to index 1 (value = 4)
//     ListNode* tail = Head2;
//     while (tail->next != NULL) {
//         tail = tail->next;
//     }
//     tail->next = Head2->next;  // cycle created

//     bool result2 = sol.hasCycle(Head2);
//     cout << (result2 ? "Cycle exists" : "No cycle") << " (Case 2)" << endl;

//     return 0;
// }
















// #include <iostream>
// #include <unordered_set>
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
//     bool hasCycle(ListNode* head) {
//         unordered_set<ListNode*> seen;
//         ListNode *curr = head;
//         while(curr){
//             if(seen.find(curr) != seen.end()){
//                 return true;
//             }
//             seen.insert(curr);
//             curr = curr->next;
//         }
//         return false;
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

//     int arr[] = {2, 4, 6, 8, 10};

//     // ---------------- Case 1: No cycle (index = -1) ----------------
//     ListNode* Head1 = CreateLinkedList(arr, 0, 5);

//     Solution sol;
//     bool result1 = sol.hasCycle(Head1);
//     cout << (result1 ? "Cycle exists" : "No cycle") << " (Case 1)" << endl;


//     // ---------------- Case 2: Cycle at index = 1 ----------------
//     ListNode* Head2 = CreateLinkedList(arr, 0, 5);

//     // make cycle: last node points to index 1 (value = 4)
//     ListNode* tail = Head2;
//     while (tail->next != NULL) {
//         tail = tail->next;
//     }
//     tail->next = Head2->next;  // cycle created

//     bool result2 = sol.hasCycle(Head2);
//     cout << (result2 ? "Cycle exists" : "No cycle") << " (Case 2)" << endl;

//     return 0;
// }
