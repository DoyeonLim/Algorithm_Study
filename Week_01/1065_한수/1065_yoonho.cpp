#include<iostream>
using namespace std;

int main() {

	int n, cal = 0, result = 99;
	cin >> n;
	
	if (n < 100)
		result = n;
	else {
		for (int i = 100; i <= n; i++) {
			int n1 = i / 100;
			int n2 = i / 10 - n1 * 10;
			int n3 = i % 10;
			if (n1 - n2 == n2 - n3)
				result++;
		}
	}
	cout << result;

	return 0;
}