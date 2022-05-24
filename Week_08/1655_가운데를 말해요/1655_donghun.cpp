#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	priority_queue<int> maxH;
	priority_queue<int, vector<int>, greater<int>> minH;
	int n, a, tmp;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a;

		if (i % 2) maxH.push(a);
		else minH.push(a);

		if (!minH.empty() && maxH.top() > minH.top()) {
			tmp = maxH.top();
			maxH.pop();
			maxH.push(minH.top());
			minH.pop();
			minH.push(tmp);
		}
		cout << maxH.top() << "\n";
	}

	return 0;
}