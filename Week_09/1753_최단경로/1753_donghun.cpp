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
	int v, e;
	int start;
	int a, b, c;

	cin >> v >> e;

	vector<vector<vertex>> list(v + 1, vector<vertex>());
	vector<int> visit(v + 1, INT_MAX);
	priority_queue<vertex> pq;

	cin >> start;
	visit[start] = 0;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		list[a].push_back({ b, c });
	}

	pq.push({ start, 0 });
	while (!pq.empty()) {
		vertex target = pq.top();
		pq.pop();
		for (auto i : list[target.e]) {
			if (visit[i.e] > i.v + target.v) {
				visit[i.e] = i.v + target.v;
				pq.push({i.e, visit[i.e]});
			}
		}
	}
 
	for (int i = 1; i <= v; i++) {
		if (visit[i] == INT_MAX)
			cout << "INF\n";
		else cout << visit[i] << "\n";
	}

	return 0;
}