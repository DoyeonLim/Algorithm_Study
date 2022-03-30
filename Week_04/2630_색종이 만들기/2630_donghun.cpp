#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
int white, blue;

void cut(int n, int x, int y) {
	int chk = v[x][y];

	for (int i = x; i < x + n && chk != -1; i++) {
		for (int j = y; j < y + n && chk != -1; j++) {
			if (v[i][j] != chk) chk = -1;
		}
	}

	switch (chk) {
	case -1:
		cut(n / 2, x, y);
		cut(n / 2, x + n / 2, y);
		cut(n / 2, x, y + n / 2);
		cut(n / 2, x + n / 2, y + n / 2);
		break;
	case 0:
		white++;
		break;
	case 1:
		blue++;
		break;
	}
}

int main() {
	
	int n;

	cin >> n;

	v.resize(n, vector<int>(n));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];

	cut(n, 0, 0);

	cout << white << "\n" << blue;

	return 0;
}