#include <bits/stdc++.h>

using namespace std;

class Student {
public:
    void Set_StuNum(int); //自行设计
    int Get_StudNum();  //自行设计
    void Set_Score(float); //自行设计
    float Get_Score();  //自行设计
    friend void Score_Trans(Student &s);

private:
    int stu_num; //学号
    float score; //分数
};

void Student::Set_StuNum(int x) { stu_num = x; }

int Student::Get_StudNum() { return stu_num; }

void Student::Set_Score(float x) { score = x; }

float Student::Get_Score() { return score; }

void Score_Trans(Student &s) {
    cout << s.stu_num << ' ';
    cout << (s.score >= 90 ? "优" : (s.score >= 80 ? "良" : (s.score >= 70 ? "中" : (s.score >= 60 ? "及格" : "不及格"))));
}

int main() {
    int n, i, stu_num, max_stu_num;
    float score, max_score;
    cin >> n;
    Student stu[n];
    for (i = 0; i < n; i++) {
        cin >> stu_num >> score;
        stu[i].Set_StuNum(stu_num);
        stu[i].Set_Score(score);
    }
    for (i = 0; i < n; i++) {
        Score_Trans(stu[i]);
        if (i < n - 1) cout << endl;
    }
    return 0;
}