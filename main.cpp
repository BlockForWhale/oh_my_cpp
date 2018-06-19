#include <bits/stdc++.h>

using namespace std;

class Student {
public:
    void Set_StuNum(int x) {
        stu_num = x;
    } //自行设计

    int Get_StudNum() {
        return stu_num;
    }  //自行设计

    void Set_Score(float x) {
        score = x;
    } //自行设计

    float Get_Score() {
        return score;
    }  //自行设计
private:
    int stu_num; //学号
    float score; //分数
};

void max(Student *list, int count, int &max_num, float &max_score) {
    max_score = -2147483647;
    for (int i = 0; i < count; i++) {
        if (list[i].Get_Score() > max_score) {
            max_num = list[i].Get_StudNum();
            max_score = list[i].Get_Score();
        }
    }
}

int main() {
    int n, stu_num, max_stu_num;
    float score, max_score;
    cin >> n;
    Student stu[n];
    for (int i = 0; i < n; i++) {
        cin >> stu_num >> score;
        stu[i].Set_StuNum(stu_num);
        stu[i].Set_Score(score);
    }
    max(stu, n, max_stu_num, max_score);
    cout << max_stu_num << " " << max_score;
    return 0;
}