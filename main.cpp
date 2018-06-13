#include <bits/stdc++.h>

using namespace std;

void string_analysis(char *ptr, int &total, int &cap, int &sma, int &num, int &oth) {
    for (int i = 0; i < strlen(ptr); i++) {
        total++;
        if (ptr[i] >= 'A' && ptr[i] <= 'Z') cap++;
        else if (ptr[i] >= 'a' && ptr[i] <= 'z') sma++;
        else if (ptr[i] >= '0' && ptr[i] <= '9') num++;
        else oth++;
    }
}

int main() {
    char str[100];
    int total, cap, sma, num, oth;
    total = cap = sma = num = oth = 0;
    cin.get(str, 100);
    string_analysis(str, total, cap, sma, num, oth);
    cout << cap << endl;
    cout << sma << endl;
    cout << num << endl;
    cout << oth << endl;
    cout << total << endl;
    return 0;
}