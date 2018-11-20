#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define tmpl template<class ElemType>
#define QNode LinkQueueNode<ElemType>

tmpl
struct LinkQueueNode {
    ElemType data;
    QNode *next;

    LinkQueueNode(QNode *ptr = NULL) { next = ptr; }

    LinkQueueNode(const ElemType &item, QNode *ptr = NULL) {
        next = ptr;
        data = item;
    }

    ElemType getData() { return data; }

    void SetLink(QNode *link) { next = link; }

    void SetData(ElemType value) { data = value; }
};

tmpl
class LinkQueue {
private:
    QNode *front;
    QNode *rear;
    int length;
public:
    LinkQueue();

    int QueueLength() const { return length; }

    bool QueueisEmpty() const;

    bool deQueue(ElemType &e);

    bool enQueue(ElemType e);

    QNode *GetFront() { return front; }

    ElemType GetFrontData() { return front->data; }

    QNode *GetRear() { return rear; }

    bool QueueTraverse() const;
};


bool judge(const string &str) {
    if (str[0] == '-') return false;
    return true;
}


int compare(string &A_str, string &B_str) {
    int Len_A = static_cast<int>(A_str.length());
    int Len_B = static_cast<int>(B_str.length());
    if (!judge(A_str)) A_str = A_str.substr(1, Len_A - 1);

    if (!judge(B_str)) B_str = B_str.substr(1, Len_B - 1);

    if (A_str > B_str) return 1;
    else if (A_str < B_str) return 2;

    return 0;
}

tmpl
LinkQueue<ElemType>::LinkQueue() {
    rear = new QNode;
    if (!rear) return;
    else front = rear;
    front->next = NULL;
    length = 0;
}

tmpl
bool LinkQueue<ElemType>::QueueisEmpty() const { return front == rear; }


tmpl
bool LinkQueue<ElemType>::deQueue(ElemType &e) {
    if (front == rear) return false;
    QNode *p;
    p = front->next;
    e = p->data;
    front->next = p->next;
    length--;
    if (rear == p) rear = front;
    delete (p);
    return true;
}


tmpl
bool LinkQueue<ElemType>::enQueue(ElemType e) {
    QNode *s;
    s = new QNode;
    s->data = e;
    s->next = NULL;
    rear->next = s;
    rear = s;
    return true;
}

tmpl
bool LinkQueue<ElemType>::QueueTraverse() const {
    QNode *v;
    v = front->next;
    while (v) {
        cout << v->data << ' ';
        v = v->next;
    }
    return true;
}

tmpl
void queuetraining(LinkQueue<ElemType> &linkQueue, int i1, int i2) {
    int minecraft, tmp1, num;
    minecraft = i1;
    tmp1 = 0;
    for (int i = 1; i <= i1; i++) linkQueue.enQueue(i);
    while (minecraft > 1) {
        tmp1++;
        linkQueue.deQueue(num);
        if (tmp1 == i2) {
            tmp1 = 0;
            minecraft--;
        } else linkQueue.enQueue(num);
    }
    linkQueue.QueueTraverse();
}

tmpl
void insCalculate(LinkQueue<ElemType> &A, string &str) {
    QNode *front;
    front = A.GetFront();

    int len = str.length();
    int s, tmp;

    if (!judge(str)) {
        front->SetData(-1);
        str = str.substr(1, len);
        len = len - 1;
    } else front->SetData(1);

    if (len % 4 == 0) s = len / 4;
    else s = len / 4 + 1;

    if (len <= 4) {
        tmp = atoi(str.c_str());
        A.enQueue(tmp);
    } else {
        for (int i = 1; i <= s; i++) {
            if (4 * i <= len) {
                tmp = atoi((str.substr(len - 4 * i, 4)).c_str());
                A.enQueue(tmp);
            } else {
                tmp = atoi((str.substr(0, len - 4 * (i - 1))).c_str());
                A.enQueue(tmp);
            }
        }
    }
}


char *reverse(char *s) {
    char temp;
    char *p = s;
    char *q = s;
    while (*q)
        ++q;
    q--;
    while (q > p) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
    return s;
}

template<class T>
void itoa(T n, char s[]) {
    int i, j, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)s[i++] = '-';
    s[i] = '\0';
    s = reverse(s);
}

