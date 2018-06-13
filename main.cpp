#include <bits/stdc++.h>

using namespace std;

string padLeft(string src, int length, char padding = ' ') {
    if (length <= src.length()) return src;
    int len = length - src.length();
    src.insert(0, len, padding);
    return src;
}

string padRight(string src, int length, char padding = ' ') {
    if (length <= src.length()) return src;
    int len = length - src.length();
    src.insert(src.length(), len, padding);
    return src;
}

int main() {
    int num, length;
    char padding;
    string src, dest;

    while (cin >> num) {
        switch (num) {
            case 11:
                cin >> src >> length;
                cout << padLeft(src, length) << endl;
                break;
            case 12:
                cin >> src >> length >> padding;
                cout << padLeft(src, length, padding) << endl;
                break;
            case 21:
                cin >> src >> length;
                cout << padRight(src, length) << endl;
                break;
            case 22:
                cin >> src >> length >> padding;
                cout << padRight(src, length, padding) << endl;
                break;
        }
    }
    return 0;
}