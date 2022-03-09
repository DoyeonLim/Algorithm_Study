#include <iostream>
#include <vector>

using namespace std;

struct person {
	int height;
	int weight;
};

int main(void) {
	int n;

	cin >> n;

	vector<person> v(n);
	vector<int> rank(n, 1);

	for (int i = 0; i < n; i++)
		cin >> v[i].weight >> v[i].height;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (v[i].height < v[j].height && v[i].weight < v[j].weight)
				rank[i]++;

	for (auto i = rank.begin(); i != rank.end(); i++)
		cout << *i << " ";

	return 0;
}