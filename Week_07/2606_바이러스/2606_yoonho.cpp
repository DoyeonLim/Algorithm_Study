#include<iostream>

using namespace std;

int cpu[101][101];
bool visited[101];
int N, cnt = -1;

void DFS(int v) {
	cnt++;
	visited[v] = true;

	for (int i = 2; i <= N; i++) {
		if (cpu[v][i] == 1 && !visited[i]) {
			DFS(i);
		}
	}
}

int main() {
	int M, c1, c2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> c1 >> c2;
		cpu[c1][c2] = 1;
		cpu[c2][c1] = 1;
	}
	
	visited[1] = true;
	DFS(1);

	cout << cnt;

	return 0;
}