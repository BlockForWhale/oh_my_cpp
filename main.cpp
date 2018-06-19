#include <bits/stdc++.h>

using namespace std;

class Rectangle;

class Point {
private:
    int x, y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    friend class Rectangle;
};

class Rectangle {
private:
    Point topLeft, topRight, bottomLeft, bottomRight;

    bool isRectangle() {
        return topLeft.x == bottomLeft.x && topLeft.y == topRight.y && bottomLeft.y == bottomRight.y &&
               topRight.x == bottomRight.x;
    }

public:
    Rectangle(Point stopLeft, Point stopRight, Point sbottomLeft, Point sbottomRight) : topLeft(stopLeft),
                                                                                        topRight(stopRight),
                                                                                        bottomLeft(sbottomLeft),
                                                                                        bottomRight(sbottomRight) {}

    int getArea() {
        if (!isRectangle()) return 0;
        int x = bottomRight.x - topLeft.x;
        int y = bottomRight.y - topLeft.y;
        if (x < 0) x = 0 - x;
        if (y < 0) y = 0 - y;
        return x * y;
    }

    bool isIn(Point p) {
        if (!isRectangle()) return false;
        return p.x > topLeft.x && p.x < bottomRight.x && p.y >= topLeft.y && p.y < bottomRight.y;
    }
};

int main() {
    int topLeftX, topLeftY, topRightX, topRightY, bottomLeftX, bottomLeftY, bottomRightX, bottomRightY;
    int px, py;

    cin >> topLeftX >> topLeftY >> topRightX >> topRightY >> bottomLeftX >> bottomLeftY >> bottomRightX >> bottomRightY;
    cin >> px >> py;

    Point p(px, py);
    Rectangle r(Point(topLeftX, topLeftY), Point(topRightX, topRightY), Point(bottomLeftX, bottomLeftY),
                Point(bottomRightX, bottomRightY));
    cout << r.getArea() << endl;
    if (r.isIn(p))
        cout << "In" << endl;
    else
        cout << "Not in" << endl;

    return 0;
}