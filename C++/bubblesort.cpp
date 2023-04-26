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

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main(){
    int n;
    cout << "Nhap vao so phan tu cua mang: ";
    cin >> n;

    int arr1[n];
    int arr2[n];
    int arr3[n];
    random(arr1, n);
//    random(arr2, n);
//    random(arr3, n);

//normal
    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    bubbleSort(arr1, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

//small to big
//    cout << "Mang truoc khi sap xep: ";
//    for (int i = 0; i < n; i++) {
//    	arr2[i] = i+1;
//    }
//    cout << endl;
//
//    bubbleSort(arr2, n);
//
//    cout << "Mang sau khi sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr2[i] << " ";
//    }
//    cout << endl;

//big to small
//    cout << "Mang truoc khi sap xep: ";
//    for (int i = n; i >= 1; i--) {
//    	arr3[n-1]=i;
//    }
//    bubbleSort(arr3, n);
//    cout << "Mang sau khi sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr3[i] << " ";
//    }
//    cout << endl;

    return 0;
}

