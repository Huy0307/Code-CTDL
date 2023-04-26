#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
 
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
/* Hàm th?c hi?n gi?i thu?t quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là ch? s? noi ph?n t? này dã d?ng dúng v? trí
         và là ph?n t? chia m?ng làm 2 m?ng con trái & ph?i */
        int pi = partition(arr, low, high);
 
        // G?i d? quy s?p x?p 2 m?ng con trái và ph?i
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void random(int arr[], int n) {
    srand(time(NULL));
    mt19937 rng(rand());
    uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < n; i++) {
    arr[i] = dist(rng) % 100 + 1;
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
//    random(arr2, n);
    random(arr3, n);

//Ngau nhien
//    cout << "Mang truoc khi sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//    quickSort(arr1, 0, n-1);
//    cout << "Mang sau khi sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;

////small to big
//    cout << "Mang truoc khi sap xep: ";
//    for (int i = 0; i < n; i++) {
//    	arr2[i] = arr2[i + 1];
//    }
//    cout << endl;
//    quickSort(arr2, 0, n-1);
//    cout << "Mang sau khi sap xep: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr2[i] << " ";
//    }
//    cout << endl;


//big to small
    cout << "Mang truoc khi sap xep: ";
       for (int i = n; i >= 1; i--) {
       arr3[n-i] = i;
    }
    cout << endl;
    quickSort(arr3, 0, n-1);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl; 
    
    return 0;
}

