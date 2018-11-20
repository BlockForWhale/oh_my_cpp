#include<iostream>

using namespace std;

#define tmpl template<class ElemType>

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

tmpl
void tri(SqQueue<ElemType> &sq, int nat) {
    int a, x;
    sq.enQueue(1);
    for (int n = 2; n <= nat + 1; n++) {
        sq.enQueue(1);
        for (int i = 1; i <= n - 2; i++) {
            sq.deQueue(a);
            cout << a << " ";
            sq.GetFront(x);
            a = a + x;
            sq.enQueue(a);
        }
        sq.deQueue(x);
        if (n == nat + 1) cout << x;
        else cout << x << endl;
        sq.enQueue(1);
    }
}

int main() {
    int n;
    SqQueue<int> su;
    cin >> n;
    tri(su, n);
    return 0;
}