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

	int n;

	for (int tc = 1;;tc++) {
		cin >> n;
		if (n == 0) break;

		vector<vector<int>> map(n + 2, vector<int>(n + 2, -1)), visit(n + 1, vector<int>(n + 1, INT_MAX));
		priority_queue<point> pq;
		int d[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];

		visit[1][1] = map[1][1];

		pq.push({ 1, 1, 0 });
		while (!pq.empty()) {
			point target = pq.top();
			pq.pop();
			if (target.v > visit[target.x][target.y]) continue;
			for (int i = 0; i < 4; i++) {
				if (map[target.x + d[i][0]][target.y + d[i][1]] != -1) {
					if (visit[target.x + d[i][0]][target.y + d[i][1]] > visit[target.x][target.y] + map[target.x + d[i][0]][target.y + d[i][1]]) {
						visit[target.x + d[i][0]][target.y + d[i][1]] = visit[target.x][target.y] + map[target.x + d[i][0]][target.y + d[i][1]];
						pq.push({ target.x + d[i][0], target.y + d[i][1], visit[target.x][target.y] + map[target.x + d[i][0]][target.y + d[i][1]] });
					}
				}
			}
		}

		cout << "Problem " << tc << ": " << visit[n][n] << "\n";
	}

	return 0;
}