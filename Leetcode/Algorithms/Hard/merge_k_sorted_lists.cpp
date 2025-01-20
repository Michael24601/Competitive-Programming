/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Starts with a dummy node that is empty
        ListNode* sorted = new ListNode();
        ListNode* ptr = sorted;
        // done[i] is true if the lists[i] is done being merged
        vector<int> done(lists.size(), 0);
        while(true){
            bool done = true;
            // We need to find the minimum of each list
            int min = 999999;
            // Which list's index had the minimum element
            int index;
            for(int i = 0; i < lists.size(); i++){
                if(lists[i] != nullptr && min > lists[i]->val){
                    min = lists[i]->val;
                    index = i;
                    done = false;
                }
            }

            // If no more minima, we are done
            if(done) break;

            ptr->next = lists[index];
            ptr = ptr->next;
            lists[index] = lists[index]->next;
        }
        // We then make the end of the list point ot nullptr
        // and we remove the dummy node
        ptr->next = nullptr;
        ptr = sorted->next;
        delete sorted;
        return ptr;
    }
};