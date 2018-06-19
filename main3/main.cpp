#include <iostream>

using namespace std;

class Object {
private:
    int length, width, height;
    int V;
public:
    void initValue() {
        cin >> length >> width >> height;
    }

    void calculate() {
        V = length * width * height;
    }

    void printV() {
        cout << V << endl;
    }
};

int main() {
    Object rect[3];
    for (int i = 0; i < 3; i++) {
        rect[i].initValue();
        rect[i].calculate();
        rect[i].printV();
    }
    return 0;
}