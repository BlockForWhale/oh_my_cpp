#include "Cylinder.h"

Cylinder::Cylinder(int xs, int ys, int banjings, int tall) : Circle(xs, ys, banjings), height(tall) {}

int Cylinder::getHeight() { return height; }