// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    // TODO: implement
    if (head == NULL) return 0;
    
    struct ListNode *slow = head; //same set up as last question
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL){ //slow will always be at middle or mid+1
        slow = slow->next;
        fast = fast->next->next;
    }
    int val = slow->val;
    return val; //return val at mid
}