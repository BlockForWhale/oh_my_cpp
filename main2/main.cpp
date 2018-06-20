#include <iostream>

using namespace std;

class Point {
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    virtual ~Point() { cout << "executing Point destructor" << endl; }

private:
    int x, y;
};

class Circle : public Point {
public:
    Circle(int x, int y, int banjing) : Point(x, y), radius(banjing) {}

    virtual ~Circle() { cout << "executing Circle destructor" << endl; }

private:
    int radius;
};

int main() {
    Point *p = (Point *) malloc(sizeof(Point));
    *p = Circle(1, 2, 5);
    delete p;
    return 0;
}
