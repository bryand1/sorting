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
#include "sorting.h"

template <typename T>
void swap(T &a, T &b) {
  T t = a;
  a = b;
  b = t;
}

void sorting::bubblesort(int a[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
        if (a[j] > a[j + 1]) {
          swap(a[j], a[j + 1]);
        }
    }
  }
}

void sorting::selectionsort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int m = i;
    for (int j = i; j < n; j++) {
        if (a[j] < a[m]) m = j;
    }
    swap(a[i], a[m]);
  }
}

void sorting::insertionsort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && key < a[j]) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

void sorting::mergesort(int a[], int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    sorting::mergesort(a, l, m);
    sorting::mergesort(a, m + 1, r);
    sorting::merge(a, l, m, r);
  }
}

void sorting::merge(int a[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  int *L = new int[n1] {};
  int *R = new int[n2] {};
  int i, j;
  for (i = 0; i < n1; i++) L[i] = a[l + i];
  for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];

  i = 0;
  j = 0;
  int k = l;

  while (i < n1 && j < n2) {
    if (L[i] < R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }

  delete [] L;
  delete [] R;
}

void sorting::quicksort(int a[], int l, int r) {
  if (l < r) {
    int pivot = sorting::partition(a, l, r);
    sorting::quicksort(a, l, pivot - 1);
    sorting::quicksort(a, pivot + 1, r);
  }
}

int sorting::partition(int a[], int l, int r) {
  int pivot = a[r];
  int i = l - 1;
  for (int j = l; j < r; j++) {
    if (a[j] <= pivot) {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[r]);
  return i + 1;
}

