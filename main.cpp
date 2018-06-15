#include <bits/stdc++.h>

using namespace std;

class Point {
private:
    int x = 0;
    int y = 0;
public:
    Point() = default;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

};

class Rectangle {
private:
    int num;
    Point topLeft = Point(0, 0);
    int width;
    int height;
public:
    Rectangle() { num = 0, width = 0, height = 0; }

    int getNum() {
        return num;
    }

    Rectangle(int num, int x, int y, int width, int height) {
        this->num = num;
        this->width = width;
        this->height = height;
        this->topLeft = Point(x, y);
    }

    int getArea() {
        return (width * height);
    }

    bool isIn(Point p) {
        return p.getX() > topLeft.getX() && p.getX() < (topLeft.getX() + width) && p.getY() > topLeft.getY() &&
               p.getY() < (topLeft.getY() + height);
    }
};

class RectangleCollection {
private:
    Rectangle rects[100];   //一个包含长方形的数组，最多100个元素
    int count = 0;            //以上数组中长方形的实际个数
public:
    RectangleCollection() = default;

    void addRectangle(Rectangle r)//添加一个长方形到数组中，并count++
    {
        rects[count] = r;
        count++;
    }

    void deleteRectangle(int num) //根据num从数组中删除一个长方形（该长方形的编号等于num）
    {
        for (int i = 0; i < count; i++) {
            if (rects[i].getNum() == num) {
                for (int j = i; j < count - 1; j++)
                    rects[j] = rects[j + 1];
                count--;
                break;
            }
        }
    }

    int inRects(Point p)//根据传入的p，判断p位于rects数组中的哪些长方形之内，返回这些长方形面积之和。
    {
        int area = 0;
        for (int i = 0; i < count; i++) {
            if (rects[i].isIn(p)) {
                area += rects[i].getArea();
            }
        }
        return area;
    }
};


int main() {
    int num, topLeftX, topLeftY, width, height;
    int px, py;
    int op;
    RectangleCollection rc;
    Rectangle r;
    Point p;
    while (cin >> op) {
        switch (op) {
            case 1:
                cin >> num >> topLeftX >> topLeftY >> width >> height;
                r = Rectangle(num, topLeftX, topLeftY, width, height);
                rc.addRectangle(r);
                break;
            case 2:
                cin >> num;
                rc.deleteRectangle(num);
                break;
            case 3:
                cin >> px >> py;
                p = Point(px, py);
                cout << rc.inRects(p) << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}