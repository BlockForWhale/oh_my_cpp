#include <iostream>

using namespace std;

class Object {
private:
    int num;
    int count;
    double price;
public:
    static int discount, n;
    static double sum, averages;

    void average() {
        averages = sum / (double) n;
    }

    void cal() {
        sum += price;
        n += count;
        average();
    }

    void input() {
        cin >> num >> count >> price;
        cal();
    }
};

int Object::discount = 1;
double Object::sum = 0;
int Object::n = 0;
double Object::averages = 0;

int main() {
    Object human[3];
    for (int i = 0; i < 3; i++) {
        human[i].input();
    }
    cout << "平均售价：" << Object::averages << endl;
    cout << "总售款：" << Object::n << endl;
    return 0;
}