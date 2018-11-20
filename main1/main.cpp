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

tmp
void Merge_L(LinkList<ElemType> &A, LinkList<ElemType> &B) {
    Node *real_next1, *real_next2, *node_tmp, *node_tmp2 = NULL;
    real_next1 = A.GetHead()->next;
    real_next2 = B.GetHead()->next;
    while (real_next2 && real_next1) {
        node_tmp = real_next1->next;
        real_next1->next = real_next2;
        if (node_tmp) {
            node_tmp2 = real_next2->next;
            real_next2->next = node_tmp;
        }
        real_next1 = node_tmp;
        real_next2 = node_tmp2;
    }
}

tmp
void Merge_L_Order(LinkList<ElemType> &A, LinkList<ElemType> &B) {
    Node *real_next1, *real_next2, *node_tmp = NULL;
    real_next1 = A.GetHead()->next;
    real_next2 = B.GetHead()->next;
    node_tmp = A.GetHead();
    while (real_next2 && real_next1) {
        if (real_next1->data <= real_next2->data) {
            node_tmp->next = real_next1;
            node_tmp = real_next1;
            real_next1 = real_next1->next;
        } else {
            node_tmp->next = real_next2;
            node_tmp = real_next2;
            real_next2 = real_next2->next;
        }
    }
    if (real_next1) node_tmp->next = real_next1;
    else node_tmp->next = real_next2;
}

tmp
void Purge_Lk_OL(LinkList<ElemType> &A) {
    Node *head;
    head = A.GetHead();
    int k = 0;
    while (head->next) {
        if (k == 0) {
            head = head->next;
            k++;
        } else {
            if (head->data != head->next->data) head = head->next;
            else head->next = head->next->next;
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
    Purge_Lk_OL(node_list1);
    node_list1.ListTraverse();
    return 0;
}