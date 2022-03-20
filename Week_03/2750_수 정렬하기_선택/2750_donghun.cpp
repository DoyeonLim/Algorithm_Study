#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    int p, tmp;
    
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        cin >> p;
        v.push_back(p);
    }

    for (int i = 0; i < n - 1; i++) {
        p = i;
        for (int j = i; j < n; j++) {
            if (v.at(p) > v.at(j)) {
                p = j;
            }
        }
        tmp = v.at(i);
        v.at(i) = v.at(p);
        v.at(p) = tmp;
    }

    for (auto i : v) cout << i << "\n";

    return 0;
}