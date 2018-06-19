#include <bits/stdc++.h>

using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int xs, int ys) : x(xs), y(ys) {}

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    int getX() { return x; }

    int getY() { return y; }
};

class Rectangle : public Point {
private:
    int width;
    int height;
public:
    Rectangle(int x, int y, int widths, int heights) : Point(x, y), width(widths), height(heights) {}

    int getArea() {
        return width * height;
    }

    bool isIn(Point p) {
        return (p.getX() > this->getX() && p.getX() < (this->getX() + width) && p.getY() > this->getY() &&
                p.getY() < (this->getY() + height));
    }
};

int main() {
    int topLeftX, topLeftY, width, height;
    int px, py, dx, dy;
    cin >> topLeftX >> topLeftY >> width >> height;
    cin >> px >> py;
    cin >> dx >> dy;
    Point p(px, py);
    Rectangle r(topLeftX, topLeftY, width, height);
    cout << r.getArea() << endl;
    if (r.isIn(p))
        cout << "In" << endl;
    else
        cout << "Not in" << endl;
    r.move(dx, dy);
    if (r.isIn(p))
        cout << "In" << endl;
    else
        cout << "Not in" << endl;
    return 0;
}