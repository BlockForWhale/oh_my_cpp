#include <iostream>

using namespace std;

class Student                                //声明基类
{
public:                                    //基类公用成员

    Student(int nums, string names, char sexs) : num(nums), name(names), sex(sexs) {}

    void get_value() { cin >> num >> name >> sex; }

    void display() {
        cout << "num: " << num << endl;
        cout << "name: " << name << endl;
        cout << "sex: " << sex << endl;
    }

private :                                   //基类私有成员
    int num;
    string name;
    char sex;
};

class Student1 : public Student                 //以public方式声明派生类Student1
{
public:

    Student1(int nums, string names, char sexs, int ages, string add)
            : Student(nums, names, sexs), age(ages), addr(add) {}

    void display_1() {
        display();
        cout << "age: " << age << endl;           //引用派生类的私有成员，正确
        cout << "address: " << addr << endl;
    }     //引用派生类的私有成员，正确
private:
    int age;
    string addr;
};

int main() {
    int num;
    string name;
    char sex;
    int age;
    string addr;
    cin >> num >> name >> sex >> age >> addr;
    Student1 a = Student1(num, name, sex, age, addr);
    a.display_1();
    return 0;
}
