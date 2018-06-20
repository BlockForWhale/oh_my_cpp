#include <iostream>

using namespace std;

class Teacher {
private:
    string 姓名;
    int 年龄;
    char 性别;
    string 地址;
    string 电话;
    string 职称;
public:
    Teacher(string 姓名s, int 年龄s, char 性别s, string 地址s, string 电话s, string 职称s)
            : 姓名(姓名s), 年龄(年龄s), 性别(性别s), 地址(地址s), 电话(电话s), 职称(职称s) {}

    void display() {
        cout << "姓名：" << 姓名 << endl;
        cout << "年龄：" << 年龄 << endl;
        cout << "性别：" << 性别 << endl;
        cout << "职称：" << 职称 << endl;
        cout << "地址：" << 地址 << endl;
        cout << "电话：" << 电话 << endl;
    }
};

class Cadre {
private:
    string 姓名;
    int 年龄;
    char 性别;
    string 地址;
    string 电话;
    string 职务;
public:
    Cadre(string 姓名s, int 年龄s, char 性别s, string 地址s, string 电话s, string 职务s)
            : 姓名(姓名s), 年龄(年龄s), 性别(性别s), 地址(地址s), 电话(电话s), 职务(职务s) {}

    void displays() {
        cout << "职务：" << 职务 << endl;
    }
};

class Teacher_Cadre : public Cadre, Teacher {
private:
    int 工资;
public:
    Teacher_Cadre(string 姓名, int 年龄, char 性别, string 地址, string 电话, string 职称, string 职务, int 工资s)
            : Teacher(姓名, 年龄, 性别, 地址, 电话, 职称), Cadre(姓名, 年龄, 性别, 地址, 电话, 职务), 工资(工资s) {}

    void show() {
        display();
        displays();
        cout << "工资：" << 工资 << endl;
    }
};

int main() {
    Teacher_Cadre a = Teacher_Cadre("LL", 10, 'F', "ssss", "10086", "Offer", "CEO", 10000);
    a.show();
    return 0;
}