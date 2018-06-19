#include <bits/stdc++.h>

using namespace std;

class ID {
private:
    char *id;
    int year, month, date;
    char sex, youth;
public:
    void set_ID(char *s) {
        char *p = (char *) malloc(sizeof(*s) * (strlen(s) + 1));
        strcpy(p, s);
        id = p;
        //cout << "current ID(first): "<<id<<endl;
        year = 0;
        month = 0;
        date = 0;
        sex = 'F';
        youth = 'N';
    }

    int getAge() {
        int age = 2015 - year;
        int asd = month * 1000 + date;
        if (asd > 1001) age--;
        return age;
    }

    void fun() {
        char *start = id;
        //cout << "current ID: "<<id<<endl;
        for (int i = 0; i < 6; i++) id++;
        //cout << "current ID: "<<id<<endl;
        year += ((*id - '0') * 1000);
        id++;
        //cout << "current ID: "<<id<<endl;
        year += ((*id - '0') * 100);
        id++;
        //cout << "current ID: "<<id<<endl;
        year += ((*id - '0') * 10);
        id++;
        //cout << "current ID: "<<id<<endl;
        year += (*id - '0');
        id++;
        //cout << "current ID: "<<id<<endl;
        month += (*id - '0') * 10;
        id++;
        //cout << "current ID: "<<id<<endl;
        month += (*id - '0');
        id++;
        //cout << "current ID: "<<id<<endl;
        date += (*id - '0') * 10;
        id++;
        //cout << "current ID: "<<id<<endl;
        date += (*id - '0');
        id += 3;
        //cout << "current ID: "<<id<<endl;
        if ((*id - '0') % 2 != 0) sex = 'M';
        else sex = 'F';
        id = start;
        //cout << "current ID: "<<id<<endl;
        if (sex == 'M' && getAge() <= 35) youth = 'Y';
        else if (sex == 'M' && getAge() > 35) youth = 'N';
        else if (sex == 'F' && getAge() <= 40) youth = 'Y';
        else youth = 'N';
    }

    void print() {
        cout << id << endl;
        cout << year << '.' << month << '.' << date << endl;
        cout << sex << endl << youth << endl;
    }

    ~ID() {
        free(id);
    }
};

int main() {
    int T, i;
    char id[19];
    cin >> T;
    ID person[T];
    for (i = 0; i < T; i++) {
        if (i > 0 && i < T) cout << endl;
        cin >> id;
        person[i].set_ID(id);
        person[i].fun();
        person[i].print();
    }
    return 0;
}