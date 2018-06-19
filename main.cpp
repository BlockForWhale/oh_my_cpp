#include <bits/stdc++.h>

using namespace std;

#define tab '\t'

class Array {
private:
    int **array;
public:
    Array(int **t, int m, int n) {//构造函数，用二阶指针t初始化二阶指针array关联访问的成员数组，m和n分别对应二维数组的行数、列数
        array = new int *[m];
        for (int i = 0; i < m; i++) {
            array[i] = new int[n];
            for (int j = 0; j < n; j++)
                array[i][j] = t[i][j];
        }
    }

    int comp(int n) {//判断整数n是否为合数，如果是合数，返回值为1，否则返回值为0
        for (int i = 2; i < n; i++)
            if (n % i == 0) return 1;
        return 0;
    }

    int sum_comp(int j) {//求数组a第j列元素中所有合数之和
        int result = 0;
        for (int i = 0; i < 4; i++) {
            if (comp(array[i][j]) == 1) result += array[i][j];
        }
        return result;
    }

    void exch(int j1, int j2) {//交换成员数组的第j1, j2列元素
        for (int i = 0; i < 4; i++) {
            int temp = array[i][j1];
            array[i][j1] = array[i][j2];
            array[i][j2] = temp;
        }
    }

    void fun(int m, int n) {//根据题意对成员数组进行列排序，m和n分别对应二维数组的行数、列数
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sum_comp(j) > sum_comp(i)) exch(i, j);
            }
        }
    }

    void print(int m, int n) {//以矩阵的形式输出成员数组，m和n分别对应二维数组的行数、列数
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << array[i][j] << tab;
            }
            cout << endl;
        }
    }


};

bool make2DArray(int row, int col, int **&array);

bool InputEdge(int row, int col, int **&array) {
    if (make2DArray(row, col, array)) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> array[i][j];
            }
        }
    }
    return true;
}

bool make2DArray(int row, int col, int **&array) {
    array = new int *[row];
    for (int i = 0; i < row; i++) {
        array[i] = new int[col];
    }
    return true;
}

int main() {
    int **array;   //二阶指针，用于关联访问二维数组
    int m, n;  //m：行数 n：列数
    cin >> m; //输入行数
    cin >> n; //输入列数
    InputEdge(m, n, array); //在申请指定行、列的二维数组的存储空间成功的基础上，针对该二维数组进行初始化
    Array arr(array, m, n);
    arr.fun(m, n);
    arr.print(m, n); //输出排序后的数组
    return 0;

}
