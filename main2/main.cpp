#include <iostream>

using namespace std;

class Complex {
private:
    double xu;
    double shi;
public:
    Complex(double shis = 0, double xus = 0) : shi(shis), xu(xus) {}

    friend Complex &operator+(Complex &self, Complex &r) {
        double shibu, xubu;
        shibu = self.shi + r.shi;
        xubu = self.xu + r.xu;
        Complex *s = (Complex *) malloc(sizeof(Complex));
        *s = Complex(shibu, xubu);
        return *s;
    }

    friend Complex &operator+(Complex &self, int a) {
        double shibu, xubu;
        shibu = self.shi + a;
        xubu = self.xu;
        Complex *s = (Complex *) malloc(sizeof(Complex));
        *s = Complex(shibu, xubu);
        return *s;
    }

    friend Complex &operator+(int a, Complex &self) {
        double shibu, xubu;
        shibu = self.shi + a;
        xubu = self.xu;
        Complex *s = (Complex *) malloc(sizeof(Complex));
        *s = Complex(shibu, xubu);
        return *s;
    }

    friend Complex &operator-(Complex &self, Complex r) {
        double shibu, xubu;
        shibu = self.shi - r.shi;
        xubu = self.xu - r.xu;
        Complex *s = (Complex *) malloc(sizeof(Complex));
        *s = Complex(shibu, xubu);
        return *s;
    }

    friend Complex &operator*(Complex &self, Complex r) {
        double shibu = 0, xubu = 0;
        shibu += self.shi * r.shi;
        xubu += self.shi * r.xu;
        xubu += self.xu * r.shi;
        shibu += self.xu * r.xu;
        Complex *s = (Complex *) malloc(sizeof(Complex));
        *s = Complex(shibu, xubu);
        return *s;
    }

    friend Complex &operator/(Complex &self, Complex r) {
        double shibu, xubu;
        shibu = self.shi * r.shi + self.xu * r.xu;
        shibu = shibu / (r.shi * r.shi + r.xu * r.xu);
        xubu = self.xu * r.shi - self.shi * r.xu;
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
    cout << (a + 3).toString() << endl;
    cout << (a + b).toString() << endl;
    cout << (4 + a).toString() << endl;
    cout << (a - b).toString() << endl;
    cout << (a * b).toString() << endl;
    cout << (a / b).toString() << endl;
    return 0;
}