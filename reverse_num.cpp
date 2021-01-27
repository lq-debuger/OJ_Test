#include<bits/stdc++.h>

using namespace std;

//反转数据

int main(int argc, const char** argv) {
    int n; 
    scanf("%d", &n);
    int ans = 0;
    while (n>0)
    {
        ans *= 10;
        ans += (n % 10);
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}