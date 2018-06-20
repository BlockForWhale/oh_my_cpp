#include <iostream>

using namespace std;

class Teacher;

class Student {
private:
    int num;
    string name;
    char sex;
public:
    Student(int nums, string names, char sexs) : num(nums), name(names), sex(sexs) {}

    int getNum() { return num; }

    string getName() { return name; }

    char getSex() { return sex; }
};

class Teacher {
private:
    int num;
    string name;
    char sex;
public:

    Teacher() {}

    Teacher(int nums, string names, char sexs) : num(nums), name(names), sex(sexs) {}

    Teacher &operator=(Student &x) {
        num = x.getNum();
        name = x.getName();
        sex = x.getSex();
        return *this;
    }

    int getNum() { return num; }

    string getName() { return name; }

    char getSex() { return sex; }
};

int main() {
    Student a = Student(101, "Jerry", 'M');
    Student b = Student(102, "LL", 'F');
    Teacher c;
    c = b;
    cout << c.getNum() << " " << c.getName() << " " << c.getSex() << endl;
    return 0;
}