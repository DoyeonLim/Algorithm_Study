#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool mycmp(string a, string b) {
    if (a.size() == b.size())
        return (a < b);
    return a.size() < b.size();
}

int main(void) {
    int n;
    string input;
    vector<string> a;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        a.push_back(input);
    }

    sort(a.begin(), a.end(), mycmp);
    a.erase(unique(a.begin(), a.end()), a.end());

    for (auto i : a)
        cout << i << "\n";
    return 0;
}