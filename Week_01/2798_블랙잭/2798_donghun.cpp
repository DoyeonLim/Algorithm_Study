#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m;
	int cnt, sum, ans;

	cin >> n >> m;

	vector<int> v(n), num(n);
	for (int i = 0; i < 3; i++) v[i] = 1;
	for (int i = 0; i < n; i++) cin >> num[i];

	sort(num.begin(), num.end());

	ans = 0;
	do {
		cnt = sum = 0;
		for (int i = 0; i < n || cnt < 3; i++) {
			if (v[i] == 1) {
				cnt++; sum += num[i];
			}
		}
		if (sum <= m && ans < sum) ans = sum;
	} while (prev_permutation(v.begin(), v.end()));

	cout << ans;

	return 0;
}