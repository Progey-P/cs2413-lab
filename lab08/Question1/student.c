#include <stdio.h>

/*
Question 1: Longest Common Prefix

Write a function to find the longest common prefix string
among an array of strings.

A prefix is the beginning part of a string.

Examples:
Input: ["flower", "flow", "flight"]
Output: "fl"

Input: ["dog", "racecar", "car"]
Output: ""

IMPORTANT:
- You ARE allowed to modify the first string (strs[0])
- You should store the result directly in strs[0]
- Return strs[0] as the result
*/

char* longestCommonPrefix(char** strs, int strsSize) {
      // TODO: implement
      if (strsSize==0) return "";
      if (strsSize==1) return strs[0];

      for (int i=1; i<strsSize; i++){
            for (int j=0; strs[0][j]!='\0'; j++){
                  if (strs[0][j] != strs[i][j]){
                        strs[0][j] = '\0';
                        break;
                  }
            }
            if (strs[0][0] == '\0') break;
      }
      return strs[0];
}