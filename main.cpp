#include <bits/stdc++.h>

using namespace std;

void CalScore(string str[], int num) {
    for (int i = 0; i < num; i++) {
        int score = 0;
        int addPlus = 1;
        for (int j = 0; j < str[i].length(); j++) {
            if (str[i][j] == 'O') {
                score += addPlus++;
            } else {
                addPlus = 1;
            }
        }
        cout << score << endl;
    }
}

int main() {
    int i, num;
    cin >> num;
    string str[num];
    for (i = 0; i < num; i++)
        cin >> str[i];
    CalScore(str, num);  //要求自行设计
    return 0;
}