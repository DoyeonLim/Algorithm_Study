#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int n, m;
    int input;

    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    cin >> m;
    vector<int> find(m);

    for (int i = 0; i < m; i++)
        cin >> find[i];

    sort(v.begin(), v.end());

    for (auto i : find) {
        if (binary_search(v.begin(), v.end(), i))
            cout << 1 << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}


