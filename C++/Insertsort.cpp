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

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

//  normal
//    cout << "Mang truoc khi sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//
//    insertionSort(arr1, n);
//
//    cout << "Mang sau khi sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
    
//small to big
    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; i++) {
    	arr2[i] = arr2[i+1];
    }
    cout << endl;

    insertionSort(arr2, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

//big to small
//    cout << "Mang truoc khi sap xep: ";
//    for (int i > n; i >=1; i--) {
//    	arr3[n-1]=i;
//    }
//    cout << endl;
//
//    insertionSort(arr3, n);
//
//    cout << "Mang sau khi sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr3[i] << " ";
//    }
//    cout << endl;
    return 0;
}

