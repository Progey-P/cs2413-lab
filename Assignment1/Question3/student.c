#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // TODO: implement
    int i=digitsSize-1; int outputSize; int carry=0; int result; // all variables needed
    
    while (i>=0 && digits[i] == 9){ //loop to check if I need a bigger array
        i--;
    }

    if (i<0){
        outputSize= digitsSize+1;
    } else{
        outputSize= digitsSize;
    }

    int* out = (int*)malloc(outputSize * sizeof(int)); // allocate memory
    *returnSize= outputSize; //return size of new array

    carry = 1; //will be adding one in either case
    int j= outputSize-1, k= digitsSize-1;

    while (k>=0){ //k will run out before j
        result= digits[k]+carry;
        out [j]= result%10; //%gives remainder
        carry= result/10; //will either be 1 or 0
        j--, k--;
    }

    if (j>=0){
        out[j]= carry; //the last index of j will be 1 (the carry)
    }
    return out; //return new array
}

