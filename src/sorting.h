#if !defined(SORTING_H)
#define SORTING_H
namespace sorting {
  void bubblesort(int a[], int n);
  void selectionsort(int a[], int n);
  void insertionsort(int a[], int n);
  void mergesort(int a[], int l, int r);
  void merge(int a[], int l, int m, int r);
  void quicksort(int a[], int l, int r);
  int partition(int a[], int l, int r);
}
#endif
