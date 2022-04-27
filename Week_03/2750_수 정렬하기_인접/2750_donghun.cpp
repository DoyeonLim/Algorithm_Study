#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    int p, tmp;
    int i, j;
    
    cin >> n;

    vector<int> v;

    for (i = 0; i < n; i++) {
        cin >> p;
        v.push_back(p);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v.at(j) > v.at(j + 1)) {
                p = v.at(j + 1);
                v.at(j + 1) = v.at(j);
                v.at(j) = p;
            }
        }
    }

    for (auto i : v) cout << i << "\n";

    return 0;
}