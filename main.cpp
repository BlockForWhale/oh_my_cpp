#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;

bool judge(const string &code) {
    int len = code.length();
    if (len >= 8 && len <= 16) {
        int i;
        int safe = 0, x = 0, y = 0, m = 0, n = 0;
        for (i = 0; code[i] != '\0'; i++) {
            if (code[i] >= 65 && code[i] <= 90 && x == 0) {
                x++;
                safe++;
            } else if (code[i] >= 97 && code[i] <= 122 && y == 0) {
                y++;
                safe++;
            } else if (code[i] >= 48 && code[i] <= 57 && m == 0) {
                m++;
                safe++;
            } else if ((code[i] == 126 || code[i] == 33 || code[i] == 64 || code[i] == 35 || code[i] == 36 ||
                        code[i] == 37) && n == 0) {
                n++;
                safe++;
            }
        }
        return safe >= 3;
    } else {
        return false;
    }
}

int main() {
    string code;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> code;
        if (judge(code)) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}