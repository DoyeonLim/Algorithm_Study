#include<iostream>

using namespace std;
void dfs(int num, int cnt);

int N, M;
int arr[9];
bool visited[9] = { false, };

int main() {

    cin >> N >> M;

    dfs(1, 0);

	return 0;
}

void dfs(int num, int cnt) {        // DFS (±íÀÌ ¿ì¼± Å½»ö)

    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }

    for (int i = num; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = i;
            dfs(i, cnt + 1);
            visited[i] = false;
        }
    } 
}