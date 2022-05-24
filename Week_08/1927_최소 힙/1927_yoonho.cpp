﻿#include<iostream>
#include<queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

    priority_queue <int> pq;
	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() * (-1) << '\n';
				pq.pop();
			}		
		}
		else {
			pq.push(x * (-1));
		}
	}

	return 0;
}