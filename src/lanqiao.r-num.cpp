#include <iostream>
#include <vector>
#include <string>
using namespace std;

//进位逻辑
void check(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == -1) {
            continue;
        }
        while (v[i] > 9) {
            if (i == v.size() - 1) {
                //如果数组到了最高位仍需进位，则需要对数组进行扩大
                v.resize(v.size() * 2);
            }
            if (i+2 >= 0 && v[i+1] == -1) v[i+2] += v[i] / 10;  //下一位是"."时
            else v[i+1] += v[i] / 10;
            v[i] %= 10;
        }
    }
}
//将数组的每一位乘以2
void mult2(vector<int>& v) {
    for (auto& i : v) {
        if (i == -1) continue;
        i *= 2;
    }
}
int main() {
    int n;
    string d;
    cin >> n >> d;
    vector<int> v(d.size());
    //倒序转化数组  （倒序可以让后续的进位计算变为正序，便于数组直接进行resize()扩大）
    for (int i = d.size()-1; i >= 0; --i) {
        if (d[i] == '.') {
            v[v.size()-1-i] = -1;   //使用-1作为".",原本想使用NULL的，但C++中NULL==0
        }
        else v[v.size()-1-i] = d[i] - '0';
    }
    //乘以n次2,就是乘以2的n次方
    for (int i=0;i<n;++i) {
        mult2(v); //每一位都乘上2
        check(v); //进行手动进位
    }
    //四舍五入
    for (int i = v.size() - 1; i >= 0; --i) {
        if (v[i] == -1 && v[i-1] >= 5) {
            v[i+1] += 1;  //五入
            check(v);  //因为入了1，导致前面一位可能大于10，手动进位
        }
    }

    //倒序输出：
    bool flag = false;
    for (int i = v.size() - 1; i >= 0; --i) {
        if (v[i] != 0) flag = true;  //直到第一个非0位，才开始输出
        if (v[i]==-1) break;
        if (flag) cout << v[i];
    }


}
