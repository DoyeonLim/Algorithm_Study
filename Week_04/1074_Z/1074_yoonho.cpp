#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int r, c, o = 0;

void cal(int x, int y, int n, int size) {
	if (size == 1) {
		o += n;
		return;
	}

	o += size * size * n;

	size /= 2;
	int cnt = -1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cnt++;
			int cx = x + size * i;
			int cy = y + size * j;

			if (cx <= r && r < cx + size && cy <= c && c < cy + size) {
				cal(cx, cy, cnt, size);
				return;
			}				
		}
	}
}

int main() {
	int N;
	cin >> N >> r >> c;

	N = pow(2, N);

	cal(0, 0, 0, N);

	cout << o;
}