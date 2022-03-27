#include<iostream>
#include<vector>

using namespace std;

vector < vector <bool> > s;

void cal(int x, int y, int size) {

	if (size == 1) {
		s[x][y] = 1;
		return;
	}

	size /= 3;
	int cnt = 0;
	for (int i = x; i < x + (3 * size); i += size) {
		for (int j = y; j < y + (3 * size); j += size) {
			cnt++;
			if (cnt % 9 == 5)
				continue;
			else
				cal(i, j, size);
		}
	}
}

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<bool> v;
		for (int j = 0; j < N; j++) {
			v.push_back(0);
		}
		s.push_back(v);
	}
	
	cal(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (s[i][j])
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
}