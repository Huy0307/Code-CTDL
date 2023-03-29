#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Tạo ma trận A ngẫu nhiên
    double** A = new double*[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            A[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Tạo ma trận B ngẫu nhiên
    double** B = new double*[n];
    for (int i = 0; i < n; i++)
    {
        B[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            B[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Tính tổng của hai ma trận A và B
    double** C = new double*[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // In ra ma trận tổng C
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
