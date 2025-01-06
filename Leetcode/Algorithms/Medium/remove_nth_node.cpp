
/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/


#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // First we need to find the size of the list
        int size = 0;
        ListNode* t = head;
        while(t != nullptr){
            t = t->next;
            size++;
        }

        // We need to remove the first node
        // (special case)
        if(size == n){
            return head->next;
        }
        
        // Normal node removal of singly linked list
        t = head;
        for(int i = 1; i < size - n; i++){
            t = t->next;
        }
        t->next = t->next->next;
        return head;
    }
};