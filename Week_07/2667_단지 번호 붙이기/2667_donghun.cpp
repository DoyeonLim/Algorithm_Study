#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int map[28][28], chk[28][28];

int main(void) {
	fill(&map[0][0], &map[28][28], -1);

	queue< pair<int, int> > q;
	int n, cnt = 0;
	int ans[400];

	memset(ans, 0, sizeof(ans));

	int i, j;
	pair<int, int> p;

	cin >> n;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			scanf("%1d", &map[i][j]);
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (map[i][j] == 1 && chk[i][j] == 0) {
				q.push(make_pair(i, j));
				chk[i][j] = 1;
				cnt++;
				p = make_pair(i, j);
				while (!q.empty()) {
					p = make_pair(q.front().first, q.front().second);
					q.pop();
					ans[cnt]++;
					if (map[p.first - 1][p.second] == 1 && chk[p.first - 1][p.second] == 0) {
						q.push(make_pair(p.first - 1, p.second));
						chk[p.first - 1][p.second] = 1;
					}
					if (map[p.first + 1][p.second] == 1 && chk[p.first + 1][p.second] == 0) {
						q.push(make_pair(p.first + 1, p.second));
						chk[p.first + 1][p.second] = 1;
					}
					if (map[p.first][p.second - 1] == 1 && chk[p.first][p.second - 1] == 0) {
						q.push(make_pair(p.first, p.second - 1));
						chk[p.first][p.second - 1] = 1;
					}
					if (map[p.first][p.second + 1] == 1 && chk[p.first][p.second + 1] == 0) {
						q.push(make_pair(p.first, p.second + 1));
						chk[p.first][p.second + 1] = 1;
					}
				}
			}
		}
	}

	cout << cnt << "\n";
	sort(ans + 1, ans + cnt + 1);
	for (i = 1; i <= cnt; i++)
		cout << ans[i] << "\n";

	return 0;
}