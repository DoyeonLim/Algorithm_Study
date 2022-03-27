#include<iostream>
#include<vector>

using namespace std;

pair<int, int> color = { 0,0 };				// white, blue
vector < vector <int> > paper;

bool check(int row, int col, int n) {		// 0 - X  1 - O
	if (n == 1)
		return true;

	int wb = paper[row][col];
	for (int i = row; i < row + n; i++) {
		for (int j = col; j < col + n; j++) {
			if (paper[i][j] != wb)
				return false;
		}
	}

	return true;
}

void cal(int row, int col, int n) {
	if (check(row, col, n)) {
		if (paper[row][col])		// 1
			color.second++;
		else
			color.first++;
		return;
	}

	n /= 2;
	cal(row, col, n);
	cal(row + n, col, n);
	cal(row, col + n, n);
	cal(row + n, col + n, n);
}

int main() {
	int N, c;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < N; j++) {
			cin >> c;
			v.push_back(c);
		}
		paper.push_back(v);
	}

	cal(0, 0, N);

	cout << color.first << '\n' << color.second;
}