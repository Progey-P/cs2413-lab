// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // TODO: implement
    if (head == NULL) return false;
    struct ListNode *slow = head; //the two pointer
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL){ //both have to be true to iterate
        slow = slow->next; //the loop for the pointers
        fast = fast->next->next;
        
        if (slow == fast) return true; //if cycle exist
    }
    return false; //if cycle doesnt exist
}