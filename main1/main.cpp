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
    LinkNode<ElemType> *head;   // 头结点
public:
    //无参数的构造函数
    LinkList() { head = new LinkNode<ElemType>; }

    //带参数的构造函数
    LinkList(const ElemType &item) { head = new LinkNode<ElemType>(item); }

    LinkNode<ElemType> *GetHead() const { return head; }

    void CreateList_Head(int n, ElemType *A);

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
void Linklist_Contact(LinkList<ElemType> &A, LinkList<ElemType> &B) {
    Node *next;
    next = A.GetHead();
    while (true) {
        next = next->next;
        if (next->next == NULL) {
            next->next = B.GetHead()->next;
            break;
        }
    }
}

int main() {
    int i, n1, n2;
    LinkList<int> node_list1, node_list2;
    cin >> n1;//length
    int array_list1[n1];
    for (i = 0; i < n1; i++) cin >> array_list1[i];
    node_list1.CreateList_Head(n1, array_list1);
    node_list1.ListTraverse();
    cin >> n2;//length
    int array_list2[n2];
    for (i = 0; i < n2; i++) cin >> array_list2[i];
    node_list2.CreateList_Head(n2, array_list2);
    node_list2.ListTraverse();
    Linklist_Contact(node_list1, node_list2);
    node_list1.ListTraverse();
    return 0;
}