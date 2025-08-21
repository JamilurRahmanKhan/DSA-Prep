// 138. Copy List with Random Pointer


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// ---------------------- Solution Class ----------------------
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if(!head) return NULL;

        // insert the new nodes in between the original linked list
        Node* cur = head;

        while (cur)
        {
            Node* curNext = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = curNext;
            cur = curNext;
        }

        // Deep copy of random pointers
        cur = head;
        while (cur && cur->next)
        {
            if(!cur->random)
            {
                cur->next->random = NULL;
            }
            else
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        // seperate the linked lists
        Node* newHead = head->next;
        Node* newCur = newHead;
        cur = head;

        while (cur && newCur)
        {
            cur->next = cur->next == NULL ? NULL : cur->next->next;

            newCur->next = newCur->next == NULL ? NULL : newCur->next->next;

            cur = cur->next;
            newCur = newCur->next;
        }
        return newHead;
    }
};

// ---------------------- Helper Functions ----------------------

// Build linked list from vector of {val, random_index}
Node *buildList(vector<pair<int, int>> nodes)
{
    if (nodes.empty())
        return nullptr;

    vector<Node *> created(nodes.size(), nullptr);

    // Create all nodes
    for (int i = 0; i < nodes.size(); i++)
    {
        created[i] = new Node(nodes[i].first);
    }

    // Set next pointers
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        created[i]->next = created[i + 1];
    }

    // Set random pointers
    for (int i = 0; i < nodes.size(); i++)
    {
        int randomIndex = nodes[i].second;
        if (randomIndex != -1)
        {
            created[i]->random = created[randomIndex];
        }
    }

    return created[0];
}

// Print linked list as [val, random_index]
void printList(Node *head)
{
    vector<Node *> nodes;
    Node *temp = head;
    while (temp)
    {
        nodes.push_back(temp);
        temp = temp->next;
    }

    cout << "[";
    for (int i = 0; i < nodes.size(); i++)
    {
        int randomIndex = -1;
        if (nodes[i]->random)
        {
            for (int j = 0; j < nodes.size(); j++)
            {
                if (nodes[j] == nodes[i]->random)
                {
                    randomIndex = j;
                    break;
                }
            }
        }
        cout << "[" << nodes[i]->val << ",";
        if (randomIndex == -1)
            cout << "null";
        else
            cout << randomIndex;
        cout << "]";
        if (i != nodes.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

// ---------------------- Main ----------------------
int main()
{
    // Example Input: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    // We'll represent null as -1
    vector<pair<int, int>> input = {
        {7, -1},
        {13, 0},
        {11, 4},
        {10, 2},
        {1, 0}};

    Node *head = buildList(input);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    Node *copied = sol.copyRandomList(head);

    cout << "Copied List:   ";
    printList(copied);

    return 0;
}










// #include <iostream>
// #include <vector>
// #include <string>
// #include <sstream>
// #include <unordered_map>
// using namespace std;

// // Definition for a Node.
// class Node
// {
// public:
//     int val;
//     Node *next;
//     Node *random;

//     Node(int _val)
//     {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

// // ---------------------- Solution Class ----------------------
// class Solution
// {
// public:
//     Node *copyRandomList(Node *head)
//     {
//         if(!head) return NULL;

//         unordered_map<Node*, Node*> mp;

//         Node* cur = head;
//         Node* prev = NULL;
//         Node* newHead = NULL;
//         // mapping new nodes with main nodes
//         while (cur)
//         {
//             Node* temp = new Node(cur->val);
//             mp[cur] = temp;

//             // create a new linked list with the copied nodes
//             if(!newHead)
//             {
//                 newHead = temp;
//                 prev = temp;
//             }
//             else
//             {
//                 prev->next = temp;
//                 prev = prev->next;
//             }
//             cur = cur->next;
//         }

//         // point the random pointers in the new linked list
//         cur = head;
//         Node* newCur = newHead;
//         while(cur)
//         {
//             if(!cur->random)
//             {
//                 newCur->random = NULL;
//             }
//             else
//             {
//                 newCur->random = mp[cur->random];
//             }
//             cur = cur->next;
//             newCur = newCur->next;
//         }
//         return newHead;
//     }
// };

// // ---------------------- Helper Functions ----------------------

// // Build linked list from vector of {val, random_index}
// Node *buildList(vector<pair<int, int>> nodes)
// {
//     if (nodes.empty())
//         return nullptr;

//     vector<Node *> created(nodes.size(), nullptr);

//     // Create all nodes
//     for (int i = 0; i < nodes.size(); i++)
//     {
//         created[i] = new Node(nodes[i].first);
//     }

//     // Set next pointers
//     for (int i = 0; i < nodes.size() - 1; i++)
//     {
//         created[i]->next = created[i + 1];
//     }

//     // Set random pointers
//     for (int i = 0; i < nodes.size(); i++)
//     {
//         int randomIndex = nodes[i].second;
//         if (randomIndex != -1)
//         {
//             created[i]->random = created[randomIndex];
//         }
//     }

//     return created[0];
// }

// // Print linked list as [val, random_index]
// void printList(Node *head)
// {
//     vector<Node *> nodes;
//     Node *temp = head;
//     while (temp)
//     {
//         nodes.push_back(temp);
//         temp = temp->next;
//     }

//     cout << "[";
//     for (int i = 0; i < nodes.size(); i++)
//     {
//         int randomIndex = -1;
//         if (nodes[i]->random)
//         {
//             for (int j = 0; j < nodes.size(); j++)
//             {
//                 if (nodes[j] == nodes[i]->random)
//                 {
//                     randomIndex = j;
//                     break;
//                 }
//             }
//         }
//         cout << "[" << nodes[i]->val << ",";
//         if (randomIndex == -1)
//             cout << "null";
//         else
//             cout << randomIndex;
//         cout << "]";
//         if (i != nodes.size() - 1)
//             cout << ",";
//     }
//     cout << "]" << endl;
// }

// // ---------------------- Main ----------------------
// int main()
// {
//     // Example Input: [[7,null],[13,0],[11,4],[10,2],[1,0]]
//     // We'll represent null as -1
//     vector<pair<int, int>> input = {
//         {7, -1},
//         {13, 0},
//         {11, 4},
//         {10, 2},
//         {1, 0}};

//     Node *head = buildList(input);

//     cout << "Original List: ";
//     printList(head);

//     Solution sol;
//     Node *copied = sol.copyRandomList(head);

//     cout << "Copied List:   ";
//     printList(copied);

//     return 0;
// }