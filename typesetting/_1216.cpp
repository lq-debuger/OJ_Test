/*
    问题描述：
        打印出一个旋转方阵,见样例输出

    输入描述：
        输入一个整数n(1 <= n <= 20), n为方阵的行数。
    输出描述：
        输出一个大小为n*n的距阵

    输入样例：
        5
    输出样例：
        1   16  15  14  13
        2   17  24  23  12
        3   18  25  22  11
        4   19  20  21  10
        5   6   7   8   9
*/

/*
    解题思路：
        一圈一圈的填值
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * @description: 
 * @param {int} a  ： 矩阵
 * @param {int} n  ： 一圈的大小
 * @param {int} k  ： 每一圈开始的位置
 * @param {int} temp  ：  每一圈最后的值
 * @return {*}
 */
int make_matrix(int a[][21], int n, int k, int temp)
{
    // a[k][k] = temp;
    for (int i = k; i <= k + n - 1; i++)
    {
        a[i][k] = temp;
        temp += 1;
    }
    for (int i = k + 1; i <= k + n - 1; i++)
    {
        a[k + n - 1][i] = temp;
        temp += 1;
    }
    for (int i = k + n - 2; i >= k; i--)
    {
        a[i][k + n - 1] = temp;
        temp += 1;
    }
    for (int i = k + n - 2; i >= k + 1; i--)
    {
        a[k][i] = temp;
        temp += 1;
    }
    int ans = temp;
    return ans;
}

int main(int argc, const char **argv)
{
    int n;
    cin >> n;
    int temp = 1;
    int a[21][21] = {0};
    int k = 1;
    for (int i = n; i > 0; i -= 2)
    {
        temp = make_matrix(a, i, k, temp);
        k += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j];
            if (a[i][j] < 10)
                cout << "   ";
            if (a[i][j] >= 10 && a[i][j] < 100)
                cout << "  ";
            if (a[i][j] >= 100 && a[i][j] < 1000)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}