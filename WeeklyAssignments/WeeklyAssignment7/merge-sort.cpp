/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Weekly Assignment 7: Sorting
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* getMid(Node* head){
    if(!head || !head->next){
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node* a, Node* b){
    if(!a){
        return b;
    }

    if(!b){
        return a;
    }

    if(a->data <= b->data){
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

Node* MergeSort(Node* head){
    if(!head || !head->next){
        return head;
    }

    Node* mid = getMid(head);
    Node* nextMid = mid->next;
    mid->next = nullptr;

    Node* left = MergeSort(head);
    Node* right = MergeSort(nextMid);

    return merge(left, right);
}

void output(Node* head){
    while(head){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "Null" << endl;
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;


    cout << "Enter Elements: ";
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;

        Node* newNode = new Node{val, nullptr};

        if(!head){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    cout << "Original List: ";
    output(head);

    head = MergeSort(head);

    cout << "Sorted List: ";
    output(head);

    return 0;
}