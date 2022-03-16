#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int k;
char arr[10];
bool ch[10] = { false, };
vector<string> ans;

bool check(string num) {
    for (int i = 0; i < k; i++) {
        if (arr[i] == '<') {
            if (num[i] > num[i + 1])
                return false;
        }
        else {
            if (num[i] < num[i + 1])
                return false;
        }
    }
    return true;
}

void cal(int idx, string num) {
    if (idx == k + 1) {
        if(check(num))
            ans.push_back(num);
        return;
    }
        
    for (int i = 0; i < 10; i++) {
        if (ch[i])
            continue;
        ch[i] = true;
        cal(idx + 1, num + to_string(i));
        ch[i] = false;
    }
}

int main() {
    
    cin >> k;
    for (int i = 0; i < k; i++) 
        cin >> arr[i];
  
    cal(0, "");
 
    cout << *max_element(ans.begin(), ans.end()) << "\n";
    cout << *min_element(ans.begin(), ans.end()) << "\n";

    return 0;
}

// 전체 경우(순열) 생성 -> 길이가 k+1이 되면 조건 만족 여부 확인 -> 저장된 vector 최대최소 출력