#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> A;
vector<int> r;

int cal(int key) {

	int left = 0;
	int right = A.size() - 1;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		if (A[mid] == key)
			return 1;
		else if (A[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return 0;
}

int main() {
	int N, M, c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c;
		A.push_back(c);
	}
	sort(A.begin(), A.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> c;
		r.push_back(cal(c));
	}

	for (int i = 0; i < M; i++) {
		cout << r[i] << '\n';
	}
}