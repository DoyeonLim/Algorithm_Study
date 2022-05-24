#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct customer {
	int id, time, number;
};

struct compare {
	bool operator()(customer &a, customer &b) {
		if (a.time == b.time)
			return a.number > b.number;
		return a.time > b.time;
	}
};

bool comparee(customer a, customer b) {
	if (a.time == b.time)
		return a.number > b.number;
	return a.time < b.time;
}

priority_queue<customer, vector<customer>, compare> pq;
vector<customer> q;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, a, b;
	long long result = 0, cnt = 1;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
	
		if (i <= k) pq.push({ a, b, i });
		else {
			customer out = pq.top();
			pq.pop();
			pq.push({a, b + out.time, out.number});
			q.push_back(out);
		}
	}

	while (!pq.empty()) {
		q.push_back(pq.top());
		pq.pop();
	}

	sort(q.begin(), q.end(), comparee);

	for (int i = 0; i < n; i++) {
		result += ((long long)i + 1) * q.at(i).id;
	}

	cout << result;

	return 0;
}