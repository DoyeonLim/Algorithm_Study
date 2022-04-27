#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> th;

int main() {

	int N, M, c = 0, ans = 0;
	cin >> N >> M;

	long long max = 0;
	for (int i = 0; i < N; i++) {
		cin >> c;
		max = max >= c ? max : c;
		th.push_back(c);	
	}

	long long min = 0, mid = 0;

	while (min <= max) {
		long long cnt = 0;
		mid = (min + max) / 2;

		for (int i = 0; i < N; i++) {
			if (th[i] > mid)
				cnt += th[i] - mid;
		}

		if (cnt >= M) {
			ans = mid;
			min = mid + 1;
		}
		else
			max = mid - 1;
			
	}

	cout << ans;
}