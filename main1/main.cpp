#include <iostream>

using namespace std;

#define tmp template<class ElemType>
#define Node LinkNode<ElemType>

struct node {
    int number;
    int code;
};

template<class ElemType>
struct LinkNode {
    ElemType data;
    Node *next;

    LinkNode(Node *ptr = NULL) { next = ptr; }

    LinkNode(const ElemType &item, Node *ptr = NULL) {
        next = ptr;
        data = item;
    }

    ElemType getData() { return data; }

    void SetLink(Node *link) { next = link; }

    void SetLink(ElemType value) { data = value; }
};


tmp
class CirLinkList {
private:
    Node *head;
    Node *tail;

public:

    CirLinkList() {
        head = new Node;
        tail = head;
        head->next = head;
    }


    CirLinkList(const ElemType &item) {
        head = new Node(item);
        tail = head;
        head->next = head;
    }

    CirLinkList(CirLinkList<ElemType> &List);

    Node *GetHead() { return head; }


    Node *GetTail() { return tail; }

    int ListLength() const;


    void SetHead(Node *p) { head = p; }


    void CreateList_Tail(int n, ElemType *A);

    bool ListTraverse() const;
};

tmp
bool CirLinkList<ElemType>::ListTraverse() const {
    Node *p;
    p = head->next;
    while (p != head) {
        cout << p->data.number << " " << p->data.code << endl;
        p = p->next;
    }
    return true;
}

tmp
void CirLinkList<ElemType>::CreateList_Tail(int n, ElemType *A) {
    Node *node, *tmp_node;
    node = head;

    for (int i = 0; i < n; i++) {
        tmp_node = new Node;
        tmp_node->data = A[i];

        node->next = tmp_node;
        node = tmp_node;
    }
    node->next = head;
    tail = node;
    this->ListTraverse();
}

tmp
void Merge_Cur_Linklist(CirLinkList<ElemType> &A, CirLinkList<ElemType> &B) {
    Node *ah, *at, *bh, *bt;
    ah = A.GetHead();
    bh = B.GetHead();
    at = A.GetTail();
    bt = B.GetTail();
    if (bh->next != bh) {
        at->next = bh->next;
        bt->next = ah;
        bh->next = bh;
    }
}

tmp
int CirLinkList<ElemType>::ListLength() const {
    int length = 0;
    Node *p;
    p = head->next;
    if (p == head) return 0;
    while (p != head) {
        length++;
        p = p->next;
    }
    return length;
}

tmp
void Joseph(CirLinkList<ElemType> &A, int m) {
    Node *aao, *hbj, *hfdsf, *hhsgdfdsfsdfdsf;
    ElemType cur_node;
    int length = A.ListLength();
    hhsgdfdsfsdfdsf = A.GetHead();
    aao = hhsgdfdsfsdfdsf;
    hbj = hhsgdfdsfsdfdsf->next;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < m - 1; j++) {
            aao = hbj;
            hbj = hbj->next;
            if (hbj == hhsgdfdsfsdfdsf) {
                aao = hhsgdfdsfsdfdsf;
                hbj = hbj->next;
            }
        }
        cur_node = hbj->getData();
        m = cur_node.code;
        if (i < length - 1)
            cout << cur_node.number << "->";
        else
            cout << cur_node.number;
        hfdsf = hbj;
        hbj = hbj->next;
        aao->next = hbj;
        delete (hfdsf);
        if (hbj == hhsgdfdsfsdfdsf) {
            aao = hhsgdfdsfsdfdsf;
            hbj = hbj->next;
        }
    }
}

int main() {
    int i, n, m, num;
    CirLinkList<node> A;
    LinkNode<node> *cur_p, *temp_p, *head;
    cin >> n;
    node Input[n], ttt;
    for (i = 0; i < n; i++) {
        Input[i].number = i + 1;
        cin >> Input[i].code;
    }
    cin >> m;
    A.CreateList_Tail(n, Input);
    cout << endl;
    head = A.GetHead();
    Joseph(A, m);
    return 0;
}