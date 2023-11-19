#include "print_array.h"

/**
 * @brief Convert an array of integers to a string.
 * 
 */
string ArrayToString(int array[], int lowindex, int highindex) {
   // Special case for empty array
   if (0 > highindex - lowindex) {
      return string("[]");
   }
   
   // Start the string with the opening '[' and element 0
   string result = "[" + to_string(array[lowindex]);
   
   // For each remaining element, append comma, space, and element
   for (int i = lowindex+1; i <= highindex; i++) {
      result += ", ";
      result += to_string(array[i]);
   }
   
   // Add closing ']' and return result
   result += "]";
   return result;
}

/**
 * @brief Print an array of integers.
 * 
 */
void printArray(int array[], int lowindex, int highindex) {
   cout << ArrayToString(array, lowindex, highindex) << endl;
}