#include<iostream>
#include<string.h>

using namespace std;

int main() {

	int N = 0;
	cin >> N;
	int lpar = 0, rpar = 0;
	
	for (int i = 0; i < N; i++) {
		string str;
		lpar = 0;
		rpar = 0;
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			if (str.at(j) == '(') 
				lpar++;	
			else	
				rpar++;

			if (rpar > lpar)
				break;
		}

		if (rpar > lpar || rpar != lpar)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
	
	return 0;
}