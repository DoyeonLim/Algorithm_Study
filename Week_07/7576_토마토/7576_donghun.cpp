#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

queue <pair<int, int> > q;

int t[1010][1010], cnt = -999, chk;

int main(void)
{
    int a, b, x, y, i, j;

    fill(&t[0][0], &t[1009][1009], -1);

    cin >> a >> b;

    for (i = 1; i <= b; i++) {
        for (j = 1; j <= a; j++) {
            cin >> t[i][j];
            if (t[i][j] == 1)
                q.push({i, j});

            if (t[i][j] == 0) chk++;
        }
    }

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second; 
        q.pop();
        if (t[x + 1][y] == 0) { 
            t[x + 1][y] = t[x][y] + 1; 
            q.push({ x + 1, y });
        }
        if (t[x - 1][y] == 0) { 
            t[x - 1][y] = t[x][y] + 1; 
            q.push({ x - 1, y }); 
        }
        if (t[x][y + 1] == 0) { 
            t[x][y + 1] = t[x][y] + 1; 
            q.push({ x, y + 1 }); 
        }
        if (t[x][y - 1] == 0) { 
            t[x][y - 1] = t[x][y] + 1; 
            q.push({ x, y - 1 });
        }
    }

    for (i = 1; i <= b; i++) {
        for (j = 1; j <= a; j++) {
            if (t[i][j] == 0) {
                cnt = -1;
                break;
            }
            cnt = max(cnt, t[i][j]);
        }
        if (cnt == -1) break;
    }

    if (cnt == -1) 
        cnt = 0; 

    cout << cnt - 1;

    return 0;
}
