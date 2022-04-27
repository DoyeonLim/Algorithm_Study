#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef vector < vector<int> > v2d;

vector <v2d> matrix;

v2d inner_product(v2d v1, v2d v2) {
    int size = v1.size();
    v2d ret(size, vector<int>(size, 0));


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                ret[i][j] += (v1[i][k] * v2[k][j]) % 1000;
            }
            ret[i][j] %= 1000;
        }
    }

    return ret;
}

void set(v2d v, long long b) {
    long long idx;

    for (idx = 1; idx <= log2(b); idx++) {
        matrix.push_back(inner_product(matrix[idx - 1], matrix[idx - 1]));
    }
}

v2d identity(int n) {
    v2d ret(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        ret[i][i] = 1;

    return ret;
}

v2d func(v2d v, long long b)
{
    v2d ret = identity(v.size());

    for (int i = log2(b); i >= 0; i--) {
        if (b < 0) break;
        else if (log2(b) >= i) {
            ret = inner_product(ret, matrix[i]);
            b -= pow(2, i);
        }
    }

    return ret;
}

int main() {
    int n;
    long long b;

    cin >> n >> b;

    v2d v(n, vector<int>(n)), ans(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    
    matrix.push_back(v);
    set(v, b);
    ans = func(v, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

    return 0;
}