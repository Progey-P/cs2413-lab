#include "Student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
     int i=0; int contender=nums[i]; int count=0; //contender= possible candidate; counter to keep track of reps
     while (i<numsSize){
          //I want to loop through the array and keep a count that inc or dec based off the element repetition
          if (count == 0){ //if count is already at zero
                    contender = nums[i]; //set contender to the new element
          }
          if (contender==nums[i]){
               count++; //if the contender is found again, increase counter
          } else{ //if count isn't zero
               count--; //decrement count and repeat the loop
          }
          i++;  
          }
     
     return contender; //return the majority element

}
