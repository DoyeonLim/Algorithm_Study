#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int height[9], sum;
	vector<int> chk{0,0,1,1,1,1,1,1,1};

	for (int i = 0; i < 9; i++)
		cin >> height[i];
	sort(height, height + 9);

	do {
		sum = 0;
		for (int i = 0; i < 9; i++)
			sum += height[i] * chk[i];
		if (sum == 100)
		{
			for (int i = 0; i < 9; i++)
				if (chk[i] == 1) cout << height[i] << "\n";
			break;
		}
	} while (next_permutation(chk.begin(), chk.end()));

	return 0;
}