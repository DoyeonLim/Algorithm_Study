#include <iostream>
#include <string>
#include <map>

using namespace std;

enum comm {
	PUSH, POP, SIZE, EMPTY, FRONT, BACK
};

static map<string, int> m;
void map_init() {
	m["push"] = PUSH;
	m["pop"] = POP;
	m["size"] = SIZE;
	m["empty"] = EMPTY;
	m["front"] = FRONT;
	m["back"] = BACK;
}

class queue {
private:
	int arr[2000001];
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
};
queue q;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string input;
	int num;

	map_init();

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;

		switch (m[input]) {
		case PUSH: 
			cin >> num;
			q.push(num);
			break;
		case POP:
			cout << q.pop() << "\n";
			break;
		case SIZE:
			cout << q.size() << "\n";
			break;
		case EMPTY:
			cout << q.empty() << "\n";
			break;
		case FRONT:
			cout << q.qfront() << "\n";
			break;
		case BACK:
			cout << q.qback() << "\n";
			break;
		}
	}

	return 0;
}