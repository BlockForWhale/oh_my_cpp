#include <bits/stdc++.h>

using namespace std;

stack<int> c_num;

string tihuan_suoyoude(string str, const string &ov, const string &nv) {
    while (true) {
        string::size_type pos(0);
        if ((pos = str.find(ov)) != string::npos)
            str.replace(pos, ov.length(), nv);
        else break;
    }
    return str;
}

inline int check(char ch) {
    if (ch == '(' || ch == ')' || ch == '!' || ch == '|' || ch == '&' || ch == '~' || ch == '+' || ch == '-' ||
        ch == '*' || ch == '/')
        return 3;
    else if (ch == 'T')return 1;
    else if (ch == 'F')return 0;
    else if ('0' <= ch && ch <= '9')return ch - '0';
    else return -1;
}

int priority(char op) {
    switch (op) {
        case '!':
            return 4;
        case '|':
        case '&':
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
        case '~':
            return 2;
        case '(':
        case ')':
            return 5;
    }
    return 0;
}

void docalculateIt(char last) {
    int a, b;
    switch (last) {
        case '!':
            a = c_num.top();
            c_num.pop();
            c_num.push(!a);
            break;
        case '|':
            a = c_num.top();
            c_num.pop();
            b = c_num.top();
            c_num.pop();
            c_num.push(a || b);
            break;
        case '&':
            a = c_num.top();
            c_num.pop();
            b = c_num.top();
            c_num.pop();
            c_num.push(a && b);
            break;
        case '~':
            a = c_num.top();
            c_num.pop();
            b = c_num.top();
            c_num.pop();
            if (a == 0 && b == 1)c_num.push(0);
            else c_num.push(1);
            break;
        case '+':
            a = c_num.top();
            c_num.pop();
            b = c_num.top();
            c_num.pop();
            c_num.push(a + b);
            break;
        case '-':
            a = c_num.top();
            c_num.pop();
            b = c_num.top();
            c_num.pop();
            c_num.push(a - b);
            break;
        case '*':
            a = c_num.top();
            c_num.pop();
            b = c_num.top();
            c_num.pop();

            c_num.push(a * b);
            break;
        case '/':
            a = c_num.top();
            c_num.pop();
            b = c_num.top();
            c_num.pop();
            c_num.push(a / b);
            break;
        default:
            break;
    }

}

int calculateIt(string express) {
    stack<char> op;
    for (auto i: express) {
        if (i == ' ')continue;
        int type = check(i);
        if (type == -1) {
            cout << "非法表达式" << endl;
            return -1;
        } else if (type == 3) {
            if (op.empty() || i == '(') {
                op.push(i);
            } else {
                char last;
                int a, b;
                last = op.top();
                if (i == ')') {
                    op.pop();
                    while (last != '(') {
                        docalculateIt(last);
                        last = op.top();
                        op.pop();
                    }
                } else {
                    if (priority(i) >= priority(last)) {
                        op.push(i);
                    } else {
                        char cur = i;
                        while (priority(i) < priority(last)) {
                            docalculateIt(last);
                            op.pop();
                            if (op.empty())break;
                            last = i;
                            i = op.top();
                        }
                        op.push(cur);
                    }
                }
            }
        } else {
            c_num.push(type);
        }
    }
    char last;
    while (!op.empty()) {
        last = op.top();
        docalculateIt(last);
        op.pop();
    }
    return c_num.top();
}

int main() {
    string p, q, a1, a2;
    bool ans;
    cout << "请输入表达式：(允许的符号：|,&,!,(,),-" << endl;
    cin >> p;
    cout << "p  q  答案" << endl;
    cout << "-----------" << endl;
    a1 = tihuan_suoyoude(p, "p", "T");
    a1 = tihuan_suoyoude(a1, "q", "T");
    ans = static_cast<bool>(calculateIt(a1));
    cout << "T   T   " << ans << endl;
    a1 = tihuan_suoyoude(p, "p", "F");
    a1 = tihuan_suoyoude(a1, "q", "T");
    ans = static_cast<bool>(calculateIt(a1));
    cout << "F   T   " << ans << endl;
    a1 = tihuan_suoyoude(p, "p", "T");
    a1 = tihuan_suoyoude(a1, "q", "F");
    ans = static_cast<bool>(calculateIt(a1));
    cout << "T   F   " << ans << endl;
    a1 = tihuan_suoyoude(p, "p", "F");
    a1 = tihuan_suoyoude(a1, "q", "F");
    ans = static_cast<bool>(calculateIt(a1));
    cout << "F   F   " << ans << endl;
    return 0;
}