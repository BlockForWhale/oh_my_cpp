#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n, is = 0;
    while (cin >> n) {
        int p[n], cnt[n];
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            cnt[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (p[i] > p[i + 1] && i != n - 1 && cnt[i] <= cnt[i + 1])
                    cnt[i] = cnt[i + 1] + 1;
            } else if (i == n - 1) {
                if (p[i] > p[i - 1] && cnt[i] <= cnt[i - 1])
                    cnt[i] = cnt[i - 1] + 1;
                if (p[i - 1] > p[i] && cnt[i - 1] <= cnt[i])
                    cnt[i - 1] = cnt[i] + 1;
            } else {
                if (p[i] > p[i - 1] && cnt[i] <= cnt[i - 1])
                    cnt[i] = cnt[i - 1] + 1;
                if (p[i] > p[i + 1] && cnt[i] <= cnt[i + 1])
                    cnt[i] = cnt[i + 1] + 1;
                if (p[i - 1] > p[i] && cnt[i - 1] <= cnt[i])
                    cnt[i - 1] = cnt[i] + 1;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == 0) {
                if (p[i] > p[i + 1] && i != n - 1 && cnt[i] <= cnt[i + 1])
                    cnt[i] = cnt[i + 1] + 1;
            } else if (i == n - 1) {
                if (p[i] > p[i - 1] && cnt[i] <= cnt[i - 1])
                    cnt[i] = cnt[i - 1] + 1;
                if (p[i - 1] > p[i] && cnt[i - 1] <= cnt[i])
                    cnt[i - 1] = cnt[i] + 1;
            } else {
                if (p[i] > p[i - 1] && cnt[i] <= cnt[i - 1])
                    cnt[i] = cnt[i - 1] + 1;
                if (p[i] > p[i + 1] && cnt[i] <= cnt[i + 1])
                    cnt[i] = cnt[i + 1] + 1;
                if (p[i - 1] > p[i] && cnt[i - 1] <= cnt[i])
                    cnt[i - 1] = cnt[i] + 1;
            }
        }
        int total = 0;
        for (int i = 0; i < n; i++) total += cnt[i];
        cout << total << endl;
    }
    return 0;
}
