#include <bits/stdc++.h>

using namespace std;

class Date {
    int year;
    int month;
    int day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {};

    int getYear() const { return year; }

    int getMonth() const { return month; }

    int getDay() const { return day; }
};

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
            return y % 4 != 0 ? 28 : (y % 100 != 0 ? 29 : (y % 400 != 0 ? 28 : 29));
    }
}

int calDay(const Date &d1, const Date &d2) {
    if (d1.getYear() < d2.getYear())
        return calDay(d2, d1);
    if (d1.getYear() == d2.getYear() && d1.getMonth() < d2.getMonth())
        return calDay(d2, d1);
    if (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() < d2.getDay())
        return calDay(d2, d1);
    int sum = 0, y = d2.getYear(), m = d2.getMonth(), d = d2.getDay();
    while (d1.getYear() != y || d1.getMonth() != m || d1.getDay() != d) {
        d++;
        if (d > getDaysOfMonth(y, m)) {
            m++;
            d = 1;
        }
        if (m > 12) {
            y++;
            m = 1;
        }
        ++sum;
    }
    return sum;
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;
    Date date1(y1, m1, d1);
    Date date2(y2, m2, d2);
    cout << calDay(date1, date2);

    return 0;

}