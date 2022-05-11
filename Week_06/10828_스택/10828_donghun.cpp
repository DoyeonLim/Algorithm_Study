#include <iostream>
#include <string>

using namespace std;

class stack {
private:
	int array[10001];
	int point = 0;
public:
	void push(int n) {
		array[point++] = n;
	}
	int pop() {
		if (point == 0) 
			return -1;
		else
			return array[--point];
	}
	int size() {
		return point;
	}
	int empty() {
		return point == 0 ? 1 : 0;
	}
	int top() {
		if (point == 0)
			return -1;
		else
			return array[point - 1];
	}
};

int main() {
	int n;
	stack s;
	string input;
	int num;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "push") {
			cin >> num;
			s.push(num);
		}
		else if (input == "pop") {
			cout << s.pop() << "\n";
		}
		else if (input == "size") {
			cout << s.size() << "\n";
		}
		else if (input == "empty") {
			cout << s.empty() << "\n";
		}
		else if (input == "top") {
			cout << s.top() << "\n";
		}
	}

	return 0;
}