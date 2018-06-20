#include <iostream>

using namespace std;

class Student {
public:
    void display();

    Student(int nums, string names, char sexs) : num(nums), name(names), sex(sexs) {}

protected :
    int num;
    string name;
    char sex;
};

void Student::display() {
    cout << "num:" << num << endl;
    cout << "name:" << name << endl;
    cout << "sex: " << sex << endl;
}

class Student1 : public Student {
public:
    void display1();

    Student1(int nums = 0, string names = "undefined", char sexs = 'M', int ages = 1, string addrs = "12#")
            : Student(nums, names, sexs), age(ages), addr(addrs) {}

    void setNum(int num) {
        this->num = num;
    }

private:
    int age;
    string addr;
};

void Student1::display1() {
    cout << "num: " << num << endl;
    cout << "name: " << name << endl;
    cout << "sex: " << sex << endl;
    cout << "age: " << age << endl;
    cout << "address: " << addr << endl;
}

int main() {
    Student1 stud1;
    stud1.display1();
    stud1.setNum(10023);
    return 0;
}