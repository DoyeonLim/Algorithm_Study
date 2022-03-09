#include <iostream>

using namespace std;

int main(void)
{
	int n, i, chk;
	int cnt = 0;

	cin >> n;

	for (i = 666;; i++)
	{
		chk = i;
		while (chk >= 666)
		{
			if (chk % 1000 == 666) {
				cnt++; break;
			}
			else chk /= 10;
		}
		if (cnt == n) {
			cout << i; break;
		}
	}
	return 0;
}