string fun(int result, int &num) {
    string str = "";
    char *Result = new char[4];
    itoa(result, Result);

    if (result == 0) str = "0000";
    else {
        if (result > 0 && result < 10) str = "000";
        if (result > 9 && result < 100) str = "00";
        if (result > 99 && result < 1000) str = "0";

        str.append(Result);

    }

    if (num > 0) str.append(",");
    else num++;
    return str;
}

tmpl
void addLongInt(LinkQueue<ElemType> &A, LinkQueue<ElemType> &B, string &result, string &A_str, string &B_str) {
    QNode *p1, *p2;
    int i;
    int aData, bData;
    ElemType neglu1, neglu2;
    int tmp_result = 0, tmp_result1 = 0, flag;
    int tmp = 0;
    char *rs = new char[4];
    int flag_A, flag_B;
    int flag1 = 0;
    int i1;
    int num = 0;

    p1 = A.GetFront();
    neglu1 = p1->data;
    p2 = B.GetFront();
    neglu2 = p2->data;

    i1 = compare(A_str, B_str);

    p1 = p1->next;
    p2 = p2->next;

    flag_A = 0;
    flag_B = 0;


    if (neglu2 == 1 && neglu1 == 1) flag1 = 0;
    if (neglu2 == -1 && neglu1 == -1) flag1 = 1;
    if (neglu1 == 1 && neglu2 == -1) {
        if (i1 == 1) flag1 = 0;
    }
    if (neglu1 == 1 && neglu2 == -1) {
        if (i1 == 2) flag1 = 1;
    }
    if (neglu1 == -1 && neglu2 == 1) {
        if (i1 == 1) flag1 = 1;
    }
    if (neglu1 == -1 && neglu2 == 1) {
        if (i1 == 2) flag1 = 0;
    }

    if (neglu1 != neglu2 && i1 == 0) {
        cout << endl << '0';
        return;
    } else {
        while (flag_A == 0 || flag_B == 0) {

            if (flag_A == 0) {
                A.deQueue(aData);
                if (i1 == 2 && neglu1 != neglu2) aData = aData * (-1);
            } else aData = 0;

            if (flag_B == 0) {
                B.deQueue(bData);
                if (i1 == 1 && neglu1 != neglu2) bData = bData * (-1);
            } else bData = 0;
            tmp_result = aData + bData + tmp;
            tmp = 0;
            if (A.QueueisEmpty()) flag_A = 1;
            if (B.QueueisEmpty()) flag_B = 1;
            if (tmp_result >= 10000 && (flag_A == 0 || flag_B == 0)) {
                tmp = 1;
                tmp_result = tmp_result - 10000;
            }
            if (tmp_result < 0 && (flag_A == 0 || flag_B == 0)) {
                tmp = -1;
                tmp_result = tmp_result + 10000;
            }


            if (flag_A == 0 || flag_B == 0) {
                result.insert(0, fun(tmp_result, num));
            } else {
                if (tmp_result == 0 && result != "") result.insert(0, "");
                else {
                    result.insert(0, ",");
                    if (tmp_result >= 10000) {
                        tmp_result = tmp_result - 10000;
                        int num1 = 0;
                        string tt = fun(tmp_result, num1);
                        tt += result;
                        result = tt;
                        result.insert(0, "1,");
                    } else {
                        itoa(tmp_result, rs);
                        result.insert(0, rs);
                    }
                }
            }
        }
    }

    if (flag1 == 1) result.insert(0, "-");
    if (result.substr(result.length() - 1, result.length()) == ",") result = result.substr(0, result.size() - 1);
    cout << endl << result;
}

tmpl
bool QueueTraverse_Reverse(LinkQueue<ElemType> &linkQueue, string &string1) {
    QNode *front;
    int temp;
    front = linkQueue.GetFront();
    int num = 0;
    if (front->data == -1) cout << "-";
    front = front->next;
    while (front != NULL) {
        temp = front->data;
        if (front->next) string1.insert(0, fun(temp, num));
        else {
            stringstream ss;
            if (num > 0) ss << temp << ",";
            else ss << temp;
            string1.insert(0, ss.str());
        }
        front = front->next;
    }
    return true;
}

int main() {
    LinkQueue<int> in1, in2;
    string s1, s2;
    string res;
    getline(cin, s1);
    getline(cin, s2);
    insCalculate(in1, s1);
    insCalculate(in2, s2);
    QueueTraverse_Reverse(in1, res);
    cout << res << endl;
    res = "";
    QueueTraverse_Reverse(in2, res);
    cout << res << endl;
    res = "";
    addLongInt(in1, in2, res, s1, s2);
    return 0;
}