#include <bits/stdc++.h>

using namespace std;

template<class ElemType>
class SqList {
private:
    ElemType *elem;   // 存储空间基址
    int length = 0;               // 当前长度
    int listsize;        // 允许的最大存储容量(以sizeof(ElemType)为单位
public:
    SqList(int maxsize = 20);

    //删除顺序表
    ~SqList() { delete[] elem; }

    //将顺序表置为空表
    void ListClear() { length = 0; }

    //返回顺序表的长度
    int getLength() const { return length; }

    void setLength(int len) { length = len; }

    //在顺序表的第pos个位置之前插入e元素
    bool ListInsert(int pos, ElemType e);

    //逆置顺序表
    void Invert(int, int);

    //遍历顺序表
    int ListTraverse() const;
};

template<class ElemType>
void SqList<ElemType>::Invert(int a, int b) {
    ElemType w;
    for (int i = a; i <= (a + b) / 2; i++) {
        w = elem[i];
        elem[i] = elem[b - i + a];
        elem[b - i + a] = w;
    }
}

template<class ElemType>
bool SqList<ElemType>::ListInsert(int pos, ElemType s) {
    //cout << "Inserting " << s << " into pos:" << pos << ", len=" << length << endl;
    for (int i = length - 1; i >= pos - 1; i--) elem[i + 1] = elem[i];
    elem[pos - 1] = s;
    length += 1;
    return true;
}

template<class ElemType>
SqList<ElemType>::SqList(int ms) {
    if (ms == 0) ms = 10;
    elem = new ElemType[ms];
    listsize = ms;
    length = 0;
}

template<class ElemType>
void createList(SqList<ElemType> &list, int len, ElemType data[]) {
    //cout << "Creating list..." << "len is " << len << endl;
    for (int i = 0; i < len; i++) list.ListInsert(i + 1, data[i]);
}

template<class ElemType>
int SqList<ElemType>::ListTraverse() const {
    //cout << "Current len :" << length << endl;
    for (int i = 0; i < length; i++) {
        cout << *(elem + i) << " ";
    }
    cout << endl;
    return 1;
}

template<class ElemType>
void exchange(SqList<ElemType> &list, int pos) {
    int n;
    if (pos > 0 && pos < list.getLength()) {
        n = list.getLength() - pos;
        list.Invert(0, pos - 1 + n);
        list.Invert(0, n - 1);
        list.Invert(n, pos + n - 1);
    }
}

int main() {
    int len, reverse_pos;
    SqList<int> list;
    cin >> len;
    int obj[len];
    for (int i = 0; i < len; i++) cin >> obj[i];
    list.ListClear();
    createList(list, len, obj);
    list.ListTraverse();
    cin >> reverse_pos;
    exchange(list, reverse_pos);
    list.ListTraverse();
    return 0;
}
