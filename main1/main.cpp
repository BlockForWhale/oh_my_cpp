#include <iostream>

using namespace std;

#define tmp template<class ElemType>
#define Node LinkNode<ElemType>

tmp
struct LinkNode {
    ElemType data;
    Node *next;

    LinkNode(Node *ptr = NULL) { next = ptr; }

    LinkNode(const ElemType &item, Node *ptr = NULL) {
        next = ptr;
        data = item;
    }
};

//带头结点的单链表
tmp
class LinkList {
private:
    Node *head;
public:
    //无参数的构造函数
    LinkList() { head = new Node; }

    //带参数的构造函数
    LinkList(const ElemType &item) { head = new Node(item); }

    //获取链表头结点
    Node *GetHead() const { return head; }

    void CreateList_Head(int n, ElemType *m);

    bool ListTraverse() const;
};

tmp
void LinkList<ElemType>::CreateList_Head(int n, ElemType *m) {
    Node *p;
    for (int i = n; i > 0; i--) {
        p = new Node;
        p->data = m[i - 1];
        p->next = head->next;
        head->next = p;
    }
}

tmp
bool LinkList<ElemType>::ListTraverse() const {
    Node *next_node;
    next_node = head->next;
    while (next_node) {
        cout << next_node->data << " ";
        next_node = next_node->next;
    }
    cout << endl;
    return true;
}

tmp
void Exchange_L(LinkList<ElemType> &list, int m) {
    Node *head_node;
    Node *point, *real_next, *q;
    int k = 1;
    head_node = list.GetHead();
    if (head_node->next != NULL && m != 0) {
        point = head_node->next;
        while (point != NULL && k < m) { // 查找am所在结点
            point = point->next;
            k++;
        }
        if (point && point->next) {
            real_next = head_node->next;
            head_node->next = point->next;
            point->next = NULL;
            q = head_node->next;
            while (q->next)
                q = q->next;
            q->next = real_next;
        }
    }
}

int main() {
    int i, n;
    LinkList<int> node_list;
    cin >> n;//length
    int array_list[n];
    for (i = 0; i < n; i++) cin >> array_list[i];
    node_list.CreateList_Head(n, array_list);
    node_list.ListTraverse();
    int asd;
    cin >> asd;
    Exchange_L(node_list, asd);
    node_list.ListTraverse();
    return 0;
}