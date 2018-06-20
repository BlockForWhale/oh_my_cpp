#include <iostream>

using namespace std;

class Complex {
private:
    double xu;
    double shi;
public:
    Complex(double shis = 0, double xus = 0) : shi(shis), xu(xus) {}

    Complex &operator+(Complex r) {
        double shibu, xubu;
        shibu = shi + r.shi;
        xubu = xu + r.xu;
        Complex *s = (Complex *) malloc(sizeof(Complex));
        *s = Complex(shibu, xubu);
        return *s;
    }

    Complex &operator-(Complex r) {
        double shibu, xubu;
        shibu = shi - r.shi;
        xubu = xu - r.xu;
        Complex *s = (Complex *) malloc(sizeof(Complex));
        *s = Complex(shibu, xubu);
        return *s;
    }

    Complex &operator*(Complex r) {
        double shibu = 0, xubu = 0;
        shibu += shi * r.shi;
        xubu += shi * r.xu;
        xubu += xu * r.shi;
        shibu += xu * r.xu;
        Complex *s = (Complex *) malloc(sizeof(Complex));
        *s = Complex(shibu, xubu);
        return *s;
    }

    Complex &operator/(Complex r) {
        double shibu, xubu;
        shibu = shi * r.shi + xu * r.xu;
        shibu = shibu / (r.shi * r.shi + r.xu * r.xu);
        xubu = xu * r.shi - shi * r.xu;
        xubu = xubu / (r.shi * r.shi + r.xu * r.xu);
        Complex *s = (Complex *) malloc(sizeof(Complex));
        *s = Complex(shibu, xubu);
        return *s;
    }

    string toString() {
        string s;
        if (shi == 0 && xu == 0) {
            s = "0";
        } else if (shi != 0 && xu == 0) {
            s = to_string(shi);
        } else if (shi == 0 && xu != 0) {
            s = to_string(xu) + "i";
        } else {
            if (xu > 0)
                s = to_string(shi) + "+" + to_string(xu) + "i";
            else
                s = to_string(shi) + to_string(xu) + "i";
        }
        return s;
    }
};

int main() {
    Complex a = Complex(2, 3);
    Complex b = Complex(5, -4.5);
    cout << (a + b).toString() << endl;
    cout << (a - b).toString() << endl;
    cout << (a * b).toString() << endl;
    cout << (a / b).toString() << endl;
    return 0;
}