#include<iostream>
using namespace std;

int main() {

	int n, m, sum = 0;
	int card[100];
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int cal = card[i] + card[j] + card[k];
				if (cal <= m && sum < cal)
					sum = cal;
			}
		}
	}

	cout << sum;

	return 0;
}