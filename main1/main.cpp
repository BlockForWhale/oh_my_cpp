#include <iostream>

using namespace std;

#define tmp template<class ElemType>
#define Node LinkNode<ElemType>

template<class ElemType>
struct LinkNode {
    ElemType data;
    LinkNode<ElemType> *next;

    LinkNode(LinkNode<ElemType> *ptr = NULL) { next = ptr; } //构造函数1，用于构造头结点
    LinkNode(const ElemType &item, LinkNode<ElemType> *ptr = NULL) {
        next = ptr;
        data = item;
    }

    ElemType getData() { return data; }   //取得结点的数据域的值
    void SetLink(LinkNode<ElemType> *link) { next = link; }  //修改结点的next域
    void SetLink(ElemType value) { data = value; }   //修改结点的next域
};

//带头结点的循环单链表
tmp
class CirLinkList {
private:
    LinkNode<ElemType> *head;   // 头结点
    LinkNode<ElemType> *tail;   // 尾结点
    //LinkNode<ElemType> *cur;   // 当前结点
public:
    //无参数的构造函数
    CirLinkList() {
        head = new LinkNode<ElemType>;
        tail = head;
        head->next = head;
    }

    //带参数的构造函数
    CirLinkList(const ElemType &item) {
        head = new LinkNode<ElemType>(item);
        tail = head;
        head->next = head;
    }

    //拷贝构造函数
    CirLinkList(CirLinkList<ElemType> &List);

    //在首节点之前插入一个结点
    //bool InsFirst( ElemType e );
    //获取循环链表头结点
    LinkNode<ElemType> *GetHead() { return head; }

    //获取循环链表尾结点
    LinkNode<ElemType> *GetTail() { return tail; }

    //设置链表头结点
    void SetHead(LinkNode<ElemType> *p) { head = p; }

    //表尾插入法动态生成链表
    void CreateList_Tail(int n, ElemType *A);

    bool ListTraverse() const;
};

tmp
bool CirLinkList<ElemType>::ListTraverse() const {
    Node *p;
    p = head->next;
    while (p != head) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
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

int main() {
    int n1, n2;
    CirLinkList<int> list1, list2;
    cin >> n1;
    int array_list1[n1];
    for (int i = 0; i < n1; i++) cin >> array_list1[i];
    list1.CreateList_Tail(n1, array_list1);
    cin >> n2;
    int array_list2[n2];
    for (int i = 0; i < n2; i++) cin >> array_list2[i];
    list2.CreateList_Tail(n2, array_list2);

    Merge_Cur_Linklist(list1, list2);
    list1.ListTraverse();
    return 0;
}