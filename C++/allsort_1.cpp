#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

void generateList(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = n-i;//rand();
}
}
void generateList_big_small(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = n-i-1;
    }
}
void generateList_small_big(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = i;
    }
}

void printList(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }
        swap(A[i], A[min_index]);
    }
}

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pivot = A[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (A[j] < pivot) {
                i++;
                swap(A[i], A[j]);
            }
        }
        swap(A[i + 1], A[high]);
        int pi = i + 1;
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
   i++;
  } else {
   A[k] = R[j];
   j++;
  }
   k++;
  }
  while (i < n1) {
   A[k] = L[i];
   i++;
   k++;
  }
  while (j < n2) {
   A[k] = R[j];
   j++;
   k++;
  }
 }
   
 void mergeSort(int A[], int left, int right) {
  if (left < right) {
   int mid = left + (right - left) / 2;
   mergeSort(A, left, mid);
   mergeSort(A, mid + 1, right);
   merge(A, left, mid, right);
  }
 }
   
   
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int A[n];
    generateList_big_small(A, n);
    generateList(A, n);
    generateList_small_big(A, n);

    auto start_time = chrono::high_resolution_clock::now();
    insertionSort(A, n);
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time = end_time - start_time;
    cout << "Insertion sort time: " << elapsed_time.count() << " seconds" << endl;

    generateList_big_small(A, n);
    generateList(A, n);
    generateList_small_big(A, n);
    start_time = chrono::high_resolution_clock::now();
    selectionSort(A, n);
    end_time = chrono::high_resolution_clock::now();
    elapsed_time = end_time - start_time;
    cout << "Selection sort time: " << elapsed_time.count() << " seconds" << endl;

    generateList_big_small(A, n);
    generateList(A, n);
    generateList_small_big(A, n);

    start_time = chrono::high_resolution_clock::now();
    bubbleSort(A, n);
    end_time = chrono::high_resolution_clock::now();
    elapsed_time = end_time - start_time;
    cout << "Bubble sort time: " << elapsed_time.count() << " seconds" << endl;

    generateList_big_small(A, n);
    generateList(A, n);
    generateList_small_big(A, n);

    start_time = chrono::high_resolution_clock::now();
    quickSort(A, 0, n - 1);
    end_time = chrono::high_resolution_clock::now();
    elapsed_time = end_time - start_time;
    cout << "Quick sort time: " << elapsed_time.count() << " seconds" << endl;

    generateList_big_small(A, n);
    generateList(A, n);
    generateList_small_big(A, n);

    start_time = chrono::high_resolution_clock::now();
    mergeSort(A, 0, n - 1);
    end_time = chrono::high_resolution_clock::now();
    elapsed_time = end_time - start_time;
    cout << "Merge sort time: " << elapsed_time.count() << " seconds" << endl;

    return 0;
}

