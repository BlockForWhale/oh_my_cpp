#include <bits/stdc++.h>

using namespace std;

class Box {
private:
    int Length;
    int Width;
    int Height;
    int V;
    int S;
public:
    void initBox(int x, int y, int z) {//设置Box的尺寸
        Length = x;
        Width = y;
        Height = z;
    }

    void setVolume() {//计算Box的体积
        V = Length * Width * Height;
    }

    void setArea() { //计算Box的表面积
        S = Length * Width * 2 + Length * Height * 2 + Width * Height * 2;
    }

    void show() {//输出盒子的信息，输出形式见“输出说明”
        cout << Length << ' ' << Width << ' ' << Height << endl << V << endl << S << endl;
    }
};

int main() {
    int intLength, intWidth, intHeight;
    Box box;
    cin >> intLength;
    cin >> intWidth;
    cin >> intHeight;
    box.initBox(intLength, intWidth, intHeight);
    box.setVolume();
    box.setArea();
    box.show();
    return 0;
}