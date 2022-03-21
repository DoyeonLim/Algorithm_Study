#include <iostream>

using namespace std;

void quickSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int pivot = left;
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (arr[i] <= arr[pivot] && i <= right)
            i++;
        while (arr[pivot] < arr[j] && left <= j)
            j--;

        if (i > j) {
            swap(arr[pivot], arr[j]);
        }  
        else {
            swap(arr[i], arr[j]);
        }
    }

    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

int main() {
    int N;
    int nums[1000];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    quickSort(nums, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << nums[i] << '\n';
    }

    return 0;
}