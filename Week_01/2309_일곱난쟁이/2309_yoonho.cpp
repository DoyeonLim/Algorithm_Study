#include<iostream>
#include <algorithm>
using namespace std;
int const num = 9;

int main() {
	int dw[num];
	int sum = 0, flag = 0;
	for (int i = 0; i < num; i++) {
		cin >> dw[i];
		sum += dw[i];
	}

	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			int cal = sum - dw[i] - dw[j];
			if (cal == 100) {
				dw[i] = dw[j] = -1;
				sort(dw, dw + num);
				for (int i = 2; i < num; i++)
					cout << dw[i] << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	return 0;
}