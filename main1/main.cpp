#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define tmp template<class ElemType1, class ElemType2>
#define Node LinkNode<ElemType1, ElemType2>
#define E1 ElemType1
#define E2 ElemType2

/* 单链表的结点定义 */
template<class ElemType1, class ElemType2>
struct LinkNode {
    ElemType1 factor; //系数
    ElemType2 indice;  //指数
    Node *next;

    LinkNode(Node *ptr = NULL) { next = ptr; } //构造函数1，用于构造头结点
    LinkNode(const ElemType1 &item1, const ElemType1 &item2,
             Node *ptr = NULL) //构造函数2，用于构造其他结点
    //函数参数表中的形参允许有默认值，但是带默认值的参数需要放后面
    {
        next = ptr;
        factor = item1;
        indice = item2;
    }

    ElemType1 getFactor() { return factor; }

    ElemType2 getIndice() { return indice; }

    void SetLink(Node *link) { next = link; }  //修改结点的next域
    void SetFactor(ElemType1 value) { factor = value; }   //修改结点的系数
    void SetIndice(ElemType2 value) { indice = value; }   //修改结点的指数
};

//带头结点的单链表（用于一元多项式计算）
template<class ElemType1, class ElemType2>
class poly_LinkList {
private:
    Node *head;   // 头结点
    Node *tail;   // 尾结点
public:
    //无参数的构造函数
    poly_LinkList() { head = new Node; }

    //带参数的构造函数
    poly_LinkList(const ElemType1 &item1, const ElemType2 &item2) {
        head = new Node(item1, item2);
    }

    //拷贝构造函数
    poly_LinkList(poly_LinkList<ElemType1, ElemType2> &List);

    //获取链表头结点
    Node *GetHead() { return head; }

    //设置链表头结点
    void SetHead(Node *p) { head = p; }

    //获取链表尾结点
    Node *GetTail() { return tail; }

    void CreateList_Tail(int n, ElemType1 *fact, ElemType2 *indi);

    bool ListTraverse() const;
};

template<class ElemType1, class ElemType2>
bool poly_LinkList<ElemType1, ElemType2>::ListTraverse() const {
    Node *p;
    p = head->next;
    while (p) {
        cout << p->factor << " " << p->indice << endl;
        p = p->next;
    }
    cout << endl;
    return true;
}

//表尾插入动态生成链表
template<class ElemType1, class ElemType2>
void poly_LinkList<ElemType1, ElemType2>::CreateList_Tail(int n, ElemType1 *fact, ElemType2 *indi) {
    Node *r;

    r = head;

    Node *p;

    for (int i = 0; i < n; i++) {
        p = new Node;
        p->factor = fact[i];
        p->indice = indi[i];

        r->next = p;
        r = p;
    }
    r->next = NULL;
    tail = r;
    this->ListTraverse();
}


template<class ElemType1, class ElemType2>
void Add_Poly(poly_LinkList<ElemType1, ElemType2> &list1, poly_LinkList<ElemType1, ElemType2> &list2, int add_sub) {
    Node *a, *b, *c, *d, *no_tmp;

    a = list1.GetHead();
    b = list2.GetHead();
    d = a;
    c = b;
    a = a->next;
    b = b->next;

    while (a && b) {
        if (a->indice == b->indice) {
            if (add_sub == 0) a->factor = a->factor + b->factor;
            if (add_sub == 1) a->factor = a->factor - b->factor;
            if (a->factor == 0) {
                no_tmp = a;
                a = a->next;
                delete no_tmp;
            } else d->next = a;
            b = b->next;
        } else if (a->indice < b->indice) {
            d->next = a;
            d = a;
            a = a->next;
        } else {
            d->next = b;
            d = b;
            b = b->next;
        }
    }

    if (a) {
        d->next = a;
    } else {
        d->next = b;
    }
    c->next = NULL;
}

int main() {
    poly_LinkList<int, int> list1, list2;
    int e, len1;
    cin >> e >> len1;
    int fa1[len1], in1[len1];
    for (int i = 0; i < len1; i++) cin >> fa1[i];
    for (int i = 0; i < len1; i++) cin >> in1[i];
    int len2;
    cin >> len2;
    int fa2[len2], in2[len2];
    for (int i = 0; i < len2; i++) cin >> fa2[i];
    for (int i = 0; i < len2; i++) cin >> in2[i];
    list1.CreateList_Tail(len1, fa1, in1);
    list2.CreateList_Tail(len2, fa2, in2);
    Add_Poly(list1, list2, e);
    list1.ListTraverse();
    return 0;
}