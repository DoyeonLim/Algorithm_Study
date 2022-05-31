#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct point {
	int x, y, v;

	bool operator<(const point v) const {
		if (this->v == v.v && this->x == v.x)
			return this->y > v.y;
		else if (this->v == v.v)
			return this->x > v.x;
		return this->v > v.v;
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> m >> n;

	vector<vector<int>> map(n + 2, vector<int>(m + 2, -1)), visit(n + 1, vector<int>(m + 1, INT_MAX));
	priority_queue<point> pq;
	int d[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	char input;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> input;
			map[i][j] = input - 48;
		}
	
	visit[1][1] = 0;

	pq.push({ 1, 1, 0 });
	while (!pq.empty()) {
		point target = pq.top();
		pq.pop();
		if (target.v > visit[target.x][target.y]) continue;
		for (int i = 0; i < 4; i++) {
			if (map[target.x + d[i][0]][target.y + d[i][1]] == 1) {
				if (visit[target.x + d[i][0]][target.y + d[i][1]] > visit[target.x][target.y] + 1) {
					visit[target.x + d[i][0]][target.y + d[i][1]] = visit[target.x][target.y] + 1;
					pq.push({ target.x + d[i][0], target.y + d[i][1], visit[target.x][target.y] + 1 });
				}
			}
			else if (map[target.x + d[i][0]][target.y + d[i][1]] == 0) {
				if (visit[target.x + d[i][0]][target.y + d[i][1]] > visit[target.x][target.y]) {
					visit[target.x + d[i][0]][target.y + d[i][1]] = visit[target.x][target.y];
					pq.push({ target.x + d[i][0], target.y + d[i][1], visit[target.x][target.y] });
				}
			}
		}
	}

	cout << visit[n][m] << "\n";
	
	return 0;
}