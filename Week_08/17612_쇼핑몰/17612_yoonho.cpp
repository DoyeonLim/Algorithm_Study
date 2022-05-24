// 예제 입출력 정상적 -> 왜 틀렸을까

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> enterPQ;
	// pair<pair<int, int>, int> - { {시간, 계산대 번호} , id }		시간 오름차순 -> 계산대 오름차순

	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> exitPQ;
	// pair<pair<int, int>, int> - { {시간, 계산대 번호} , id }		시간 오름차순 -> 계산대 내림차순
	
	int N, k, w, id;
	long long result = 0;
	pair<pair<int, int>, int> temp;

	cin >> N >> k;

	for (int i = 1; i <= N; i++) {
		cin >> id >> w;

		if (i <= k) {
			enterPQ.push({ { w,i }, id });
			continue;
		}
		
		temp = enterPQ.top();
		enterPQ.pop();
		exitPQ.push({ {temp.first.first, -temp.first.second} , temp.second });
		enterPQ.push({ {temp.first.first + w, temp.first.second}, id });	
	}

	while (!enterPQ.empty()) {
		exitPQ.push({ {enterPQ.top().first.first, -enterPQ.top().first.second} , enterPQ.top().second});
		enterPQ.pop();
	}

	for (int i = 1; i <= N; i++) {
		result += i * exitPQ.top().second;
		exitPQ.pop();
	}

	cout << result;

	return 0;
}