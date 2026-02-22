// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in Student.h.
//
// You are designing a fixed-size queue with capacity k.
// The queue supports enqueue/dequeue in O(1) time using a circular array.
//
// Recommended invariants (simple + robust):
// - Use an integer `size` to track how many elements are currently stored.
// - Queue is empty  <=> size == 0
// - Queue is full   <=> size == capacity
// - `head` points to the current front element
// - `tail` points to the next insertion position
// - Wrap indices using modulo: (idx + 1) % capacity
//
// Examples (k = 3):
//   enQueue(1) -> true    queue: [1]
//   enQueue(2) -> true    queue: [1,2]
//   enQueue(3) -> true    queue: [1,2,3]
//   enQueue(4) -> false   (full)
//   Rear()     -> 3
//   isFull()   -> true
//   deQueue()  -> true    queue: [2,3]
//   enQueue(4) -> true    queue: [2,3,4]
//   Rear()     -> 4
//   Front()    -> 2
//
// Return values rules:
// - Front / Rear should return -1 if the queue is empty.
//
// How to run tests (from the folder containing the Makefile):
//   make run2
// ------------------------------------------------------------

/*
typedef struct {
    int *data;      // buffer of length capacity
    int capacity;   // k
    int head;       // index of front element
    int tail;       // index of next insertion position
    int size;       // number of elements currently in queue
} MyCircularQueue;
*/

#include "Student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool

MyCircularQueue* myCircularQueueCreate(int k) {
    // TODO:
    // - Allocate MyCircularQueue
    // - Allocate the internal buffer `data` of length k
    // - Initialize capacity, head, tail, size
    MyCircularQueue *p = malloc(sizeof(MyCircularQueue)); //memory for queue
    if (p==NULL) return NULL;
    p->data= malloc(k * sizeof(int)); //memory for array of size k (internal buffer)
    if (p->data == NULL){
        free(p);
        return NULL;
    }
    p->capacity =k;  //initializing
    p->head =0;
    p->tail =0;
    p->size =0;

    return p; //return the pointer to use for later (obj)
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    // TODO:
    // - If full, return false
    // - Write value at tail, advance tail (wrap), size++
    if (myCircularQueueIsFull(obj) == true) return false;
    obj->data[obj->tail] = value;
    obj->tail = (obj->tail+1) % obj->capacity; obj->size++; 
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    // TODO:
    // - If empty, return false
    // - Advance head (wrap), size--
    if (myCircularQueueIsEmpty(obj) == true) return false;
    obj->head = (obj->head+1) % obj->capacity; obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    // TODO:
    // - Return -1 if empty
    // - Otherwise return data[head]
    if (myCircularQueueIsEmpty(obj) == true) return -1; //if empty
    int Front = obj->data[obj->head]; //front is data[head]
    return Front;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    // TODO:
    // - Return -1 if empty
    // - Otherwise return the last inserted element
    //   (tail points to next insertion position)
    if (myCircularQueueIsEmpty(obj) == true) return -1;
    int rearIndex = (obj->tail -1 + obj->capacity)% obj->capacity; //need the element before tail and no neg nums
    int Rear = obj->data[rearIndex];
    return Rear;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    // TODO:
    // - Return true if size == 0
    if(obj->size == 0){
        return true;
    } else {
        return false;
    }
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    // TODO:
    // - Return true if size == capacity
    if (obj->size == obj->capacity){
        return true;
    } else{
        return false;
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    // TODO:
    // - Free internal buffer then free obj
    free(obj->data);
    free(obj);
}
