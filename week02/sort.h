#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>

//Basic outline of selectionSort:
//   From 0 to n-1, inclusive:
//     find least element in remainder of array, swap with current element
//Max runtime: O(n^2)
//Min runtime: OMEGA(n^2)
//So we hsave: THETA(n^2)
void selectionSort(int *array, int length);

//Basic outline of insertionSort:
//   Place first element of array as element 0 in sorted array
//   From 1 to n-1, inclusive:
//     insert current element in unsorted array into proper place in sorted array
//Max runtime: O(n^2)
//Min runtime: OMEGA(n)
void insertionSort(int *array, int length);

//Basic outline of bubbleSort:
//   Continue until no swaps:
//     from 0 to n-2, inclusive:
//       if a[i] > a[i+1], swap
//Note: This passes the largest element to the end every time
//Max runtime: O(n^2)
//Min runtime: OMEGA(n)
void bubbleSort(int *array, int length);

//Basic outline of mergeSort:
//   While length of array is > 1:
//     MergeSort left half
//     MergeSort right half
//     Merge two halves
//This is recursive, invoking itself until the length is one,
//   then merging the two halves such that they are sorted
//Max runtime: O(nlog(n))
//Min runtime: OMEGA(nlog(n))
//So we have:  THETA(nlog(n))
void mergeSort(int *array, int length);

#endif

