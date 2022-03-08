#include<iostream>
using namespace std;

int main() {

	int n;
	int w[50], h[50], cnt[50];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> h[i];
		cnt[i] = 1;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (w[i] < w[j] && h[i] < h[j])		// i의 덩치가 작은 경우
				cnt[i]++;
			else if (w[i] > w[j] && h[i] > h[j])		// j의 덩치가 작은 경우
				cnt[j]++;
			else
				continue;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << cnt[i] << ' ';
	}

	return 0;
}