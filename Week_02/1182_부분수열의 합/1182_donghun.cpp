#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, s, pnt;
	int sum, ans = 0;

	cin >> n >> s;

	vector<int> v(n), visit(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	for (int i = 0; i < n; i++) {
		visit.assign(n, 0);
		for (int j = 0; j <= i; j++)
			visit[j] = 1;
		do {
			sum = 0;
			for (int j = 0; j < n; j++) {
				sum += v[j] * visit[j];
			}
			if (sum == s) ans++;

		} while (prev_permutation(visit.begin(), visit.end()));
	}

	cout << ans;

	return 0;
}