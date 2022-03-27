#include<iostream>

using namespace std;

int m[5][5];
int c[5][5];
int r[5][5];

int N;
long long int B;

void mul(int m1[5][5], int m2[5][5]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = 0;
			for (int k = 0; k < N; k++)
				c[i][j] += (m1[i][k] * m2[k][j]);
			c[i][j] %= 1000;
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			m1[i][j] = c[i][j];

}

int main() {
	
	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
		}
		r[i][i] = 1;						// I !!!!!!
	}

	while (B) {
		if (B % 2) {
			mul(r, m);
		}
		mul(m, m);
		B /= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << r[i][j] << ' ';
		}
		cout << '\n';
	}
}