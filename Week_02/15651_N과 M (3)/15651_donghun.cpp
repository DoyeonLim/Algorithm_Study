#include <iostream>
#include <vector>

using namespace std;

void func(int m, int dep, vector<int> v)
{
	if (dep == 0) {
		for (auto i : v)
			cout << i << " ";
		cout << "\n";
	}
	else {
		for (int i = 1; i <= m; i++) {
			v.push_back(i);
			func(m, dep - 1, v);
			v.pop_back();
		}
	}
}

int main(void) {
	int n, m;

	cin >> n >> m;

	vector<int> v;

	func(n, m, v);

	return 0;
}