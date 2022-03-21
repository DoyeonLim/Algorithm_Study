#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
vector<string> word;

int comp(string a, string b) {
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}


int main() {
    
    string str;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        word.push_back(str);
    }
    
    sort(word.begin(), word.end(), comp);
    word.erase(unique(word.begin(), word.end()), word.end());

    for (auto i : word) {
        cout << i << '\n';
    }

    return 0;
}


/*
시간 초과 실패

void sort_w() {          // Bubble sort

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (comp(word[j], word[j + 1]) <= 0)
                swap(word[j], word[j + 1]);
        }
    }
    word.erase(unique(word.begin(), word.end()), word.end());       // 중복 제거
}
*/