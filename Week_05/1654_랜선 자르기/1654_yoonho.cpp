#include<iostream>
#include<algorithm>

using namespace std;

long long arr[10000];

int main() {
	int K, N, c;
	long long max = 0;
	cin >> K >> N;

	for (int i = 0; i < K; i++){
		cin >> arr[i];
		max = max >= arr[i] ? max : arr[i];
	}

	long long min = 1, mid = 0;

	while (min <= max) {
		int cnt = 0;
		mid = (min + max) / 2;

		for (int i = 0; i < K; i++) {
			cnt += arr[i] / mid;
		}

		if (cnt >= N)
			min = mid + 1;
		else
			max = mid - 1;
	}

	cout << max << '\n';
}