#include <iostream>

using namespace std;

class Student                        //声明基类
{
public:                            //基类公用成员
    void display();

    Student(int nums, string names, char sexs) : num(nums), name(names), sex(sexs) {}

protected :                        //基类保护成员
    int num;
    string name;
    char sex;
};

void Student::display()               //定义基类成员函数
{
    cout << "num:" << num << endl;
    cout << "name:" << name << endl;
    cout << "sex: " << sex << endl;
}

class Student1 : protected Student      //用protected方式声明派生类Student1
{
public:
    void display1();

    Student1(int nums = 0, string names = "undefined", char sexs = 'M', int ages = 1, string addrs = "12#")
            : Student(nums, names, sexs), age(ages), addr(addrs) {}
    //派生类公用成员函数

    void setNum(int num) {
        this->num = num;
    }

private:
    int age;                               //派生类私有数据成员
    string addr;                          //派生类私有数据成员
};

void Student1::display1()            //定义派生类公用成员函数
{
    cout << "num: " << num << endl;         //引用基类的保护成员，合法
    cout << "name: " << name << endl;        //引用基类的保护成员，合法
    cout << "sex: " << sex << endl;            //引用基类的保护成员，合法
    cout << "age: " << age << endl;            //引用派生类的私有成员，合法
    cout << "address: " << addr << endl;       //引用派生类的私有成员，合法
}

int main() {
    Student1 stud1;                     //stud1是派生类Student1类的对象
    stud1.display1();                  //合法，display1是派生类中的公用成员函数
    stud1.setNum(10023);                    //错误，外界不能访问保护成员
    return 0;
}