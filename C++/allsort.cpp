#include <iostream>
#include <random>
#include <ctime>
#include <ctime>
using namespace std;
void randomArray(int arr[], int n) {
    srand(time(NULL));
    mt19937 rng(rand());
    

    uniform_int_distribution<int> dist(1, 100);
    

    for (int i = 0; i < n; i++) {
        arr[i] = dist(rng);
    }
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
    const int n = 1000;
    int arr1[n];
    int arr2[n];
    int arr3[n];

//    randomArray(arr1, n);
//    randomArray(arr2, n);
    randomArray(arr3, n);
//normal
//    cout << "Mang chua sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//    cout<<"\nMang sau khi sap xep:";
//    bubbleSort(arr1, n);
//    for (int i = 0; i < n; i++) {
//    }

//// day lon be
//    for (int i = n; i >= 1; i--) {
//        arr2[n - i] = i;
//    }   
//    bubbleSort(arr2, n);
//    cout<<"\n Mang sau khi sap xep";
//     for (int i = 0; i < n; i++) {
//        cout << arr2[i] << " ";
//    }
//  
// day be lon  
    for (int i = 0; i < n; i++) {
        arr3[i] = i + 1;
    }  
    bubbleSort(arr3, n);
	    cout<<"\n Mang sau khi sap xep";  
	     for (int i = 0; i < n; i++) {
        cout << arr3[i] << " ";
    }
    return 0;
}
