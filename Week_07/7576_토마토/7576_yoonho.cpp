#include<iostream>
#include<queue>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int tomato[1000][1000];
int N, M;
queue<pair<int, int>> q;

void BFS() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && 0 <= ny && nx < N && ny < M) {
				if (tomato[nx][ny] == 0) {
					tomato[nx][ny] = tomato[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
}

int main() {
	
	int t, day = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> t;
			tomato[i][j] = t;
			if (tomato[i][j] == 1)
				q.push({ i,j });
		}
	}

	BFS();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] > day)
				day = tomato[i][j];
			if (tomato[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << day - 1;

	return 0;
}