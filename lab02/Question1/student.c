// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

//assume array wouldnt be bigger than 100

bool isValid(const char *s) {
    // TODO: Implement using a stack.

    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.

    if (s == NULL ){ //corner case check
        return false;
    }
    
    size_t n= strlen(s); //set n equal to the string length
    if  (n%2 == 1){ //checks if its odd, an odd array always fails
        return false;
    }
    
    char stack[n]; //stack with size of strlen, always enough space
    size_t top=0; 
    for (size_t i=0; i<n; i++){ //loop to check all elements
        char c = s[i];

        if (c == '(' || c == '[' || c=='{'){ //checking for open brackets
            stack [top++] = c;
            continue;
        }
        
        if (top == 0) return false;
        char open = stack[top-1]; //check top of the stack and see if it is open or closed
        
        switch (c) {  //checks for any mismatches
            case ')':
                if (open != '(') return false;
                break;
            case ']':
                if (open != '[') return false;
                break;
            case '}':
                if (open != '{') return false;
                break;
            default:
                return false;
        }
        top--; //pop
    }
    return top==0; //final check, if empty, return true else false
}