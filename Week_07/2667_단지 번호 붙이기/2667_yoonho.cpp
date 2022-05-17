#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int graph[25][25];
int cnt[25*25];
bool visited[25][25];
int N, num = 0;

void DFS(int x, int y) {
	cnt[num]++;
	visited[x][y] = true;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (graph[nx][ny] && !visited[nx][ny]) {
				DFS(nx, ny);
			}
		}
	}
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			if (str.at(j) == '1')
				graph[i][j] = 1;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] && !visited[i][j]) {
				DFS(i, j);
				num++;
			}
		}
	}

	sort(cnt, cnt+num);
	cout << num << '\n';
	for (int i = 0; i < num; i++)
		cout << cnt[i] << '\n';

	return 0;
}