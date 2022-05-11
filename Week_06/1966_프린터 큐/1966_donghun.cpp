#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class queue {
private:
	int arr[1001];
	int front = 0, back = 0;
public:
	void push(int n) {
		arr[back++] = n;
	}
	int pop() {
		if (empty())
			return -1;
		else {
			return arr[front++];
		}
	}
	int size() {
		return back - front;
	}
	int empty() {
		return front == back ? 1 : 0;
	}
	int qfront() {
		if (empty())
			return -1;
		else
			return arr[front];
	}
	int qback() {
		if (empty())
			return -1;
		else
			return arr[back-1];
	}
	void clear() {
		front = back = 0;
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	int n, m;
	queue q;
	int num;
	int cnt;
	vector<int> v;

	cin >> t;

	for (int i = 0; i < t; i++) {
		v.clear();
		q.clear();
		cin >> n >> m;
		cnt = 1;
		for (int j = 0; j < n; j++) {
			cin >> num;
			q.push(num);
			v.push_back(num);
		}
		sort(v.begin(), v.end());

		while (!q.empty()) {
			if (q.qfront() == v.back() && m == 0) {
				cout << cnt << "\n";
				break;
			}
			else if (q.qfront() == v.back()) {
				q.pop();
				v.pop_back();
				cnt++;
				m--;
			}
			else if (m == 0) {
				q.push(q.pop());
				m = q.size() - 1;
			}
			else {
				q.push(q.pop());
				m--;
			}
		}
	}

	return 0;
}