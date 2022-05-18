#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<bool> chk;
stack<int> s;

void dfs() {
    int top = s.top();
    for (auto j : map[top]) {
        if (!chk[j]) {
            chk[j] = true;
            s.push(j);
            dfs();
            s.pop();
        }
    }
}

int main()
{
    int top = 0, n, e, i, j, a, b, c, cnt = 2;

    cin >> n >> e;

    map.assign(101, vector<int>());
    chk.assign(101, false);

    for (int i = 1; i <= e; i++) {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    top = 1;
    s.push(top);
    chk[top] = 1;
    dfs();

    cnt = 0;
    for (i = 2; i <= 100; i++) {
        if (chk[i]) cnt++;
    }

    cout << cnt;

    return 0;
}
