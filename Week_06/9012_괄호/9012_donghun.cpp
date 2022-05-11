#include <iostream>
#include <string>

using namespace std;

class stack {
private:
	char array[60];
	int point = 0;
public:
	void push(char c) {
		array[point++] = c;
	}
	int pop() {
		if (point == 0) 
			return 0;
		else {
			point--;
			return 1;
		}
	}
	int size() {
		return point;
	}
	int empty() {
		return point == 0 ? 1 : 0;
	}
	char top() {
		if (point == 0)
			return ' ';
		else
			return array[point - 1];
	}
	void clear() {
		point = 0;
	}
};

int main() {
	int n;
	stack s;
	string input;
	int flag;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		flag = 1;
		s.clear();
		for (auto j : input) {
			if (j == '(')
				s.push(j);
			else {
				if (s.top() == '(')
					s.pop();
				else {
					cout << "NO\n";
					flag = 0;
					break;
				}
			}
		}
		if (flag && s.size() != 0)
			cout << "NO\n";
		else if (flag)
			cout << "YES\n";
		
	}

	return 0;
}