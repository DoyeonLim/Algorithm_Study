#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;
vector<bool> chk;

void func(int p, int n) {
	if (p == n - 1) {
		for (auto i : ans)
			cout << i << " ";
		cout << "\n";
		return ;
	}

	for (int i = 1; i <= n; i++) {
		if (chk.at(i)) continue;
		else {
			ans.push_back(i);
			chk.at(i) = true;
			func(p + 1, n);
			ans.pop_back();
			chk.at(i) = false;
		}
	}
}


int main(void) {
	int n, pnt, i;

	cin >> n;

	for (i = 1; i <= n; i++) {
		chk.assign(n + 1, false);
		ans.clear();
		ans.push_back(i);
		chk.at(i) = true;
		
		func(0, n);
	}

	return 0;
}