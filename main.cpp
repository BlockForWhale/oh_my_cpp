#include <bits/stdc++.h>

using namespace std;

string cpy(string src, int startIndex = 0, int endIndex = 999) {
    if (endIndex == 999) endIndex = src.length() - 1;
    if (startIndex >= src.length() || startIndex < 0) return "";
    if (endIndex >= src.length() || endIndex < startIndex) return "";
    src = src.substr(startIndex, endIndex - startIndex + 1);
    return src;
}

int main() {
    int num, length, index, startIndex, endIndex;
    string src, dest;

    while (cin >> num) {
        switch (num) {
            case 1:
                cin >> src;
                cout << cpy(src) << endl;
                break;
            case 2:
                cin >> src >> startIndex;
                cout << cpy(src, startIndex) << endl;
                break;
            case 3:
                cin >> src >> startIndex >> endIndex;
                cout << cpy(src, startIndex, endIndex) << endl;
                break;
        }
    }
    return 0;
}