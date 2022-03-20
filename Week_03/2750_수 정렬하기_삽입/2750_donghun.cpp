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

    for (i = 1; i < n; i++) {
        p = v.at(i);
        for (j = i - 1; j >= 0; j--) {
            if (p < v.at(j)) {
                v.at(j + 1) = v.at(j);
            }
            else {
                v.at(j + 1) = p;
                break;
            }
        }
        if (j < 0) {
            v.at(0) = p;
        }
    }

    for (auto i : v) cout << i << "\n";

    return 0;
}