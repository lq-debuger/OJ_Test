#include<iostream>

using namespace std;

int sum(int a, int b){
    return a+b;
}

int main(int argc, const char** argv) {
    int a, b;
    cin >> a >> b;
    cout << sum(a, b) << endl;
    return 0;
}