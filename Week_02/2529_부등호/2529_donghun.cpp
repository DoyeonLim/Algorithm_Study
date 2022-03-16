#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;
vector<bool> chk;
vector<char> input;

int find_max(int dep) {
	if (dep == 1) {
		for (auto i : ans)
			cout << i;
		cout << "\n";
		return 1;
	}

	for (int j = 9; j >= 0; j--) {
		if (chk.at(j)) continue;
		if (input.at(ans.size() - 1) == '<' && ans.back() < j) {
			ans.push_back(j);
			chk.at(j) = true;
			if (find_max(dep - 1) == 1) return 1;
			ans.pop_back();
			chk.at(j) = false;
		}
		if (input.at(ans.size() - 1) == '>' && ans.back() > j) {
			ans.push_back(j);
			chk.at(j) = true;
			if (find_max(dep - 1) == 1) return 1;
			ans.pop_back();
			chk.at(j) = false;
		}
	}
	return 0;
}

int find_min(int dep) {
	if (dep == 1) {
		for (auto i : ans)
			cout << i;
		cout << "\n";
		return 1;
	}

	for (int j = 0; j <= 9; j++) {
		if (chk.at(j)) continue;
		if (input.at(ans.size() - 1) == '<' && ans.back() < j) {
			ans.push_back(j);
			chk.at(j) = true;
			if (find_min(dep - 1) == 1) return 1;
			ans.pop_back();
			chk.at(j) = false;
		}
		if (input.at(ans.size() - 1) == '>' && ans.back() > j) {
			ans.push_back(j);
			chk.at(j) = true;
			if (find_min(dep - 1) == 1) return 1;
			ans.pop_back();
			chk.at(j) = false;
		}
	}

	return 0;
}

int main(void) {
	int n, pnt, i, j = 0;
	char a;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		input.push_back(a);
	}

	for (i = 9; i >= 0; i--) {
		chk.assign(10, false);
		ans.clear();
		ans.push_back(i);
		chk.at(i) = true;

		if (find_max(n + 1) == 1) break;
	}

	for (i = 0; i <= 9; i++) {
		chk.assign(10, false);
		ans.clear();
		ans.push_back(i);
		chk.at(i) = true;
		
		if (find_min(n + 1) == 1) break;
	}

	return 0;
}