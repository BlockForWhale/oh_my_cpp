#include <iostream>

using namespace std;

#define tmpl template<class ElemType>
#define FARMER 8
#define GOAT 1
#define CABBAGE 2
#define WOLF 4

tmpl
class SqQueue {
private:
    ElemType *elem;
    int front;
    int rear;
    int maxSize;
public:
    SqQueue(int m = 20);

    bool QueueClear();

    bool QueueisEmpty() const { return front == rear; }

    bool QueueFull() const;

    bool GetFront(ElemType &e);

    bool enQueue(const ElemType &e);

    bool deQueue(ElemType &e);

    bool QueueDestroy();

    bool DoubleSpace();
};

tmpl
SqQueue<ElemType>::SqQueue(int m) {
    if (m == 0) m = 100;
    elem = new ElemType[m];
    if (!elem) return;
    rear = 0;
    front = rear;
    maxSize = m;
}

tmpl
bool SqQueue<ElemType>::GetFront(ElemType &e) {

    if (front == rear) return false;
    e = elem[(front + 1) % maxSize];
    return true;
}

tmpl
bool SqQueue<ElemType>::DoubleSpace() {
    ElemType *tmp;
    tmp = elem;
    elem = new ElemType[maxSize * 2];
    if (!elem) return false;
    for (int i = 0; i < maxSize; i++) elem[i] = tmp[(front + i) % maxSize];
    front = 0;
    rear = maxSize;
    maxSize = maxSize * 2;
    delete[]tmp;
    return true;
}

tmpl
bool SqQueue<ElemType>::enQueue(const ElemType &e) {
    if ((rear + 1) % maxSize == front) DoubleSpace();
    rear = (rear + 1) % maxSize;
    elem[rear] = e;
    return true;
}


tmpl
bool SqQueue<ElemType>::deQueue(ElemType &e) {
    if (front == rear) return false;
    front = (front + 1) % maxSize;
    e = elem[front];
    return true;
}

template<class ElemType>
void decode(SqQueue<ElemType> &S, string &code) {
    int len = code.size();
    int i = 1, j;
    char c;
    ElemType e;


    for (int i = 0; i < len; i++) {
        if (code[i] == ' ') continue;
        S.enQueue(code[i]);
    }

    while (!S.QueueisEmpty()) {
        S.deQueue(e);
        cout << e;
        if (!S.QueueisEmpty()) {
            S.deQueue(e);
            S.enQueue(e);
        }
    }
}

int main() {
    SqQueue<char> su;
    string s;
    getline(cin, s);
    decode(su, s);
    return 0;
}

