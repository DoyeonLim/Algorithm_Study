#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> A;
vector<int> r;

int upper(int key) {
	int left = 0, right = A.size() - 1, mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (A[mid] <= key)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return right;
}

int lower(int key) {
	int left = 0, right = A.size() - 1, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (A[mid] < key)
			left = mid + 1;
		else {
			right = mid - 1;
		}
	}
	return left;
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
		r.push_back(upper(c)- lower(c) + 1);
	}

	for (int i = 0; i < M; i++) {
		cout << r[i] << ' ';
	}
}

/*
auto upper = upper_bound(v.begin(), v.end(), K);
auto lower = lower_bound(v.begin(), v.end(), K);

answer = upper - lower;
*/