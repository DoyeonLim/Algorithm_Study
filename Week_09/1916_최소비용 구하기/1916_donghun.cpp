#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct vertex {
	int e, v;

	bool operator<(const vertex v) const {
		if (this->v == v.v)
			return this->e > v.e;
		return this->v > v.v;
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	int start, end;
	int a, b, c;

	cin >> n >> m;

	vector<vector<vertex>> list(n + 1, vector<vertex>());
	vector<int> visit(n + 1, INT_MAX);
	priority_queue<vertex> pq;

	
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		list[a].push_back({ b, c });
	}

	cin >> start >> end;
	visit[start] = 0;

	pq.push({ start, 0 });
	while (!pq.empty()) {
		vertex target = pq.top();
		pq.pop();
		if (target.v > visit[target.e]) continue;
		for (auto i : list[target.e]) {
			if (visit[i.e] > i.v + target.v) {
				visit[i.e] = i.v + target.v;
				pq.push({ i.e, visit[i.e] });
			}
		}
	}

	cout << visit[end] << "\n";
	
	return 0;
}