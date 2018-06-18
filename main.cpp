#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

char week_name[8][10] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int getDaysOfYear(int y) {
    return y % 4 != 0 ? 365 : (y % 100 != 0 ? 366 : (y % 400 != 0 ? 365 : 366));
}

int getDaysOfMonth(int y, int m) {
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
        default:
            return (y % 4 != 0 ? 28 : (y % 100 != 0 ? 29 : (y % 400 != 0 ? 28 : 29)));
    }
}

int getDaysFrom(int y, int m, int d) {
    int days = 0;
    for (int i = 1753; i < y; i++) {
        days += getDaysOfYear(i);
    }
    for (int i = 1; i < m; i++) {
        days += getDaysOfMonth(y, i);
    }
    days += (d - 1);
    return days;
}

int main() {
    int y, m, d;
    while (cin >> y >> m >> d) {
        int days = getDaysFrom(y, m, d);
        int week = days % 7 + 1;
        cout << week_name[week] << endl;
    }
    return 0;
}