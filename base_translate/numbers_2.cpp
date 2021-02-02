#include<bits/stdc++.h>

using namespace std;

//统计给定区间出现2的次数

int count_2(int a){
    int sum = 0 ;
    while(a){
        if(a%10 == 2) sum++;
        a /= 10;
    }
    return sum;
}

int main(int argc, const char** argv) {
    int min_num, max_num, count=0;
    cin >> min_num >> max_num;
    if(min_num > max_num) return 1;
    for (int i = min_num; i <= max_num; i++)
    {
        count += count_2(i);
    }
    cout << count << endl;
    
    return 0;
}