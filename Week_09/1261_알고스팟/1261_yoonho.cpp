#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int map[100][100];
int dist[100][100];
int M, N;

void BFS() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dist[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

			if (map[nx][ny] == 1) {
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny });
				}
			}
			else if (map[nx][ny] == 0) {
				if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					q.push({ nx, ny });
				}
			}
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str.at(j) - '0';
			dist[i][j] = INT_MAX;
		}
	}

	BFS();
	cout << dist[M - 1][N - 1] << '\n';
}