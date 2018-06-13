#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int year;
    int month;
    int day;
} Date;

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

int getDaysOfYear(int y) {
    return y % 4 != 0 ? 365 : (y % 100 != 0 ? 366 : (y % 400 != 0 ? 365 : 366));
}

Date AddDay(Date d, int days) {
    for (int i = 1; i <= days; i++) {
        d.day++;
        if (d.day > getDaysOfMonth(d.year, d.month)) {
            d.month++;
            d.day = 1;
        }
        if (d.month > 12) {
            d.year++;
            d.month = 1;
        }
    }
    return d;
}

Date AddMonth(Date d, int months) {
    Date i = d;
    i.month += months;
    while (i.month > 12) {
        ++i.year;
        i.month -= 12;
    }
    if (i.day > getDaysOfMonth(i.year, i.month))
        i.day = getDaysOfMonth(i.year, i.month);
    return i;
}

Date AddYear(Date d, int years) {
    for (int i = 1; i <= years; i++) {
        d.year++;
    }
    if (d.day > getDaysOfMonth(d.year, d.month)) {
        d.day = getDaysOfMonth(d.year, d.month);
    }
    return d;
}

int Subtract(Date d1, Date d2) {
    if (d1.year < d2.year)
        return -1 * Subtract(d2, d1);
    if (d1.year == d2.year && d1.month < d2.month)
        return -1 * Subtract(d2, d1);
    if (d1.year == d2.year && d1.month == d2.month &&
        d1.day < d2.day)
        return -1 * Subtract(d2, d1);
    int sum = 0;
    while (d1.year != d2.year || d1.month != d2.month || d1.day != d2.day) {
        d2 = AddDay(d2, 1);
        ++sum;
    }
    return sum;
}

int GetWeekDay(Date in) {

}

typedef int DayName;

int main() {
    char WeekDayNames[][15] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int op;
    while (cin >> op) {
        Date d1, d2;
        int n;
        DayName w;
        switch (op) {
            case 1:  //add days
                cin >> d1.year >> d1.month >> d1.day >> n;
                d2 = AddDay(d1, n);
                cout << d2.year << " " << d2.month << " " << d2.day << endl;
                break;
            case 2:
                cin >> d1.year >> d1.month >> d1.day >> n;
                d2 = AddMonth(d1, n);
                cout << d2.year << " " << d2.month << " " << d2.day << endl;
                break;
            case 3:
                cin >> d1.year >> d1.month >> d1.day >> n;
                d2 = AddYear(d1, n);
                cout << d2.year << " " << d2.month << " " << d2.day << endl;
                break;
            case 4:
                cin >> d1.year >> d1.month >> d1.day >> d2.year >> d2.month >> d2.day;
                n = Subtract(d1, d2);
                cout << n << endl;
                break;
            case 5:
                cin >> d1.year >> d1.month >> d1.day;
                w = GetWeekDay(d1);
                cout << WeekDayNames[w] << endl;
                break;
        }
    }
    return 0;
}