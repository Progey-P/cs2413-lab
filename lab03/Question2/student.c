// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      if (head == NULL || head->next == NULL) return head; //Makes sure there is a pair to start with
      struct ListNode dummy; //make a fake node that points to head
      dummy.next = head;  // makes sure we always have head in the right place
      struct ListNode *prev = &dummy;
      
      while (prev->next !=NULL && prev->next->next != NULL){ //checks if two nodes exist outside the initial pair
            struct ListNode *first = prev->next; //the elements I need to swap
            struct ListNode *second = first->next;
            struct ListNode *nxp = second->next; //makes sure I dont lose the next nodule after pair

            second->next = first;
            first->next = nxp;
            prev->next = second;
            prev = first;
      }
      return dummy.next;
}