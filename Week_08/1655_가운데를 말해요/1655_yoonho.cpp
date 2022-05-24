// 반을 나눠 작은 것들의 최댓값 -> 중간값

#include<iostream>
#include<queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	priority_queue<int> maxH, minH;
	vector<int> v;

	int N, x, temp1, temp2;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (maxH.size() > minH.size())
			minH.push(-x);
		else
			maxH.push(x);

		if (!minH.empty() && maxH.top() > -minH.top()) {
			temp1 = maxH.top();
			temp2 = -minH.top();
			maxH.pop();
			minH.pop();

			maxH.push(temp2);
			minH.push(-temp1);
		}

		cout << maxH.top() << '\n';
	}

	return 0;
}