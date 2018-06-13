#include <bits/stdc++.h>

using namespace std;

int myatoi(char *string) {
    int num = 0;
    int s = '+';
    if (*string == '-') {
        s = '-';
        string++;
    }
    if (*string == '+') {
        s = '+';
        string++;
    }
    while (*string >= '0' && *string <= '9') {
        if (*string == 0) break;
        num = num * 10 + (*string - '0');
        string++;
    }
    int r = (s == '+' ? 1 : -1) * num;
    return r;
}

int main() {
    char str[100];
    while (cin >> str)
        cout << myatoi(str) << endl;
    return 0;
}