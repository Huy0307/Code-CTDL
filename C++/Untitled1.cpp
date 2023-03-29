#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RandomArray(int *A, int n, int k) {
    srand(time(NULL));//Kh?i t?o s? ng?u nhiên
    int randNum = 0;
    for (int i = 0; i < n; i++) {
        randNum = rand() % k;
        A[i] = randNum;
    }
}
void RandomArray1(int *A, int n, int k) {
    srand(time(NULL));//Kh?i t?o s? ng?u nhiên
    int randNum;
    for (int i = 0; i < n; i++) {
        randNum = rand() % k;
        A[i] = randNum;
    }
}
void SumArray()
{
	printf("Bat dau P");
	int *P;
	int p = 100;
	int j = 99;
	P = new int[p];
	RandomArray(P, p, j);
	printf("Ket thuc P");
	printf("Bat dau q");
	int *Q;
	int q = 100;
	int h = 99;
	Q = new int[q];
	RandomArray1(Q, q, h);
	printf("Ket thuc q");
	for (int i = 0; i < p; i++) {
        printf("%4d", P[i]);

    }
        printf("\n");
	for (int i = 0; i < q; i++) {
        printf("%4d", Q[i]);

    }
        printf("\n");
}
int main() {
    int *A;
    int n = 1000; /* S? lu?ng ph?n t? c?a m?ng */
    int k = 9; /* M?i ph?n t? có giá tr? ng?u nhiên n?m trong kho?ng t? 0 d?n k */

    A = new int[n]; // C?p phát b? nh? cho m?ng A

    RandomArray(A, n, k);

    /* Xu?t m?ng */
    for (int i = 0; i < n; i++) {
        printf("%4d", A[i]);

    }
        printf("\n");
    delete[]A; // Free vùng nh? sau khi s? d?ng
    SumArray();
    return 0;
    
}
