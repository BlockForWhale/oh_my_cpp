#include <iostream>
#include <bitset>

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

int goat(int st) { return (st & GOAT) != 0; }

int cabbage(int st) { return (st & CABBAGE) != 0; }

int wolf(int st) { return (st & WOLF) != 0; }

int farmer(int st) { return (st & FARMER) != 0; }

int isSafe(int st) {
    return (goat(st) == cabbage(st)) && (goat(st) != farmer(st)) ? 0 : (goat(st) == wolf(st)) &&
                                                                       (goat(st) != farmer(st)) ? 0 : 1;
}

tmpl
void tri(SqQueue<ElemType> &sq) {
    int pm, st, nn;
    int ro[16];

    sq.enQueue(0x00);

    for (int i = 0; i < 16; i++) ro[i] = -1;

    ro[0] = 0;

    while (!sq.QueueisEmpty() && (ro[15] == -1)) {
        sq.deQueue(st);
        for (pm = 1; pm <= 8; pm <<= 1) {
            if (farmer(st) == (0 != (st & pm))) {
                nn = st ^ (8 | pm);
                if (ro[nn] == -1 && isSafe(nn)) {
                    ro[nn] = st;
                    sq.enQueue(nn);
                }
            }
        }
    }
    if (ro[15] != -1) {
        for (st = 15; st >= 0; st = ro[st]) {
            bitset<4> bs(st);
            if (st > 0) cout << bs << endl;
            else cout << bs;
            if (st == 0) break;
        }
    } else {
        cout << "No Solution";
    }
}

int main() {
    SqQueue<int> su;
    tri(su);
    return 0;
}

