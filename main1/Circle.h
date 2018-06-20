#include "Point.h"

class Circle : public Point {
private:
    int banjing;
public:
    Circle(int xs, int ys, int banjings);

    int getBanjing();
};