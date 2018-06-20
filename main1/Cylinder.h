#include "Circle.h"

class Cylinder : public Circle {
private:
    int height;
public:
    Cylinder(int xs, int ys, int banjing, int height);

    int getHeight();
};