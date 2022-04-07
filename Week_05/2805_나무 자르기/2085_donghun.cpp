#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll calc_cnt(vector<int> v, ll len) {
    ll ret = 0;
    
    for (auto i : v)
        ret += (i - len) > 0 ? i - len : 0;

    return ret;
}

ll binary_search(vector<int> v, ll l, ll r, int cnt) {
    ll sum;
    ll mid;
    
    while (l + 1 < r)
    {
        mid = (l + r) / 2;

        sum = calc_cnt(v, mid);
        if (sum >= cnt) l = mid;
        else r = mid;
    }

    return l;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, max = -1e9;
    cin >> n >> m;

    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        max = max > v[i] ? max : v[i];
    }

    cout << binary_search(v, 0, max, m);

    return 0;
}
