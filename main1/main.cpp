#include <iostream>
#include <cstdio>
#include "Cylinder.h"

using namespace std;

int main() {
    Cylinder a = Cylinder(1, 2, 3, 4);
    printf("(%d,%d)\n", a.getX(), a.getY());
    printf("半径:%d\n高:%d\n", a.getBanjing(), a.getHeight());
    return 0;
}