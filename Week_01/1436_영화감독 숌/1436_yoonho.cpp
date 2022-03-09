#include<iostream>
#include <string>
using namespace std;

int main() {

	int n, cal = 1, i = 666;
	cin >> n;

	while (cal < n) {
		i++;
		string a = to_string(i);
		if (a.find("666") != string::npos)
			cal++;	
	}
	cout << i;

	return 0;
}