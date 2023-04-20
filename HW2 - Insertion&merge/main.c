#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

void InsertionSort(int *A, int n);
void MergeSort(int *A, int left, int right);
void Merge(int *A, int left, int mid, int right);

void GenerateRamdomIntegers(int *A, int n);
bool IsSorted(int *A, int n, bool accedingOrder);
void CheckTheResult(int *A, int n, bool accendingOrder);
void PrintArray(int *A, int n);
int GetCurrentUsec();

int main(void) {
  int arr_n[] = {10, 50, 100, 500, 1000, 2000, 3000};
  for (int i = 0; i < 7; i++) {
    int n = arr_n[i];
    printf("n = %d\n", n);
    int *A = (int *)malloc(n * sizeof(int)); // line 21
    GenerateRamdomIntegers(A, n);            // line 22
    // int A[] = {31, 41, 59, 26, 41, 58}; // line 23
    // int n = sizeof(A) / sizeof(A[0]);   // line 24

    int *B = (int *)malloc(n * sizeof(int));
    memcpy(B, A, n * sizeof(int));

    // print input
    // printf("Input : ");
    // PrintArray(A, n);
    // CheckTheResult(A, n, true);
    int t_merge;
    int t_insertion;

    int t1, t2;

    // Insertion Sort
    t1 = GetCurrentUsec();
    InsertionSort(A, n);
    t2 = GetCurrentUsec();
    // printf("Output : ");
    // PrintArray(A, n);
    CheckTheResult(A, n, true);
    t_insertion = t2 - t1;
    printf("Insertion took %d usec\n", t_insertion);

    // Merge Sort
    t1 = GetCurrentUsec();
    MergeSort(B, 0, n - 1);
    t2 = GetCurrentUsec();
    // printf("Output : ");
    // PrintArray(B, n);
    CheckTheResult(A, n, true);
    t_merge = t2 - t1;
    printf("Merge took %d usec\n", t_merge);

    float ratio = (float)t_merge / (float)t_insertion;
    printf("Ratio : %0.3f\n\n", ratio);

    // if (ratio == 1.00000) {
    //   printf("approximate n is : %d\n", n);
    //   return 0;
    // }
  }

  return 0;
}

void GenerateRamdomIntegers(int *A, int n) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    A[i] = rand() % 100;
  }
  return;
}

void InsertionSort(int *A, int n) {
  // your code here
  int i, key, j;

  for (j = 1; j < n; j++) {
    key = A[j];
    i = j - 1;

    while (i >= 0 && A[i] > key) {
      A[i + 1] = A[i];
      i = i - 1;
    }

    A[i + 1] = key;
  }
  return;
}

void MergeSort(int *A, int left, int right) { // A , 0 , n-1
  if (left < right) {
    int mid = floor((left + right) / 2);
    // your code here
    MergeSort(A, left, mid);
    MergeSort(A, mid + 1, right);

    Merge(A, left, mid, right);
  }
}

void Merge(int *A, int left, int mid, int right) { // A , 0 , (n-1)/2 , n-1
  int size = right - left + 1;
  int *M = (int *)malloc(sizeof(int) * (size));

  int i = left;
  int j = mid + 1; // right

  int m = 0;
  while ((i <= mid) && (j <= right)) {
    if (A[i] <= A[j]) {
      M[m] = A[i];
      i++;
    } else {
      M[m] = A[j];
      j++;
    }
    m++;
  }

  while (i <= mid) {
    M[m] = A[i];
    i++;
    m++;
  }

  while (j <= right) {
    M[m] = A[j];
    j++;
    m++;
  }

  for (int k = 0; k < size; k++) {
    A[left + k] = M[k];
  }

  return;
}

void PrintArray(int *A, int n) {
  printf("{");
  for (int i = 0; i < n; i++) {
    printf("%d, ", A[i]);
  }
  printf("}\n");
}

int GetCurrentUsec() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_usec;
}

void CheckTheResult(int *A, int n, bool accendingOrder) {
  printf("The result is ");
  if (!IsSorted(A, n, true))
    printf("not ");
  printf("sorted in ascending order.\n");
  return;
}

bool IsSorted(int *A, int n, bool accedingOrder) {
  for (int i = 0; i < n - 1; i++) {
    if (accedingOrder) {
      if (A[i] > A[i + 1])
        return false;
    } else {
      if (A[i] < A[i + 1])
        return false;
    }
  }
  return true;
}
