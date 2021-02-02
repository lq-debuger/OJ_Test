/*
    问题描述：
        二进制转换的问题，想必大家都没有问题了吧，比如给你一个十进制数13，
        其对应的二进制表示为：1101。因为13=1*2^3+1*2^2+0*2^1+1*2^0.
        江鸟整天胡思乱想，现在他想到一个问题：如果将平时二进制转换过程中的基数2变成-2，那么转换过来的数将又是什么呢？
        江鸟将这种转换方式称为“负二进制转换”，为了让大家接受他的理论，他举了个例子如下：
        1*(-2)^3+1*(-2)^2+0*(-2)^1+1*(-2)^0=-3，所以-3的该种转换为1101.

    输入描述：
        有多组测试数据。 输入为一个整数M.-100000<=M<=100000

    输出描述：
        输出该种转换得到的结果(输出结果为只有0和1表示的一个串)
*/

/*
    二进制数：向下取整
    负二进制数：向上取整
*/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int m;
    while (cin >> m)
    {
        int s[105];
        stack<int> out;
        // cin >> m;
        if (m == 0)
        {
            cout << '0' << endl;
            continue;
        }
        while (m)
        {
            int temp = abs(m % (-2));
            out.push(temp);
            m = (m - temp) / (-2);
        }
        while (!out.empty())
        {
            cout << out.top();
            out.pop();
        }
        cout << endl;
    }

    return 0;
}