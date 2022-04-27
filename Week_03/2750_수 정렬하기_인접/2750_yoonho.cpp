#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j + 1] < arr[j])
                swap(arr[j + 1], arr[j]);
        }
    }
}

int main() {
    int N;
    int nums[1000];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    bubbleSort(nums, N);

    for (int i = 0; i < N; i++) {
        cout << nums[i] << '\n';
    }

    return 0;
}