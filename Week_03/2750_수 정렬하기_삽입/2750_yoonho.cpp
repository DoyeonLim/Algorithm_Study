#include <iostream>

using namespace std;

void insertionSort(int arr[], int size) {

    for (int i = 1; i < size; i++) {
        int j;
        int temp = arr[i];
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > temp)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int N;
    int nums[1000];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    insertionSort(nums, N);

    for (int i = 0; i < N; i++) {
        cout << nums[i] << '\n';
    }

    return 0;
}
