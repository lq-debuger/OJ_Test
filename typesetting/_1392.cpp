/*
    题目描述：
        输入n值，使用递归函数，求杨辉三角形中各个位置上的值。
    
    输入描述：
        一个大于等于2的整型数n
    输出描述：
        题目可能有多组不同的测试数据，对于每组输入数据，
        按题目的要求输出相应输入n的杨辉三角形。
*/


/*
-----非递归的方法

#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    int n;
    cin >> n;
    if (n < 2)
    {
        cout << "print error" << endl;
    }
    int a[21][21] = {0};
    a[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)        {
            a[i][j] = a[i-1][j] + a[i-1][j-1] ; 
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
} */

#include<bits/stdc++.h>

using namespace std;

int yanghui_traingle(int i, int j){
    if (j == 1 || j == i)
    {
        return 1;
    }else
    {
        return (yanghui_traingle(i-1,j-1) + yanghui_traingle(i-1,j));
    }
    
    
}

int main(int argc, const char** argv) {
    int n;
    while (cin >> n)
    {
        if (n < 2)
        {
            printf("print error");
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << yanghui_traingle(i,j) << " ";
            }
            cout << endl;
        }
           
    }
    return 0;
}