/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/reorder-list/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {

        // This can either be solved by manually reversing a copy of the
        // list, or using a stack, and popping the elements to get them
        // in reverse (likewise, using recursion works).

        // First we create a copy of the list (and count its size)
        int size = 0;
        ListNode* newHead = new ListNode(head->val);
        ListNode* temp = head->next;
        ListNode* newTemp = newHead;
        while(temp != nullptr){
            newTemp->next = new ListNode(temp->val);
            temp = temp->next;
            newTemp = newTemp->next;
            size++;
        }
        size++;
        
        // Then we reverse the list
        ListNode* prev = nullptr;
        ListNode* curr = newHead;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // The head is now the last node previously
        newHead = prev;

        // Then we just modify the original list such that it alternates
        // between the two we built until we reach the halfway point
        temp = head;
        for(int i = 1; i < size; i++){
            // Inserting a new node
            ListNode* newNode = new ListNode(newHead->val, temp->next);
            temp->next = newNode;
            newHead = newHead->next;
            i++;
            // Ensures that we stop at the right node according to size
            if(i < size)
                temp = temp->next->next;
            else temp = temp->next;
        }
        temp->next = nullptr;
    }
};