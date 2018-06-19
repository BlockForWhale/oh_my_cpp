#include <bits/stdc++.h>

using namespace std;

bool judge(const string &s, const string &t) {
    int occur[s.length()];
    int curPos = 0;
    for (int i = 0; i < s.length(); i++) occur[i] = 0;
    for (int i = 0; i < s.length(); i++) {
        if (t.find(s[i], curPos) == -1) return false;
        else {
            curPos = t.find(s[i], curPos);
        }
    }
    return true;
}

int main() {
    string s, t;
    int len_s, len_t;
    while (cin >> s >> t) {
        if (judge(s, t)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}