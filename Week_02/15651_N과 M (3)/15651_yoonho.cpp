#include<iostream>

using namespace std;
void dfs(int cnt);

int N, M;
int arr[9];

int main() {

    cin >> N >> M;
    dfs(0);

    return 0;
}

void dfs(int cnt) {

    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';                   // endl은 출력버퍼를 비워서 느림 -> 시간 초과 유발
        return;
    }

    for (int i = 1; i <= N; i++) {
        arr[cnt] = i;
        dfs(cnt + 1);
    }
}