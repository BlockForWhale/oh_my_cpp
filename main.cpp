#include <iostream>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    static int maxYear;
    static int minYear;

    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    static void SetMaxYear(int maxY) {
        maxYear = maxY;
    }

    static void SetMinYear(int minY) {
        minYear = minY;
    }

    friend class StudentList;

    friend class Student;
};

int Date::maxYear = 0;
int Date::minYear = 0;

class Student {
private:
    int num;
    string name;
    Date birthday;
public:

    Student() : num(-1), name(""), birthday(Date(0, 0, 0)) {}

    Student(int nums, string names, Date birthdays) : num(nums), name(names), birthday(birthdays) {
        if (birthdays.year > Date::maxYear) birthdays.year = Date::maxYear;
        if (birthdays.year < Date::minYear) birthdays.year = Date::minYear;
        this->birthday = birthdays;
    }

    friend class StudentList;
};

class StudentList {
private:
    Student list[100];
    int count;
public:
    StudentList() : count(0) {}

    void AddStudent(Student stu) {
        list[count++] = stu;
    }

    void DeleteStudent(int num) {
        for (int i = 0; i < count; i++) {
            if (list[i].num == num) {
                for (int j = i; j < count - 1; j++) {
                    list[j] = list[j + 1];
                }
                count--;
            }
        }
    }

    StudentList GetStudent(int year1, int year2) {
        StudentList ls;
        for (int i = 0; i < count; i++) {
            if (list[i].birthday.year >= year1 && list[i].birthday.year <= year2) {
                ls.AddStudent(list[i]);
            }
        }
        return ls;
    }

    void Print() {
        if (count == 0)
            cout << "No result." << endl;
        else {
            for (int i = 0; i < count; i++) {
                cout << list[i].num << ' ' << list[i].name << ' ' << list[i].birthday.year << ' '
                     << list[i].birthday.month << ' ' << list[i].birthday.day << endl;
            }
        }
    }
};

int main() {
    int num, birthYear, birthMonth, birthDay;
    int maxYear, minYear, year1, year2;
    int op;
    string name;
    StudentList sl;
    Student stu;
    cin >> maxYear >> minYear;
    Date::SetMaxYear(maxYear);
    Date::SetMinYear(minYear);
    while (cin >> op) {
        switch (op) {
            case 1:
                cin >> num >> name >> birthYear >> birthMonth >> birthDay;
                stu = Student(num, name, Date(birthYear, birthMonth, birthDay));
                sl.AddStudent(stu);
                break;
            case 2:
                cin >> num;
                sl.DeleteStudent(num);
                break;
            case 3:
                cin >> year1 >> year2;
                StudentList temp = sl.GetStudent(year1, year2);
                temp.Print();
                break;
        }
    }
    return 0;
}