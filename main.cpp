#include <bits/stdc++.h>

using namespace std;

class MyString {
public:
    static int totalCount;

    MyString(unsigned n, char c) {
        totalCount++;
        s = "";
        for (int i = 0; i < n; i++) {
            s = s + c;
        }
    }

    MyString(char *p) {
        s = p;
        totalCount++;
    }

    MyString() {
        s = "";
        totalCount++;
    }

    MyString(const MyString &r) {
        s = r.s;
        totalCount++;
    }

    MyString &operator=(MyString r) {
        s = r.s;
        return *this;
    }

    ~MyString() {
        totalCount--;
    }

    static int GetCount() {
        return totalCount;
    }

    void ShowStr() {
        cout << s;
    }

private:
    string s;
};

int MyString::totalCount = 0;

void fun1(int n) {
    //cout << "定义数组前：" << MyString::GetCount() << endl;
    MyString strArr[n];
    //cout << "定义数组后：" << MyString::GetCount() << endl;
    MyString *pStr;
    cout << strArr[0].GetCount() << endl;
}

void fun2(int n) {
    //cout << "定义数组前：" << MyString::GetCount() << endl;
    MyString *pStr = new MyString[n];
    //cout << "定义数组后：" << MyString::GetCount() << endl;
    cout << MyString::GetCount() << endl;
}

void fun3(MyString &s1, MyString s2) {
    MyString s3;
    s3 = s1 = s2;
    cout << MyString::GetCount() << endl;
    s3.ShowStr();
    cout << endl;
}

int main() {
    //cout << "initial：" << MyString::GetCount() << endl;
    MyString s1;
    MyString s2;
    int n;
    char charArr[20];
    int op;
    while (cin >> op) {
        switch (op) {
            case 1: {
                cin >> n;
                fun1(n);
                break;
            }
            case 2: {
                cin >> n;
                fun2(n);
                break;
            }
            case 3: {
                int m;
                char ch;
                cin >> m >> ch;
                s2 = MyString(m, ch);
                fun3(s1, s2);
                s1.ShowStr();

                cout << endl;

                break;
            }
            case 4: {
                cin >> charArr;
                s1 = MyString(charArr);
                cout << MyString::GetCount() << endl;
                s1.ShowStr();
                cout << endl;
                break;
            }
        }
    }

    return 0;
}