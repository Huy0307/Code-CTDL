#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void random(int arr[], int n) {
    srand(time(NULL));
    mt19937 rng(rand());
    
    uniform_int_distribution<int> dist(1, 100);
    
    for (int i = 0; i < n; i++) {
        arr[i] = dist(rng);
    }
}

void merge(int arr[], int l, int m, int r) 
{ 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    // Create temp arrays  
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays L[] and R[]  
    for(int i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for(int j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back into arr[l..r] 
      
    // Initial index of first subarray 
    int i = 0;  
      
    // Initial index of second subarray 
    int j = 0;  
      
    // Initial index of merged subarray 
    int k = l; 
      
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j])  
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else 
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // L[], if there are any  
    while (i < n1)  
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // R[], if there are any  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l + (r - l) / 2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int main(){
    int n;
    cout << "Nhap vao so phan tu cua mang: ";
    cin >> n;

    int arr1[n];
    int arr2[n];
    int arr3[n];
//    random(arr1, n);
    random(arr2, n);
//    random(arr3, n);
////normal
//    cout << "Mang chua sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//
//    mergeSort(arr1, 0, n - 1);
//
//    cout << "Mang da sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//

//small to big
cout << "Mang chua sap xep: ";
    for (int i = 0; i < n; i++) {
        arr2[i] = arr2[i + 1];
    }
    cout << endl;

    mergeSort(arr2, 0, n - 1);

    cout << "Mang da sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

//big to small
//    cout << "Mang truoc khi sap xep: ";
//    for (int i > n; i >=1; i--) {
//    	arr3[n-1] = i;
//    }
//    cout << endl;
//    mergeSort(arr3, 0, n - 1);
//    cout << "Mang sau khi sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr3[i] << " ";
//    }
//    cout << endl;

    return 0;
}

