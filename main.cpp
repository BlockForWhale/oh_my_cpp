#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int iMap[100][100];
int d[100] = {0};

void gen(int n) {
    srand((unsigned) time(nullptr));
    cout << "矩阵：" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            iMap[i][j] = rand() % 2;
            cout << iMap[i][j] << (j == n - 1 ? "\n" : " ");
        }
    }
}

void getDegrees(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (iMap[i][j] == 1) {
                d[i]++;
                d[j]++;
            }
    for (int i = 0; i < n; i++) cout << i << "'s:  " << d[i] << endl;
}

int main() {
    int n;
    cin >> n;
    gen(n);
    getDegrees(n);
    return 0;
}