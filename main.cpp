#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

class Points {
private:
    int x, y;
public:
    Points(int a = 0, int b = 0) {
        x = a;
        y = b;
    }

    void setXY(int a, int b) {
        x = a;
        y = b;
    }

    int getX() { return x; }

    int getY() { return y; }
};

class Rectangle {
private:
    Points point1, point2, point3, point4;
public:
    Rectangle(Points one, Points four) {
        point1 = one;
        point4 = four;
        point3 = Points(one.getX(), four.getY());
        point2 = Points(four.getX(), one.getY());
    }

    Rectangle(int x1, int y1, int x2, int y2) {
        point1 = Points(x1, y1);
        point3 = Points(x1, y2);
        point2 = Points(x2, y1);
        point4 = Points(x2, y2);
    }

    void printPoint() {
        cout << point1.getX() << ' ' << point1.getY() << endl;
        cout << point2.getX() << ' ' << point2.getY() << endl;
        cout << point3.getX() << ' ' << point3.getY() << endl;
        cout << point4.getX() << ' ' << point4.getY() << endl;
    }

    int getArea() {
        int x = point1.getX() - point4.getX();
        if (x < 0) x = 0 - x;
        int y = point1.getY() - point4.getY();
        if (y < 0) y = 0 - y;
        return x * y;
    }
};

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    Points p1(x1, y1), p4(x2, y2); //定义两个点
    Rectangle r1(p1, p4);//用两个点做参数，声明一个对角顶点分别为p1,p4的矩形对象r1
    r1.printPoint(); //输出矩形对象r1的4个顶点坐标，
    cout << r1.getArea(); //输出矩形对象r1的面积
    return 0;

}