#include <iostream>

using namespace std;

void selectionSort(int arr[], int size) {

    for (int i = 0; i < size - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[idx]) {
                idx = j;
            }
        }
        swap(arr[idx], arr[i]);
    }
}

int main() {
    int N;
    int nums[1000];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    selectionSort(nums, N);

    for (int i = 0; i < N; i++) {
        cout << nums[i] << '\n';
    }

    return 0;
}