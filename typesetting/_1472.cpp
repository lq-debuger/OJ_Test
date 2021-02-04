/*
    问题描述：  
        2048游戏是一个4*4矩阵，用户可以按上下左右4个方向键让所有的方块向同一个方向运动，
        两个相同数字方块撞一起之后合并成为他们的和，每次操作之后随即生成一个2或者4.
        合并规则：相邻会碰撞的两个数字合并且一个位置只会触发一次合并，并且优先合并移动方向顶部的位置
        比如:
            2 2 2 2行向右合并为0 0 4 4
            0 2 2 2行向右合并为0 0 2 4

    输入描述：
        输入第一行是用户按下的方向键，其中1,2,3,4分表代表上、下、左、右键；
        接下来是一个4*4的矩阵，空格分割，0代表该位置没有数字.
    输出描述： 
        输出用户按下该方向键后生成的数字矩阵.
        不考虑随机生成的数字.

    输入样例：
        1
        0 0 0 2
        0 0 0 2
        0 0 4 8
        0 0 4 8
    输出样例：
        0 0 8 4
        0 0 0 16
        0 0 0 0
        0 0 0 0
*/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int x;
    while (cin >> x)
    {
        // 输入数据
        int a[5][5] = {0};
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                cin >> a[i][j];
            }
        }

        // 进行操作
        // 向上
        if (x == 1)
        {
            // 合并
            for (int j = 1; j <= 4; j++)
            {
                for (int i = 1; i < 4; i++)
                {
                    if (a[i][j] == 0)
                        continue;
                    if (a[i][j] == a[i + 1][j])
                    {
                        a[i][j] *= 2;
                        a[i + 1][j] = 0;
                    }
                }
            }
            // 移位
            for (int j = 1; j <= 4; j++)
            {
                for (int i = 1; i <= 4; i++)
                {
                    if (a[i][j] == 0)
                    {
                        for (int k = i + 1; k <= 4; k++)
                        {
                            if (a[k][j] != 0)
                            {
                                a[i][j] = a[k][j];
                                a[k][j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        // 向下
        if (x == 2)
        {
            // 合并
            for (int j = 1; j <= 4; j++)
            {
                for (int i = 4; i > 1; i--)
                {
                    if (a[i][j] == 0)
                        continue;
                    if (a[i][j] == a[i - 1][j])
                    {
                        a[i][j] *= 2;
                        a[i - 1][j] = 0;
                    }
                }
            }
            // 移位
            for (int j = 1; j <= 4; j++)
            {
                for (int i = 4; i >= 1; i--)
                {
                    if (a[i][j] == 0)
                    {
                        for (int k = i - 1; k >= 1; k--)
                        {
                            if (a[k][j] != 0)
                            {
                                a[i][j] = a[k][j];
                                a[k][j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        // 向左
        if (x == 3)
        {
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 1; j < 4; j++)
                {
                    if (a[i][j] == 0)
                        continue;
                    if (a[i][j] == a[i][j + 1])
                    {
                        a[i][j] *= 2;
                        a[i][j + 1] = 0;
                    }
                }
            }
            // 移位
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 1; j <= 4; j++)
                {
                    if (a[i][j] == 0)
                    {
                        for (int k = j + 1; k <= 4; k++)
                        {
                            if (a[i][k] != 0)
                            {
                                a[i][j] = a[i][k];
                                a[i][k] = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        // 向右
        if (x == 4)
        {
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 4; j > 1; j--)
                {
                    if (a[i][j] == 0)
                        continue;
                    if (a[i][j] == a[i][j -1])
                    {
                        a[i][j] *= 2;
                        a[i][j-1] = 0;
                    }
                }
            }
            // 移位
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 4; j >= 1; j--)
                {
                    if (a[i][j] == 0)
                    {
                        for (int k = j - 1; k >= 1; k--)
                        {
                            if (a[i][k] != 0)
                            {
                                a[i][j] = a[i][k];
                                a[i][k] = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }

        // 输出
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
