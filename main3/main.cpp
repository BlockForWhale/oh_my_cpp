#include <iostream>

using namespace std;

class Matrix {
private:
    int ls[2][3];
    int sizeX, sizeY;
public:
    Matrix(int lsx[2][3]) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                ls[i][j] = lsx[i][j];
    }

    void print() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                cout << ls[i][j] << (j == 2 ? "\n" : " ");
            }
        }
    }

    friend Matrix &operator+(Matrix &a, Matrix &b) {
        Matrix *p = (Matrix *) malloc(sizeof(Matrix));
        *p = a;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                (*p).ls[i][j] += b.ls[i][j];
            }
        }
        return *p;
    }
};

int main() {
    int p[2][3] = {
            1, 2, 3, 5, 6, 7
    };
    int p2[2][3] = {
            2, 3, 4, 5, 6, -2
    };
    Matrix a = Matrix(p);
    Matrix b = Matrix(p2);
    Matrix c = a + b;
    c.print();
    return 0;
}