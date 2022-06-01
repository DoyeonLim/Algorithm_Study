#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	int cnt = 0;

	while (1) {
		cnt++;

		vector<vector<int>> v;
		vector<vector<int>> visit;
		
		int N, c;
		cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; i++) {
			vector<int> p, p1;
			for (int j = 0; j < N; j++) {
				cin >> c;
				p.push_back(c);
				p1.push_back(INT_MAX);
			}
			v.push_back(p);
			visit.push_back(p1);
		}

		queue<pair<int, int>> q;
		q.push({ 0,0 });
		visit[0][0] = v[0][0];

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

				if (visit[nx][ny] > visit[x][y] + v[nx][ny]) {
					visit[nx][ny] = visit[x][y] + v[nx][ny];
					q.push({ nx, ny });
				}
			}
		}
		cout << "Problem " << cnt << ": " << visit[N - 1][N - 1] << '\n';

	}
}