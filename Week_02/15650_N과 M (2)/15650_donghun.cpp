#include <iostream>
#include <vector>

using namespace std;

void func(int m, int dep, vector<int> v)
{
	if (dep == 0) {
		for (auto i = v.begin() + 1; i != v.end(); i++)
			cout << *i << " ";
		cout << "\n";
	}
	else {
		for (int i = 1; i <= m; i++) {
			if (v.back() < i) {
				v.push_back(i);
				func(m, dep - 1, v);
				v.pop_back();
			}
		}
	}
}

int main(void) {
	int n, m;

	cin >> n >> m;

	vector<int> v;

	v.push_back(0);
	func(n, m, v);

	return 0;
}