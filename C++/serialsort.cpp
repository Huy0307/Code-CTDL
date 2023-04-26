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
int main(){
    
}
