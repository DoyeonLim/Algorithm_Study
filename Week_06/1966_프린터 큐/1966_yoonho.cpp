#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<pair<int, int>> v;

	int T = 0, N, M, c;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> c;
			v.push_back({j, c});			// 순서, 중요도
		}

		c = 1;
		while (!v.empty()) {
			pair<int, int> s = v[0];
			int pri = s.second;

			for (auto k : v) {
				if (pri < k.second) {
					v.push_back(s);
					v.erase(v.begin());
					pri = 0;
					break;
				}
			}
			
			if (pri) {
				if (s.first == M) {
					cout << c << '\n';
					break;
				}
				else {
					v.erase(v.begin());
					c++;
				}
			}

		}
		v.clear();
	}
	
	return 0;
}