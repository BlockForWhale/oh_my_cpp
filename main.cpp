#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

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

string cpy(string src, int startIndex = 0, int endIndex = 999) {
    if (endIndex == 999) endIndex = src.length() - 1;
    if (startIndex >= src.length() || startIndex < 0) return "";
    if (endIndex >= src.length() || endIndex < startIndex) return "";
    int j = 0;
    //for(int i = startIndex; i <= endIndex; i++,j++){
    //    cout<<src[i];
    //    src[j] = src[i];
    //}
    src = src.substr(startIndex, endIndex - startIndex + 1);
    //cout<<"done:"<<j<<endl;
    //src[j] = '\0';
    //cout<<src<<endl;
    return src;
}

string remove(string src, char delChar) {
    for (int i = 0; i < src.length(); i++) {
        if (src[i] == delChar) {
            src = src.erase(i, 1);
            i--;
        }
    }
    return src;
}

string remove(string src, int index) {
    if (index >= src.length() || index < 0) return src;
    src = src.erase(index, 1);
    return src;
}

string remove(string src, int startIndex, int endIndex) {
    if (startIndex > src.length() || startIndex < 0) return src;
    if (endIndex > src.length() || endIndex < startIndex) return src;
    int len = endIndex - startIndex + 1;
    return src.erase(startIndex, len);
}

int main() {
    int num, length, index, startIndex, endIndex;
    char padding, delChar;
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
            case 31:
                cin >> src;
                cout << cpy(src) << endl;
                break;
            case 32:
                cin >> src >> startIndex;
                cout << cpy(src, startIndex) << endl;
                break;
            case 33:
                cin >> src >> startIndex >> endIndex;
                cout << cpy(src, startIndex, endIndex) << endl;
                break;
            case 41:
                cin >> src >> delChar;
                cout << remove(src, delChar) << endl;
                break;
            case 42:
                cin >> src >> index;
                cout << remove(src, index) << endl;
                break;
            case 43:
                cin >> src >> startIndex >> endIndex;
                cout << remove(src, startIndex, endIndex) << endl;
                break;
        }
    }
    return 0;
}