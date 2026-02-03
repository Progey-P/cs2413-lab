#include "two_sum.h"

int two_sum(const int* nums, int n, int target, int* out_i, int* out_j) { //this is a function
    /* nums is pointer to first element of array; int n is number of elements in nums; target is the value you want; out put parameters (the index where values are stored) */

    // TODO: implement Two Sum.
    // Requirements:
    //  - find i < j such that nums[i] + nums[j] == target
    //  - store indices in *out_i and *out_j
    //  - return 1 if found; otherwise return 0
    // This solution is O(n^2)
    if (!nums || n<2 || !out_i || !out_j){ // if array is too small or other parameters arent sent through function
        return 0; //no solution
    }
    for (int i=0; i<n; i++){ // grabs first element; This is a brute force way; other ways are possible
        for (int j=i+1; j<n; j++){ //with first element held, loop through other elements to find a match to target
            if (nums[i] + nums[j] == target){
                *out_i = i; //will bring back pointers to those specific indexes to get target
                *out_j = j;
                return 1; // if found return 1
            }
        }
    }

    return 0; //no solution
}

//think about the time complexity and space complexity of your solution
/* Idea: Two for loops that loop through the array. 
   One grabs the first element and the other loops through the other elements in attempt to find solution
   Once solution has been found, return their pointers to the fucntion */
   /*Ideas 2: Could use another data structure like some sort algorithm that checks both sides? */
