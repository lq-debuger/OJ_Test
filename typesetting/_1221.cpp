/*
    问题描述：
        不知道为什么，哈特一直对矩阵情有独钟。 从以前的“哈特13的矩阵”、“神奇的矩阵”到现在的“旋转方阵”，Orz. 
        旋转方阵是一个有n行m列的矩阵，每个矩阵格子里有一个数字。 
        同样地，旋转方阵有3种操作： 
            操作1：将方阵顺时针旋转90度 
            操作2：将方阵沿纵向对称轴翻折 
            操作3：将方阵逆时针旋转90度 
        现在将对方阵进行k次操作，输出最后的方阵状态。 

    输入描述：
        多组输入数据，约20组 每组数据n+2行，第一行有三个整数n、m和k，1<=n<=100,1<=m<=100，1<=100<=k 
        第2行到n+1行每行有m个数字，表示方阵的初始状态，方阵格子数字大小不超过10000， 第n+2行有k个数字，表示k个操作的编号
    输出描述：
        每组数据输出一个矩阵，表示最终的方阵状态。

    输入样例：  
        2 3 1
        1 2 3
        4 5 6
        1
    输出样例：
        4 1
        5 2
        6 3
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * @description: 将矩阵顺时针旋转90° 
 * @param {int} a
 * @param {int} n
 * @param {int} m
 * @return {*}
 */
void spin_90_clock(int a[][101], int &n, int &m)
{
    int t[101][101] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            t[j][n - i + 1] = a[i][j];
        }
    }
    int temp = n;
    n = m;
    m = temp;
    // cout << n << m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = t[i][j];
        }
    }
}

/**
 * @description: 将矩阵逆时针旋转90°
 * @param {int} a
 * @param {int} n
 * @param {int} m
 * @return {*}
 */
void spin_90_unclock(int a[][101], int &n, int &m)
{
    int t[101][101] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            t[m - j + 1][i] = a[i][j];
        }
    }
    int temp = n;
    n = m;
    m = temp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = t[i][j];
        }
    }
}

/**
 * @description: 将方阵沿纵向对称轴翻折 
 * @param {int} a
 * @param {int} n
 * @param {int} m
 * @return {*}
 */
void symeetry(int a[][101], int n, int m)
{
    for (int i = 1, j = m; i < j; i++, j--)
    {
        for (int x = 1; x <= n; x++)
        {
            int temp = a[x][i];
            a[x][i] = a[x][j];
            a[x][j] = temp;
        }
    }
}

int main(int argc, const char **argv)
{
    // 输入数据
    int m, n, k;
    while (cin >> n >> m >> k)
    {
        int a[101][101] = {0};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        int op[101];
        for (int i = 1; i <= k; i++)
        {
            cin >> op[i];
        }

        // 进行操作
        for (int i = 1; i <= k; i++)
        {
            if (op[i] == 1)
                spin_90_clock(a, n, m);
            if (op[i] == 2)
                symeetry(a, n, m);
            if (op[i] == 3)
                spin_90_unclock(a, n, m);
        }

        // 输出数据
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}