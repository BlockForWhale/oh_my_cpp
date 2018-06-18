#include <bits/stdc++.h>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    int getYear() { return year; }

    int getMonth() { return month; }

    int getDay() { return day; }

    static int getDaysOfMonth(int y, int m) {
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

    static int getDaysOfYear(int y) { return y % 4 != 0 ? 365 : (y % 100 != 0 ? 366 : (y % 400 != 0 ? 365 : 366)); }

    void addDay(int days) {
        for (int i = 1; i <= days; i++) {
            day++;
            if (day > getDaysOfMonth(year, month)) {
                month++;
                day = 1;
            }
            if (month > 12) {
                year++;
                month = 1;
            }
        }
    }

    void addMonth(int months) {
        month += months;
        while (month > 12) {
            ++year;
            month -= 12;
        }
        if (day > getDaysOfMonth(year, month))
            day = getDaysOfMonth(year, month);
    }

    void addYear(int years) {
        for (int i = 1; i <= years; i++) {
            year++;
        }
        if (day > getDaysOfMonth(year, month)) {
            day = getDaysOfMonth(year, month);
        }
    }

    int Subtract(Date d2) {
        int sum;
        if (year < d2.getYear()) {
            sum = 0;
            while (year != d2.getYear() || month != d2.getMonth() || day != d2.getDay()) {
                this->addDay(1);
                sum++;
            }
            return 0 - sum;
        }
        if (year == d2.getYear() && month < d2.getMonth()) {
            sum = 0;
            while (year != d2.getYear() || month != d2.getMonth() || day != d2.getDay()) {
                this->addDay(1);
                sum++;
            }
            return 0 - sum;
        }
        if (year == d2.getYear() && month == d2.getMonth() && day < d2.getDay()) {
            sum = 0;
            while (year != d2.getYear() || month != d2.getMonth() || day != d2.getDay()) {
                this->addDay(1);
                sum++;
            }
            return 0 - sum;
        }
        sum = 0;
        while (year != d2.getYear() || month != d2.getMonth() || day != d2.getDay()) {
            d2.addDay(1);
            ++sum;
        }
        return sum;
    }

    int getWeekDay() {
        return 0;
    }
};

int main() {
    char WeekDayNames[][15] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int op;
    while (cin >> op) {
        int year, month, day;
        int y3, m3, d3;
        int n;
        if (op == 1) {
            cin >> year >> month >> day >> n;
            Date d2 = Date(year, month, day);
            d2.addDay(n);
            cout << d2.getYear() << " " << d2.getMonth() << " " << d2.getDay() << endl;
        } else if (op == 2) {
            cin >> year >> month >> day >> n;
            Date d2 = Date(year, month, day);
            d2.addMonth(n);
            cout << d2.getYear() << " " << d2.getMonth() << " " << d2.getDay() << endl;
        } else if (op == 3) {
            cin >> year >> month >> day >> n;
            Date d2 = Date(year, month, day);
            d2.addYear(n);
            cout << d2.getYear() << " " << d2.getMonth() << " " << d2.getDay() << endl;
        } else if (op == 4) {
            cin >> year >> month >> day >> y3 >> m3 >> d3;
            Date d2 = Date(year, month, day);
            Date s2 = Date(y3, m3, d3);
            n = d2.Subtract(s2);
            cout << n << endl;
        } else if (op == 5) {
            cin >> year >> month >> day;
            Date d2 = Date(year, month, day);
            int w = d2.getWeekDay();
            cout << WeekDayNames[w] << endl;
        }
    }
    return 0;
}