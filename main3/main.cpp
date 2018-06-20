#include <iostream>

using namespace std;

class Shape {
public:
    virtual void printArea();
};

void Shape::printArea() {

}

class Circle : public Shape {
private:
    int radius;
public:
    Circle(int radiuss) : radius(radiuss) {}

    void printArea() {
        cout << (3.14159 * radius * radius) << endl;
    }
};

class Rectangle : public Shape {
private:
    int x;
    int y;
public:
    Rectangle(int xs, int ys) : x(xs), y(ys) {}

    void printArea() {
        cout << (x * y) << endl;
    }
};

class Triangle : public Shape {
private:
    int bottom;
    int height;
public:
    Triangle(int bot, int hei) : bottom(bot), height(hei) {}

    void printArea() {
        cout << (bottom * height) << endl;
    }
};

int main() {
    Triangle t = Triangle(3, 4);
    Rectangle r = Rectangle(3, 5);
    Circle c = Circle(2);
    t.printArea();
    r.printArea();
    c.printArea();
    return 0;
}