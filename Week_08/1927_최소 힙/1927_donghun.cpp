#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<int>> pq;
	int n, a;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else cout << "0\n";
		}
		else pq.push(a);
	}

	return 0;
}