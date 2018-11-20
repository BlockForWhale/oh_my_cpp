#include <iostream>

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

    ElemType getElem(int i) const;

    //返回顺序表的长度
    int getLength() const { return length; }

    void setLength(int len) { length = len; }

    //在顺序表的第pos个位置之前插入e元素
    bool ListInsert(int pos, ElemType e);

    //遍历顺序表
    int ListTraverse() const;
};

template<class ElemType>
ElemType SqList<ElemType>::getElem(int i) const {
    return elem[i];
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
int listCompare(SqList<ElemType> &a, SqList<ElemType> &b) {
    int min_len = a.getLength() > b.getLength() ? b.getLength() : a.getLength();
    for (int i = 0; i < min_len; ++i) {
        if (a.getElem(i) > b.getElem(i)) return 1;
        else if (a.getElem(i) < b.getElem(i)) return -1;
        else continue;
    }
    return 0;
}

int main() {
    int len1, len2;
    SqList<int> list_1, list_2;
    cin >> len1;
    int obj1[len1];
    for (int i = 0; i < len1; i++) cin >> obj1[i];
    list_1.ListClear();
    createList(list_1, len1, obj1);
    list_1.ListTraverse();
    cin >> len2;
    int obj2[len2];
    for (int i = 0; i < len2; i++) cin >> obj2[i];
    list_2.ListClear();
    createList(list_2, len2, obj2);
    list_2.ListTraverse();
    cout << listCompare(list_1, list_2) << endl;
    return 0;
}
