#include <bits/stdc++.h>

using namespace std;

class Student {
private:
    int norm, ex, final, overall;
    char name[15];
public:
    void init(char *name1, int nor1, int ex1, int fin1) {
        strcpy(name, name1);
        norm = nor1;
        ex = ex1;
        final = fin1;
    }

    void fun() {
        double overalls = 0;
        overalls += (norm * 0.2);
        overalls += (ex * 0.25);
        overalls += (final * 0.55);
        int intPart = (int) overalls;
        double ss = overalls - intPart;
        if (ss >= 0.5) {
            intPart++;
        }
        if (final >= 50)
            overall = intPart;
        else overall = final;
    }

    void print() {
        cout << name << ' ' << norm << ' ' << ex << ' ' << final << ' ' << overall << endl;
    }

    friend void sort(Student st[], int n);
};

void sort(Student st[], int n) {
    Student t;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (st[i].overall < st[j].overall) {
                t = st[i];
                st[i] = st[j];
                st[j] = t;
            }
}

int main() {
    int n;
    int norm, ex, final;
    char name[15];
    cin >> n;
    Student stu[n];
    for (int i = 0; i < n; i++) {
        cin >> name >> norm >> ex >> final;
        stu[i].init(name, norm, ex, final);
        stu[i].fun();
    }
    sort(stu, n);
    for (int i = 0; i < n; i++) {
        stu[i].print();
    }
    return 0;

}
