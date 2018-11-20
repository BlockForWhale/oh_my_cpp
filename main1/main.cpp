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
    front->next = p->next;  // 修改头结点指针
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

int main() {
    LinkQueue<int> mine;
    int num, c;
    cin >> num >> c;
    queuetraining(mine, num, c);
    return 0;
}