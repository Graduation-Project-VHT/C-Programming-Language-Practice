/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:
Input: head = [1,1,2]
Output: [1,2]


Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

*/

#include <stdio.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *current = head;
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
}