/*
 * Sorting
 * Purpose: Benchmark runtime of popular sorting algorithms
 *
 * @author Bryan Andrade
 * @version 0.1 03/26/2018
 *
 * + Bubble sort
 * + Selection sort
 * + Insertion sort
 * + Merge sort
 * + Quick sort
 */
#include <iostream>
#include <chrono>
#include <string>
#include "sorting.h"

/**
 * Iterate through each sorting algorithm
 * For each sorting algorithm, perform sorts of
 * + 100 items
 * + 1,000 items
 * + 10,000 items
 * + 100,000 items
 * + 1,000,000 items
 */
int main(int argc, char *argv[]) {
  int n = 10;
  int *a = new int[n] {9, 2, 3, 4, 1, 7, 8, 5, 0, 6};
  // sorting::bubblesort(a, n);
  // sorting::selectionsort(a, n);
  // sorting::insertionsort(a, n);
  // sorting::mergesort(a, 0, 9);
  sorting::quicksort(a, 0, 9);
  for (int i = 0; i < n; i++) std::cout << a[i];
  std::cout << std::endl;
  delete [] a;
  return 0; 
}

