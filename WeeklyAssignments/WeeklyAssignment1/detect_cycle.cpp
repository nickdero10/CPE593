/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Weekly Assignment 1: Detect Cycle
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // initializes the slow and fast pointers at the start
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            // moves slow forward 1
            slow = slow->next;
            //moves fast forward 2
            fast = fast->next->next;
            // when they meet grab the node from findCycleStart
            if (slow == fast) {
                // grabs value from findCycleStart
                return findCycleStart(head, slow);
            }
        }
        return nullptr;
    }
private:
    ListNode *findCycleStart(ListNode *head, ListNode *meetingPoint) {
        // initializes the head as the first pointer and meeting point as second pointer
        ListNode *ptr1 = head, *ptr2 = meetingPoint;
        // keeps movind through cycle until the two pointers meet
        while (ptr1 != ptr2) {
            // moves each pointer one space at a time
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        // returns the value they met at
        return ptr1;
    }
};

// Helper function to create a cycle in the linked list
void createCycle(ListNode* head, int pos) {
    if (!head || pos == -1) return;
    ListNode* tail = head;
    ListNode* cycleNode = nullptr;
    int index = 0;
    
    while (tail->next) {
        if (index == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        index++;
    }
    
    if (cycleNode) {
        tail->next = cycleNode; // Create a cycle
    }
}

int main() {
    int n, cyclePos;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "No nodes to create a linked list." << endl;
        return 0;
    }
    
    vector<int> values(n);
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    
    cout << "Enter the position to create a cycle (-1 for no cycle): ";
    cin >> cyclePos;

    // Create the linked list
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    // Create the cycle if specified
    createCycle(head, cyclePos);

    // Detect the cycle
    Solution solution;
    ListNode* cycleStart = solution.detectCycle(head);

    if (cycleStart) {
        cout << "Cycle detected. Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
