#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void quick_sort(int left, int right) {
    if (left < right) {
        int p = left;
        int low, high, tmp;
        low = left + 1;
        high = right;

        while (low < high) {
            while (low <= right && v.at(low) <= v.at(p))
                low++;
            while (high >= left && v.at(high) > v.at(p))
                high--;
            if (low < high) {
                tmp = v.at(low);
                v.at(low) = v.at(high);
                v.at(high) = tmp;
            }
        }
        
        if (v.at(high) < v.at(left)) {
            tmp = v.at(high);
            v.at(high) = v.at(left);
            v.at(left) = tmp;
        }

        quick_sort(left, high - 1);
        quick_sort(high + 1, right);
    }
}

int main(void) {
    int n;
    int p;
    int i, j;
    
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> p;
        v.push_back(p);
    }

    quick_sort(0, n - 1);

    for (auto i : v) cout << i << "\n";

    return 0;
}