#include<iostream>
#include<queue>

using namespace std;

int graph[1001][1001];
bool visited[1001];
int N, M;

void DFS(int v) {
	visited[v] = true;
	cout << v << " ";

	for (int i = 1; i <= N; i++) {
		if (graph[v][i] == 1 && !visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	cout << v << " ";

	while (!q.empty()) {
		v = q.front();
		q.pop();
		
		for (int i = 1; i <= N; i++) {
			if (graph[v][i] == 1 && !visited[i]) { //현재 정점과 연결되어있고 방문되지 않았으면
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}

int main() {
	
	int V, c1, c2;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> c1 >> c2;
		graph[c1][c2] = 1;
		graph[c2][c1] = 1;
	}

	DFS(V);
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	cout << '\n';
	BFS(V);

	return 0;
}