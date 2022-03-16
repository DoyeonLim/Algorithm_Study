#include <iostream>

using namespace std;

int N, S;
int arr[20];
int result = 0;

void cal(int idx, int sum) {

    sum += arr[idx];

    if (idx >= N)
        return;
    if (sum == S)
        result++;

    cal(idx + 1, sum - arr[idx]);
    cal(idx + 1, sum);
}


int main() {

    cin >> N >> S;
    for (int i = 0; i < N; i++) 
        cin >> arr[i];
  
    cal(0, 0);

    cout << result;

    return 0;
}