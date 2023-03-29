#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n = 30;
    vector<int> s(n);

    // Seed the random number generator
    srand(time(NULL));

    // Generate n random numbers and add them to the vector
    for (int i = 0; i < n; i++) {
        s[i] = rand() % 100;
        cout << s[i] << " ";
    }
    cout << endl;

    // Find the longest non-decreasing subsequence
    int max_len = 1;
    int curr_len = 1;
    int max_sum = s[0];
    int curr_sum = s[0];
    int start = 0;
    int max_start = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] >= s[i-1]) {
            curr_len++;
            curr_sum += s[i];
        } else {
            if (curr_len > max_len) {
                max_len = curr_len;
                max_sum = curr_sum;
                max_start = start;
            }
            curr_len = 1;
            curr_sum = s[i];
            start = i;
        }
    }

    if (curr_len > max_len) {
        max_len = curr_len;
        max_sum = curr_sum;
        max_start = start;
    }

    // Output the result

    cout << "Day con lien tuc khong giam dai nhat cua S la: ";
    for (int i = max_start; i < max_start + max_len; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    cout << "Day con lien tuc khong giam dai nhat cua S co do dai = " << max_len << endl;
    cout << "Tong cua no = " << max_sum << endl;
    return 0;
}