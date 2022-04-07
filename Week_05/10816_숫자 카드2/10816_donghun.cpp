#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    int input;

    cin >> n;
    vector<int> v(n);
    map<int, int> cnt;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    
    for (int i = 0; i < n; i++) {
        if (binary_search(v.begin(), v.end(), v[i]))
            cnt[v[i]]++;
        else
            cnt.insert(pair<int, int>(v[i], 1));
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> input;
        if (binary_search(v.begin(), v.end(), input))
            cout << cnt[input] << " ";
        else cout << "0 ";
    }

    return 0;
}


