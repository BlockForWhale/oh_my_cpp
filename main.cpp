#include <bits/stdc++.h>
#include <utility>

using namespace std;

class Student {
private:
    int number;//学号
    string name;//名字
    double chinese;//语文成绩
    double math;//数学成绩
    double average;//平均成绩
public:
    Student() {}

    Student(int numbers, string names) : number(numbers), name(names) {}

    bool setChinese(double num) {
        if (num > 0 && num <= 100) {
            chinese = num;
            return true;
        }
        chinese = 0;
        return false;
    }

    bool setMath(double num) {
        if (num >= 0 && num <= 100) {
            math = num;
            return true;
        }
        math = 0;
        return false;
    }

    double getChinese() { return chinese; }

    double getMath() { return math; }

    int getNumber() { return number; }

    string getName() { return name; }

    double getAverage() {
        average = math + chinese;
        average = average / 2.0;
        return average;
    }
};

void findStudent(Student stu[], int n, string search) {
    bool finds = false;
    for (int i = 0; i < n; i++) {
        if (stu[i].getName().find(search, 0) != stu[i].getName().npos) {
            finds = true;
            cout << stu[i].getNumber()
                 << ' '
                 << stu[i].getName()
                 << ' '
                 << stu[i].getChinese()
                 << ' '
                 << stu[i].getMath()
                 << ' '
                 << stu[i].getAverage()
                 << endl;
        }
    }
    if (!finds) {
        cout << "Not found." << endl;
    }
}

int main() {
    int n, i;
    int number;
    string name, searchName;
    double math, chinese;
    cin >> n;
    Student stu[n];
    for (i = 0; i < n; i++) {
        cin >> number >> name >> chinese >> math;
        stu[i] = Student(number, name);
        stu[i].setChinese(chinese);
        stu[i].setMath(math);
    }
    cin >> searchName;  //输入需要查找的姓名
    findStudent(stu, n, searchName);  //调用函数，查找学生，输出信息
    return 0;
}