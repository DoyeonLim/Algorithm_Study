#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<bool> chk;

void dfs(stack<int> s) {
	int top = s.top();

	for (auto j : v[top]) {
		if (!chk[j]) {
			s.push(j);
			chk[j] = true;
			cout << j << " ";
			dfs(s);
			s.pop();
		}
	}
}

int main() {
	int n, m, start;
	int a, b;

	cin >> n >> m >> start;
	
	v.assign(n + 1, vector<int>());
	chk.assign(n + 1, false);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	stack<int> s;
	s.push(start);

	chk[start] = true;
	cout << start << " ";
	dfs(s);

	cout << "\n";

	chk.assign(n + 1, false);
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int top = q.front();
		if (chk[top] == false) {
			cout << top << " ";
			chk[top] = true;
		}
		for (auto j : v[top]) {
			if (!chk[j]) {
				q.push(j);
			}
		}
		q.pop();
	}

	return 0;
}
