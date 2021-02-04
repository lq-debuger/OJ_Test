/*
    问题描述： 
        任意输入两个9阶以下矩阵，要求判断第二个是否是第一个的旋转矩阵，如果是，输出旋转角度（0、90、180、270），如果不是，输出-1。 
        要求先输入矩阵阶数，然后输入两个矩阵，每行两个数之间可以用任意个空格分隔。行之间用回车分隔，两个矩阵间用任意的回车分隔。

    输入描述：
        输入有多组数据。
        每组数据第一行输入n(1<=n<=9)，从第二行开始输入两个n阶矩阵

    输出描述： 
        判断第二个是否是第一个的旋转矩阵，如果是，输出旋转角度（0、90、180、270），如果不是，输出-1。
        如果旋转角度的结果有多个，则输出最小的那个

*/

/*
    别人的答案：
    #include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    int a[10][10],b[10][10];
    while(scanf("%d", &n)!=EOF){
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <= n ; j++){
            scanf("%d", &a[i][j]);
        }
        }
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <= n ; j++){
            scanf("%d", &b[i][j]);
        }
        }
            int c[4]={0};
            for (int i = 1 ; i <= n ; i++){
                for (int j = 1 ; j <= n ; j++){
                        if(a[i][j] == b[i][j])              c[0]++;
                        if(a[i][j] == b[j][n-i+1])          c[1]++;
                        if(a[i][j] == b[n-i+1][n-j+1])      c[2]++;
                        if(a[i][j] == b[n-j+1][i])          c[3]++;

    }

    }
    if (c[0] == n*n){
        printf("0\n");
        //continue;
    }
    else if (c[1] == n*n){
        printf("90\n");
    }
    else if (c[2] == n*n){
        printf("180\n");
    }
    else if (c[3] == n*n){
        printf("270\n");
    }
    else
        printf("-1\n");

}
        return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

// 判断a矩阵旋转90°后是否与b相同
bool spin_90(int a[][10], int b[][10], int c[][10], int n)
{
    // 旋转90度
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[j][n - i + 1] = a[i][j];
        }
    }
    // 判断c是否和b相同
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (c[i][j] != b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, const char **argv)
{
    int n;
    while (cin >> n)
    {
        int flag[4] = {0};
        int a[10][10] = {0};
        int b[10][10] = {0};
        int c[10][10] = {0};
        //输入第一个矩阵
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        // 输入第二个矩阵
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        // 旋转0°
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] != b[i][j])
                {
                    cnt = 1;
                    break;
                }
            }
            if (cnt == 1)
            {
                break;
            }
        }
        if (cnt == 0)
            flag[0] = 1;
        // 旋转90°
        if (spin_90(a, b, c, n))
        {
            flag[1] = 1;
        }
        // 旋转180°
        if (spin_90(c, b, a, n))
        {
            flag[2] = 1;
        }
        // 旋转270°
        if (spin_90(a, b, c, n))
        {
            flag[3] = 1;
        }
        if (flag[0] == 1)
        {
            cout << 0 << endl;
        }
        else if (flag[1] == 1)
        {
            cout << 90 << endl;
        }
        else if (flag[2] == 1)
        {
            cout << 180 << endl;
        }
        else if (flag[3] == 1)
        {
            cout << 270 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}