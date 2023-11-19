#pragma once

#include <iostream>
using namespace std;

/**
 * @brief Convert an array of integers to a string.
 * 
 * @param array Input array.
 * @param lowindex The lowest index of the array to be converted.
 * @param highindex The highest index of the array to be converted.
 * @return string Converted string
 */
string ArrayToString(int array[], int lowindex, int highindex);

/**
 * @brief Print an array of integers.
 * 
 */
void printArray(int array[], int lowindex, int highindex);