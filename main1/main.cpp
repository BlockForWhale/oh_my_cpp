#include <iostream>

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

    bool LinkQueueDestroy();

    bool LinkQueueClear();

    int QueueLength() const { return length; }

    bool QueueisEmpty() const;

    bool deQueue(ElemType &e);

    bool enQueue(ElemType e);

    QNode *GetFront() { return front; }

    ElemType GetFrontData() { return front->data; }

    QNode *GetRear() { return rear; }

    bool QueueTraverse() const;
};



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
    length = length + 1;
    return true;
}

tmpl
void queuetraining(LinkQueue<ElemType> &lq, int im) {
    int num;
    int la, mine1;
    int n;
    while (im--) {
        cin >> n;
        la = n;
        mine1 = n;
        if (n <= 3) {
            if (n == 1)
                cout << "1";
            if (n == 2)
                cout << "1,2";
            if (n == 3)
                cout << "1,2,3";
        } else {
            for (int i = 1; i <= n; i++) lq.enQueue(i);
            while (la > 3) {
                for (int i = 1; i <= la; i++) {
                    lq.deQueue(num);
                    if (i % 2 == 1) {
                        lq.enQueue(num);
                    } else --mine1;
                }
                la = mine1;
                if (la > 3) {
                    for (int i = 1; i <= la; i++) {
                        lq.deQueue(num);
                        if (i % 3 != 0) {
                            lq.enQueue(num);
                        } else mine1--;
                    }
                    la = mine1;
                }
            }
            while (!lq.QueueisEmpty()) {
                lq.deQueue(num);
                if (!lq.QueueisEmpty()) cout << num << ",";
                else cout << num;
            }
            if (im > 0) cout << endl;
        }
    }
}

int main() {
    LinkQueue<int> mine;
    int num;
    cin >> num;
    queuetraining(mine, num);
    return 0;
}