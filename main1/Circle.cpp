#include "Circle.h"

Circle::Circle(int xs, int ys, int banjings) : Point(xs, ys), banjing(banjings) {}

int Circle::getBanjing() { return banjing; }