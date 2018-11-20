#include <iostream>

using namespace std;

#define INT32_MAX 2147483647

template<class ElemType>
class SqList {
private:
    ElemType *elem;   // 存储空间基址
    int length;               // 当前长度
    int listsize;        // 允许的最大存储容量(以sizeof(ElemType)为单位
public:
    SqList(int maxsize = 20);

    //删除顺序表
    ~SqList() { delete[] elem; }

    //将顺序表置为空表
    void ListClear() { length = 0; }

    ElemType getElem(int i) const;

    bool setElem(int i, ElemType e);

    //返回顺序表的长度
    int getLength() const { return length; }

    void setLength(int len) { length = len; }

    //在顺序表的第pos个位置之前插入e元素
    bool ListInsert(int pos, ElemType e);

    //删除顺序表的第pos个位置的元素
    bool ListDelete(int pos);

    //遍历顺序表
    int ListTraverse() const;
};

template<class ElemType>
ElemType SqList<ElemType>::getElem(int i) const {
    return elem[i];
}

template<class ElemType>
bool SqList<ElemType>::setElem(int i, ElemType e) {
    elem[i] = e;
    return true;
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
bool SqList<ElemType>::ListDelete(int pos) {
    for (int i = pos; i < length - 1; i++) {
        elem[i] = elem[i + 1];
    }
    length--;
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
void Purge_Sq_OL(SqList<ElemType> &list) {
    for (int i = 0; i < list.getLength() - 1; i++) {
        for (int j = i + 1; j < list.getLength(); j++) {
            if (list.getElem(i) == list.getElem(j) && list.getElem(i) != INT32_MAX) {
                list.setElem(j, INT32_MAX);
            }
        }
    }
    int i = 0;
    while (i < list.getLength()) {
        if (list.getElem(i) == INT32_MAX) list.ListDelete(i);
        else i++;
    }
}

template<class ElemType>
void Intersect_Sq_OL_C(const SqList<ElemType> &A, const SqList<ElemType> &B, SqList<ElemType> &C) {
    int i = 0, j = 0, k = 0;
    while (i < A.getLength() || j < B.getLength()) {
        if (A.getElem(i) < B.getElem(j))
            i++;
        else if (A.getElem(i) > B.getElem(j))
            j++;
        else if (A.getElem(i) == B.getElem(j))
            k++, C.ListInsert(k, A.getElem(i)), i++, j++;
    }
}

template<class ElemType>
void Search_Pairs(SqList<ElemType> &A, int sum) {
    int qp, asd, we, iop;
    int temp1, temp2;
    ElemType t;
    qp = 0;
    asd = A.getLength() - 1;
    A.getElem(qp);
    iop = 0;
    while (qp < asd) {
        temp1 = A.getElem(qp);
        temp2 = A.getElem(asd);
        we = temp1 + temp2;
        if (we == sum) {
            iop = 1;
            cout << temp1 << "," << temp2;
            ++qp;
            --asd;
            if (qp < asd) cout << endl;
        }
        if (we < sum) ++qp;
        if (we > sum) --asd;
    }
    if (iop == 0) cout << "NULL";
}

int main() {
    SqList<int> sqlist;
    int i, n, s;
    cin >> n;
    int array[n];
    for (i = 0; i < n; i++) cin >> array[i];
    cin >> s;
    createList(sqlist, n, array);
    sqlist.ListTraverse();
    Search_Pairs(sqlist, s);
    return 0;
}
