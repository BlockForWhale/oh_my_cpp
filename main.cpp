#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, min;
    int maxN = 2147483647;
    cin >> n >> m;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i == j) e[i][j] = 0;
            else e[i][j] = maxN;
    for (i = 1; i <= m; i++) {
        scanf("%d %d %d", &t1, &t2, &t3);
        e[t1][t2] = t3;
    }
    int start, end;
    cout << "start:";
    cin >> start;
    cout << "end:";
    cin >> end;
    for (i = 0; i < n; i++) dis[i + 1] = e[start][i + 1];
    for (i = 0; i < n; i++) book[i + 1] = 0;
    book[1] = 1;
    for (i = 0; i < n - 1; i++) {
        min = maxN;
        for (j = 1; j <= n; j++) {
            if (book[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;
        for (v = 1; v <= n; v++) {
            if (e[u][v] < maxN) {
                if (dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
    }
    cout << dis[end] << endl;
    return 0;
}